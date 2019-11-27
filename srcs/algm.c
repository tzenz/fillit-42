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

void		fc2(char **field, t_tet *tmp)
{
	int 	count;
	int 	i;
	int 	j;
	int 	m;
	int 	n;

	count = 0;
	i = 0;
	j = 0;
	m = 0;
	n = 0;
	while (tmp->content[i] && count != 4 && tmp != NULL)
	{
		if (tmp->content[i][0] != field[j][0])
		{
			printf("tmp - %s++++\n", tmp->content[i]);
			j++;
			if (tmp->content[i + 1])
				i++;
			count++;
		}
		else
		{
			printf("--------------\n");
			tmp = tmp->next;
			count = 0;
			i = 0;
			j = 0;
		}
		printf("i - %d, count - %d\n", i, count);
	}
	if (count == 4)
	{
		ft_write(field, tmp->content);
		tmp->count++;
	}
}

void		ft_write(char **field, char **content)
{
	int 	i;
	int 	j;
	int 	m;

	m = 0;
	i = 0;
	j = 0;

//	ft_putsstr(content);
	while (content[i] != NULL)
	{
		if (content[i][j] != '\n')
		{
			field[m][0] = content[i][j++];
			m++;
			if (content[i][j] == '\0')
			{
				i++;
				j = 0;
			}
		}
		else
		{
			i++;
			j = 0;
		}
	}
}

int			fc1(char **field, t_tet *head)
{
	t_tet	*tmp;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	tmp = head;
//	while (field[i])
//	{
		fc2(field, head);
//		i++;
//	}
	return (-1);
}

void		algm(t_tet *head)
{
	t_tet		*tmp;
	char		**field;
	int 		i;

	field = NULL;
	tmp = head;
	field = addfield(field, 4);
	fc1(field, tmp);
//	while ((fc1(field, tmp)) > 0)
//		addfield(field, plus(tmp) + 1);
//	ft_putsstr(field);
}