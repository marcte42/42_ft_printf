/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converters_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:40:16 by mterkhoy          #+#    #+#             */
/*   Updated: 2020/12/11 21:41:16 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_minus_correction(char *s)
{
	char *minus_ptr;
	char *zero_ptr;

	minus_ptr = ft_strchr(s, '-');
	zero_ptr = ft_strchr(s, '0');
	if (zero_ptr && minus_ptr && zero_ptr < minus_ptr)
	{
		*zero_ptr = '-';
		*ft_strrchr(s, '-') = '0';
	}
}

char	*ft_add_precision(char *s, t_arg arg)
{
	char	*precision;
	int		len;

	len = ft_strlen(s);
	if (s[0] == '-')
		len--;
	if (arg.precision <= len)
		return (s);
	if (!(precision = calloc((arg.precision - len + 1), sizeof(char))))
		return (NULL);
	ft_memset(precision, '0', arg.precision - len);
	return (ft_fstrjoin(precision, s));
}

char	*ft_add_width(char *s, t_arg arg)
{
	char	*width;
	int		len;

	len = ft_strlen(s);
	if (arg.width <= len)
		return (s);
	if (!(width = calloc((arg.width - len + 1), sizeof(char))))
		return (NULL);
	if (arg.flag.zero && (arg.precision < 0 || arg.precision > len))
		ft_memset(width, '0', arg.width - len);
	else
		ft_memset(width, ' ', arg.width - len);
	if (arg.flag.minus)
		return (ft_fstrjoin(s, width));
	return (ft_fstrjoin(width, s));
}
