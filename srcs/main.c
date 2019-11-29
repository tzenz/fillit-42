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
void		fc2(char **field, t_tet *superhead, t_tet *tmp)
{
	if (tmp->y == 4 && !tmp->count)
	{
		printf("1");
		ft_write(field, tmp->y, tmp->content);
		tmp->count++;
		fc2(field, superhead, (tmp = superhead));

	}
	else if (tmp->x == 4 && !tmp->count)
	{
		printf("2");
		ft_write(field, tmp->x, tmp->content);
		tmp->count++;
		fc2(field, superhead, (tmp = superhead));
	}
else
{
//		ft_putsstr(tmp->content);
printf("3");
fc2(field, superhead, (tmp = tmp->next));
}
}

void		ft_write(char **field, int x, char **content)
{
	int		count;
	int 	i;
	int 	j;
	int 	m;
	int 	n;

	i = 0;
	j = 0;
	m = 0;
	count = ft_wr(*field);
	n = count;
	while (x > (ft_strlen(*field) - 1) - count)
	{
		m++;
		n = 0;
		count = 0;
	}
	while (content[i] != NULL)
	{
		if (content[i][j] != field[m][n] && ft_cm(x, field[m]))
			field[m][n++] = content[i][j++];
		else if (content[i][j++] == '.')
			n++;
		else
		{
			m++;
			i++;
			n = count;
			j = 0;
		}
	}
}


int				ft_wr(char *field, int x)
{
	int 		i;

	i = 0;
	while (i <= x)
	{
		if (field[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int				ft_wd(char **field, int y)
{
	int 		m;
	int 		n;

	m = 0;
	n = 0;
	while (m <= y)
	{
		if (field[m][n] != '.' && field[m])
			return (0);
		m++;
	}
	return (1);
}

}*/