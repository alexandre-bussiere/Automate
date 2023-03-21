//
// Created by tmKla on 11/03/2023.
//

#include "afficherAutomate.h"
void displayAutomate(listEtat* Automate, char* listLettres) {
    int nblettres= strlen(listLettres);
    listEtat * temp=Automate; Transitions *liaisons1;
    printf("Etats\t|");
    for (int i=0; i<nblettres;i++){
        printf("\t%c\t|", listLettres[i]);
    }
    printf("\n");
    printf("----------------------\n");
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
            int j=0;
            while (liaisons1!=NULL){
                printf("%s,", liaisons1->data->nom);
                liaisons1=liaisons1->next;
            }
            printf("\t|\t");
        }
        printf("\n");
        printf("-------\t-------\t-------\t\n");
        temp=temp->next;
    }

}