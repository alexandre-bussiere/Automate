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

    Etat *test= combine2Etat(Automate->data, Automate->next->data);
    displayAutomate(Automate,"abcd");
    printf("\n\n\nNew automate:\n");

    listEtat *temp = Automate;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    Transitions *temp2 = creerTransition();
    temp2->data = test;
    temp->next = temp2;
    displayAutomate(Automate,"abcd");

    return 0;
}