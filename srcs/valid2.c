/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:15:12 by tzenz             #+#    #+#             */
/*   Updated: 2019/11/05 12:15:13 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"

int		valid1(char *s)
{
    int 	i;
    int 	m;
    int		count;

    i = 0;
    m = 5;
    count = 0;
    while (s[i])
    {
        while (s[i] != '\n' && s[i])
        {
            if ((s[i] != '#' && s[i] != '.') || i >= (m - 1))
                return (-1);
            if (s[i] == '#')
                count++;
            i++;
        }
        if (i < (m - 1) && s[i - 1] != '\n')
            return (-1);
        if (s[i - 1] != '\n')
            m = m + 5;
        if ((s[i] == '\n' && s[i + 1] == '\n') || s[i + 1] == '\0')
        {
            if (count != 4)
                return (-1);
            count = 0;
            m++;
        }
        if (s[i] == '\n' && s[i + 1] == '\n' && s[i + 2] == '\n')
            return (-1);
        i++;
    }
    return (0);
}

int		valid2(char *s, char sim)
{
    int 	count;
    int 	e;
    int		i;
    int 	j;

    count = 0;
    i = 0;
    j = 0;
    e = 0;
    while (s[i] != '#')
        i++;
    e = i;
    while ((s[e + 1] == '#') || (s[e + 5] == '#' || s[e] == '#'))
    {
        s[e] = sim;
        count++;
        i = e;
        while (s[i + 5] == '#' && i + 5 < 21)
        {
            i += 5;
            j = i;
            while (s[j + 1] == '#')
            {
                j++;
                s[j] = sim;
                count++;
            }
            j = i;
            while (s[j - 1] == '#')
            {
                j--;
                s[j] = sim;
                count++;
            }
            s[i] = sim;
            count++;
        }
        e++;
    }
    return ((count != 4)) ? -1 : 0;
}