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

/*tetrimino   *newtet(char *s)
{
    tetrimino   *ptr;

    ptr = (tetrimino*)ft_memalloc(sizeof(tetrimino));
}*/

tetrimino   *tetr(char *s)
{
    tetrimino   *ptr;
    char 	buf[8];
    int     i;
    int 	j;
    int 	e;

    j = 0;
    i = 0;
    while (s[i] != '#')
    	i++;
	while (s[i + 1] == '#' || s[i] == '#')
	{
	//	buf[j++] = s[i++];
		ft_putstr(buf);
	}
	buf[j] = '\0';
	ft_putstr(buf);
	return (NULL);
}