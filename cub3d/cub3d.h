/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ouaj <mel-ouaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:10:27 by mel-ouaj          #+#    #+#             */
/*   Updated: 2025/11/28 10:30:58 by mel-ouaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>
# define ERROR 1
# define SUCCESS 0
# define MAX_WIDTH 512
# define MAX_HEIGHT 512
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
# define SPEED 1
# define ROT 0.04
# define SCREEN_WIDTH 1000
# define SCREEN_HEIGHT 800

typedef struct s_tex
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bpp;
	int			line_len;
	int			endian;
}				t_tex;

typedef struct s_data
{
	t_tex		tex_no;
	t_tex		tex_so;
	t_tex		tex_ea;
	t_tex		tex_we;
	t_tex		*wall_tex;
	int			map_height;
	int			map_width;
	int			w;
	int			a;
	int			s;
	int			d;
	int			right;
	int			left;
	char		**map;
	void		*mlx;
	void		*mlx_window;
	double		x_pos;
	double		y_pos;
	double		x_dir;
	double		y_dir;
	double		x_plane;
	double		y_plane;
	double		ray_dir_x;
	double		ray_dir_y;
	double		deltadist_x;
	double		deltadist_y;
	double		sidestep_x;
	double		sidestep_y;
	double		player_x;
	double		player_y;
	double		wall_dist;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	double		camera_x;
	void		*img;
	char		*addr;
	int			line_length;
	int			bpp;
	int			endian;
	int			side;
	int			tex_num;
	double		wall_x;
	double		fwallx;
	double		texpos;
	double		tex_step;
	int			tex_x;
	int			tex_y;
}				t_data;

typedef struct s_rgb
{
	int			r;
	int			g;
	int			b;
	char		*red;
	char		*green;
	char		*blue;
	char		**rgb_colors;
}				t_rgb;

typedef struct s_map
{
	char		**map_grid;
	char		**flood_fill_copy;
	size_t		width;
	size_t		height;
}				t_map;

typedef struct s_config
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			seen_id[6];
	int			floor_flag;
	int			ceiling_flag;
	t_rgb		floor;
	t_rgb		ceiling;
	t_map		map;
}				t_config;

typedef struct s_player
{
	int			index;
}				t_player;

typedef struct s_game
{
	t_config	config;
	t_player	player;
	t_data		*data;
	size_t		line_length;
	size_t		line_count;
	int			textures_data_count;
	int			player_seen;
	int			map_exist_flag;
}				t_game;

/* ------------------------ Parsing main functions -------------------------- */

int				parse_map(t_game *game, char *filename);
int				get_map_copy_demensions(t_game *game, int fd);
int				measure_map(size_t *height, size_t *max_width, char *filename);
int				check_cub_extension(char *filename);

/* ------------------------ Line processing --------------------------------- */

int				process_line(t_game *game, char *line);
int				fill_map_grid(t_game *game, char *line);
int				is_map_line(char *line);
int				player_is_duplicated(char *line, t_game *game);

/* ------------------------ Map validation ---------------------------------- */

int				validate_map_grid(t_game *game);
int				all_lines_are_walled(size_t height, char **map_grid);
int				line_is_walled(char *line);
int				map_is_walled(char **map, size_t height, size_t width);
int				if_space_is_walled(char **map, size_t height, size_t width);
void			mark_border_spaces(char **map, int height, int width);
int				is_identifier(char c, t_game *game);
bool			is_walkable(char c);
bool			char_is_wall(char **map, size_t *index, size_t height,
					size_t width);

/* ------------------------ Map padding ------------------------------------- */

int				pad_map(t_game *game);
char			*pad_line(char *line, size_t max_len);

/* ------------------------ Texture & RGB parsing --------------------------- */

int				get_map_directions_rgb(t_game *game, char *line);
int				get_north_path(char *line, int index, t_game *game);
int				get_south_path(char *line, int index, t_game *game);
int				get_west_path(char *line, int index, t_game *game);
int				get_east_path(char *line, int index, t_game *game);
int				get_floor_rgb(t_game *game, char *line);
int				get_ceiling_rgb(t_game *game, char *line);

/* ------------------------ Utility functions ------------------------------- */

char			*skip_identifier_and_spaces(char *line, int index, int id_len);
int				check_for_ids_existence(t_game *game);
int				textures_before_map(t_game *game);
int				is_valid_xpm_path(char *path);
int				validate_texture_paths(t_config *config);

