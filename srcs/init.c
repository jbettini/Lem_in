/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:18:31 by jbettini          #+#    #+#             */
/*   Updated: 2024/03/21 19:32:19 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemIn.h"

t_simulation    *getEmptySimulation(void) {
    t_simulation    *simu = malloc(sizeof(t_simulation) * 1);
    simu->graph = NULL;
    simu->ants = 0;
    return simu;
}