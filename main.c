#include <stdio.h>

#include "afficherAutomate.h"
#include "get_from_txt.h"
#include "determine.h"
#include "complet.h"
#include "strandard.h"


int main() {


    listEtat* Automate= creerAutomate("abcd");
    displayAutomate(Automate,"abcd");


    char* *** tab = take_Everyting_FromTxt();
    int nb_colone = Nb_Colone();
    int nb_ligne = Nb_Ligne();
    printf("printing the values in array: \n\n");
    for (int i = 0; i < nb_ligne; i++)
    {
        for (int j = 0; j < nb_colone; j++)
        {
            for (int k = 0; k < nb_ligne-1; k++) {
                printf("%s ", tab[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    free(tab);

    printf("%d\n",Nb_Colone());
    printf("%d\n",Nb_Ligne());
    printf("%s\n", extract_alphabet_FromLine(1));
    printf("%s\n", extract_Name_FromLine(3));

    printf("d:%d\n", isAutomatonDetermine(Automate));
    printf("c:%d\n", IsComplet(Automate));
    printf("s:%d\n", isAutomatStandard(Automate));
    return 0;
}