/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:05:14 by arkim             #+#    #+#             */
/*   Updated: 2019/10/20 01:52:39 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>

# define FT_ABS(A)			((A) < 0) ? (-A) : (A)
# define FT_MAX(A, B)		((A) >= (B)) ? (A) : (B)
# define FT_MIN(A, B)		((A) <= (B)) ? (A) : (B)
# define STR_NULL			"(null)"

/*
**						specifier: flags
*/

# define FLAGS			"-+ 0#*$'"
# define F_MINUS		(1 << 0)
# define F_PLUS			(1 << 1)
# define F_SPACE		(1 << 2)
# define F_ZERO			(1 << 3)
# define F_HASH			(1 << 4)
# define F_ASTERISK		(1 << 5)
# define F_DOLLAR		(1 << 6)
# define F_APOSTROPHE	(1 << 7)

/*
**						specifier: length
*/

# define LEN_MODIF		"hljtzL"
# define F_H			(1 << 11)
# define F_L			(1 << 12)
# define F_J			(1 << 13)
# define F_T			(1 << 14)
# define F_Z			(1 << 15)
# define F_UL			(1 << 16)
# define F_HH			(1 << 17)
# define F_LL			(1 << 18)

/*
**						bonus
*/

# define F_WIDTH		(1 << 8)
# define F_PREC			(1 << 9)
# define F_PREC_STAR	(1 << 10)

/*
**						CONV specifiers
*/

# define CONV			"diouxfegacspnbrk%"
# define CONV2			"DIOUXFEGACSPNBRK"
# define C_UPCASE		(1 << 0)
# define C_D			(1 << 1)
# define C_I			(1 << 2)
# define C_O			(1 << 3)
# define C_U			(1 << 4)
# define C_X			(1 << 5)
# define C_F			(1 << 6)
# define C_E			(1 << 7)
# define C_G			(1 << 8)
# define C_A			(1 << 9)
# define C_C			(1 << 10)
# define C_S			(1 << 11)
# define C_P			(1 << 12)
# define C_N			(1 << 13)
# define C_B			(1 << 14)
# define C_R			(1 << 15)
# define C_K			(1 << 16)
# define C_PER			(1 << 17)
# define C_INT			(C_D | C_I)
# define C_UINT			(C_O | C_U | C_X | C_B)

/*
**		fmt : format string		|	prec_w  : precision width
**		f   : flag				|	cur_len : current length
**		c   : conversiions		|	len		: cumulative length
**		w   : width				|	base    : base number
*/

typedef struct		s_printf
{
	char			*fmt;
	int				f;
	int				c;
	int				w;
	int				prec_w;
	int				cur_len;
	int				len;
	int				base;
	int				fd;
	va_list			ap;
}					t_pf;

/*
**					ft_printf.c
*/

int					ft_printf(const char *format, ...);
void				reset_pf(t_pf *p);

/*
**					parsing.c
*/

void				parse_flags(t_pf *p);
void				parse_width(t_pf *p);
void				parse_precision(t_pf *p);
void				parse_length_modifier(t_pf *p);
void				parse_conversion(t_pf *p);

/*
**					parsing2.c
*/

void				parsing(t_pf *p);
void				pf_num_base(t_pf *p);
void				ignoring(t_pf *p);
int					pf_nbrlen(int64_t n, t_pf *p);
int					pf_dbllen(long double n, t_pf *p);

/*
**					sorting.c
*/

void				sorting(t_pf *p);
void				sort_int(t_pf *p);
void				sort_uint(t_pf *p);
void				sort_dbl(t_pf *p);

/*
**					numbers.c
*/

void				pf_numbers(t_pf *p, int64_t n);
void				pf_doubles(t_pf *p, long double n);

/*
**					put_util.c
*/

void				pf_put_int(uint64_t n, t_pf *p);
void				pf_put_dbl(long double n, t_pf *p);
void				pf_put_scinum(long double n, t_pf *p);

/*
**					put_util2.c
*/

void				pf_put_char(t_pf *p);
void				pf_put_str(t_pf *p);
void				pf_put_ptraddr(t_pf *p);
void				pf_put_color(t_pf *p);

#endif
