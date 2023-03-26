//
// Created by maelwenn on 25/03/2023.
//

#ifndef AUTOMATE_STARTFUNCTION_H
#define AUTOMATE_STARTFUNCTION_H
#include "get_from_txt.h"
#include "determine.h"
#include "complet.h"
#include "strandard.h"
#include "complementarisation.h"
#define lastNb '6'

void printMenu();
char choixUtilisateur();

int completAnAutomate(listEtat *automate);
int determineAnAutomate(listEtat *automate);
int standardAnAutomate(listEtat *automate);

#endif //AUTOMATE_STARTFUNCTION_H
