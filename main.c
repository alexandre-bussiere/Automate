#include <stdio.h>

#include "afficherAutomate.h"
#include "get_from_txt.h"
#include "determine.h"
#include "complet.h"
#include "strandard.h"


int main() {
    char* listelettre = extract_alphabet_FromLine(0);

    listEtat* Automate= creerAutomate(listelettre);
    displayAutomate(Automate, listelettre);

    printf("c:%d\n", IsComplet(Automate));
    printf("s:%d\n", isAutomatStandard(Automate));
    printf("d:%d\n", isAutomatonDetermine(Automate));

    char tg;
    int nbLettre = Nb_Colone()-2;
    printf("Rentrez un truc\n");
    scanf("%c", &tg);

    while (tg!='q'){
        if(tg=='s'){
            standardiseAutomate(Automate, nbLettre);
            displayAutomate(Automate, listelettre);
        } else if(tg=='d'){
            determine(Automate);
            displayAutomate(Automate, listelettre);
        } else if(tg=='c'){
            Complet(Automate);
            displayAutomate(Automate, listelettre);
        }
        printf("Rentrez un truc\n");
        scanf("%c", &tg);
    }

    return 0;
}