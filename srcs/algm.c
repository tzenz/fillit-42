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

int				ft_write(char **field, int x, int y, char **content)
{
	int			m;
	int			n;

	m = 0;
	n = 0;
	while (field[m] && field[m][n])
	{
		if (x == ft_countx(content, m, &n, field))
		{
			ft_humhum(field, content, m, n);
			return (ft_s(m, n, x, field));
		}
		if (field[m][n] == '\n')
		{
			m++;
			n = 0;
		}
		else
			n++;
	}
	return (-1);
}

int				ft_countx(char **content, int m, int *n, char **field)
{
	int			j;

	j = 0;
	while (field[m][*n] != '\n' && field[m][*n])
	{
		while ((content[0][j] != field[m][*n] && content[0][j] == '.') ||
			   (content[0][j] != field[m][*n] && field[m][*n] == '.') ||
			   (content[0][j] == '.' && field[m][*n] == '.'))
		{
			if (j + 1 == (ft_strlen(content[0])) && field[m][*n] != '\n')
			{
				if (ft_county(content, m, *n - j, field))
				{
					*n = *n - j;
					return (j + 1);
				}
			}
			j++;
			*n += 1;
		}
		*n = (*n - j) + 1;
		j = 0;
	}
	return (0);
}

int				ft_county(char **content, int m, int n, char **field)
{
	int			i;
	int			j;
	int			count;

	count = m;
	i = 0;
	j = 0;
	while ((content[i][j] != field[m][n] && content[i][j] == '.') ||
			(content[i][j] != field[m][n] && field[m][n] == '.') ||
			(content[i][j] == '.' && field[m][n] == '.'))
	{
		i++;
		m++;
		if (i == ft_countptr(content))
		{
			if (j + 1 == ft_strlen(*content))
				return (j + 1);
			i = 0;
			m = count;
			n++;
			j++;
		}
	}
	return (0);
}

int				ft_s(int m, int n, int x, char **field)
{
	int 		count;

	count = 0;
	n = n + x;
	while (field[m][n] != '.' && field[m][n])
	{
		if (field[m][n] == '\n' && field[m + 1])
			while (field[m][n] == '\n' && field[m + 1])
			{
				n = 0;
				m++;
			}
		else
			n++;
	}
	if (field[m][n - 1] == '.')
		count++;
	while (field[m][n++] == '.')
		count++;
	return (count > 4) ? 4 : count;
}
