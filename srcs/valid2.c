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
