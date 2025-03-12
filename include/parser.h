#ifndef	PARSER_H
# define PARSER_H

# include <stdbool.h>
# include "scene.h"

bool	verify_filename(char *filename);
int		parse_scene(char *filename);
int		parse_ambient_light(char **line, t_scene *scene);
int		parse_camera(char **line, t_scene *scene);
int		parse_light(char **line, t_scene *scene);
int		parse_sphere(char **line, t_scene *scene);
int		parse_plane(char **line, t_scene *scene);
int		parse_cylinder(char **line, t_scene *scene);
bool	ft_is_double(char *s);
double	ft_atodbl(char *s);
double	ft_safe_atodbl(char *s);

#endif