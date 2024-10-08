/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassa <cassassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:42:15 by cassassa          #+#    #+#             */
/*   Updated: 2024/05/27 14:42:15 by cassassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *) destination;
	s = (unsigned char *) source;
	i = -1;
	if (d > s)
		while (size-- > 0)
			d[size] = s[size];
	else
		while (++i < size)
			d[i] = s[i];
	return (destination);
}
// 
// int main(void)
// {
	// char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	// char *dest = ft_memmove(sResult + 1, sResult, 2);
	// printf("%s\n", dest);
// }