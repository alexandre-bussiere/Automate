#include <stdio.h>

#include "afficherAutomate.h"
#include "get_from_txt.h"
#include "determine.h"
#include "complet.h"
#include "strandard.h"


int main() {
    //resoudre se systeme de merde
    char* listelettre = extract_alphabet_FromLine(0);

    listEtat* Automate= creerAutomate(listelettre);

    printf("c:%d\n", IsComplet(Automate));
    Complet(Automate);
    displayAutomate(Automate,listelettre);
    printf("c:%d\n", IsComplet(Automate));

    listEtat* Automate1= creerAutomate(listelettre);

    printf("c:%d\n", isAutomatonDetermine(Automate1));
    determine(Automate1);
    displayAutomate(Automate1,listelettre);
    printf("c:%d\n", isAutomatonDetermine(Automate1));

    listEtat* Automate2= creerAutomate(listelettre);

    printf("c:%d\n", isAutomatStandard(Automate2));
    standardiseAutomate(Automate2,Nb_Colone()-2);
    displayAutomate(Automate2,listelettre);
    printf("c:%d\n", isAutomatStandard(Automate2));
    return 0;
}