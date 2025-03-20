#include "../../include/parser.h"
#include "../../include/scene.h"

void	initialize_scene(t_scene *scene)
{
	scene->ambient_light.is_set = false;
	scene->camera.is_set = false;
	scene->light.is_set = false;
	scene->objects = NULL;
}

int	validate_scene(t_scene *scene)
{
	if (scene->ambient_light.is_set == false)
		return (NO_AMBIENT_LIGHT);
	if (scene->camera.is_set == false)
		return (NO_CAMERA);
	if (scene->light.is_set == false)
		return (NO_LIGHTS);
	return (SUCCESS);
}