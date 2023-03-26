//
// Created by maelwenn on 26/03/2023.
//

#include "complementarisation.h"
#include "determine.h"
#include "complet.h"
#include "afficherAutomate.h"

int complementarisation(listEtat *currentAutomate) {
    if (isAutomatonDetermine(currentAutomate) != 0) {
        determine(currentAutomate);
    }
    if (!IsComplet(currentAutomate)) {
        Complet(currentAutomate);
    }

    char *listelettre = extract_alphabet_FromLine(0);
    printf("Nous allons complementariser cette automate :\n");
    displayAutomate(currentAutomate, listelettre);

    Etat *currentEtat = currentAutomate->data;
    listEtat *currentLine = currentAutomate;
    while (currentLine != NULL) {
        currentEtat->sortie = !currentEtat->sortie;

        currentLine = currentLine->next; // parcours liste chaine contenant les états
        if (currentLine != NULL) {
            currentEtat = currentLine->data; // aller au prochaine état
        }
    }

    return 0;
}