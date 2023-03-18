//
// Created by lentz on 16/03/2023.
//

#include "strandard.h"

bool isAutomatStandard(listEtat *automaton) {
    int countEntry = 0;
    int nbColumn = Nb_Colone() - 2;

    if ((automaton != NULL) || (automaton->data != NULL)) {
        Etat *currentEtat = automaton->data;
        Etat *adresseEntree = NULL;
        listEtat *nextLine = automaton->next;
        do {
            // compter le nb d'entrée
            if (currentEtat->entree) {
                countEntry++;
                adresseEntree = currentEtat;
            }
            if (nextLine != NULL) {
                currentEtat = nextLine->data; // aller au prochaine état
                nextLine = nextLine->next; // parcours liste chaine contenant les états
            }
        } while ((nextLine != NULL) && ((countEntry < 2)));

        if (countEntry != 1) {
            return false;
        }
        Etat *EtatActuel;
        listEtat *ligneSuivante;
        currentEtat = automaton->data;
        nextLine = automaton;

        do {
            nextLine = nextLine->next; // parcours liste chaine contenant les états
            for (int i = 0; i < nbColumn; i++) {
                int nbTransition = currentEtat->listnbTransitions[i];
                if (nbTransition != 0) {
                    EtatActuel = currentEtat->listTransitions[i]->data;
                    ligneSuivante = currentEtat->listTransitions[i]->next;
                    for (int j = 0; j < nbTransition; j++) {
                        if (EtatActuel == adresseEntree) {
                            return false;
                        }
                        if (ligneSuivante != NULL) {
                            EtatActuel = ligneSuivante->data; // aller au prochaine état
                            ligneSuivante = ligneSuivante->next; // parcours liste chaine contenant les transitions
                        }
                    }
                }

            }
            if (nextLine != NULL) {
                currentEtat = nextLine->data; // aller au prochaine état
            }
        } while ((nextLine != NULL));
    }
    return true;
}