/* ------------------------ RGB validation ---------------------------------- */

int				parse_rgb(t_rgb *rgb, char *rgb_line);
int				has_only_digits(char *red, char *blue, char *green);
int				check_rgb_values(int red, int green, int blue);
int				is_valid_rgb_char(char c);
int				is_valid_rgb_line(char *rgb_line);

/* ------------------------ Memory & error handling ------------------------- */

void			free_array(char **double_array);
void			free_rgb_array(char **rgb_array);
int				malloc_failed(t_rgb *rgb);
int				free_all_data(t_game *game);
int				initilaize_data(t_game *game);
int				safe_free(char *line);
void			free_textures(t_data *data);
void			free_config(t_config *config);
void			free_rgb(t_rgb *rgb);
void			free_paths(t_config *config);
void			free_colors(char *red, char *green, char *blue);

/* ------------------------ Game & rendering ------------------------------- */

int				start_game(t_game *game);

////////////////////////////////////////////////////////////////////////
//                             FREE FUNCTIONS                         //
////////////////////////////////////////////////////////////////////////

void			cleanup_mlx(t_game *game);
void			free_array(char **double_array);
void			free_rgb_array(char **rgb_array);
int				free_all_data(t_game *game);
int				free_if_malloc_failed(char *red, char *blue, char *green,
					char **rgb_colors);
int				free_if_malloc_failed(char *red, char *blue, char *green,
					char **rgb_colors);

////////////////////////////////////////////////////////////////////////
//                             MAP CHECK FUNCTIONS                    //
////////////////////////////////////////////////////////////////////////

int				textures_before_map(t_game *game);
int				is_map_line(char *line);

////////////////////////////////////////////////////////////////////////
//                             ERROR MESSAGES FUNCTIONS               //
////////////////////////////////////////////////////////////////////////

int				file_not_found(char *filename);
int				malloc_failure(void);
int				invalid_extension(char *filename);
int				empty_map(void);
int				id_is_duplicate(int which_dir);
int				map_is_not_last(void);
int				is_identifier(char c, t_game *game);
int				invalid_map(char *line);
int				texture_missing(void);
int				east_direction_missing(void);
int				west_direction_missing(void);
int				north_direction_missing(void);
int				south_direction_missing(void);
int				ceiling_is_missing(void);
int				floor_is_missing(void);
int				textures_not_found(void);
int				map_is_short(void);
int				line_isnt_start_walled(int line_index);
int				line_isnt_end_walled(int line_index);
int				map_is_not_fully_walled(void);
int				stranger_element(void);
int				duplicated_player(void);
int				player_not_found(void);
int				invalid_north_path(char *north_path);
int				invalid_south_path(char *south_path);
int				invalid_west_path(char *west_path);
int				invalid_east_path(char *east_path);
int				forbidden_north_line(char *north_line);
int				forbidden_south_line(char *south_line);
int				forbidden_east_line(char *east_line);
int				forbidden_west_line(char *west_line);
int				map_row_is_short(void);
int				space_isnt_walled(void);
int				missing_map_file(void);

////////////////////////////////////////////////////////////////////////
//                             RAYCASTING FUNCTIONS                   //
////////////////////////////////////////////////////////////////////////

void			draw_tiles(t_data *data, int size);
void			draw_map(t_game *game);
void			read_map(char **map, char *str);
void			my_pixel_put(t_data *img, int x, int y, int color);
void			player_pos(t_data *data);
void			draw_player(t_data *data);
void			free_all(t_data *data);
void			draw_line(t_data *data, int x_end, int y_end, int color);
void			player_dir(t_data *data);
void			draw_direction(t_data *data);
void			rotate_left(t_data *data, double angle);
void			rotate_right(t_data *data, double angle);
void			rotation(t_data *data, double angle);
int				keyrelease(int keycode, t_game *game);
int				keyhook(void *data);
int				keypress(int keycode, t_game *game);
int				close_win(t_game *game);
void			cast_rays(t_data *data);
void			calculation(t_data *data);
void			dda(t_data *data);
void			map_dimensions(t_game *game);
void			draw_walls(t_data *data, int x);
void			coloring(t_data *data, t_config *config);
void			free_maps(t_data *data);
void			load_all_textures(t_game *game);
int				load_texture(t_data *data, t_tex *tex, char *path);
void			draw_textured_wall(t_data *data, int x);
int				check_tile(t_data *data, int tile_x, int tile_y);
#endif
