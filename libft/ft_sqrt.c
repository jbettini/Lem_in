/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 20:16:21 by jbettini          #+#    #+#             */
/*   Updated: 2024/03/24 06:55:23 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	i;
	long	res;

	i = 1;
	res = 0;
	if (nb <= 0)
		return (0);
	while (res < nb)
	{
		res = i * i;
		if (res == nb)
			return (i);
		i++;
	}
	return (0);
}