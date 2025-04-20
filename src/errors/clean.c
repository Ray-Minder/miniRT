#include "../../include/minirt.h"

//	=== Function Declarations ===

void	clean_and_exit(t_data *data, int exit_code);
void	free_scene(t_scene **scene);
void	free_camera(t_camera *camera);
void	free_light(t_light *light);
void	free_objects(t_object **object_list);

//	=== Function Definitions ===

void	clean_and_exit(t_data *data, int exit_code)
{
	if (!data)
		exit(exit_code);
	if (data->canvas)
		mlx_delete_image(data->mlx, data->canvas);
	if (data->mlx)
	{
		mlx_close_window(data->mlx);
		mlx_terminate(data->mlx);
	}
	if (data->scene)
		free_scene(&data->scene);
	exit(exit_code);
}

void	free_scene(t_scene **scene)
{
	if (!*scene)
		return ;
	if ((*scene)->camera.is_set)
		free_camera(&(*scene)->camera);
	if ((*scene)->light.is_set)
		free_light(&(*scene)->light);
	if ((*scene)->objects != NULL)
		free_objects(&(*scene)->objects);
	free(*scene);
	*scene = NULL;
}


void	free_camera(t_camera *camera)
{
	if (!camera)
		return ;
	if (camera->transform)
		free_matrix(&camera->transform);
	if (camera->inverse_transform)
		free_matrix(&camera->inverse_transform);
	camera->is_set = false;
}

void	free_light(t_light *light)
{
	if (!light)
		return ;
	light->is_set = false;
}

void	free_objects(t_object **object_list)
{
	t_object	*next;
	t_object	*current;

	if (!object_list || !*object_list)
		return ;
	current = *object_list;
	while (current)
	{
		next = current->next;
		if (current->transform)
			free_matrix(&current->transform);
		if (current->inverse_transform)
			free_matrix(&current->inverse_transform);
		if (current->inverse_transpose)
			free_matrix(&current->inverse_transpose);
		free(current);
		current = next;
	}
	*object_list = NULL;
}
