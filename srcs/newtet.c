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

tetrimino   *newtet(char *s)
{
    tetrimino   *ptr;

    ptr = (tetrimino*)ft_memalloc(sizeof(tetrimino));
}

tetrimino   *tetr(char *s)
{
    tetrimino   *ptr;
    int     i;

    i = 0;
    while (s[i])
    {
        if (s[i] != '.' && s[i] != '\n' && s[i])
        {
            
            i++;
        }
    }
}