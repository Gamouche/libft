/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:02:24 by cyfermie          #+#    #+#             */
/*   Updated: 2017/11/07 16:07:09 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	index_1;
	size_t	index_2;
	char	*strjoin;

	index_1 = 0;
	index_2 = 0;
	while (s1[index_1] != '\0')
		++index_1;
	while (s2[index_2] != '\0')
		++index_2;
	strjoin = (char *)malloc(sizeof(char) * (index_1 + index_2 + 1));
	if (strjoin == NULL)
		return (NULL);
	index_1 = 0;
	while (*s1 != '\0')
		strjoin[index_1++] = *s1++;
	while (*s2 != '\0')
		strjoin[index_1++] = *s2++;
	strjoin[index_1] = '\0';
	return (strjoin);
}
