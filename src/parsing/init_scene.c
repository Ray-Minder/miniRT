/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_scene.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eandela <eandela@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/30 12:12:59 by eandela       #+#    #+#                 */
/*   Updated: 2025/04/30 12:13:00 by eandela       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//	=== Function Declarations ===

void	init_scene(t_scene *scene);
int		validate_scene(t_scene *scene);

//	=== Function Definitions ===

void	init_scene(t_scene *scene)
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
