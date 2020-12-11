/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:40:16 by mterkhoy          #+#    #+#             */
/*   Updated: 2020/12/11 20:36:17 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
