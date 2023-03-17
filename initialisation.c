//
// Created by tmKla on 10/03/2023.
//

#include "initialisation.h"
Transitions *creerTransition() {
    Transitions *NewList = malloc(sizeof(Transitions));
    NewList->data = NULL;
    NewList->next = NULL;
    return NewList;
}
listEtat *creerListEtat(){
    return creerTransition();
}

Etat *creerEtat(char *nom, int nblettre) {
    Etat *NewEtat = malloc(sizeof(Etat));
    NewEtat->nom = nom;
    NewEtat->listTransitions = malloc(sizeof (Transitions));
    NewEtat->listnbTransitions= malloc(nblettre * sizeof (int));
    for (int i=0;i<nblettre;i++){
        NewEtat->listTransitions[i]= NULL;
        NewEtat->listnbTransitions[i]=0;
    }
    NewEtat->entree=NewEtat->sortie=false;
    return NewEtat;
}

void ajouterTransition(Etat* EtatX, Etat * EtatLie, int num) {
    Transitions *NewList = creerTransition(), *temp=EtatX->listTransitions[num];
    NewList->data = EtatLie;
    EtatX->listnbTransitions[num]++;
    if (temp== NULL) {
        temp=EtatX->listTransitions[num]= creerTransition();
        *temp = *NewList;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = NewList;

}
listEtat* ajouterEtat(listEtat* Automate,int nbEtat, int nblettre) {
    listEtat* temp=Automate;
    for (int i=0; i<nbEtat;i++){
        char* nom= extract_Name_FromLine(2+i);
        temp->data= creerEtat(nom,nblettre);
        if (i<nbEtat-1){
            temp->next= creerListEtat();
        }
        temp=temp->next;
    }
    return Automate;
}