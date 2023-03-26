//
// Created by maelwenn on 18/03/23.
//

#ifndef AUTOMATE_DETERMINE_H
#define AUTOMATE_DETERMINE_H

#include "basicFunctionDetermine.h"

int isAutomatonDetermine(listEtat *currentAutomaton); // return 0 si l'automate est déterminé, 1 si + d'1 entrée, 2 si + d'1 transition par lettre de l'aphabet
int determine(listEtat *currentAutomaton); // return 0 si pas de pb, 1 si pb
#endif //AUTOMATE_DETERMINE_H
