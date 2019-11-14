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
	char	buf[100];
	int		fd;
	int		r;
	tetrimino *head;

	fd = open("testone", O_RDONLY);
	s = ft_strnew(1);
	while ((r = (read(fd, buf, 100))))
	{
		buf[r] = '\0';
		s = ft_strjoin(s, buf);
	}
	if (valid(&s) < 0)
	{
		ft_putstr("0\n");
		return (-1);
	}
    head = maintet(s);
//    ft_putstr(s);
	return (0);
}

/*void	ft_check(char **s, int i, int sim)
{
	char 	buf[10];

	ft_bzero(buf, 10);
	if (sim)
	{
		i -= 4;
		while (s[i] && s[i] != '\n')
		{
			if (s[i] == sim || s[i + 5] == sim || s[i + 10] == sim)
				buf[j++] = s[i];
			else if (s[i - 5] == sim || s[i - 10] == sim)
				buf[j++] = s[i];
			i++;
		}
		buf[j++] = '\n';
		sim = 0;
	}
}

tetrimino   *tetr(char *s)
{
	tetrimino   *ptr;
	int     i;
	int 	j;
	int 	sim;

	j = 0;
	i = 0;
	sim = 0;
	while (s[i])
	{
		while (s[i] && s[i] != '\n')
		{
			if (s[i] != '.')
				sim = s[i];
			i++;
		}
		if (sim)
		{
			ft_check(&s[i], sim);
		}
		i++;
	}
	ft_putstr(buf);
	return (NULL);
}

 void	ft_add2(char **s, **buf, int *i, int sim)
{
	while (s[i] && s[i] != '\n')
	{
		if (s[i] == sim || s[i + 5] == sim || s[i + 10] == sim)
			buf[j++] = s[i];
		else if (s[i - 5] == sim || s[i - 10] == sim)
			buf[j++] = s[i];
		i++;
	}
	buf[j++] = '\n';
}*/