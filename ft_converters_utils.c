/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converters_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:40:16 by mterkhoy          #+#    #+#             */
/*   Updated: 2020/12/11 19:48:20 by mterkhoy         ###   ########.fr       */
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
	size_t	len;

	len = ft_strlen(s);
	if (arg.width <= len)
		return (s);
	if (!(width = calloc((arg.width - len + 1), sizeof(char))))
		return (NULL);
	if (arg.flag.zero && (arg.precision > len))
		ft_memset(width, '0', arg.width - len);
	else
		ft_memset(width, ' ', arg.width - len);
	if (arg.flag.minus)
		return (ft_fstrjoin(s, width));
	return (ft_fstrjoin(width, s));
}

int		ft_intlen_base(unsigned long n, size_t base)
{
	unsigned int i;

	if (!n)
		return (1);
	i = 0;
	while (n)
	{
		i++;
		n /= base;
	}
	return (i);
}

char	*ft_itoa_base(unsigned long n, size_t base)
{
	int				len;
	char			*tab;
	unsigned long	nbr;
	char			*hex;

	hex = "0123456789abcdef";
	len = ft_intlen_base(n, base);
	nbr = n;
	if (n < 0)
	{
		len++;
		nbr = -n;
	}
	if (!(tab = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	tab[0] = '0';
	tab[len--] = 0;
	while (nbr)
	{
		tab[len--] = hex[nbr % base];
		nbr /= base;
	}
	if (n < 0)
		tab[len] = '-';
	return (tab);
}

char	*ft_fstrjoin(char *s1, char *s2)
{
	size_t	len;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	str[0] = '\0';
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	free(s1);
	free(s2);
	return (str);
}
