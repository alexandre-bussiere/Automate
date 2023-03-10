//
// Created by tmKla on 10/03/2023.
//

#ifndef AUTOMATE2_STRUCTURE_H
#define AUTOMATE2_STRUCTURE_H
#include <stdbool.h>

typedef struct Etat{
    char* nom;
    struct Transions** listTransitions;
    int* listnbTransitions;
    bool entree;
    bool sortie;
}Etat;
typedef struct Transitions{
    Etat* data;
    struct Transions* next;
}Transition;
typedef struct Transitions listEtat;
#endif //AUTOMATE2_STRUCTURE_H
