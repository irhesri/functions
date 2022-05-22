/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:16:50 by irhesri           #+#    #+#             */
/*   Updated: 2022/05/22 18:17:05 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char u)
{
	int	i;
	int	b;

	i = 8;
	while (i--)
	{
		b = ((u & 128) != 0) + 48;
		write(1, &b, 1);
		u <<= 1;
	}
}

unsigned char	reverse_bits(unsigned char c)
{
	unsigned char	u;
	int				i;

	u = 0;
	i = 8;
	while (i--)
	{
		u <<= 1;
		u |= (c & 1);
		c >>= 1;
	}
	return (u);
}

// int	main()
// {
// 	print_bits('2');
// 	printf("\n");
// 	print_bits(reverse_bits('2'));
// 	printf("\n");
// 	printf("%c\n", reverse_bits('2'));
// }
