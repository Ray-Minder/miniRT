#include <fcntl.h>
#include "../include/parser.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 1)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	// parse_scene(argv[1]);
	printf("%f\n", ft_atodbl("0.001"));
}