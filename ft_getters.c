/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:00:32 by mterkhoy          #+#    #+#             */
/*   Updated: 2020/12/11 12:40:41 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		ft_get_flag(char *s, va_list ap, size_t *index)
{
	t_flag flags;

	while (ft_isflag(s[*index]))
	{
		if (s[*index] == '-')
		{
			flags.minus = 1;
			flags.zero = 0;
		}
		if (s[*index] == '+')
		{
			flags.plus = 1;
			flags.space = 0;
		}
		if (s[*index] == '0' && !(flags.minus))
			flags.zero = 1;
		if (s[*index] == ' ' && !(flags.plus))
			flags.space = 1;
		if (s[*index] == '#')
			flags.hash = 1;
		(*index)++;
	}
	return (flags);
}

int			ft_get_width(char *s, va_list ap, size_t *index)
{
	int width;

	width = 0;
	if (s[*index] == '*')
	{
		(*index)++;
		return (va_arg(ap, int));
	}
	width = ft_atoi(&s[*index]);
	while (ft_isdigit(s[*index]))
		(*index)++;
	return (width);
}

int			ft_get_precision(char *s, va_list ap, size_t *index)
{
	int precision;

	if (s[*index] == '.')
	{
		precision = 0;
		(*index)++;
		if (s[*index] == '*')
		{
			(*index)++;
			return (va_arg(ap, int));
		}
		precision = atoi(&s[*index]);
		while (ft_isdigit(s[*index]))
			(*index)++;
		return (precision);
	}
	return (-1);
}

int			ft_get_length(char *s, va_list ap, size_t *index)
{
	if (s[*index] == 'l' && s[*index + 1] == 'l')
	{
		(*index) += 2;
		return (1);
	}
	else if (s[*index] == 'l')
	{
		(*index)++;
		return (2);
	}
	else if (s[*index] == 'h' && s[*index + 1] == 'h')
	{
		(*index) += 2;
		return (3);
	}
	else if (s[*index] == 'h')
	{
		(*index)++;
		return (4);
	}
	return (0);
}

char		ft_get_type(char *s, va_list ap, size_t *index)
{
	if (ft_istype(s[*index]))
	{
		return (s[(*index)++]);
	}
	return (0);
}
