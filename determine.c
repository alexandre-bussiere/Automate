//
// Created by maelwenn on 18/03/23.
//

#include "determine.h"

bool isAutomatonDetermine(listEtat *automaton) {
    bool moreThanOneTransition = false;
    int countEntry = 0, i;
    int nbColumn = Nb_Colone() - 2;

    if ((automaton != NULL) || (automaton->data != NULL)) {
        Etat *currentEtat = automaton->data;
        listEtat *nextLine = automaton;
        do {
            nextLine = nextLine->next; // parcours liste chaine contenant les états
            i = 0;
            // compter le nb d'entrée
            if (currentEtat->entree) {
                countEntry++;
            }
            // compter le nb de liaison
            while ((i < nbColumn) && (!(moreThanOneTransition))) {
                if (currentEtat->listnbTransitions[i] >= 2) {
                    moreThanOneTransition = true;
                }
                i++;
            }
            if (nextLine != NULL) {
                currentEtat = nextLine->data; // aller au prochaine état
            }
        } while ((nextLine != NULL) && (!(moreThanOneTransition)) && ((countEntry < 2)));
    }

    if ((countEntry == 1) && (!(moreThanOneTransition))) {
        return true;
    }
    return false;
}

listEtat *determine(listEtat *currentAutomaton) {
    if (isAutomatonDetermine(currentAutomaton)) {
        return currentAutomaton;
    }
    listEtat *determineAutomate = creerTransition();
    listEtat *currentTransition = determineAutomate;
    currentTransition->data = combineEveryEntry(currentAutomaton);
    int nbColumn = Nb_Colone() - 2;
    int haveEtatToAdd = 0;
    Etat *currentEtat = currentTransition->data, *etatToAdd;
    char *nameCurrentTransition;

    currentTransition = currentTransition->next;
    while ((haveEtatToAdd != nbColumn) && (currentTransition!=NULL)) {
        haveEtatToAdd = 0;
        for (int i = 0; i < nbColumn; i++) {
            nameCurrentTransition = concatNameTransition(currentEtat->listTransitions[i]);
            etatToAdd = findSimilarEtat(determineAutomate, nameCurrentTransition);
            if (etatToAdd == NULL) {
                etatToAdd = combineEveryEtatFromTransitions(currentEtat->listTransitions[i]);
                addEtatEndAutomate(determineAutomate, etatToAdd);
            } else {
                haveEtatToAdd++;
            }
        }
        if(currentTransition!=NULL){
            currentEtat = currentTransition->data;
            currentTransition=currentTransition->next;
        }
    }

    return determineAutomate;
}
