#include <stdio.h>

#include "afficherAutomate.h"
#include "get_from_txt.h"
#include "determine.h"
#include "complet.h"
#include "strandard.h"


int main() {
    listEtat* Automate= creerAutomate("abcd");
    printf("%d", isAutomatStandard(Automate));
    standardiseAutomate(Automate,4);
    printf("%d", isAutomatStandard(Automate));
    displayAutomate(Automate,"abcd");


    printf("c:%d\n", IsComplet(Automate));
    Complet(Automate);
    displayAutomate(Automate,"abcd");
    printf("c:%d\n", IsComplet(Automate));

    printf("c:%d\n", isAutomatonDetermine(Automate));
    (Automate);
    displayAutomate(Automate,"abcd");
    printf("c:%d\n", isAutomatonDetermine(Automate));

    printf("c:%d\n", isAutomatStandard(Automate));
    standardiseAutomate(Automate);
    displayAutomate(Automate,"abcd");
    printf("c:%d\n", isAutomatStandard(Automate));
    return 0;
}    