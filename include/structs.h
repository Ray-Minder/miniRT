#ifndef STRUCTS_H
# define STRUCTS_H

# include "minirt.h"

typedef struct s_intersection t_x;

typedef struct s_tuple {
    double x;
    double y;
    double z;
    double w;
}	t_tuple;

typedef struct s_matrix {
	int		rows;
	int		columns;
	double	**values;
}	t_matrix;

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
	double	brightness;
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
	bool		is_set;
	t_tuple		position;
	t_matrix	*transform;
	double		brightness;
	t_color		color;
}	t_light;

typedef struct s_material
{
	t_color	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}	t_material;

typedef struct s_object
{
	t_object_type	type;
	t_tuple			position;
	t_tuple			direction;
	t_matrix		*transform;
	t_material		material;
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

typedef struct s_scene
{
	t_ambient_light ambient_light;
	t_camera		camera;
	t_light			light;
	t_object		*objects;
}	t_scene;

typedef struct	s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_computations
{
	t_x			*hit;		// The hit pointer, instead of the below variable which is the value at the intersection
	// double		t;			// The t-value of the intersection
	t_object	*object;	// The object intersected
	t_tuple		point;		// The intersection point, in world space
	t_tuple		eyev;		// The vector pointing from the point to the eye/camera
	t_tuple		normalv;	// The normal vector at the intersection point (in world space)
	bool		inside;		// A boolean to check if the ray was originating from inside the object 
	t_tuple		over_point;	// Point slightly offset above the surface (for shadows)
	t_tuple		reflectv;	// The reflection vector
}	t_comps;


typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*canvas;
	t_camera	*cam;
	t_light		*light;
	t_scene		*scene;
	int			width;
	int			height;
}	t_data;

#endif
