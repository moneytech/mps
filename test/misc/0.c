/* 
TEST_HEADER
 id = $Id$
 summary = cause segv and see if has usual effect
 language = c
 link = testlib.o
OUTPUT_SPEC
 memoryerror = true
END_HEADER
*/

#include <stdio.h>
#include "mps.h"
#include "testlib.h"

static void test(void *stack_pointer)
{
 mps_arena_t arena;
 int *p;

 cdie(mps_arena_create(&arena, mps_arena_class_vm(), mmqaArenaSIZE), "create arena");

 p = NULL;
 printf("%i", *p);
}

int main(void)
{
 run_test(test);
 return 0;
}

