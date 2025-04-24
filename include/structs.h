#ifndef STRUCTS_H
# define STRUCTS_H

# include "minirt.h"

typedef struct s_intersection	t_x;

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

typedef struct s_matrix
{
	int		rows;
	int		columns;
	double	**values;
}	t_matrix;

typedef struct s_4x4_matrix
{
	double	values[4][4];
}	t_4x4_matrix;

typedef enum e_object_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_object_type;

typedef struct s_uint8color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
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
	double	brightness;
	t_color	color;
}	t_ambient_light;

typedef struct s_camera
{
	bool		is_set;
	t_tuple		position;
	t_tuple		forward;
	t_matrix	*transform;
	t_matrix	*inverse_transform;
	t_tuple		origin;
	double		fov;
	double		hsize;
	double		vsize;
	double		half_view;
	double		aspect;
	double		pixel_size;
	double		half_width;
	double		half_height;
}	t_camera;

typedef struct s_light
{
	bool		is_set;
	t_tuple		position;
	double		brightness;
	t_color		color;
}	t_light;

typedef struct s_object
{
	t_object_type	type;
	t_tuple			pos;
	t_tuple			dir;
	t_matrix		*transform;
	t_matrix		*inv_transform;
	t_matrix		*inv_transpose;
	t_color			color;
	double			diameter;
	double			height;
	struct s_object	*next;
}	t_object;

typedef struct s_intersection
{
	t_object	*object;
	double		t;
	bool		is_hit;
	t_x			*next;
}	t_x;

typedef struct s_comps
{
	t_x			*hit;
	t_object	*object;
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
	bool		inside;
	t_tuple		over_point;
}	t_comps;

typedef struct s_scene
{
	t_ambient_light	ambient_light;
	t_camera		camera;
	t_light			light;
	t_object		*objects;
}	t_scene;

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*canvas;
	t_scene		*scene;
	t_camera	*cam;
	t_light		*light;
	int			width;
	int			height;
	int			current_row;
	t_x			*xs_list;
	t_x			*curr_xs;
	t_x			*hit;
}	t_data;

#endif
