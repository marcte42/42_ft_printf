/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:00:32 by mterkhoy          #+#    #+#             */
/*   Updated: 2020/12/11 19:38:52 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		ft_get_flag(const char *format, size_t *i)
{
	t_flag flags;

	ft_bzero(&flags, sizeof(t_flag));
	while (ft_isflag(format[*i]))
	{
		if (format[*i] == '-')
		{
			flags.minus = 1;
			flags.zero = 0;
		}
		if (format[*i] == '+')
		{
			flags.plus = 1;
			flags.space = 0;
		}
		if (format[*i] == '0' && !(flags.minus))
			flags.zero = 1;
		if (format[*i] == ' ' && !(flags.plus))
			flags.space = 1;
		if (format[*i] == '#')
			flags.hash = 1;
		(*i)++;
	}
	return (flags);
}

int			ft_get_width(const char *format, va_list ap, size_t *i)
{
	int width;

	width = 0;
	if (format[*i] == '*')
	{
		(*i)++;
		return (va_arg(ap, int));
	}
	width = ft_atoi(&format[*i]);
	while (ft_isdigit(format[*i]))
		(*i)++;
	return (width);
}

int			ft_get_precision(const char *format, va_list ap, size_t *i)
{
	int precision;

	if (format[*i] == '.')
	{
		precision = 0;
		(*i)++;
		if (format[*i] == '*')
		{
			(*i)++;
			return (va_arg(ap, int));
		}
		precision = atoi(&format[*i]);
		while (ft_isdigit(format[*i]))
			(*i)++;
		return (precision);
	}
	return (-1);
}

int			ft_get_length(const char *format, size_t *i)
{
	if (format[*i] == 'l' && format[*i + 1] == 'l')
	{
		(*i) += 2;
		return (1);
	}
	else if (format[*i] == 'l')
	{
		(*i)++;
		return (2);
	}
	else if (format[*i] == 'h' && format[*i + 1] == 'h')
	{
		(*i) += 2;
		return (3);
	}
	else if (format[*i] == 'h')
	{
		(*i)++;
		return (4);
	}
	return (0);
}

char		ft_get_type(const char *format, size_t *i)
{
	if (ft_istype(format[*i]))
	{
		return (format[(*i)++]);
	}
	return (0);
}
