//
// Created by maelwenn on 18/03/23.
//

#include "determine.h"

int isAutomatonDetermine(listEtat *automaton) {
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
        return 0;
    } else if(countEntry != 1){
        return 1;
    } else{
        return 2;
    }
}

int determine(listEtat *currentAutomaton) {
    if (isAutomatonDetermine(currentAutomaton)==0) {
        printf("L'automate est deja determiniser.\n");
        return 1;
    }
    listEtat *determineAutomate = creerTransition();
    listEtat *currentLine = determineAutomate;
    currentLine->data = combineEveryEntry(currentAutomaton); // création de la nouvelle entrée
    int nbColumn = Nb_Colone() - 2;
    Etat *currentEtat = currentLine->data, *etatToAdd;
    char *nameCurrentTransition;

    while (currentLine != NULL) {
        for (int i = 0; i < nbColumn; i++) {
            if (currentEtat->listnbTransitions[i] != 0) {
                nameCurrentTransition = concatNameTransition(currentEtat->listTransitions[i]);
                etatToAdd = findSimilarEtat(determineAutomate, nameCurrentTransition); // est-ce que l'état existe déjà ?
                if (etatToAdd == NULL) {
                    etatToAdd = combineEveryEtatFromTransitions(currentEtat->listTransitions[i]); // création du nouvel état
                    etatToAdd->entree = false;
                    addEtatEndAutomate(determineAutomate, etatToAdd); // ajout du nouvel état a la fin de l'automate
                }
            }
        }
        currentLine = currentLine->next; // parcours de l'automate
        if (currentLine != NULL) {
            currentEtat = currentLine->data;
        }
    }
    updateListTransitions(determineAutomate); // mise a jour des transition
    *currentAutomaton = *determineAutomate;
    return 0;
}
