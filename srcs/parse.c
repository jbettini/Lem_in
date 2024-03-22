/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:17:50 by jbettini          #+#    #+#             */
/*   Updated: 2024/03/22 23:31:59 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemIn.h"

bool    onlyDigitStr(char *str){
    for (int i = 0; str[i]; i++){
        if (!(ft_isdigit(str[i])))
            return false;
    }
    return true;
}

bool    isComment(char *str){
    if (str[0] == '#' && str[1] != '#')
        return true;
    return false;
}

bool    isStart(char *str){
    if (str[0] == '#' && str[1] == '#' && ft_strlen(str) == 7 && ft_strequ((str + 2), "start"))
        return true;
    return false;
}

bool    isEnd(char *str){
    if (str[0] == '#' && str[1] == '#' && ft_strlen(str) == 5 && ft_strequ((str + 2), "end"))
        return true;
    return false;
}

bool    isInstruction(char *str){
    if (str[0] == '#' && str[1] == '#')
        return true;
    return false;
}


//is Room
//is link

t_simulation    *parseStdin(void) {
    t_simulation    *simu = getEmptySimulation();
    char            *line;
    int             step = 0;
    while ((line = get_next_line(0))) {
        if (isComment(line)) {
            free(line);
            continue ;
        }
        else if (onlyDigitStr(line)){
            if (step != 0) {
                // clean simulation
                badInputFile(line);
                free(line);
                return NULL;
            }
            simu->ants = ft_atoi(line);
            step++;
        }
        //is room
        //is link
        free(line);
    }
    return simu;
}