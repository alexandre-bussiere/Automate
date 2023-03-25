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
        listEtat *nextLine = automaton;
        do {
            nextLine = nextLine->next; // parcours liste chaine contenant les états
            // compter le nb d'entrée
            if (currentEtat->entree) {
                countEntry++;
                adresseEntree = currentEtat;
            }
            if (nextLine != NULL) {
                currentEtat = nextLine->data; // aller au prochaine état
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


listEtat *findEntree(listEtat *Automate) {
    listEtat *listEntree = creerListEtat(), *temp = Automate, *temp2 = listEntree;
    while (temp != NULL) {
        if (temp->data->entree == true) {
            if (temp2->next!=NULL){
                temp2=temp2->next;
            }
            temp2->data = temp->data;
            temp2->next = creerListEtat();
        }
        temp = temp->next;
    }
    temp2->next=NULL;
    return listEntree;
}

void standardiseAutomate(listEtat *Automate, int nblettre) {
    if (isAutomatStandard(Automate)==true){
        printf("L'automate est deja standard.\n");
        return;
    }
    Etat *I = creerEtat("I", nblettre);
    listEtat *listEntree = findEntree(Automate), *temp = listEntree;
    I->sortie=false;
    I->entree=true;
    while (temp != NULL) {
        for (int i = 0; i < nblettre; i++) {
            I->listTransitions[i] = concatListTransition(I->listTransitions[i], temp->data->listTransitions[i]);
            I->listnbTransitions[i] += temp->data->listnbTransitions[i];
        }
        temp->data->entree=false;
        if (temp->data->sortie==true){
            I->sortie=true;
        }
        temp = temp->next;
    }
    listEtat* EtatStandart=creerListEtat();
    EtatStandart->data=I;
    EtatStandart->next=creerListEtat();
    EtatStandart->next->data=Automate->data;
    EtatStandart->next->next=Automate->next;
    *Automate=*EtatStandart;
}