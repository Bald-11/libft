/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:19:24 by yabarhda          #+#    #+#             */
/*   Updated: 2024/11/03 10:12:51 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_string(char *str, long n, int len)
{
	str[len] = '\0';
	while (len)
	{
		len--;
		if (n < 0)
		{
			str[0] = '-';
			n *= -1;
		}
		if (str[len] != '-')
			str[len] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		len;
	long	temp_n;

	len = 0;
	temp_n = n;
	if (temp_n == 0)
		len++;
	while (temp_n != 0)
	{
		len++;
		temp_n /= 10;
	}
	len += n < 0;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	fill_string(dest, n, len);
	return (dest);
}