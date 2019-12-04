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

char        **addfield(char **before, int numb)
{
	char 	**field;
	char	buf[numb * (numb + 1)];
	int		ins;
	int		i;

	i = 0;
	ins = numb;
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
	buf[i] = '\0';
	field = ft_strsplitc(buf, '\n');
	if (before)
		field = ft_cpyptrn(field, before);
	return (field);
}

int				ft_fieldlong(t_tet *head, int i)
{
	int 		count;

	count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	count *= 4;
	if (ft_sqrt(count) * ft_sqrt(count) < count)
		return (ft_sqrt(count) + 1 + i);
	else
		return (ft_sqrt(count) + i);
}

int				maxnumb(t_tet *head)
{
	int 		count;

	count = 0;
	while (head != NULL)
	{
		if (!head->count)
			count++;
		head = head->next;
	}
	return (count);
}

int				fc1(char **field, int next, t_tet *head, t_tet *tmp)
{
	int			count;
	int 		random;

	random = 4;
	count = maxnumb(head);
	while (tmp != NULL)
	{
		while (tmp != NULL)
		{
			if (tmp->x == next && !tmp->count)
				break;

			tmp = tmp->next;
		}
		if (!tmp)
		{
			random = (random - 1 < 1) ? 4 : random - 1;
			next = random;
			tmp = head;
		}
		printf("count - %d  numb - %zu  next - %d  tmp->count - %zu\n", count, tmp->numb, next, tmp->count);
		if (tmp->x == next && !tmp->count)
		{
			if ((next = ft_write(field, tmp->x, tmp->content)) > 0)
			{
				count--;
				tmp->count++;
			}
			else
				return (-1);
		}
		tmp = head;
		if (!count)
			return (0);
	}
	return (0);
}

void			algm(t_tet *head)
{
	char		**field;
	int 		count;

	count = 1;
	field = NULL;
//	field = addfield(field, 6);
//	fc1(field, 1, head, head);
	field = addfield(field, ft_fieldlong(head, 0));
	while (fc1(field, 1, head, head) < 0)
	{
		printf(" -- \n");
		field = addfield(field, ft_fieldlong(head, count++));
	}
	ft_putsstr(field);
}


 /*
  *void			fc1(int next, char **field, t_tet *head, t_tet *tmp)
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
		fc1(ft_write(field, tmp->x, tmp->y, tmp->content), field, head, tmp->next)'

	}
	else
		fc1(next, field, head, tmp->next);
}
 */