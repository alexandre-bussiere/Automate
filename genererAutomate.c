//
// Created by tmKla on 10/03/2023.
//

#include "genererAutomate.h"
int lenlist(char** ch){
    int i=0;
    if (ch[i]==NULL){
        return 0;
    }
    while (ch[i][0]>='0' && ch[i][0]<='9'){
        i++;
        if (ch[i]==NULL){
            return i;
        }
    }
    return i;
}
void isEntreeSortie(Etat* EtatX,char*** ligne,int nbcolonne){
    char* data=ligne[nbcolonne-1][0];
    if (data[0]=='E'){
        EtatX->entree=true;
        if (data[1]=='S'){
            EtatX->sortie=true;
        }
    }
    if (data[0]=='S'){
        EtatX->sortie=true;
    }
}
bool isSameWord(char *mot1, char *mot2) {
    int taille = strlen(mot1);
    if (taille != strlen(mot2)) {
        return false;
    }
    int i = 0;
    while (i < taille - 1 && mot1[i] == mot2[i]) {
        i++;
    }
    return mot1[i] == mot2[i];
}

Etat* findEtatinList(Nom nom,   listEtat* listEtatpres) {
    listEtat* temp=listEtatpres;
    while (temp!=NULL && !isSameWord(temp->data->nom,nom)){
        temp=temp->next;
    }
    return temp->data;
}


Etat *creerchemin(Etat *EtatX, listEtat* listEtatspres, char *listLetrres, Nom** listnomtransition) {
    int nblettre = strlen(listLetrres),nbtransition;
    int listnbtrnasition [nblettre];
    Etat *EtatLie;
    for (int i = 0; i < nblettre; i++) {
        nbtransition= lenlist(listnomtransition[i+1]);
        listnbtrnasition[i]=nbtransition;
    }
    for (int i=0; i<nblettre+1;i++){
        int taille=listnbtrnasition[i];
        for (int j=0;j<taille;j++){
            EtatLie= findEtatinList(listnomtransition[i+1][j], listEtatspres);
            ajouterTransition(EtatX, EtatLie, i);
        }
    }
    return EtatX;

}

listEtat* creerAutomate(char *listLettres){
    int nbEtat=Nb_Ligne()-1,nblettre=Nb_Colone()-2;

    listEtat* Automate= creerListEtat(),*temp;
    ajouterEtat(Automate,nbEtat, strlen(listLettres));
    temp=Automate;
    char**** listNomTransition=take_Everyting_FromTxt();
    int i=1;
    while (temp!=NULL){
        isEntreeSortie(temp->data,listNomTransition[i],nblettre+2);
        temp->data= creerchemin(temp->data,Automate,listLettres,listNomTransition[i]);
        temp=temp->next;
        i++;
    }
    return Automate;

}