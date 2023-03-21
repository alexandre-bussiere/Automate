//
// Created by tmKla on 10/03/2023.
//
#include "structure.h"
#include "stdlib.h"
#include "get_from_txt.h"

#ifndef AUTOMATE2_INITIALISATION_H
#define AUTOMATE2_INITIALISATION_H
typedef char* Nom;
listEtat *creerListEtat();
Transitions *creerTransition();
Etat *creerEtat(Nom, int nblettre);
void ajouterTransition(Etat* EtatX, Etat * EtatLie, int num);
listEtat* ajouterEtat(listEtat* Automate,int nbEtat, int nblettre);
void ajouter1etat(listEtat* Automate, Etat *NewEtat);

#endif //AUTOMATE2_INITIALISATION_H
