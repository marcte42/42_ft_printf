/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:17:14 by mterkhoy          #+#    #+#             */
/*   Updated: 2020/12/11 12:25:26 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_pf	pf;

	va_start(ap, format);
	ft_init_pf(&pf, 1);
	if (!(ft_process(&pf, format, ap)))
		return (-1);
	va_end(ap);
	return (ft_display(&pf));
}
