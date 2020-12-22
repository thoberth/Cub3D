/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:01:59 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/17 17:03:13 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H

typedef	struct			s_bpm
{
	struct				s_bmpfh
	{
		unsigned short	bf_debug;
		unsigned char	bf_type[2];
		unsigned int	bf_sizefile;
		unsigned short	bf_reserved1;
		unsigned short	bf_reserved2;
		unsigned int	bf_offset;
	}					bmp_fh;
	struct				s_bmpih
	{
		unsigned int	bi_hsize;
		unsigned int	bi_width;
		unsigned int	bi_height;
		unsigned short	bi_planes;
		unsigned short	bi_bpp;
		unsigned int	bi_comp;
		unsigned int	bi_sizeimg;
		unsigned int	bi_ppmx;
		unsigned int	bi_ppmy;
		unsigned int	bi_clrused;
		unsigned int	bi_clrmajor;
	}					bmp_ih;
}						t_bmp;

#endif
