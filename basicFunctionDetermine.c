//
// Created by maelwenn on 22/03/23.
//

#include "basicFunctionDetermine.h"

Transitions *concatListTransition(Transitions *t1, Transitions *t2) {
    Transitions *t3 = creerTransition(), *temp, *temp3;
    temp = t1, temp3 = t3;
    if (t2 != NULL) {
        while (temp != NULL) {
            if (findEtatinList(temp->data->nom, t2) == NULL) {
                temp3->data = temp->data;
                temp3->next = creerTransition();
                temp3 = temp3->next;
            }
            temp = temp->next;
        }
        temp3->data = t2->data;
        temp3->next = t2->next;
        return t3;
    }
    return t1;
}

void updateListnbTransitions(Etat *currentEtat) {
    int nbColumn = Nb_Colone() - 2;
    int count = 0;
    for (int i = 0; i < nbColumn; i++) {
        Transitions *nextLine = currentEtat->listTransitions[i];
        do {
            nextLine = nextLine->next; // parcours liste chaine contenant les transitions
            count++;
            if (nextLine != NULL) {
                currentEtat = nextLine->data; // aller au prochaine état
            }
        } while (nextLine != NULL);
        currentEtat->listnbTransitions[i] = count;
        count = 0;
    }
}

Etat *combine2Etat(Etat *firstEtat, Etat *secondEtat) {
    Etat *newCombineEtat = malloc(sizeof(Etat));
    int nbColumn = Nb_Colone() - 2;

    //Créé le nom combiner
    char *name;
    name = firstEtat->nom;;
    strcat(name, secondEtat->nom);

    newCombineEtat = creerEtat(name, nbColumn);

    //Créé la liste des transitions combiner, et la list du nb de transitions
    for (int i = 0; i < nbColumn; i++) {
        newCombineEtat->listTransitions[i] = concatListTransition(firstEtat->listTransitions[i],
                                                                  secondEtat->listTransitions[i]);
    }
    updateListnbTransitions(newCombineEtat);

    //État combiner, entrée/sortie
    if ((firstEtat->entree) || (secondEtat->entree)) {
        newCombineEtat->entree = true;
    }
    if ((firstEtat->sortie) || (secondEtat->sortie)) {
        newCombineEtat->sortie = true;
    }

    return newCombineEtat;
}
