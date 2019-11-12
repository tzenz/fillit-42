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
int		one(char *s, int i, int *m, int *count);
void    two(char *s, int *i, int *j, int *count, char *sim);

int		valid(char **s)
{
	char	sim;
	int		i;

	i = 0;
	if (vone(*s) < 0)
		return (-1);
	sim = 'A';
	while (s[0][i])
	{
		if (vtwo(&s[0][i], sim++) < 0)
			return (-1);
		i += 21;
	}
	return (0);
}

int		vone(char *s)
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
        if (i > 545)
            return (-1);
       if (one(s, i, &m, &count) < 0)
           return (-1);
        i++;
    }
    return (0);
}

int		one(char *s, int i, int *m, int *count)
{
    if (i < (*m - 1) && s[i - 1] != '\n')
        return (-1);
    if (s[i - 1] != '\n')
        *m = *m + 5;
    if ((s[i] == '\n' && s[i + 1] == '\n') || s[i + 1] == '\0')
    {
        if (*count != 4)
            return (-1);
        *count = 0;
        *m += 1;
    }
    if (s[i] == '\n' && s[i + 1] == '\n' && s[i + 2] == '\n')
        return (-1);
    return(0);
}

int		vtwo(char *s, char sim)
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
        two(s, &i, &j, &count, &sim);
        e++;
    }
    return ((count != 4)) ? -1 : 0;
}

void    two(char *s, int *i, int *j, int *count, char *sim)
{
    while (s[*i + 5] == '#' && *i + 5 < 21)
    {
        *i += 5;
        *j = *i;
        while (s[*j + 1] == '#')
        {
            *j += 1;
            s[*j] = *sim;
            *count += (s[*j + 5] == '#') ? 2 : 1;
            s[*j + 5] = (s[*j + 5] == '#') ? *sim : s[*j + 5];
        }
        *j = *i;
        while (s[*j - 1] == '#')
        {
            *j -= 1;
            s[*j] = *sim;
            *count += (s[*j + 5] == '#') ? 2 : 1;
            s[*j + 5] = (s[*j + 5] == '#') ? *sim : s[*j + 5];
        }
        s[*i] = *sim;
        *count += 1;
    }
}
