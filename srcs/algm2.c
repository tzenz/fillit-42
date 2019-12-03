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

char        **addfield(int numb)
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
	field = ft_strsplitc(buf, '\n');
	return (field);
}

void			fc1(char **field, t_tet *tmp)
{
	int 		count;

	count = 0;
	while (tmp != NULL)
	{
		if (ft_write(field, tmp->x, tmp->content) < 0)
		{
			printf ("-1");
			return;
		}
		tmp = tmp->next;
	}
}

void			algm(t_tet *head)
{
	char		**field;
	int 		next;

	next = 1;
	field = NULL;
	field = addfield(5);
//	field = addfield(field, ft_fieldlong(head));
	fc1(field, head);
	ft_putsstr(field);
}

int				ft_fieldlong(t_tet *head)
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
		return (ft_sqrt(count) + 1);
	else
		return (ft_sqrt(count));
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
  *
 void			fc1(int next, char **field, t_tet *head, t_tet *tmp)
{
	int 		count;

	count = 0;
	while (tmp != NULL)
	{
		if (ft_write(field, tmp->x, tmp->y, tmp->content) < 0)
		{
			printf ("-1");
			return;
		}
		tmp = tmp->next;
	}
}

  char        **addfield(char **beforefield, int numb)
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
	field = ft_strsplitc(buf, '\n');
	return (field);
}
 */