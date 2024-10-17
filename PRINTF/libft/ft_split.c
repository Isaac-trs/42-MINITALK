/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istripol <istripol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:27:31 by istripol          #+#    #+#             */
/*   Updated: 2024/01/19 21:41:12 by istripol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static
char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	str = malloc(n + 1);
	if (str)
		ft_strlcpy(str, s, n + 1);
	return (str);
}

static unsigned int	count_words(char const *str, char sep)
{
	unsigned int	cpt;
	unsigned int	i;

	cpt = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		if (!str[i])
			break ;
		cpt++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (cpt);
}

static char	**free_split(char **split, int index)
{
	while (--index >= 0)
		free(split[index]);
	free(split);
	return (NULL);
}

static char	**init_split(const size_t words)
{
	char	**res;

	res = malloc(sizeof(char *) * (words + 1));
	if (res)
		res[words] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	const size_t	words = count_words(s, c);
	int				i;
	int				j;
	int				start;

	res = init_split(words);
	i = 0;
	j = -1;
	start = 0;
	while (res && s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		res[++j] = ft_strndup(s + start, i - start);
		if (!res[j])
			return (free_split(res, j));
	}
	return (res);
}
