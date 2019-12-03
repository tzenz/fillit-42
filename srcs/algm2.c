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
	buf = NULL;
	return (field);
}

int			plus(t_tet *tmp)
{
	while (tmp != NULL)
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
	while (content[i])
	{
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

void			fc1(int next, char **field, t_tet *head, t_tet *tmp)
{
	int 		count;

	count = 0;
	if (tmp == NULL)
	{
		tmp = head;
		while (tmp->next != NULL)
		{
			if (tmp->count)
				count++;
			tmp = tmp->next;
		}
		printf("next - %d  count - %d  tmp->numb - %zu\n", next, count, tmp->numb);
		if (++count == tmp->numb)
			return;
		else
			fc1(next, field, head, (tmp = head));
	}
	else if (next == tmp->x && !tmp->count)
	{
		tmp->count++;
		fc1(ft_write(field, tmp->x, tmp->y, tmp->content), field, head, tmp->next);
	}
	else
		fc1(next, field, head, tmp->next);
}

void			algm(t_tet *head)
{
	char		**field;
	int 		next;

	next = 1;
	field = NULL;
	field = addfield(field, 5);
	fc1(next, field, head, head);
	ft_putsstr(field);
}

/*int			fc1(int next, char **field, t_tet *head, t_tet *tmp)
{
	if (next == tmp->x)
	{
		tmp->count++;
		fc1(ft_write(field, tmp->x, tmp->y, tmp->content), field, head, tmp->next);
	}
	else if (tmp == NULL)
		return (0);
	else
		fc1(tmp->x, field, head, tmp);
	return (0);
}*/