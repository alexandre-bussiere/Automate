//
// Created by Albane Coiffe on 13/03/2023.
//

#include "complet.h"
#include "structure.h"
#include <stdbool.h>
#include <stdio.h>

bool IsComplet(listEtat *automate) {
    bool complet = true;
    int nbLettre = 3;
    Etat *temp = automate->data;
    listEtat *tempNext = automate->next;
    while ((tempNext->next != NULL) && (complet != false)) {
        int i = 0;
        while ((temp->listnbTransitions[i] != 0) && (i < nbLettre - 1)) {
            i++;
        }
        if (temp->listnbTransitions[i] == 0) {
            complet = false;
        }
        temp = tempNext->data; // aller au prochaine état
        tempNext = tempNext->next; // parcours liste chaine contenant les états
    }
    return complet;
}
