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

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_uint8color
{
	uint8_t	r;
	uint8_t g;
	uint8_t b;
}	t_uint8color;

typedef struct s_ambient_light
{
	bool	is_set;
	double	brightness;
	t_color color;
}	t_ambient_light;

typedef struct s_camera
{
	bool		is_set;
	t_tuple		position;	// 'From' point
	t_tuple		forward;	// Normalized direction vector camera is looking
	t_matrix	*transform;	// Camera-to-world matrix (INVERSE view transform)
	double		fov;		// Horizontal field of view in DEGREES [0, 180]
}	t_camera;

typedef struct s_light
{
	bool		is_set;
	t_tuple		position;	// Position of the light source
	t_matrix	*transform;	// Not needed for point lights
	double		brightness;	// Light brightness ratio [0.0, 1.0]
	t_color		color;		// Light color
}	t_light;

typedef struct s_material
{
	t_color	color;
	double	ambient;	// [0, 1] how much ambient light it reflects
	double	diffuse;	// [0, 1] how much diffuse light it reflects
	double	specular;	// [0, 1] how much specular light it reflects
	double	shininess;	// [10, ~] controls size of specular highlight (e.g., 200)
}	t_material;

typedef struct s_object
{
	t_object_type	type;
	t_tuple			position;	// Center for sphere/cylinder, a point on the plane
	t_tuple			direction;	// Normalized axis vector for cylinder, normal for plane
	t_matrix		*transform;	// Object's transformation matrix (world space)
	t_material		material;	// Surface properties
	double			diameter;	// Sphere/Cylinder diameter
	double			height;		// Cylinder height
	struct s_object	*next;		// Next object in the linked list
}	t_object;

typedef struct s_intersection
{
	t_object	*object;	// The object hit
	double		t;			// Parameter along the ray where the hit occurred
	bool		is_hit;
	t_x			*next;		 // Next intersection in the list
}	t_x;

typedef struct s_scene
{
	t_ambient_light ambient_light;
	t_camera		camera;
	t_light			light;		// Only one for mandatory part
	t_object		*objects;	// Linked list of all objects in the scene
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
	t_scene		*scene;		// Pointer to the parsed scene data
	int			width;		// Canvas width
	int			height;		// Canvas height
}	t_data;

#endif
