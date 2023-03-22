//
// Created by maelwenn on 22/03/23.
//

#ifndef AUTOMATE_BASICFUNCTIONDETERMINE_H
#define AUTOMATE_BASICFUNCTIONDETERMINE_H

#include "genererAutomate.h"
#include <stdio.h>

void updateListnbTransitions(Etat *currentEtat);

Etat *findSimilarEtat(listEtat *currentAutomate, char *nameEtat); // comme findEtatinList, mais l'état 120 = l'état 012

Etat *combine2Etat(Etat *firstEtat, Etat *secondEtat);
Etat *combineEveryEntry(listEtat *automate);
Etat *combineEveryEtatFromTransitions(Transitions *listCurrentTransitions);

char *concatNameTransition(Transitions *listCurrentTransitions);

void addEtatEndAutomate(listEtat *automate, Etat *etatToAdd);



void Test();

#endif //AUTOMATE_BASICFUNCTIONDETERMINE_H
