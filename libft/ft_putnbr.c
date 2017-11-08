/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:16:00 by cyfermie          #+#    #+#             */
/*   Updated: 2017/11/07 16:16:09 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	char			tab[50];
	unsigned short	index;
	unsigned int	u;

	index = 49;
	u = (n < 0) ? ((unsigned int)-n) : ((unsigned int)n);
	while (u > 0)
	{
		tab[index] = u % 10 + '0';
		--index;
		u = u / 10;
	}
	if (n < 0)
	{
		tab[index] = '-';
		--index;
	}
	else if (n == 0)
	{
		tab[index] = '0';
		--index;
	}
	write(STDOUT_FILENO, tab + index + 1, 49 - index);
}
