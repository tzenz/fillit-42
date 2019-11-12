/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reason.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzenz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:09:25 by tzenz             #+#    #+#             */
/*   Updated: 2019/11/12 19:09:29 by tzenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		reason(char *s)
{
	char *print;
	int count;
	int flag;
	int stop;
	int i;
	int j;

	stop = 21;
	flag = 0;
	i = 0;
	j = 0;
	print = addline(s);
	while (print[i] && !flag)
	{
		if (print[i] == '.')
		{
			count = 0;
			while (s[j] != 'A' && s[j] != 'B' && s[j] != 'C' && s[j] != 'D')
				j++;
			print[i + count++] = s[j++];
			while (j < stop)
			{
				if (s[j] == 'A')
				{
					print[i + count] = s[j];
					count++;
					j++;
//					printf("ONE\n");
				}
				else
				{
					while (s[j] != 'A' && j < stop)
					{
						count++;
						j++;
					}
//					printf("TWO\n");
					print[i + count++] = s[j];
					j++;
				}
				if (s[j] == '\0')
					flag = 1;
				printf("count - %d\n", count);
			}
		}
		stop *= 2;
		i++;
	}
	ft_putstr(print);
	printf("\nj - %d\n", j);
	printf("stop - %d\n", stop);
	return (0);
}
