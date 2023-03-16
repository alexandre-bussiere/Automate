#include <stdio.h>
#include "afficherAutomate.h"
#


int main() {
    char* listLettres="abc";
    listEtat* Automate= creerAutomate(listLettres);
    displayAutomate(Automate,listLettres);


    return 0;
}
