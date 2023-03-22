#include <stdio.h>

#include "afficherAutomate.h"
#include "get_from_txt.h"
#include "determine.h"
#include "complet.h"
#include "strandard.h"


int main() {
    listEtat* Automate= creerAutomate("abcd");
    displayAutomate(Automate,"abcd");

    printf("%d\n",Nb_Colone());
    printf("%d\n",Nb_Ligne());
    printf("%s\n", extract_alphabet_FromLine(1));
    printf("%s\n", extract_Name_FromLine(3));

    printf("\nd:%d\n", isAutomatonDetermine(Automate));
    printf("c:%d\n", IsComplet(Automate));
    printf("s:%d\n", isAutomatStandard(Automate));

    Etat *test= combineEveryEntry(Automate);
    displayAutomate(Automate,"abcd");
    printf("\n\n\n");

    addEtatEndAutomate(Automate, test);
    displayAutomate(Automate,"abcd");

    listEtat *endOfAutomate = Automate;
    while (endOfAutomate->next!=NULL){
        endOfAutomate=endOfAutomate->next;
    }
    test = combineEveryEtatFromTransitions(endOfAutomate->data->listTransitions[1]);
    addEtatEndAutomate(Automate, test);
    displayAutomate(Automate,"abcd");
    return 0;
}