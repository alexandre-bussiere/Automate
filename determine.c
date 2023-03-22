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

int determine(listEtat *currentAutomaton){
    if(isAutomatonDetermine(currentAutomaton)){
        return 1;
    }
    listEtat *determineAutomate=creerTransition();
    listEtat *temp=determineAutomate;
    temp->data= combineEveryEntry(currentAutomaton);

}