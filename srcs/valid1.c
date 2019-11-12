/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:57:50 by tzenz             #+#    #+#             */
/*   Updated: 2019/10/31 11:57:51 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"

int		valid(char **s)
{
	char	sim;
	int		i;

	i = 0;
	if (valid1(*s) < 0)
		return (-1);
	sim = 'A';
	while (s[0][i])
	{
		if (valid2(&s[0][i], sim++) < 0)
			return (-1);
		i += 21;
	}
	return (0);
}

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

//int		valid1-a(char *s)
