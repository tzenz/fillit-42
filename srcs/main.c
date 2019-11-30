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
		printf("x - %zu y - %zu numb - %zu\n", head->x, head->y, head->numb);
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
	while ((content[i][j] != field[m][n] && content[i][j] == '.') ||
			(content[i][j] != field[m][n] && field[m][n] == '.') ||
			(content[i][j] == '.' && field[m][n] == '.'))
	{
		i++;
		j++;
		if (j == 3)
			return (j);
	}
	return (0);
}


int				ft_countx(char **content, int x, int *n, char *field)
{
	int 		j;

	j = 0;
//	printf(" -JJJ- ");
	while (field[*n] != '\n')
	{
		while ((content[0][j] != field[*n] && content[0][j] == '.') ||
			   (content[0][j] != field[*n] && field[*n] == '.') ||
			   (content[0][j] == '.' && field[*n] == '.'))
		{
//			printf("con - %c field - %c\n", content[0][j], field[*n]);
//			printf("n - %d j - %d\n", *n, j);
			j++;
			*n += 1;

			if (j == x)
			{
//				ft_putnbr(j);
//				ft_putchar('\n');
				*n = *n - j;
				return (j);
			}
		}
		*n = (*n - j) + 1;
		j = 0;
	}
	return (0);
}
 && ft_countptr(content) == ft_county(content, m, *n, field)
 */