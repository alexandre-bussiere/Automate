//
// Created by maelwenn on 26/03/2023.
//

#include "complementarisation.h"
#include "determine.h"
#include "complet.h"
#include "afficherAutomate.h"

int complementarisation(listEtat *currentAutomate) {
    if (isAutomatonDetermine(currentAutomate) != 0) { // si pas déterminer, détermination
        determine(currentAutomate);
    }
    if (!IsComplet(currentAutomate)) { // si pas complet, compléter
        Complet(currentAutomate);
    }

    char *listelettre = extract_alphabet_FromLine(0);
    printf("Nous allons complementariser cette automate :\n");
    displayAutomate(currentAutomate, listelettre); // affichage automate déterminer et complet

    Etat *currentEtat = currentAutomate->data;
    listEtat *currentLine = currentAutomate;
    while (currentLine != NULL) {
        currentEtat->sortie = !currentEtat->sortie; // inversement des sorties
        currentLine = currentLine->next; // parcours liste chaine contenant les états
        if (currentLine != NULL) {
            currentEtat = currentLine->data; // aller au prochaine état
        }
    }
    return 0;
}