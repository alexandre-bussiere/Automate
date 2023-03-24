//
// Created by maelwenn on 18/03/23.
//

#ifndef AUTOMATE_DETERMINE_H
#define AUTOMATE_DETERMINE_H

#include "basicFunctionDetermine.h"

bool isAutomatonDetermine(listEtat *currentAutomaton); // return true si l'automate est déterminé, false sinon
listEtat *determine(listEtat *currentAutomaton); // return 0 si pas de pb, 1 si pb
#endif //AUTOMATE_DETERMINE_H
