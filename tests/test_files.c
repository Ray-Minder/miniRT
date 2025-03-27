#include "../include/parser.h"
#include "../include/minirt.h"

void test_parse_ambient_light()
{
	t_scene scene;

	assert(parse_ambient_light(ft_split("A 0.01321 125,125,125", ' '), &scene) == SUCCESS);
	assert(compare_doubles(scene.ambient_light.strength, 0.01321));
	assert(scene.ambient_light.color.r == 125);
	assert(scene.ambient_light.color.g == 125);
	assert(scene.ambient_light.color.b == 125);

	assert(parse_ambient_light(ft_split("A 0.01321 125,125,125,125", ' '), &scene) == INVALID_ARG_COUNT);
	assert(parse_ambient_light(ft_split("A 0.01321 125,125", ' '), &scene) == INVALID_ARG_COUNT);
	assert(parse_ambient_light(ft_split("A -123 125,125,125", ' '), &scene) == DOUBLE_OUT_OF_RANGE);
	printf("parse_ambient_light tests passed\n");
}

void test_parse_uint8()
{
	uint8_t result;
	result = 0;
	assert(parse_uint8("0", &result) == SUCCESS);
	assert(result == 0);
	assert(parse_uint8("255", &result) == SUCCESS);
	assert(result == 255);
	assert(parse_uint8("256", &result) == INVALID_INT);
	assert(result == 0);
	assert(parse_uint8("a", &result) == INVALID_INT);
	assert(result == 0);
	assert(parse_uint8("1a", &result) == INVALID_INT);
	assert(result == 0);
	assert(parse_uint8("a1", &result) == INVALID_INT);
	assert(result == 0);
	assert(parse_uint8("a1a", &result) == INVALID_INT);
	assert(result == 0);
	assert(parse_uint8("1a1", &result) == INVALID_INT);
	assert(result == 0);
	assert(parse_uint8("1", &result) == SUCCESS);
	assert(result == 1);
	assert(parse_uint8("01", &result) == SUCCESS);
	assert(result == 1);
	assert(parse_uint8("001", &result) == SUCCESS);
	assert(result == 1);
	assert(parse_uint8("0001", &result) == SUCCESS);
	assert(result == 1);
	assert(parse_uint8("00001", &result) == INVALID_INT);
	printf("result: %d\n", result);
	assert(result == 0);
}

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
	test_parse_ambient_light();
	test_parse_uint8();
	test_ft_safe_atodbl();
	test_ft_is_double();
	test_filename();
	printf("All tests passed!\n");
}