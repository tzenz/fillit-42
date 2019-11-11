/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:57:32 by tzenz             #+#    #+#             */
/*   Updated: 2019/11/11 14:57:33 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"

char	*addline(char *s)
{
	char 	*str;
	int 	count;
	int 	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			count++;
		i++;
	}
	count++;
	str = ft_strnew(21);
	i = 0;
	while (i < 20)
	{
		str[i] = '.';
		if (i == 3 || i == 8 || i == 13 || i == 18)
		{
			str[i + 1] = '\n';
			i++;
		}
		i++;
	}
	str[i] = '\0';
	return (str);
}