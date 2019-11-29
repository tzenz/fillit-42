/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:58:29 by tzenz             #+#    #+#             */
/*   Updated: 2019/11/22 14:58:30 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include <stdio.h>

void			ft_write(char **field, int x, int y, t_tet *tmp)
{
	int i;
	int j;
	int n;
	int m;

	i = 0;
	j = 0;
	n = 0;
	m = 0;
	if (ft_cm(tmp->content, x, y, field))
	{
//		printf("~~");
	}
}

int				ft_cm(char **content, int x, int y, char **field)
{
	int 		count;
	int 		rescount;
	int 		i;
	int 		j;
	int 		n;
	int 		m;

	i = 0;
	j = 0;
	n = 0;
	m = 0;
	rescount = 0;
	while (field[m][n])
	{
		while ((content[i][j] != field[m][n] && field[m][n] == '.' && content[i][j]) || (content[i][j] != field[m][n] && content[i][j] == '.'))
		{
			count = m;
			i = 0;
			j++;
			n++;
			if (j == x)
			{
				ft_humhum(field, content, n - j, m);
				return (1);
			}
		}
		j = 0;
		if (field[m][n] == '\n')
		{
			n = 0;
			m++;
		}
		else
			n++;
	}
	return (0);
}

void			ft_humhum(char **field, char **content, int n, int m)
{
	int 		count;
	int 		i;
	int 		j;
//	int 		m;

	i = 0;
	j = 0;
//	m = 0;
	count = n;
//	ft_putsstr(field);
//	ft_putsstr(content);
//	printf("+++++++ n - %d, m - %d\n", n, m);
	while (content[i] != NULL)
	{
		if (content[i][j] != '\n')
		{
			field[m][n++] = content[i][j++];
		}
		else if (content[i][j] == '.')
			j++;
		else
		{
			m++;
			i++;
			n = count;
			j = 0;
		}
	}
}

int				fc1(char **field, t_tet *head)
{
	t_tet		*superhead;
	t_tet		*tmp;
	int 		m;
	int 		n;

	m = 0;
	n = 5;
	tmp = head;
	superhead = head;
//	ft_putnbr(ft_strlen(*field));
	while (tmp != NULL)
	{
		ft_write(field, tmp->x, tmp->y, tmp);
		tmp = tmp->next;
	}
	return (-1);
}

void			algm(t_tet *head)
{
	t_tet		*tmp;
	char		**field;
	int 		i;

	field = NULL;
	tmp = head;
	field = addfield(field, 7);
	fc1(field, tmp);
//	while ((fc1(field, tmp)) > 0)
//		addfield(field, plus(tmp) + 1);
	ft_putsstr(field);
}