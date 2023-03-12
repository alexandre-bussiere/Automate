#include <stdio.h>
#include "afficherAutomate.h"

int main() {
    int nbEtat=3; //calcul le nombre de ligne pour obtenir le nb d'Etat(s)
    char* listLettres="abc";  // alphabet
    Nom listNom[3]={"0","1","2"}; //recup 1er caractère de chaque ligne
    Nom list[3][3][2]=
                    //a                 //b             //c
            {{{"0"},{"1","2"},{}},// recup les colonnes du milieu de chaque ligne
             {{"1"},{"0"},       {"1"}},// pour obtenir un tableau en 3D
             {{"1"},{},             {"0"}},
             };
    Nom*** list2= malloc(3);
    for(int i=0;i<3;i++){
        list2[i]= malloc(3);
        for(int j=0;j<3;j++){
            list2[i][j]=list[i][j];
        }
    }
    listEtat* Automate= creerAutomate(listLettres,nbEtat,listNom,list2);
    displayAutomate(Automate,listLettres);
    return 0;
}
