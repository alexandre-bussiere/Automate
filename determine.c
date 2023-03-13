//
// Created by maelwenn on 13/03/23.
//

#include "determine.h"

bool isAutomatonDetermine(listEtat currentAutomaton){
    bool result;
    int count=0;
    Etat* currentEtat;
    Transition* nextEtat;
    Transition temp = currentAutomaton;
    currentEtat = currentAutomaton.data;
    if (currentEtat != NULL){
        nextEtat = currentAutomaton.next;
    }

    return result;
}