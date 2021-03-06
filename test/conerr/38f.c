/* 
TEST_HEADER
 id = $Id$
 summary = reserve and commit (functions) with different sizes
 language = c
 link = myfmt.o testlib.o
OUTPUT_SPEC
 assert = true
 assertfile P= mpsi.c
 assertcond = PointerAdd(mps_ap->init, size) == mps_ap->alloc
END_HEADER
*/

#include "testlib.h"
#include "mpscamc.h"
#include "myfmt.h"

#undef mps_reserve
#undef mps_commit

#define genCOUNT (3)

static mps_gen_param_s testChain[genCOUNT] = {
  { 6000, 0.90 }, { 8000, 0.65 }, { 16000, 0.50 } };

static void test(void *stack_pointer)
{
 mps_arena_t arena;
 mps_pool_t pool;
 mps_thr_t thread;
 mps_root_t root;

 mps_chain_t chain;
 mps_fmt_t format;
 mps_ap_t ap;
 mps_addr_t p;
 mps_addr_t q;

 cdie(mps_arena_create(&arena, mps_arena_class_vm(), mmqaArenaSIZE), "create arena");

 cdie(mps_thread_reg(&thread, arena), "register thread");

 cdie(mps_root_create_thread(&root, arena, thread, stack_pointer), "thread root");
 cdie(
  mps_fmt_create_A(&format, arena, &fmtA),
  "create format");

 cdie(mps_chain_create(&chain, arena, genCOUNT, testChain), "chain_create");

 cdie(
  mps_pool_create(&pool, arena, mps_class_amc(), format, chain),
  "create pool");

 cdie(
  mps_ap_create(&ap, pool, mps_rank_exact()),
  "create ap");

 do
 {
  cdie(mps_reserve(&p, ap, 0x100), "Reserve: ");
  q = (mps_addr_t) ((char *)p);
 }
 while (!mps_commit(ap, q, 0x110));
 comment("Committed.");

 mps_ap_destroy(ap);
 comment("Destroyed ap.");

 mps_pool_destroy(pool);
 comment("Destroyed pool.");

 mps_fmt_destroy(format);
 comment("Destroyed format.");

 mps_chain_destroy(chain);
 comment("Destroyed chain.");

 mps_root_destroy(root);
 comment("Destroyed root.");

 mps_thread_dereg(thread);
 comment("Deregistered thread.");

 mps_arena_destroy(arena);
 comment("Destroyed arena.");
}

int main(void)
{
 run_test(test);
 return 0;
}

