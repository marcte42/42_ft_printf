/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:40:16 by mterkhoy          #+#    #+#             */
/*   Updated: 2020/12/11 19:30:53 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_init_pf(t_pf *pf, int fd)
{
	pf->lst = NULL;
	pf->fd = fd;
	return (1);
}

int		ft_isflag(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#');
}

int		ft_istype(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || \
			c == 'i' || c == 'u' || c == 'x' || c == 'X' || \
			c == 'n' || c == 'f' || c == 'g' || c == 'e' || c == '%');
}

char	*ft_strduptoperc(const char *s1, size_t *index)
{
	char	*dst;
	size_t	i;
	size_t	len;

	len = 0;
	while (s1[len] && s1[len] != '%')
		len++;
	if (!(dst = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (++i < len)
		dst[i] = s1[i];
	dst[i] = '\0';
	(*index) += len;
	return (dst);
}
