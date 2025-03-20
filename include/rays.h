#ifndef RAYS_H
# define RAYS_H

# include "tuples.h"
# include "minirt.h"

typedef struct	s_ray
{
	t_tuple	origin;
	t_tuple	direction;
	
}	t_ray;

typedef struct s_data t_data;


t_ray	create_ray(t_tuple origin, t_tuple direction);
t_tuple	position(t_ray ray, double t);

mlx_image_t	*draw_circle(t_data *data, int radius);

#endif