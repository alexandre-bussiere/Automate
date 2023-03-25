//
// Created by maelwenn on 25/03/2023.
//

#include "startFunction.h"

void printMenu() {
    printf("\nQue voulez-vous faire ?\n");
    printf("\t1-Completer l'automate\n");
    printf("\t2-Standartiser l'automate\n");
    printf("\t3-Determiniser l'automate\n");
    printf("\t4-Determiniser et completer l'automate\n");
    printf("\t5-Quitter\n");
}

char choixUtilisateur() {
    char choix;
    scanf("%c", &choix);
    while ((choix < '1') || (choix > lastNb)) {
        scanf("%c", &choix);
    }
    return choix;
}


int completAnAutomate(listEtat *automate) {
    bool result = IsComplet(automate);
    if (result) {
        printf("L'automate est complet.\n");
    } else {
        printf("L'automate n'est pas complet.\n");
    }
    return 0;
}

int determineAnAutomate(listEtat *automate) {
    int result = isAutomatonDetermine(automate);
    if (result==0) {
        printf("L'automate est determiner.\n");
    } else {
        printf("L'automate n'est pas determiner, ");
        if(result==1){
            printf("car il a plus d'une entree.\n");
        } else if(result==2){
            printf("car il a plus d'une flèches libellées du même caractère sortant du même état.\n");
        }
    }
    return 0;
}

int standardAnAutomate(listEtat *automate) {
    bool result = isAutomatStandard(automate);
    if (result) {
        printf("L'automate est standard.\n");
    } else {
        printf("L'automate n'est pas standard.\n");
    }
    return 0;
}