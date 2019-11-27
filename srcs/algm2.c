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
	field = ft_strsplit(buf, '\n');
	free(buf);
	return (field);
}

int			plus(t_tet *tmp)
{
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->numb);
}