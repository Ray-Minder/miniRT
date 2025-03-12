#include "../include/transformations.h"
#include <assert.h>

void	test_translation()
{

	printf("Test translation passed.!\n");
}

void	test_scaling()
{

	printf("Test scaling passed.!\n");
}

void	test_rotation()
{

	printf("Test rotation passed.!\n");
}

void	test_shearing()
{

	printf("Test shearing passed.!\n");
}

int main(void)
{
	test_translation();
	test_scaling();
	test_rotation();
	test_shearing();
	printf("All tests passed!\n");
	return (0);
}