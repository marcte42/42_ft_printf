/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:17:31 by mterkhoy          #+#    #+#             */
/*   Updated: 2020/12/11 12:42:01 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_flag
{
	unsigned char minus : 1;
	unsigned char zero : 1;
	unsigned char hash : 1;
	unsigned char space : 1;
	unsigned char plus : 1;
}				t_flag;

typedef struct	s_arg
{
	t_flag		flag;
	int			width;
	int			precision;
	int			length : 3;
	char		type;
}				t_arg;

typedef struct	s_pf
{
	char	*str;
	int		fd;
}				t_pf;


//MAIN
int				ft_printf(const char *format, ...);

// GETTERS
t_flag		ft_get_flag(char *s, va_list ap, size_t *index);
int			ft_get_width(char *s, va_list ap, size_t *index);
int			ft_get_precision(char *s, va_list ap, size_t *index);
int			ft_get_length(char *s, va_list ap, size_t *index);
char		ft_get_type(char *s, va_list ap, size_t *index);

#endif
