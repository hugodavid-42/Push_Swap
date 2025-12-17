#include "pushswap.h"

static void	ft_freetab(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

static int	ft_countwords(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**ft_mallocandwrite(char const *s, char c, char **res, int i)
{
	int	start;
	int	wordcount;

	wordcount = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			res[wordcount] = ft_substr(s, start, i - start);
			if (!res[wordcount])
			{
				ft_freetab(res, wordcount - 1);
				return (NULL);
			}
			wordcount++;
		}
	}
	res[wordcount] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!res)
		return (NULL);
	return (ft_mallocandwrite(s, c, res, 0));
}
