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
    char 	buf[10];
    int     i;
    int 	j;
	int 	sim;

    j = 0;
    i = 0;
    sim = 0;
    ft_bzero(buf, 10);
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
			i -= 4;
			while (s[i] && s[i] != '\n')
			{
				if (s[i] == sim || (s[i] == '.' && s[i + 5] == sim && s[i + 10] == sim))
					buf[j++] = s[i];
				else if ((s[i] == '.' && s[i - 5] == sim) || (s[i] == '.' && s[i - 10] == sim))
					buf[j++] = s[i];
				i++;
			}
			buf[j++] = '\n';
			sim = 0;
		}
		i++;
	}
	ft_putstr(buf);
	return (NULL);
}