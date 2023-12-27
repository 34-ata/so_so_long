/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faata <faata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:19:32 by marvin            #+#    #+#             */
/*   Updated: 2023/12/27 14:15:32 by faata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_len(int len, long n)
{
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_res(char *res, long nbr, int len)
{
	while (nbr > 0)
	{
		res[len] = (nbr % 10) + 48;
		len--;
		nbr /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*res;
	int		len;

	nbr = n;
	len = ft_len(0, nbr);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	len--;
	if (nbr == 0)
	{
		res[0] = 48;
		return (res);
	}
	if (nbr < 0)
	{
		nbr *= -1;
		res[0] = '-';
	}
	return (ft_res(res, nbr, len));
}
