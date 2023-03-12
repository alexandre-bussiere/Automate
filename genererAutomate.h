//
// Created by tmKla on 10/03/2023.
//

#ifndef AUTOMATE2_GENERERAUTOMATE_H
#define AUTOMATE2_GENERERAUTOMATE_H

#endif //AUTOMATE2_GENERERAUTOMATE_H
#include "structure.h"
#include "initialisation.h"
#include "stdlib.h"

bool isSameWord(char *mot1, char *mot2);
Etat* findEtatinList( Nom nom,   listEtat* listEtatpres);
Etat *creerchemin(Etat *EtatX, listEtat* listEtatspres, char *listLetrres,Nom** listnomtransition);
listEtat* creerAutomate(char *listLettres, int nbEtat, char** listnom, Nom*** listtransition);