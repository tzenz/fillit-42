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

int			ft_write(char **field, int x, int y, char **content)
{
	int 	i;
	int 	j;
	int 	m;
	int 	n;

	i = 0;
	j = 0;
	m = 0;
	n = 0;
	while (field[m] && field[m][n])
	{
		if (x == ft_countx(content, m, &n, field) && y == ft_county(content, m, n, field))
		{
			ft_humhum(field, content, m, n);
			return (1);
		}
		if (field[m][n] == '\n')
		{
			m++;
			n = 0;
		} else
			n++;
	}
	return (0);
}

int				ft_county(char **content, int m, int n, char **field)
{
	int 		i;
	int 		j;

	i = 0;
	j = 0;
	while ((content[i][0] != field[m][n] && content[i][0] == '.') ||
			(content[i][0] != field[m][n] && field[m][n] == '.') ||
			(content[i][0] == '.' && field[m][n] == '.'))
	{
		i++;
		m++;
		if (i == ft_countptr(content))
			return (i);
	}
	return (0);
}


int				ft_countx(char **content, int m, int *n, char **field)
{
	int 		j;
	int 		stop;

	j = 0;
	while (field[m][*n] != '\n')
	{
		while ((content[0][j] != field[m][*n] && content[0][j] == '.') ||
			   (content[0][j] != field[m][*n] && field[m][*n] == '.') ||
			   (content[0][j] == '.' && field[m][*n] == '.'))
		{
			j++;
			*n += 1;
			if (j == (ft_strlen(content[0]) - 1) && ft_countptr(content) == ft_county(content, m, *n, field))
			{
//				ft_putsstr(field);

				stop = ft_countptr(content);
				printf("ptr - %d\n", stop);
				stop = ft_county(content, m, *n, field);
				printf("y - %d\n", stop);

				*n = *n - j;
				return (j);
			}
		}
		*n = (*n - j) + 1;
		j = 0;
	}
	return (0);
}

//int				ft_comp(char **content, char )

int				ft_countptr(char **s)
{
	int 		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}