/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:12:02 by dbreton           #+#    #+#             */
/*   Updated: 2015/04/15 08:47:45 by dbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

static char			**resize(char **tab, int j)
{
	char			**newtab;

	newtab = (char **)malloc(sizeof(char *) * j + 1);
	if (newtab)
	{
		newtab[j] = NULL;
		while (j > 0)
		{
			newtab[j - 1] = tab[j - 1];
			j--;
		}
		if (tab)
			free(tab);
	}
	return (newtab);
}

char				**ft_strsplit(char const *s, char c)
{
	int				i;
	int				j;
	int				begin;
	char			**tab;

	i = 0;
	j = 0;
	tab = NULL;
	if (s)
	{
		while (s[i] != '\0')
		{
			while (s[i] == c && s[i] != '\0')
				i++;
			begin = i;
			while (s[i] != c && s[i] != '\0' && s[i] != '\n')
				i++;
			tab = resize(tab, j);
			tab[j] = ft_strsub(s, begin, i - begin);
			j++;
		}
		tab = resize(tab, j);
		tab[j] = NULL;
	}
	return (tab);
}
