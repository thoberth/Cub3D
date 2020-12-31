/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:30:01 by thoberth          #+#    #+#             */
/*   Updated: 2020/09/18 11:35:12 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
int		ft_test_if_n(char *str);
int		ft_strlen(char *str);
char	*ft_strdup_gnl(char *s1, int a);
char	*ft_strjoin_gnl(char *s1, char *s2, int a);
int		ft_1test(int fd, char **line, char **tmp);
int		ft_2test(char **line, char **tmp, int fd);
void	ft_free_str(char *str);

#endif
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
