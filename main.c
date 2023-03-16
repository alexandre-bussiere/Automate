#include <stdio.h>
#include "get_from_txt.h"


int main() {
    printf("Hello, World!\n");
    char* *** tab = take_Everyting_FromTxt();
    int nb_colone = Nb_Colone();
    int nb_ligne = Nb_Ligne();
    printf("printing the values in array: \n");
    for(int i=0;i<nb_ligne;i++)
    {
        for(int j=0;j<nb_colone;j++)
        {
           // for(int k=1;k<=3;k++)
            //{
                printf("%s ",tab[i][j][0]);
             //   if(k==3)
             //   {
             //       printf("\n");
             //   }
        //    }
        }
        printf("\n");
    }
    return 0;
}
