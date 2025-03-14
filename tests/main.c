#include <fcntl.h>
#include "../include/parser.h"
#include "../libft/libft.h"
#include "../include/scene.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	t_scene scene;
	scene.objects = NULL;
	int error;

	error = 0;
	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	error = parse_scene(argv[1], &scene);
	if (error != SUCCESS)
	{
		cleanup(&scene);
		printf("Error: %d\n", error);
		return (1);
	}
	printf("Ambient light strength: %f\n", scene.ambient_light.strength);
	printf("Ambient light color: %d, %d, %d\n\n", scene.ambient_light.color.r, scene.ambient_light.color.g, scene.ambient_light.color.b);
	printf("Camera position: %f, %f, %f\n", scene.camera.position.x, scene.camera.position.y, scene.camera.position.z);
	printf("Camera forward: %f, %f, %f\n", scene.camera.forward.x, scene.camera.forward.y, scene.camera.forward.z);
	printf("Camera fov: %f\n\n", scene.camera.fov);
	printf("Light position: %f, %f, %f\n", scene.light.position.x, scene.light.position.y, scene.light.position.z);
	printf("Light brightness: %f\n", scene.light.brightness);
	printf("Light color: %d, %d, %d\n\n", scene.light.color.r, scene.light.color.g, scene.light.color.b);
	printf("Error: %d\n", error);
	print_objects(scene.objects);
	cleanup(&scene);
	return (0);
}