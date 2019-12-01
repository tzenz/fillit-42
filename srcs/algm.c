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
	int 	m;
	int 	n;

	m = 0;
	n = 0;
	while (field[m] && field[m][n])
	{
		if (x == ft_countx(content, m, &n, field))
		{
			ft_humhum(field, content, m, n);
			return (1);
		}
		if (field[m][n] == '\n')
		{
			m++;
			n = 0;
		}
		else
			n++;
	}
	return (0);
}

int				ft_county(char **content, int m, int n, char **field)
{
	int 		i;
	int 		j;
	int 		count;

	count = m;
	i = 0;
	j = 0;
//	ft_putsstr(content);
	ft_putchar(':');
	while ((content[i][j] != field[m][n] && content[i][j] == '.') ||
			(content[i][j] != field[m][n] && field[m][n] == '.') ||
			(content[i][j] == '.' && field[m][n] == '.'))
	{
		i++;
		m++;
		ft_putsstr(content);
		ft_putchar('\n');
		printf("i - %d\n", i);
		printf("j - %d\n", j);
		printf("m - %d\n", m);
		printf("n - %d\n", n);
		printf("countptr - %d\n", ft_countptr(content));
		if (i == ft_countptr(content))
		{
			printf(" ----- \n");
			if (j + 1 == ft_strlen(*content))
			{
				return (j + 1);
			}
			i = 0;
			m = count;
			n++;
			j++;
		}
	}
	return (0);
}


int				ft_countx(char **content, int m, int *n, char **field)
{
	int 		j;

	j = 0;
	while (field[m][*n] != '\n' && field[m][*n])
	{
		while ((content[0][j] != field[m][*n] && content[0][j] == '.') ||
			   (content[0][j] != field[m][*n] && field[m][*n] == '.') ||
			   (content[0][j] == '.' && field[m][*n] == '.'))
		{
			if (j + 1 == (ft_strlen(content[0])) && field[m][*n] != '\n')
			{
//				printf("j - %d  n - %d\n", j ,*n);
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

int				ft_countptr(char **s)
{
	int 		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}