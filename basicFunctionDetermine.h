//
// Created by maelwenn on 22/03/23.
//

#ifndef AUTOMATE_BASICFUNCTIONDETERMINE_H
#define AUTOMATE_BASICFUNCTIONDETERMINE_H

#include "genererAutomate.h"
#include <stdio.h>

void updateListnbTransitions(Etat *currentEtat);
Etat *combine2Etat(Etat *firstEtat, Etat *secondEtat);
Etat *combineEveryEntry(listEtat *automate);

#endif //AUTOMATE_BASICFUNCTIONDETERMINE_H
