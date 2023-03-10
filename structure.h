//
// Created by tmKla on 10/03/2023.
//

#ifndef AUTOMATE2_STRUCTURE_H
#define AUTOMATE2_STRUCTURE_H
typedef struct Etat{
    char* nom;
    struct Transions** listLiaisons;
    int* listnbTransitions;
}Etat;
typedef struct Transions{
    Etat* data;
    struct Transions* next;
}liaisons;
typedef struct Transions listEtat;
#endif //AUTOMATE2_STRUCTURE_H
