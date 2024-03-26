/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 04:21:39 by jbettini          #+#    #+#             */
/*   Updated: 2024/03/26 03:27:29 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemIn.h"

int main (int ac, char **av) {
    (void)av;
    if (ac != 1)
        return invalidNumOfArg();
    t_simulation	*simu = parseStdin();
    if (!simu)
        return ERROR;
    pathFinding(simu);
    system("leaks lem-in");
    // ft_lstiter_strs(simu->paths, ft_putsendl);
    return 0;
}