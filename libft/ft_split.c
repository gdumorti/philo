/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdumorti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:21:48 by gdumorti          #+#    #+#             */
/*   Updated: 2023/05/02 17:35:10 by gdumorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_word(char const *s, char c)
{
	size_t	nb_word;

	nb_word = 0;
	while (s && *s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			while (*s && *s != c)
				s++;
			nb_word++;
		}
	}
	return (nb_word);
}

static char	*ft_getword(char const *s, unsigned int *start, char c)
{
	size_t	len;

	while (s[*start] && s[*start] == c)
		(*start)++;
	len = 0;
	while (s[*start] && s[*start] != c)
	{
		(*start)++;
		len++;
	}
	return (ft_substr(s, *start - len, len));
}

static void	ft_free(char **s, size_t nb_word_tab)
{
	size_t	i;

	i = 0;
	while (i < nb_word_tab)
		free(s[i++]);
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char			**split;
	size_t			nb_word;
	size_t			i;
	unsigned int	start;

	if (!s)
		return (0);
	nb_word = ft_nb_word(s, c);
	split = ft_calloc(nb_word + 1, sizeof(char *));
	if (!split)
		return (NULL);
	i = -1;
	start = 0;
	while (++i < nb_word)
	{
		split[i] = ft_getword(s, &start, c);
		if (!split[i])
		{
			ft_free(split, i);
			return (NULL);
		}
	}
	split[i] = NULL;
	return (split);
}
