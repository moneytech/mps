/* 
TEST_HEADER
 id = $Id$
 summary = use AMC and LO without inactive LO pool
 language = c
 link = testlib.o awlfmt.o
 parameters = ITERATIONS=10
END_HEADER
*/

#include "testlib.h"
#include "mpscamc.h"
#include "mpsclo.h"
#include "mpsavm.h"
#include "awlfmt.h"


#define genCOUNT (3)

static mps_gen_param_s testChain[genCOUNT] = {
  { 6000, 0.90 }, { 8000, 0.65 }, { 16000, 0.50 } };


static void test(void *stack_pointer)
{
 mps_arena_t arena;
 mps_pool_t poolamc, poollo;
 mps_thr_t thread;
 mps_root_t root;

 mps_fmt_t format;
 mps_chain_t chain;
 mps_ap_t apamc, aplo;

 mycell *a, *b, *c, *d, *e, *f, *g;

 int i;
 int j;

 RC;

 cdie(mps_arena_create(&arena, mps_arena_class_vm(), mmqaArenaSIZE),
      "create arena");

 die(mps_thread_reg(&thread, arena), "register thread");
 cdie(mps_root_create_thread(&root, arena, thread, stack_pointer), "thread root");
 die(mps_fmt_create_A(&format, arena, &fmtA), "create format");
 cdie(mps_chain_create(&chain, arena, genCOUNT, testChain), "chain_create");

 die(mmqa_pool_create_chain(&poolamc, arena, mps_class_amc(), format, chain),
     "create pool(amc)");

 cdie(
  mps_pool_create(&poollo, arena, mps_class_lo(), format),
  "create pool");

 cdie(
  mps_ap_create(&aplo, poollo, mps_rank_exact()),
  "create ap");

 cdie(
  mps_ap_create(&apamc, poolamc, mps_rank_exact()),
  "create ap(amc)");

 b = allocone(apamc, 1, 1);

 for (j = 1; j <= ITERATIONS; j++) {
  comment("%i of %i.", j, ITERATIONS);
  UC;
  a = allocone(apamc, 5, 1);
  b = a;
  c = a;
  d = a;
  e = a;
  f = a;
  g = a;

  for (i = 0; i < 5000; i++) {
   UC;
   c = allocone(apamc, 20, 1);
   d = allocone(aplo, 20, 1);
   if (ranint(8) == 0) e = c;
   if (ranint(8) == 0) f = c;
   if (ranint(8) == 0) g = c;
   UC;
   setref(b, 0, c);
   UC;
   setref(c, 1, d);
   UC;
   setref(c, 2, e);
   UC;
   setref(c, 3, f);
   UC;
   setref(c, 4, g);
   UC;
   b = c;
  }
  DC;
  DMC;
 }

 mps_arena_park(arena);
 mps_ap_destroy(aplo);
 mps_ap_destroy(apamc);
 mps_pool_destroy(poolamc);
 mps_pool_destroy(poollo);
 mps_chain_destroy(chain);
 mps_fmt_destroy(format);
 mps_root_destroy(root);
 mps_thread_dereg(thread);
 mps_arena_destroy(arena);
 comment("Destroyed arena.");
}


int main(void)
{
 run_test(test);
 pass();
 return 0;
}
