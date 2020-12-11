/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 11:28:25 by mterkhoy          #+#    #+#             */
/*   Updated: 2020/11/18 14:52:09 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int n)
{
	int i;

	if (!n)
		return (1);
	i = 0;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*tab;
	unsigned int	nbr;

	len = ft_intlen(n);
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
		tab[len--] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n < 0)
		tab[len] = '-';
	return (tab);
}
