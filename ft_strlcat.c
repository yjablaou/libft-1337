/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:16:10 by yojablao          #+#    #+#             */
/*   Updated: 2023/11/06 21:19:19 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ls;
	size_t	ld;
	size_t	l;
	size_t	i;
	size_t	j;

	ld = ft_strlen(dst);
	ls = ft_strlen(src);
	l = ld;
	i = 0;
	if (size == 0 || size < ld)
		return (size + ls);
	while (l < (size -1) && src[i] != '\0')
	{
		dst[l] = src[i];
		i++;
		l++;
	}
	dst[l] = '\0';
	j = ld + ls;
	if (ld < size)
		j = ld + ls;
	else 
		j = size + ls;
	return (j);
}
