//
// Created by maelwenn on 18/03/23.
//

#include "determine.h"

bool isAutomatonDetermine(listEtat *automaton) {
    bool moreThanOneTransition = false;
    int countEntry = 0, i;
    int nbColumn = Nb_Colone() - 2; // = function Alex nb column;

    if ((automaton != NULL) && (automaton->data != NULL)) {
        Etat *currentEtat = automaton->data;
        listEtat *nextLine = automaton->next;
        do {
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
                nextLine = nextLine->next; // parcours liste chaine contenant les états
            }
        } while ((nextLine != NULL) && (!(moreThanOneTransition)) && ((countEntry < 2)));
    }

    if ((countEntry == 1) && (!(moreThanOneTransition))) {
        return true;
    }
    return false;
}