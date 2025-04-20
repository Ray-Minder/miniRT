#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <math.h>
# include <assert.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

# include "../libraries/libft/include/libft.h"
# include "../libraries/MLX42/include/MLX42/MLX42.h"

# include "structs.h"
# include "constants.h"
# include "definitions.h"
# include "errors.h"
# include "get_next_line.h"

typedef enum e_error t_error;
typedef struct s_tuple t_tuple;
typedef struct s_matrix t_matrix;
typedef enum e_object_type t_object_type;
typedef struct s_color t_color;
typedef struct s_ambient_light t_ambient_light;
typedef struct s_camera t_camera;
typedef struct s_light t_light;
typedef struct s_sphere t_sphere;
typedef struct s_plane t_plane;
typedef struct s_cylinder t_cylinder;
typedef struct s_object t_object;
typedef struct s_scene t_scene;
typedef struct s_intersection t_x;
typedef struct	s_ray t_ray;
typedef struct s_data t_data;


#endif