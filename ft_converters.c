/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:40:16 by mterkhoy          #+#    #+#             */
/*   Updated: 2020/12/11 20:41:56 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_convert_char(t_pf *pf, t_arg arg, va_list ap)
{
	char	*str;
	char	*tmp;
	int		len;

	len = 1;
	if (arg.width > 1)
		len = arg.width;
	tmp = va_arg(ap, char *);
	if (!(str = malloc(len * sizeof(char))))
		return (0);
	ft_memset(str, ' ', len);
	if (arg.flag.minus)
		str[0] = (unsigned char)tmp;
	else
		str[len - 1] = (unsigned char)tmp;
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

int		ft_convert_int(t_pf *pf, t_arg arg, va_list ap)
{
	char	*str;
	int		nb;

	nb = va_arg(ap, int);
	if (nb == 0 && arg.precision == 0)
	{
		arg.flag.zero = 0;
		if (!(str = ft_strdup("")))
			return (0);
	}
	else if (!(str = ft_itoa(nb)))
		return (0);
	if (arg.precision > 0)
		if (!(str = ft_add_precision(str, arg)))
			return (0);
	if (!(str = ft_add_width(str, arg)))
		return (0);
	ft_minus_correction(str);
	if (!ft_pf_lstadd_back(&pf->lst, ft_pf_lstnew(str, ft_strlen(str))))
		return (0);
	return (1);
}

int		ft_convert_unsigned(t_pf *pf, t_arg arg, va_list ap)
{
	char			*str;
	unsigned int	nb;

	nb = (unsigned int)va_arg(ap, int);
	if (nb == 0 && arg.precision == 0)
	{
		if (!(str = ft_strdup("")))
			return (0);
	}
	else if (arg.type == 'x' || arg.type == 'X')
	{
		if (!(str = ft_itoa_base(nb, 16)))
			return (0);
		if (arg.type == 'X')
			ft_strtoupper(str);
	}
	else
	{
		if (!(str = ft_itoa_base(nb, 10)))
			return (0);
	}
	if (arg.precision > 0)
		if (!(str = ft_add_precision(str, arg)))
			return (0);
	if (!(str = ft_add_width(str, arg)))
		return (0);
	if (!ft_pf_lstadd_back(&pf->lst, ft_pf_lstnew(str, ft_strlen(str))))
		return (0);
	return (1);
}

int		ft_convert_pointer(t_pf *pf, t_arg arg, va_list ap)
{
	char			*str;
	char			*str2;
	unsigned long	pointer;

	pointer = (unsigned long)va_arg(ap, void *);
	if (pointer == 0)
	{
		str = (arg.precision == 0) ? ft_strdup("0x") : ft_strdup("0x0");
		if (!str)
			return (0);
	}
	else
	{
		if (!(str = ft_strdup("0x")))
			return (0);
		str2 = ft_itoa_base(pointer, 16);
		str = ft_fstrjoin(str, str2);
	}
	if (!(str = ft_add_width(str, arg)))
		return (0);
	if (!ft_pf_lstadd_back(&pf->lst, ft_pf_lstnew(str, ft_strlen(str))))
		return (0);
	return (1);
}
