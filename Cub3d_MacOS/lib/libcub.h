/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:08:08 by thoberth          #+#    #+#             */
/*   Updated: 2021/01/18 15:42:30 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCUB_H
# define LIBCUB_H
# define BUF_SIZE 75
# define ERROR_MALLOC 4
# define ERROR_FILE_MANIP 1
# define WRONG_FILECUB 2
# define WRONG_NUMBER_ARGUMENTS 3
# define SAVE 5
# define KEY_ESC 53
# define KEY_TURN_LEFT 123
# define KEY_TURN_RIGHT 124
# define KEY_GO_AHEAD 13
# define KEY_GO_BACK 1
# define KEY_GO_LEFT 0
# define KEY_GO_RIGHT 2
# define M_PI 3.141592
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "get_next_line.h"
# include "bitmap.h"

/*
** Structure contenant les variables
*/

typedef struct	s_all
{
	struct		s_verif
	{
		int		verif_reso;
		int		verif_f;
		int		verif_c;
		int		last_verif;
		int		save;
		int		problem;
	}			verif;
/*
** Structure contenant les var de verif
*/
	struct		s_map
	{
		char	**map;
		char	*no;
		char	*so;
		char	*we;
		char	*ea;
		char	*sprite;
		int		reso[2];
		int		reso_2d[2];
		int		f[3];
		int		c[3];
		int		t_map_x;
		int		t_map_y;
		int		size_line2d;
		int		size_line;
		float	tcub;
	}			map;
/*
** Structure contenant les infos de la map
*/
	struct		s_plr
	{
		int		posplrx;
		int		posplry;
		float	vposx;
		float	vposy;
		int		angle_plr;
	}			plr;
/*
** Structure contenant les infos du joueur
*/
	struct		s_data
	{
		int		is_2d;
		void	*mlx_ptr;
		void	*win_ptr;
		void	*img_ptr;
		char	*data_addr;
		void	*img_ptr_minimap;
		char	*data_addr_minimap;
	}			data;
/*
** Structure contenant le data de la minilibx
*/
	struct		s_ray
	{
		int		fov;
		float	*dist;
		float	ang_next_ray;
		float	actual_ang;
		int		dist_to_pp;
		float	**is_sprite;
		int		tmp_sprite[2];
		float	delta[2];
		int		nbr_sprite;
		int		*sort;
	}			ray;
/*
** Structure contenant les variables du raycaster
*/
	struct		s_dis
	{
		int		color_wall;
		int		t_wall;
		int		t_fc;
	}			dis;
/*
** <-Structure contenant les variables de display
*/

/*
** Structure contenant les variables des texture ->
*/
	struct		s_tex
	{
		void	*imgno;
		char	*texno;
		int		t_no[2];
		void	*imgso;
		char	*texso;
		int		t_so[2];
		void	*imgea;
		char	*texea;
		int		t_ea[2];
		void	*imgwe;
		char	*texwe;
		int		t_we[2];
		void	*imgs;
		char	*texs;
		int		t_s[2];
		int		sizeline;
		int		bpp;
		int		endian;
		int		**wall_tex;
		float	line;
		int		s_e_th[2];
		int		s_e_pr[2];
		int		debut_h;
	}			tex;
}				t_list_map;

/*
** Fonctions Classiques
*/
void			ft_putchar(char c);
void			ft_putstr(char	*str);
void			ft_putnbr(int nb);
int				ft_atoi(const char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(char *s1);
int				ft_strcmp(const char *s1, const char *s2);
/*
** Fonctions de test map, et recup, d'information
*/
void			ft_detect_map(t_list_map *map, char *line);
void			ft_init_map(t_list_map *map, char *cub);
void			ft_init_map2(t_list_map *map);
int				ft_test_info_map(t_list_map *map);
int				ft_test_map(t_list_map *map);
char			**ft_line_to_array_of_str(char	**map, char *line, int c);
int				ft_charmap_isgood(char c);
int				ft_no_acc_space(char **map, int t_map);
int				ft_test_if_nsew(t_list_map *map);
int				ft_space_found(char **map, int i, int t, int t_map);
int				ft_circled_of_1_horizontal(char **map, int t_map);
int				ft_circled_of_1_vertical(char **map, int t_map);
char			**ft_resize_map(t_list_map *map, int t_map);
int				ft_map_is_split(char **map, int t_map);
void			ft_verif_reso(t_list_map *map);
/*
** Fonctions pour le raycasting
*/
void			ft_player(t_list_map *map);
void			ft_raycasting(t_list_map *map);
void			ft_start_all(t_list_map *map, char *str);
float			ft_dist_wall(t_list_map *map, int i);
float			ft_mod_angle2(float angle);
int				ft_iswall(t_list_map *map, int t, int i, int v);
void			ft_display_cub(t_list_map *map);
float			ft_dist_wall2h(t_list_map *map, float ax, float ay, int i);
float			ft_dist_wall2v(t_list_map *map, float ax, float ay, int i);
float			ft_dist_wall3(t_list_map *map, float nx, float ny);
void			ft_recup_data_tex(t_list_map *map);
void			ft_display(t_list_map *map);
int				ft_display_walltex(t_list_map *map, int i, int *tab, char *str);
int				ft_texture(t_list_map *map, int a, int i);
void			ft_init_var(t_list_map *map);
void			ft_calcul_deltah(t_list_map *map);
void			ft_calcul_deltav(t_list_map *map);
void			ft_sprite(t_list_map *map, int i);
void			ft_sort_sprite(t_list_map *map);
void			ft_display_sprite(t_list_map *map);
void			ft_display_sprite2(t_list_map *map, int j);
/*
** Fonctions cas d'erreurs, manip de fichiers, et les events
*/
void			ft_return_error(t_list_map *map, int define);
void			ft_save(t_list_map *map);
int				ft_open(t_list_map *map, int fd);
void			ft_close(t_list_map *map, int fd);
int				do_nothing(void);
int				deal_key(int key, t_list_map *map);
int				close_window(t_list_map *map);
void			ft_mod_pos2(int key, t_list_map *map, int vitesse);
int				ft_detect_wall(t_list_map *map, int x, int y);

#endif
