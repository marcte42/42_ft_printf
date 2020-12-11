/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converters1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:40:16 by mterkhoy          #+#    #+#             */
/*   Updated: 2020/12/11 21:44:28 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_convert_char(t_pf *pf, t_arg arg, va_list ap)
{
	char			*str;
	int				len;
	unsigned char	c;

	if (arg.type == '%')
		c = '%';
	else
		c = (unsigned char)va_arg(ap, char *);
	len = 1;
	if (arg.width > 1)
		len = arg.width;
	if (!(str = malloc(len * sizeof(char))))
		return (0);
	if (arg.flag.zero && (arg.precision < 0 || arg.precision > len))
		ft_memset(str, '0', len);
	else
		ft_memset(str, ' ', len);
	if (arg.flag.minus)
		str[0] = c;
	else
		str[len - 1] = c;
	if (!ft_pf_lstadd_back(&pf->lst, ft_pf_lstnew(str, len)))
		return (0);
	return (1);
}

int		ft_convert_string(t_pf *pf, t_arg arg, va_list ap)
{
	char *str;
	char *tmp;

	tmp = va_arg(ap, char *);
	if (!tmp)
	{
		if (!(str = ft_strndup("(null)", arg.precision)))
			return (0);
	}
	else if (!(str = ft_strndup(tmp, arg.precision)))
		return (0);
	if (!(str = ft_add_width(str, arg)))
		return (0);
	if (!ft_pf_lstadd_back(&pf->lst, ft_pf_lstnew(str, ft_strlen(str))))
		return (0);
	return (1);
}
