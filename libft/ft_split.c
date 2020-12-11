/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:40:06 by mterkhoy          #+#    #+#             */
/*   Updated: 2020/11/18 15:24:39 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	wc;

	wc = 0;
	i = -1;
	while (s[++i])
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			wc++;
	return (wc);
}

char			*ft_strduptosep(const char *s1, char c, size_t *index)
{
	char	*dst;
	size_t	i;
	size_t	len;

	len = 0;
	while (s1[len] && s1[len] != c)
		len++;
	if (!(dst = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (++i < len)
		dst[i] = s1[i];
	dst[i] = '\0';
	(*index) += len - 1;
	return (dst);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	wc;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	wc = ft_word_count(s, c);
	if (!(tab = (char **)malloc((wc + 1) * sizeof(char *))))
		return (NULL);
	j = 0;
	i = -1;
	while (s[++i])
		if ((i == 0 && s[i] != c) || (i != 0 && s[i] != c && s[i - 1] == c))
			tab[j++] = ft_strduptosep(&s[i], c, &i);
	tab[j] = 0;
	return (tab);
}
