/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algm2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:21:06 by tzenz             #+#    #+#             */
/*   Updated: 2019/11/26 15:21:07 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include <stdio.h>

char        **addfield(char **beforefield, int numb)
{
	char 	**field;
	char	*buf;
	int		ins;
	int		i;
	int 	j;

	i = 0;
	ins = numb;
	buf = ft_strnew(numb * (numb + 1));
	while (i < numb * (numb + 1))
	{
		if (i == ins)
		{
			buf[i] = '\n';
			ins += numb + 1;
		}
		else
			buf[i] = '.';
		i++;
	}
/*	if (beforefield)
	{
		i = 0;
		j = 0;

		while (beforefield[i])
		{
			if (beforefield[j] != '\n')
				field[i++] = beforefield[j++];
			else
				j++;
		}
	}*/
	field = ft_strsplitc(buf, '\n');
	free(buf);
	return (field);
}

int			plus(t_tet *tmp)
{
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->numb);
}

void			ft_humhum(char **field, char **content, int m, int n)
{
	int 		count;
	int 		i;
	int 		j;

	i = 0;
	j = 0;
	count = n;
//	printf("HUMHUM m - %d  n - %d\n", m , n);
//	ft_putsstr(content);
	while (content[i])
	{
//		ft_putsstr(field);
		if (content[i][j] != '.' && content[i][j])
			field[m][n++] = content[i][j++];
		else if (content[i][j++] == '.')
			n++;
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
	t_tet		*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_write(field, tmp->x, tmp->y, tmp->content);
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
	field = addfield(field, 6);
	fc1(field, tmp);
//	while ((fc1(field, tmp)) > 0)
//		addfield(field, plus(tmp) + 1);
	ft_putsstr(field);
}