#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# include "minirt.h"

# define SCALE 4

# define MAX_WINDOW_WIDTH 3840
# define MAX_WINDOW_HEIGHT 2160
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define MIN_WINDOW_WIDTH 500
# define MIN_WINDOW_HEIGHT 500


//	===== FUNCTIONS =====

//	===== CAMERA =====

//	camera.c

// t_camera *camera(double hsize, double vsize, double field_of_view);
void	camera(t_data *data, double field_of_view);

//	view_transform.c

// t_matrix	*view_transform(t_tuple from, t_tuple to, t_tuple up);
t_matrix	*view_transform(t_tuple forward, t_tuple point);

//	ray_for_pixel.c

t_ray	ray_for_pixel(t_camera *camera, int x, int y);

//	===== COLORS =====

t_color	color(double r, double g, double b);
t_color	add_colors(t_color c1, t_color c2);
t_color	subtract_colors(t_color c1, t_color c2);
t_color	multiply_color_by_scalar(t_color c, double scalar);
t_color	divide_color_by_scalar(t_color c, double scalar);
t_color	hadamard_product(t_color c1, t_color c2);
uint32_t	color_to_uint32(t_color color);

//	===== ERRORS =====

//	clean.c

void	clean(t_data *data, char *error_msg);
void	clean_and_exit(t_data *data, char *error_msg, int exit_code);

//	print_error.c

void	print_error_msg(char *error_msg);
void	print_errno(char *function_name);

//	===== INIT =====

void	init_data(t_data *data);
void	init_mlx(t_data	*data);

//	===== INTERSECT =====

//	color_at.c
t_color color_at(t_scene *scene, t_ray *ray);

// intersect_world.c

t_x *intersect_world(t_scene *scene, t_ray *ray);
t_x *cylinder_intersect(t_ray *ray, t_object *cylinder);


//	===== LIGHTING =====

//	ambient_lighting.c

t_color ambient_lighting(t_ambient_light ambient_light, t_color object_color);

//	diffuse_lighting.c

t_color diffuse_lighting(t_light light, t_tuple normal, t_tuple position, t_color object_color);

//	lighting.c

t_color	lighting(t_scene *scene, t_comps *comps);

//	shading.c

t_color	shade_hit(t_scene *scene, t_comps *comps);
bool	is_shadowed(t_scene *scene, t_tuple point);

//	specular_lighting.c

t_color	specular_lighting(t_light light, t_material material, double reflect_dot_eye);


//	===== MATRICES ======

// matrices.c

t_matrix	*create_matrix(int rows, int columns);
void 		initialize_matrix(t_matrix *matrix, double *data, int data_size);
t_matrix	*copy_matrix(t_matrix *m);
t_matrix	*identity(int size);

//	matrix_operations_1.c

bool		compare_matrices(t_matrix *a, t_matrix *b);
t_matrix	*multiply_matrices(t_matrix *a, t_matrix *b);
t_tuple		get_row_as_tuple(t_matrix *m, int row);
t_tuple		multiply_matrix_by_tuple(t_matrix *m, t_tuple t);

//	matrix_operations_2.c

t_matrix	*transpose_matrix(t_matrix *m);
t_matrix	*submatrix(t_matrix	*m, int row, int column);
double		determinant(t_matrix *m);
double		cofactor(t_matrix *m, int row, int col);
t_matrix	*invert_matrix(t_matrix *m);

//	matrix_utils.c

void 	free_matrix(t_matrix **matrix);
void 	free_array_of_matrices(t_matrix ***matrices);
int		size_of_array_of_matrices(t_matrix **matrices);
bool	is_matrix_initialized(t_matrix *matrix);
void 	print_matrix(t_matrix* matrix);

//	===== MLX =====

void	key_hooks(mlx_key_data_t keydata, void *param);


//	===== RAYS =====

//	normals.c

t_tuple	normal_at(t_object *object, t_tuple world_point);
t_tuple	normal_at_plane(t_object *object, t_tuple world_point);
t_tuple normal_at_cylinder(t_object *object, t_tuple world_point);
t_tuple normal_at_sphere(t_object *object, t_tuple world_point);
t_tuple reflect(t_tuple in, t_tuple normal);

//	intersection_utils.c

t_x		*new_intersection_node(void);
void	free_intersections_list(t_x **xs_list);
void	free_intersection_node(t_x **node_ptr);
void	print_intersection_list(t_x *xs_list);

//	intersections.c

t_x		*intersect(t_ray *ray, t_object *object);
t_x		*hit(t_x *xs_list);
void	add_intersection_node(t_x **xs_list, t_x *current);
t_x		*sphere_intersect(t_ray *ray, t_object *sphere);
t_x		*plane_intersect(t_ray *ray, t_object *plane);
double	calculate_discriminant(t_ray *ray);

//	ray.c

t_ray	create_ray(t_tuple origin, t_tuple direction);
t_tuple	position(t_ray ray, double t);


//	transform.c

t_ray	transform_ray(t_ray *ray, t_matrix *matrix);
void	set_transform(t_object *object, t_matrix *transformation);

//	===== RENDERING =====

void	init_render_params(t_render_params *params, int width, int height);
void	setup_default_scene(t_scene *scene);
t_comps	*prepare_computations(t_x *hit, t_ray *ray);

//	render_scene.c

void	render_scene(t_data *data);

//	render_sphere.c

void 	render_sphere(t_data *data);

//	render.c

void	render(t_data *data, t_camera *cam, t_scene *scene);

//	===== TRANSFORMATIONS =====

t_matrix	*translation(double x, double y, double z);
t_matrix	*translate_from_tuple(t_tuple tuple);
t_matrix	*scaling(double x, double y, double z);
t_matrix	*scaling_from_tuple(t_tuple tuple);
t_matrix	*rotation_x(double radians);
t_matrix	*rotation_y(double radians);
t_matrix	*rotation_z(double radians);
t_matrix	*shearing(double xy, double xz, double yx, 
						double yz, double zx, double zy);
t_matrix	*chain_transformations(t_matrix *matrices[]);

//	===== TUPLES =====

t_tuple	tuple(double x, double y, double z, double w);
t_tuple	point(double x, double y, double z);
t_tuple	vector(double x, double y, double z);
t_tuple add_tuples(t_tuple a, t_tuple b);
t_tuple	subtract_tuples(t_tuple a, t_tuple b);
t_tuple	negate_tuple(t_tuple t);
t_tuple	multiply_tuple_by_scalar(t_tuple t, double scalar);
t_tuple	divide_tuple_by_scalar(t_tuple t, double scalar);
double  tuple_magnitude(t_tuple t);
t_tuple normalize_tuple(t_tuple t);
t_tuple normalize_point(t_tuple t);
double  dot_product(t_tuple a, t_tuple b);
t_tuple cross_product(t_tuple a, t_tuple b);
void	print_tuple(t_tuple tuple);
bool	compare_tuples(t_tuple a, t_tuple b);

//	tuple_utils.c

t_color	tuple_to_color(t_tuple tuple);
t_tuple	color_to_tuple(t_color color);

//	===== UTILITIES =====

bool	compare_doubles(double a, double b);
double	radians(double degrees);


#endif