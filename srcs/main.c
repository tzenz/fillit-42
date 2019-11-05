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
int		valid(char *s);

int		part1(char *s, char sim)
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
	while ((s[e + 1] == '#') || (s[e + 5] == '#' || s[e] == '#')) {
	    s[e] = sim;
//      ft_putchar('O');
        count++;
 //     ft_putnbr(e);
        i = e;
        while (s[i + 5] == '#') {
            i += 5;
 //         ft_putchar('U');
            j = i;
            while (s[j + 1] == '#') {
                j++;
                s[j] = sim;
 //             ft_putchar('L');
                count++;
                }
                j = i;
            while (s[j - 1] == '#') {
 //             ft_putchar('M');
                j--;
                s[j] = sim;
                count++;
                }
                s[i] = sim;
                count++;
        }
        e++;
     }
    printf("count - %d\n", count);
	return ((count != 4)) ? -1 : 0;
}

int		main(void)
{
	char *s;
	char buf[100];
	char sim;
	int fd;
	int r;
	int i;

	i = 0;
	fd = open("testease", O_RDONLY);
	s = ft_strnew(1);
	while ((r = (read(fd, buf, 100))))
	{
		buf[r] = '\0';
		s = ft_strjoin(s, buf);
	}
	if (valid(s) < 0)
		return (-1);
	sim = 'A';
	while (s[i]) {
        part1(&s[i], sim++);
        i += 21;
 //       ft_putchar('V');
    }
	ft_putstr(s);
	return (0);
}


