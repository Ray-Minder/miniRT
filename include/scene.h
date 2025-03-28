#ifndef SCENE_H
# define SCENE_H

#include <stdint.h>
#include "tuples.h"
#include "matrices.h"

typedef enum e_object_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_object_type;

typedef struct s_uint8color
{
	uint8_t	r;
	uint8_t g;
	uint8_t b;
}	t_uint8color;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_ambient_light
{
	bool	is_set;
	double	strength;
	t_color color;
}	t_ambient_light;

typedef struct s_camera
{
	bool		is_set;
	t_tuple		position;
	t_tuple		forward;
	t_matrix	*transform;
	double		fov;
}	t_camera;

typedef struct s_light
{
	bool	is_set;
	t_tuple	position;
	t_matrix	*transform;
	double	brightness;
	t_color	color;
}	t_light;

// typedef struct s_sphere
// {
// 	t_tuple	position;
// 	double	diameter;
// 	t_co	color;
// 	struct s_sphere	*next;
// }	t_sphere;

// typedef struct s_plane
// {
// 	t_tuple	point;
// 	t_tuple	normal;
// 	t_uint8color	color;
// 	struct s_plane	*next;
// }	t_plane;

// typedef struct s_cylinder
// {
// 	t_tuple	position;
// 	t_tuple	axis;
// 	double	diameter;
// 	double	height;
// 	t_uint8color	color;
// 	struct s_cylinder	*next;
// }	t_cylinder;

typedef struct s_object
{
	t_object_type	type;
	t_tuple			position;
	t_matrix		*transform;
	t_tuple			direction;
	t_color			color;
	double			diameter;
	double			height;
	struct s_object	*next;
}	t_object;

typedef struct s_scene
{
	t_ambient_light ambient_light;
	t_camera		camera;
	t_light			light;
	t_object		*objects;
}	t_scene;

#endif