#ifndef	PARSER_H
# define PARSER_H

# include "minirt.h"

typedef enum e_error
{
	SUCCESS,
	INVALID_FILENAME,
	NO_ACCESS,
	INVALID_ELEMENT,
	SPLIT_ERROR,
	INVALID_DOUBLE,
	INVALID_INT,
	INVALID_ARG_COUNT,
	TOO_MANY_AMBIENT_LIGHTS,
	NO_AMBIENT_LIGHT,
	TOO_MANY_CAMERAS,
	NO_CAMERA,
	TOO_MANY_LIGHTS,
	NO_LIGHTS,
	FOV_OUT_OF_RANGE,
	DOUBLE_OUT_OF_RANGE,
	MALLOC_FAIL
}	t_error;

bool	verify_filename(char *filename);
int		parse_scene(char *filename, t_scene *scene);
int		parse_ambient_light(char **line, t_scene *scene);
int		parse_camera(char **line, t_scene *scene);
int		parse_light(char **line, t_scene *scene);
int		parse_sphere(char **line, t_scene *scene);
int		parse_plane(char **line, t_scene *scene);
int		parse_cylinder(char **line, t_scene *scene);
bool	ft_is_double(const char *s);
double	ft_atodbl(char *s);
double	ft_safe_atodbl(char *s);
int		parse_uint8(const char *s, uint8_t *result);
int		parse_double(const char *s, double *result);
int		parse_color(char *line, t_color *color);
int		parse_tuple(char *line, t_tuple *tuple);
int		count_tokens(char **tokens);
void	ft_free_ptrs(char **ptrs);
void	print_objects(t_object *object_list);
void	cleanup(t_scene *scene);
int		add_new_object(t_scene *scene, t_object **new_object);
int		print_error(t_error error);
int		validate_scene(t_scene *scene);
int		set_object_transforms(t_object *objects);
t_matrix *get_transform(t_tuple tuple, t_tuple position);
t_matrix *tuples_to_matrix(t_tuple up, t_tuple right, t_tuple forward, t_tuple position);
t_matrix *get_camera_matrix(t_camera camera);
int			set_transforms(t_scene *scene);

#endif