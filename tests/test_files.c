#include "../include/parser.h"
#include <assert.h>
#include <stdio.h>

void test_filename()
{
	char *fn = "test.rt";
	char *fn1 = "test.rtrt";
	char *fn2 = "test.";
	char *fn3 = "test";
	char *fn4 = "testrt";
	char *fn5 = "test.rt.rt";
	assert(verify_filename(fn) == true);
	assert(verify_filename(fn1) == false);
	assert(verify_filename(fn2) == false);
	assert(verify_filename(fn3) == false);
	assert(verify_filename(fn4) == false);
	assert(verify_filename(fn5) == true);
	printf("Filename tests passed.\n");
}

int main(void)
{
	test_filename();
	printf("All tests passed!\n");
}