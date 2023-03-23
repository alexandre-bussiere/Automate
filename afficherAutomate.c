//
// Created by tmKla on 11/03/2023.
//

#include "afficherAutomate.h"
void displayAutomate(listEtat* Automate, char* listLettres) {
    for (int g =0 ; g< Nb_Colone()-1;g++) {
        printf("-------\t");
    }
    printf("\n");
    int nblettres= strlen(listLettres);
    listEtat * temp=Automate; Transitions *liaisons1;
    printf("Etats\t|");
    for (int i=0; i<nblettres;i++){
        printf("\t%c\t|", listLettres[i]);
    }
    printf("\n");
    for (int g =0 ; g< Nb_Colone()-1;g++) {
        printf("-------\t");
    }
    printf("\n");
    while (temp!=NULL){
        if (temp->data->entree==true && temp->data->sortie==true){
            printf("(E/S)");
        }
        else{
            if (temp->data->entree==true){
                printf("(E)");
            }
            if (temp->data->sortie==true){
                printf("(S)");
            }
        }

        printf("%s\t|\t",temp->data->nom);
        for (int i=0;i<nblettres;i++){
            liaisons1=temp->data->listTransitions[i];
            while (liaisons1!=NULL){
                printf("%s,", liaisons1->data->nom);
                liaisons1=liaisons1->next;
            }
            printf("\t|\t");
        }
        printf("\n");
        for (int g =0 ; g< Nb_Colone()-1;g++) {
            printf("-------\t");
        }
        printf("\n");
        temp=temp->next;
    }

}