/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:08:08 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/22 18:09:04 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCUB_H
# define LIBCUB_H
# define BUF_SIZE 5
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include "get_next_line.h"

/*
** Structure contenant les variables
*/
typedef struct	s_all
{
	/*
	** Structure contenant les var de verif
	*/
	struct		s_verif
	{
		int		verif_reso; //0 si reso non defini un si def
		int		verif_f; //0 si reso non defini un si def
		int		verif_c; //0 si reso non defini un si def
		int		last_verif; //incrementez a chaque info fournie donc si diff de 8 <- Error
	}			verif;
	/*
	** Structure contenant les infos de la map
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
		int		f[3];
		int		c[3];
		int 	t_map_x;
		int		t_map_y;
		int		Vcubx;
		int		Vcuby;
	}			map;
	/*
	** Structure contenant les infos du joueur
	*/
	struct		s_plr
	{
		int		PosplrX; // en case
		int		PosplrY; //en case
		int		Vposx;
		int		Vposy;
		int		Angle_plr;
	}			plr;
	/*
	** Structure contenant le data de la minilibx
	*/
	struct		s_data
	{
		void	*mlx_ptr;
		void	*win_ptr;
		void	*img_ptr;
		char	*data_addr;
		void	*img_ptr_minimap;
		char	*data_addr_minimap;
	}			data;
	/*
	** Structure contenant les variables du raycaster
	*/
	struct		s_ray
	{
		int		FOV;
	}			ray;
	
}				t_list_map;

/*
** Fonctions
*/
int		ft_detect_map(t_list_map *map,char *line);
int 	ft_init_map(t_list_map *map, char *cub);
void	ft_init_map2(t_list_map *map);
int		ft_test_info_map(t_list_map *map);
int     ft_return_error(void);
void	ft_putchar(char c);
void	ft_putstr(char	*str);
void	ft_putnbr(int nb);
int		ft_atoi(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
int     ft_test_map(t_list_map *map);
char	**ft_line_to_array_of_str(char	**map, char *line, int c);
int     ft_charmap_isgood(char c);
int     ft_no_acc_space(char **map, int t_map);
int		ft_test_if_nsew(t_list_map *map);
int     ft_space_found(char **map, int i, int t, int t_map);
int		ft_circled_of_1_horizontal(char **map, int t_map);
int		ft_circled_of_1_vertical(char **map, int t_map);
char	**ft_resize_map(t_list_map *map, int t_map);
int		ft_map_is_split(char **map, int t_map);
void	ft_map2d(t_list_map *map);
void	ft_event(t_list_map *map);
void	ft_raycasting(t_list_map *map);
void	ft_player(t_list_map *map);
void	ft_write2d(t_list_map *map, int i, int t);
void	ft_start_all(t_list_map *map);

#endif