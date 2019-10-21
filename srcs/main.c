/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 12:01:04 by exam              #+#    #+#             */
/*   Updated: 2019/09/18 12:19:27 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../srcs/fillit.h"

void	ft_strswap(char **s, char c)
{
	int count;

	count = 0;
	while (s[0][count])
	{
		if (s[0][count] == '#')
			s[0][count] = c;
		count++;
	}
}

int 	main(int argc, char **argv)
{
	char 	**s;
	char    **res;
	char 	*str;
	char 	buf[100];
	int 	fd;
	char 	c;
	int 	r;
	int 	i;

	c = 'A';
	if (argc != 2)
	{
		ft_putstr("exit\n");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	str = ft_strnew(1);
	while ((r = read(fd, buf, 100)))
	{
		buf[r] = '\0';
		str = ft_strjoin(str , buf);
	}
	s = ft_strsplit(str, '\n');
	r = 0;
	i = 4;
	while (s[r])
	{
		ft_strswap(&s[r++], c);
		if (r == i)
		{
			i *= 2;
			c++;
		}
	}
	r = 0;
    while (s[r]) //утечка strims выделяет новые строки, старые нужно затереть
    {
        s[r] = ft_strtrims(s[r]);
        r++;
    }
    r = r / 3;
    res = (char **)ft_memalloc(sizeof(char **) * r)
    r = 0;
    while (s[r])
    {
        if (s[r] > s[r + 1])
        {
            while ()
        }
        r++;
    }*/
	ft_putsstr(s);
	return (0);
}