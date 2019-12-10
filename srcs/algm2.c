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
//	ft_putsstr(field);
//	ft_putchar('\n');
	return (field);
}

int				ft_scount(t_tet *head)
{
	while (head != NULL)
	{
		if (!head->count)
			return (1);
		head = head->next;
	}
	return (0);
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

void			ft_cntminus(int x, int y, t_tet *head)
{
	while (head)
	{
		if (x == head->x)
			head->cnt = 0;
		else if (y == head->y)
			head->cnt = 0;
		head = head->next;
	}
}

t_tet			*ft_snum(int next, t_tet *head, t_tet *tmp)
{
	while (tmp)
	{
		while (tmp)
		{
//			printf("next - %d  tmp->count - %zu  tmp->cnt - %d\n", next, tmp->count, tmp->cnt);
			if (next == tmp->y && !tmp->count && !tmp->cnt)
			{
				ft_cntminus(0, tmp->y, head);
				return (tmp);
			}
			tmp = tmp->next;
		}
		next = (next - 1 > 0) ? next - 1 : 4;
		tmp = head;
//		printf("SDS");
	}
	return (0);
}

int				fc1(char **field, int next, t_tet *head, t_tet *tmp)
{
	t_tet		*buf;

//	ft_putsstr(field);
	if (!ft_scount(head))
	{
		ft_putsstr(field);
		return (0);
	}

	if ((next = ft_write(field, (buf = ft_snum(next, head, head)))) == -2)
	{
		next = buf->y;
//		buf->cnt++;
		return (-2);
	}
	else if (next == -1)
	{
		next = buf->y;
		buf->cnt++;
	}
	else
	{
		printf("buf->numb - %zu\n", buf->numb);
		ft_putsstr(field);
	}
	fc1(addfield(field, ft_fieldlong(head, 0)), next, head, head);

	if ((next = ft_write(field, (buf = ft_snum(next, head, head)))) != -2)
	{
//		printf("buf->numb - %zu\n", buf->numb);
//		if (buf->count)
//			buf->count = 0;
//		ft_putsstr(field);
		printf("next - %d\n", next);
//		ft_putsstr(buf->content);
		fc1(field, buf->y, head, head);
	}
//	ft_putsstr(field);
//	ft_putchar('\n');
	return (0);
}

t_tet			*ft_lstdelete(t_tet *head)
{
	t_tet		*buf;
	int 		i;
	int 		j;

	i = 0;
	j = 0;
	if (head)
	{
		while (head->content[i][j] == '.')
			j++;
		if (head->content[i][j] == 'A')
		{
			buf = head;
			head = head->next;
		} else
		{
			buf = head->next;
			head->next = buf->next;
		}
		free(buf->content);
		free(buf);
		buf = NULL;
	}
	return (head);
}

/*int				fc1(char **field, int next, t_tet *head, t_tet *tmp)
{
	t_tet		*buf;

	while (ft_scount(head))
	{
		if ((next = ft_write(field, (buf = ft_snum(next, head, head)))) == -2)
			return (-2);
		else if (next == -1)
		{
			next = buf->y;
			buf->cnt++;
			ft_putnbr(buf->cnt);
		}
		else
		{
			while (tmp->numb != buf->numb)
				tmp = tmp->next;
			tmp->next = buf->next;
			free(buf->content);
			buf->numb = 0;
//			free(buf);
			buf = NULL;
			tmp = head;
		}
//		printf("\nnext - %d\n", next);
//		ft_putsstr(field);
	}
	while (head)
	{
		ft_putnbr(head->numb);
		ft_putchar('\n');
		head = head->next;
	}
	return (0);
}*/

void			algm(t_tet *head)
{
	t_tet *tmp;
	char **field;
	int count;


	count = 1;
	field = NULL;
	field = addfield(field, 6);
//	field = addfield(field, ft_fieldlong(head, 0));
	fc1(field, 1, head, head);
/*	while (fc1(field, 1, head, head) < 0)
	{
		printf(" -- \n");
		field = addfield(field, ft_fieldlong(head, count++));
		tmp = head;
		while (tmp)
		{
			if (tmp->count)
				tmp->count = 0;
			tmp = tmp->next;
		}
	}*/
/*	while (head)
	{
		ft_write(field, head);
		head = head->next;
	}*/
//	ft_putsstr(field);
}

/*
 * t_tet			*ft_snum(int next, t_tet *head, t_tet *tmp)
{
	while (tmp)
	{
		while (tmp)
		{
			if (next == tmp->y && !tmp->count && !tmp->cnt)
			{
				ft_cntminus(0, tmp->y, head);
				return (tmp);
			}
			tmp = tmp->next;
		}
		next = (next - 1 > 0) ? next - 1 : 4;
		tmp = head;
	}
	return (0);
}

int				fc1(char **field, int next, t_tet *head, t_tet *tmp)
{
	t_tet		*buf;

	while (ft_scount(head))
	{
		if ((next = ft_write(field, (buf = ft_snum(next, head, head)))) == -2)
			return (-2);

		else if (next == -1)
		{
			next = buf->y;
			buf->cnt++;
			ft_putnbr(buf->cnt);
		}
		else
		{

		}
		printf("\nnext - %d\n", next);
	ft_putsstr(field);
	}

	return (0);
}


int				fc1(char **field, int next, t_tet *head, t_tet *tmp)
{
	t_tet		*buf;

//	ft_putsstr(field);
	if (!ft_scount(head))
	{
		ft_putsstr(field);
		return (0);
	}

	if ((next = ft_write(field, (buf = ft_snum(next, head, head)))) == -2)
	{
		next = buf->y;
//		buf->cnt++;
		return (-2);
	}
	else if (next == -1)
	{
		next = buf->y;
		buf->cnt++;
	}
	fc1(addfield(field, ft_fieldlong(head, 0)), next, head, head);
	if ((next = ft_write(field, (buf = ft_snum(next, head, head)))) != -2)
	{
//		if (buf->count)
//			buf->count = 0;
//		ft_putsstr(field);
		printf("next - %d\n", next);
//		ft_putsstr(buf->content);
		fc1(field, buf->y, head, head);
	}
//	ft_putsstr(field);
//	ft_putchar('\n');
	return (0);
}
*/