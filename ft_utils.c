/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:27:55 by mterkhoy          #+#    #+#             */
/*   Updated: 2020/12/11 17:26:01 by mterkhoy         ###   ########.fr       */
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