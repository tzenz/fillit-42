/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:37:14 by tzenz             #+#    #+#             */
/*   Updated: 2019/10/30 14:37:16 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include <stdio.h>

tetrimino	*maintet(char *s)
{
	tetrimino	*head;
	tetrimino	*tmp;
	int			i;
	int 		count;

	i = 0;
	count = 0;
	tmp = head;
//	while (s[i])
//	{
		if (!head)
			tmp = ft_newtet(ft_add(&s[i]), count);
		else
			tmp->next = ft_newtet(ft_add(&s[i]), count);
		ft_putstr(tmp->content);
		tmp = tmp->next;
		count++;
		i += 21;
//	}
	return (head);
}

tetrimino   *ft_newtet(char *s, int	numb)
{
	tetrimino   *tmp;

	tmp = (tetrimino*)ft_memalloc(sizeof(tetrimino));
	tmp->numb = numb;
	tmp->content = s;
	tmp->next = NULL;
	return (tmp);

}

char   *ft_add(char *s)
{
	char 	*buf;
	int 	sim;
	int     i;
	int 	j;

	buf = ft_strnew(10);
	j = 0;
	i = 0;
	sim = 0;
	while (s[i])
	{
		while (s[i] && s[i] != '\n')
		{
			if (s[i] != '.')
				sim = s[i];
			i++;
		}
		if (sim)
		{
			i -= 4;
			while (s[i] && s[i] != '\n')
			{
				if (s[i] == sim || s[i + 5] == sim || s[i + 10] == sim)
					buf[j++] = s[i];
				else if (s[i - 5] == sim || s[i - 10] == sim)
					buf[j++] = s[i];
				i++;
			}
			buf[j++] = '\n';
		}
		i++;
	}
	return (buf);
}

/*void	ft_add2(char **s, **buf, int *i, int sim)
{
	while (s[i] && s[i] != '\n')
	{
		if (s[i] == sim || s[i + 5] == sim || s[i + 10] == sim)
			buf[j++] = s[i];
		else if (s[i - 5] == sim || s[i - 10] == sim)
			buf[j++] = s[i];
		i++;
	}
	buf[j++] = '\n';
}*/
