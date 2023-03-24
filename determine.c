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
    listEtat *currentLine = determineAutomate;
    currentLine->data = combineEveryEntry(currentAutomaton);
    int nbColumn = Nb_Colone() - 2;
    Etat *currentEtat = currentLine->data, *etatToAdd;
    char *nameCurrentTransition;

    while (currentLine != NULL) {
        for (int i = 0; i < nbColumn; i++) {
            if (currentEtat->listnbTransitions[i] != 0) {
                nameCurrentTransition = concatNameTransition(currentEtat->listTransitions[i]);
                etatToAdd = findSimilarEtat(determineAutomate, nameCurrentTransition);
                if (etatToAdd == NULL) {
                    etatToAdd = combineEveryEtatFromTransitions(currentEtat->listTransitions[i]);
                    etatToAdd->entree = false;
                    addEtatEndAutomate(determineAutomate, etatToAdd);
                }
            }
        }
        if (currentLine != NULL) {
            currentEtat = currentLine->data;
            currentLine = currentLine->next;
        }
    }

    updateListTransitions(determineAutomate);
    return determineAutomate;
}
