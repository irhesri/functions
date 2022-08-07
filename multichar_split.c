/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multichar_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <irhesri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 21:07:46 by irhesri           #+#    #+#             */
/*   Updated: 2022/08/07 21:07:47 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_struct
{
	int				data;
	struct s_struct	*next;
}	t_struct;

static short	my_error(char **str, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free (str[i++]);
	free (str);
	write(1, "allocation error\n", 17);
	exit (1);
}

static void	add_back(t_struct **lst, int n)
{
	static t_struct	*last;
	t_struct		*new;

	new = (t_struct *) malloc(sizeof(t_struct));
	new->data = n;
	new->next = NULL;
	if (!*lst)
	{
		*lst = new;
		last = new;
		return ;
	}
	last->next = new;
	last = new;
}

short	is_splitter(char *splitters, char c)
{
	while (*splitters)
	{
		if (c == *splitters)
			return (1);
		splitters++;
	}
	return (0);
}

static t_struct	*get_size(char *str, char *splitters)
{
	int			word_size;
	t_struct	*size;

	size = NULL;
	add_back(&size, 0);
	while (*str)
	{
		word_size = 0;
		while (*str && is_splitter(splitters, *str))
			str++;
		while (*str && !is_splitter(splitters, *str))
		{
			str++;
			word_size++;
		}
		if (word_size)
		{
			add_back(&size, word_size);
			size->data++;
		}
	}
	return (size);
}

static	char	**fill(t_struct *size, char *str, char *splitter)
{
	char	**words;
	int		i;
	int		j;

	words = (char **) malloc(sizeof(char *) * (size->data + 1));
	!words && my_error(words, 0);
	size = size->next;
	i = -1;
	while (size)
	{
		words[++i] = malloc((size->data + 1));
		!words[i] && my_error(words, i);
		while (*str && is_splitter(splitter, *str))
			str++;
		j = -1;
		while (++j < size->data)
			words[i][j] = *str++;
		words[i][j] = '\0';
		size = size->next;
	}
	words[++i] = NULL;
	return (words);
}

char	**multichar_split(char *str, char *splitters/*, int *len*/)
{
	char		**words;
	t_struct	*size;
	t_struct	*tmp;

	if (!str || !splitters)
		return (NULL);
	while (*str && is_splitter(splitters, *str))
		str++;
	size = get_size(str, splitters);
	words = fill(size, str, splitters);
	/*if (len)
		(*len) = size->data;*/
	while (size)
	{
		tmp = size->next;
		free (size);
		size = tmp;
	}
	return (words);
}
