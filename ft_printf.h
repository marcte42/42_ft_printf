/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:17:31 by mterkhoy          #+#    #+#             */
/*   Updated: 2020/12/11 20:22:35 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_flag
{
	unsigned char	minus	: 1;
	unsigned char	zero	: 1;
	unsigned char	hash	: 1;
	unsigned char	space	: 1;
	unsigned char	plus	: 1;
}				t_flag;

typedef struct	s_arg
{
	t_flag			flag;
	int				width;
	int				precision;
	int				length	: 3;
	char			type;
}				t_arg;

typedef struct	s_pf_lst
{
	size_t			size;
	void			*content;
	struct s_pf_lst	*next;
}				t_pf_lst;

typedef struct	s_pf
{
	t_pf_lst		*lst;
	int				fd;
}				t_pf;

int				ft_printf(const char *format, ...);
int				ft_process(t_pf *pf, const char *format, va_list ap);
int				ft_parse_arg(t_pf *pf, const char *format,
								va_list ap, size_t *i);

t_flag			ft_get_flag(const char *format, size_t *i);
int				ft_get_width(const char *format, va_list ap, size_t *i);
int				ft_get_precision(const char *format, va_list ap, size_t *i);
int				ft_get_length(const char *format, size_t *i);
char			ft_get_type(const char *format, size_t *i);

int				ft_convert_percent(t_pf *pf, t_arg arg);
int				ft_convert_char(t_pf *pf, t_arg arg, va_list ap);
int				ft_convert_string(t_pf *pf, t_arg arg, va_list ap);
int				ft_convert_int(t_pf *pf, t_arg arg, va_list ap);
int				ft_convert_unsigned(t_pf *pf, t_arg arg, va_list ap);
int				ft_convert_pointer(t_pf *pf, t_arg arg, va_list ap);

void			ft_minus_correction(char *s);
char			*ft_add_precision(char *s, t_arg arg);
char			*ft_add_width(char *s, t_arg arg);
int				ft_intlen_base(unsigned long n, size_t base);
char			*ft_itoa_base(unsigned long n, size_t base);
char			*ft_fstrjoin(char *s1, char *s2);
char			*ft_strduptoperc(const char *s1, size_t *index);

int				ft_init_pf(t_pf *pf, int fd);
int				ft_isflag(char c);
int				ft_istype(char c);

t_pf_lst		*ft_pf_lstnew(void *content, size_t size);
int				ft_pf_lstadd_back(t_pf_lst **alst, t_pf_lst *new);
t_pf_lst		*ft_pf_lstlast(t_pf_lst *lst);
void			ft_pf_lstdelone(t_pf_lst *lst, void (*del)(void *));
void			ft_pf_lstclear(t_pf_lst **lst, void (*del)(void *));

#endif
