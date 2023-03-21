//
// Created by Albane Coiffe on 13/03/2023.
//

#include "complet.h"
#include "structure.h"

bool IsComplet(listEtat *automate) {
    bool complet = true;
    int nbLettre = Nb_Colone() - 2;
    Etat *temp = automate->data;
    listEtat *tempNext = automate;
    do {
        tempNext = tempNext->next; // parcours liste chaine contenant les états
        int i = 0;
        while ((temp->listnbTransitions[i] != 0) && (i < nbLettre - 1)) {
            i++;
        }
        if (temp->listnbTransitions[i] == 0) {
            complet = false;
        }
        if (tempNext != NULL) {
            temp = tempNext->data; // aller au prochaine état
        }
    } while ((tempNext != NULL) && (complet != false));
    return complet;
}