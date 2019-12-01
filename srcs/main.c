/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:37:14 by tzenz             #+#    #+#             */
/*   Updated: 2019/10/30 14:37:16 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include <stdio.h>

int		main(void)
{
	char	*s;
	char	buf[550];
	int		fd;
	int		r;
	t_tet 	*head;

	fd = open("testone", O_RDONLY);
	r = (read(fd, buf, 550));
	buf[r] = '\0';
	s = ft_strdup(buf);
	if (valid(&s) < 0)
	{
		ft_putstr("0\n");
		return (-1);
	}
	head = maintet(s);
	algm(head);
/*	while (head != NULL)
	{
		ft_putsstr(head->content);
		//		printf("x - %zu y - %zu numb - %zu\n", head->x, head->y, head->numb);
		head = head->next;
	}*/
	return (0);
}

/*
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
		if (x == ft_countx(content, x, &n, field[m]) && y == ft_county(content, m, n, field))
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
//		printf("cont - %c  field - %c  -   i - %d  m - %d n - %d\n", content[i][0], field[m][n], i, m, n);
		if (i + 1 == ft_countptr(content))
			return (i + 1);

		i++;
		m++;
	}
	return (0);
}


int				ft_countx(char **content, int m, int *n, char **field)
{
	int 		j;
	int 		stop;

	j = 0;
	while (field[m][*n] != '\n' && field[m][*n])
	{
		while ((content[0][j] != field[m][*n] && content[0][j] == '.') ||
			   (content[0][j] != field[m][*n] && field[m][*n] == '.') ||
			   (content[0][j] == '.' && field[m][*n] == '.'))
		{
//			printf("j - %d  n - %d\n", j ,*n);
			if (j + 1 == (ft_strlen(content[0])) && field[m][*n] != '\n')
			{
				if (ft_countptr(content) == ft_county(content, m, *n - j, field))
				{
					*n = *n - j;
					return (j + 1);
				}
				else
				{
					j++;
					*n += 1;
				}
//				printf("in if      j - %d  n - %d\n", j ,*n);
//				ft_putsstr(field);

				stop = ft_countptr(content);
				printf("ptr - %d\n", stop);
				stop = ft_county(content, m, *n, field);
				printf("y - %d\n", stop);
		}
		j++;
		*n += 1;
	}
	*n = (*n - j) + 1;
	j = 0;
}
return (0);
}
 && ft_countptr(content) == ft_county(content, m, *n, field)
 */

/*int				ft_county(char **content, int m, int n, char **field)
{
	int 		i;
	int 		j;

	i = 0;
	j = 0;
	while ((content[i][j] != field[m][n] && content[i][j] == '.') ||
		   (content[i][j] != field[m][n] && field[m][n] == '.') ||
		   (content[i][j] == '.' && field[m][n] == '.'))
	{
		if (i + 1 == ft_countptr(content))
		{
//			ft_putsstr(content);
			if (j + 1 == ft_countptr(content))
				return (j + 1);
			i = 0;
			j++;
		}
		i++;
		m++;
	}
	return (0);
}*/