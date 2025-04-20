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

typedef struct s_4x4_matrix {
	double values[4][4];
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
	t_matrix	*transform;			// Transforms from object space to world space
	t_matrix	*inverse_transform;	// Transforms from world space to object space
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
	t_tuple			position;
	t_tuple			direction;
	t_matrix		*transform;			// Transforms from object space to world space
	t_matrix		*inverse_transform;	// Transforms from world space to object space
	t_matrix		*inverse_transpose;
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
	t_x			*hit;		//The hit pointer.
	t_object	*object;	//The intersected object.
	t_tuple		point;		//The intersection point, in world space.
	t_tuple		eyev;		//The vector pointing from the point to the eye/camera.
	t_tuple		normalv;	//The normal vector at the intersection point (in world space).
	bool		inside;		//A boolean to check if the ray was originating from inside the object.
	t_tuple		over_point;	//The point just above the intersection point, used to avoid shadow acne.
}	t_comps;

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

typedef	struct s_render_params
{
	double	wall_z;			//Defines the fixed distance of the projection plane from the camera origin.
	double	wall_size;		//Defines the fixed world-space dimensions of the projection wall (which is a square).
	double	half_wall;		//Is half the size of the projection plane
	double	pixel_size;		//Calculates the size of one pixel on the fixed projection plane
	t_tuple	world_position;	//Stores the calculated world-space coordinates on the projection plane (wall) corresponding to the current pixel
	t_ray	ray;			//Stores the final ray directed from the origin towards the world position
}	t_render_params;


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
}	t_data;

#endif

