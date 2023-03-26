//
// Created by lentz on 16/03/2023.
//

#ifndef AUTOMATE_STRANDARD_H
#define AUTOMATE_STRANDARD_H
#include "structure.h"
#include "genererAutomate.h"
#include <stdlib.h>
#include <stdio.h>

bool isAutomatStandard(listEtat *automaton);
Transitions *concatListTransition(Transitions *t1, Transitions *t2);
Transitions* concatListTransition(Transitions* t1,Transitions* t2);
void standardiseAutomate(listEtat* Automate);
listEtat* findEntree(listEtat* Automate);

#endif //AUTOMATE_STRANDARD_H