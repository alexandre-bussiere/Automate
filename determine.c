//
// Created by maelwenn on 13/03/23.
//

#include "determine.h"

bool isAutomatonDetermine(listEtat* automaton){
    bool moreThanOneTransition;
    int countEntry=0, i;
    int nbColumn=3; // = function Alex nb column;

    if(automaton==NULL){
        Etat* currentEtat = automaton->data;
        listEtat* nextLine = automaton->next;
        do{
            i=0;
            if(currentEtat->entree){
                countEntry++;
            }
            while((i < nbColumn) && (currentEtat->listnbTransitions[i] < 2)){
                i++;
            }
            if(currentEtat->listnbTransitions[i] < 2){
                moreThanOneTransition = true;
            }
            nextLine = nextLine->next;
        }while ((nextLine!=NULL) && (!(moreThanOneTransition)) && ((countEntry<2)));
    }

    if((countEntry==1) && (!(moreThanOneTransition))){
        return true;
    }
    return false;
}