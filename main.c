#include <stdio.h>
#include "get_from_txt.h"


int main() {
    char* *** tab = take_Everyting_FromTxt();
    int nb_colone = Nb_Colone();
    int nb_ligne = Nb_Ligne();
    printf("printing the values in array: \n\n");
    for (int i = 0; i < nb_colone-1; i++)
    {
        for (int j = 0; j < nb_ligne+1; j++)
        {
            for (int k = 0; k < nb_ligne-1; k++) {
                printf("%s ", tab[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
