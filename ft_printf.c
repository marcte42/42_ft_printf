/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:17:14 by mterkhoy          #+#    #+#             */
/*   Updated: 2020/12/11 21:31:31 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_convert_arg(t_pf *pf, t_arg arg, va_list ap)
{
	if (arg.type == 's')
		return (ft_convert_string(pf, arg, ap));
	if (arg.type == 'c' || arg.type == '%')
		return (ft_convert_char(pf, arg, ap));
	if (arg.type == 'd' || arg.type == 'i')
		return (ft_convert_int(pf, arg, ap));
	if (arg.type == 'u')
		return (ft_convert_unsigned(pf, arg, ap));
	if (arg.type == 'x' || arg.type == 'X')
		return (ft_convert_hex(pf, arg, ap));
	if (arg.type == 'p')
		return (ft_convert_pointer(pf, arg, ap));
	return (1);
}

int		ft_parse_arg(t_pf *pf, const char *format, va_list ap, size_t *i)
{
	t_arg	arg;

	arg.flag = ft_get_flag(format, i);
	arg.width = ft_get_width(format, ap, i);
	if (arg.width < 0)
	{
		arg.flag.minus = 1;
		arg.flag.zero = 0;
		arg.width = -arg.width;
	}
	arg.precision = ft_get_precision(format, ap, i);
	arg.length = ft_get_length(format, i);
	arg.type = ft_get_type(format, i);
	if (!ft_convert_arg(pf, arg, ap))
		return (0);
	return (1);
}

int		ft_process(t_pf *pf, const char *format, va_list ap)
{
	size_t	i;
	char	*str;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!(ft_parse_arg(pf, format, ap, &i)))
				return (0);
		}
		else
		{
			str = ft_strduptoperc(&format[i], &i);
			if (!ft_pf_lstadd_back(&pf->lst, ft_pf_lstnew(str, ft_strlen(str))))
				return (0);
		}
	}
	return (1);
}

int		ft_display(t_pf pf)
{
	int		size;

	size = 0;
	while (pf.lst)
	{
		write(pf.fd, pf.lst->content, pf.lst->size);
		size += pf.lst->size;
		pf.lst = pf.lst->next;
	}
	return (size);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_pf	pf;
	int		size;

	va_start(ap, format);
	ft_init_pf(&pf, 1);
	if (!(ft_process(&pf, format, ap)))
	{
		ft_pf_lstclear(&pf.lst, free);
		return (-1);
	}
	va_end(ap);
	size = ft_display(pf);
	ft_pf_lstclear(&pf.lst, free);
	return (size);
}
