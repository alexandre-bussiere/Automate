#include <stdio.h>

#include "afficherAutomate.h"
#include "get_from_txt.h"
#include "determine.h"
#include "complet.h"
#include "strandard.h"


int main() {

    listEtat* Automate= creerAutomate("abcd");
    displayAutomate(Automate,"abcd");
    printf("\n");
    standardiseAutomate(Automate);
    displayAutomate(Automate,"abcd");


    return 0;
}