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

void Complet(listEtat *automate){
    int nb_alphabet = Nb_Colone() -2;
    int nb_etat = Nb_Ligne()-2;
    if (IsComplet(automate) == true ){
        return;
    }
    else {
        Etat *P = creerEtat("P",nb_alphabet);

        ajouter1etat(automate, P);

        for (int i =0; i< nb_alphabet; i++){
            P->listTransitions[i] = creerTransition();
            P->listTransitions[i]->data = P;
        }

        int nbColumn = Nb_Colone() - 2;

        if ((automate != NULL) || (automate->data != NULL)) {

            while ((automate != NULL)) {
                for (int i = 0; i < nbColumn; i++) {
                    int nbTransition = automate->data->listnbTransitions[i];
                    if (nbTransition == 0) {

                       automate->data->listTransitions[i] = *P->listTransitions;
                    }
                }
                automate = automate->next; // parcours liste chaine contenant les états
            }
        }
    }
}