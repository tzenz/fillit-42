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

void		fc2(char *field, t_tet *tmp)
{

}

int			fc1(char *field, t_tet *head)
{
	t_tet	*tmp;
	int 	nembtet;
	int 	max;
	int 	i;

	i = 0;
	max = 0;
	tmp = head;
	while (tmp->next != NULL)
	{
		if (tmp->y > max)
		{
			nembtet = tmp->numb;
			max = tmp->y;
		}
		tmp = tmp->next;
	}
	fc2()
	while (field[i])
	{

	}
	return (-1);
}

void		algm(t_tet *head)
{
	t_tet		*tmp;
	char		*field;
	int 		i;

	field = NULL;
	tmp = head;
	field = addfield(field, plus(tmp));
	while ((fc1(field, tmp)) > 0)
		addfield(field, plus(tmp) + 1);
	ft_putstr(field);
}