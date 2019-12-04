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

int		main(int argc, char **argv)
{
	t_tet 	*head;
	char	buf[550];
	char	*s;
	int		fd;
	int		r;

	fd = open(argv[1], O_RDONLY);
	r = (read(fd, buf, 550));
	buf[r] = '\0';
	s = ft_strdup(buf);
	if (valid(&s) < 0 || argc != 2)
	{
		ft_putstr("error\n");
		exit (EXIT_SUCCESS);
		return (0);
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
