/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:26:17 by mterkhoy          #+#    #+#             */
/*   Updated: 2020/12/11 19:26:49 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s1);
	if (n < len)
		len = n;
	if (!(dst = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_strncpy(dst, s1, n);
	return (dst);
}
