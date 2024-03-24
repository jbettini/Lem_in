/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 03:07:42 by jbettini          #+#    #+#             */
/*   Updated: 2024/03/24 04:02:34 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemIn.h"

char *ft_strdup_except(char *src, char exclude)
{
    size_t i;
    size_t j;
    char *str;

    i = 0;
    j = 0;
    while (src[i])
    {
        if (src[i] != exclude)
            j++;
        i++;
    }
    str = malloc(j + 1);
    if (!str)
        return (NULL);
    i = 0;
    j = 0;
    while (src[i])
    {
        if (src[i] != exclude)
        {
            str[j] = src[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
	free(src);
    return (str);
}