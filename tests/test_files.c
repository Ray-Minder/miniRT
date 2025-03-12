#include "../include/parser.h"
#include "../include/utilities.h"
#include <assert.h>
#include <stdio.h>

void test_ft_safe_atodbl()
{
	assert(compare_doubles(ft_safe_atodbl("0.0001"), 0.0001));
	assert(compare_doubles(ft_safe_atodbl("1"), 1));
	assert(compare_doubles(ft_safe_atodbl("2000"), 2000));
	assert(compare_doubles(ft_safe_atodbl("-200"), -200));
	assert(compare_doubles(ft_safe_atodbl("-200.0001"), -200.0001));
	assert(compare_doubles(ft_safe_atodbl("0.0001"), 0.0001));
	assert(compare_doubles(ft_safe_atodbl("0"), 0));
	assert(compare_doubles(ft_safe_atodbl("0.0"), 0));
	assert(compare_doubles(ft_safe_atodbl("0.0asaf"), 0));
	assert(compare_doubles(ft_safe_atodbl("0.0.0"), 0));
	assert(compare_doubles(ft_safe_atodbl("asdf"), 0));
	printf("%f\n", ft_safe_atodbl("0.0001"));
	printf("%f\n", ft_safe_atodbl("1"));
	printf("%f\n", ft_safe_atodbl("2000"));
	printf("%f\n", ft_safe_atodbl("-200"));
	printf("%f\n", ft_safe_atodbl("-200.0001"));
	printf("%f\n", 0.0001);
	printf("ft_safe_atodbl tests passed\n");
}

void test_ft_is_double(void)
{
	assert(ft_is_double(".00001") == true);
	assert(ft_is_double(".a") == false);
	assert(ft_is_double("123098120398123.00000") == true);
	assert(ft_is_double("..01") == false);
	assert(ft_is_double("1.1"));
	assert(ft_is_double(".0") == true);
	assert(ft_is_double("0") == true);
	assert(ft_is_double("9") == true);
	assert(ft_is_double("a") ==  false);
	assert(ft_is_double("") == false);
	assert(ft_is_double(".") == false);
	assert(ft_is_double("-9") == true);
	assert(ft_is_double("+9") == true);
	assert(ft_is_double("-9.03") == true);
	assert(ft_is_double("-") == false);
	assert(ft_is_double("+") == false);
	assert(ft_is_double("++9") == false);
	assert(ft_is_double("1.") == false);
	printf("ft_is_double tests passed\n");
}

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
	test_ft_safe_atodbl();
	test_ft_is_double();
	test_filename();
	printf("All tests passed!\n");
}