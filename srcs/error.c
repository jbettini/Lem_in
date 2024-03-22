/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:29:37 by jbettini          #+#    #+#             */
/*   Updated: 2024/03/22 23:30:03 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemIn.h"

int    invalidNumOfArg(void){
    ft_putstr("Invalid number of argument\n");
    return ERROR;
}

int    badInputFile(char *badLine){
    ft_putstr("Input file has a bad syntax : ");
    ft_putendl(badLine);
    return ERROR;
}



