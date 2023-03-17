#include <stdio.h>
#include "get_from_txt.h"


int main() {
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
    return 0;
}
