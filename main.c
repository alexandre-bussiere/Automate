#include <stdio.h>

#include "afficherAutomate.h"
#include "get_from_txt.h"
#include "startFunction.h"


int main() {
    char* listelettre = extract_alphabet_FromLine(0);

    listEtat* automate= creerAutomate(listelettre);

    printf("Voici l'automate actuel :\n");
    displayAutomate(automate, listelettre);

    printf("\n");

    determineAnAutomate(automate);
    standardAnAutomate(automate);
    completAnAutomate(automate);

    printMenu();
    char choix = choixUtilisateur();
    int  nbLettre = Nb_Colone() - 2;
    while (choix!=lastNb){
        switch (choix) {
            case '1':
                Complet(automate);
                printf("\nVoici l'automate completer :\n");
                break;
            case '2':
                standardiseAutomate(automate, nbLettre);
                printf("\nVoici l'automate standartiser :\n");
                break;
            case '3':
                determine(automate);
                printf("\nVoici l'automate determiner :\n");
                break;
            case '4':
                determine(automate);
                Complet(automate);
                printf("\nVoici l'automate équivalent deterministe et complet :\n");
                break;
            default:
                printf("\nJ'ai pas compris, et comment t'es arriver la !!\n");
        }
        displayAutomate(automate, listelettre);
        printMenu();
        choix = choixUtilisateur();
    }
    return 0;
}