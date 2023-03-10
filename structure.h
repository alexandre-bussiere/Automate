//
// Created by tmKla on 10/03/2023.
//

#ifndef AUTOMATE2_STRUCTURE_H
#define AUTOMATE2_STRUCTURE_H
typedef struct Etat{
    char* nom;
    struct Transions** listTransitions;
    int* listnbTransitions;
}Etat;
typedef struct Transions{
    Etat* data;
    struct Transions* next;
}Transitions;
typedef struct Transions listEtat;
#endif //AUTOMATE2_STRUCTURE_H
