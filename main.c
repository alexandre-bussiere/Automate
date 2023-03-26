#include <stdio.h>

#include "afficherAutomate.h"
#include "get_from_txt.h"
#include "determine.h"
#include "complet.h"
#include "strandard.h"


int main() {
    listEtat* Automate= creerAutomate();
    displayAutomate(Automate,"a");
    printf("\n");
    standardiseAutomate(Automate);
    displayAutomate(Automate,"a");


    return 0;
}