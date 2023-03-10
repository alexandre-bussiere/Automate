#include <stdio.h>
#include "get_from_txt.h"


int main() {
    printf("Hello, World!\n");
    char* nom = extract_alphabet_FromLine(3);
    //printf("%s",nom);
    //int i = Nb_Colone();
    nom = extract_alphabet_FromLine(3);
    printf("%s",nom);


    return 0;
}
