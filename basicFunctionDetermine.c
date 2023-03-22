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

char *copyString(char *s) {
    int i;
    char *s2;
    s2 = (char *) malloc(20);

    for (i = 0; s[i] != '\0'; i++) {
        s2[i] = s[i];
    }
    s2[i] = '\0';
    return s2;
}

void updateListnbTransitions(Etat *currentEtat) {
    int nbColumn = Nb_Colone() - 2;
    int count = 0;
    for (int i = 0; i < nbColumn; i++) {
        Etat *currentTransition;
        Transitions *nextLine = currentEtat->listTransitions[i];
        do {
            nextLine = nextLine->next; // parcours liste chaine contenant les transitions
            count++;
            if (nextLine != NULL) {
                currentTransition = nextLine->data; // aller au prochaine état
            }
        } while (nextLine != NULL);
        currentEtat->listnbTransitions[i] = count;
        count = 0;
    }
}

Etat *combine2Etat(Etat *firstEtat, Etat *secondEtat) {
    Etat *newCombineEtat;
    int nbColumn = Nb_Colone() - 2;

    //Créé le nom combiner
    char *name;
    name = copyString(firstEtat->nom);
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

Etat *combineEveryEntry(listEtat *automate) {
    Etat *combineEntry = NULL;
    if ((automate != NULL) || (automate->data != NULL)) {
        Etat *currentEtat = automate->data;
        listEtat *nextLine = automate;
        do {
            nextLine = nextLine->next; // parcours liste chaine contenant les états
            if (currentEtat->entree) {
                if (combineEntry == NULL) {
                    combineEntry = currentEtat;
                } else {
                    combineEntry = combine2Etat(combineEntry, currentEtat);
                }
            }
            if (nextLine != NULL) {
                currentEtat = nextLine->data; // aller au prochaine état
            }
        } while (nextLine != NULL);
    }
    return combineEntry;
}


char *concatNameTransition(Transitions *listCurrentTransitions) {
    char *nameConcat = NULL;
    if ((listCurrentTransitions != NULL) || (listCurrentTransitions->data != NULL)) {
        Etat *currentEtat = listCurrentTransitions->data;
        listEtat *nextLine = listCurrentTransitions;
        do {
            nextLine = nextLine->next; // parcours liste chaine contenant les états
            if (nameConcat == NULL) {
                nameConcat = currentEtat->nom;
            } else {
                strcat(nameConcat, currentEtat->nom);
            }

            if (nextLine != NULL) {
                currentEtat = nextLine->data; // aller au prochaine état
            }
        } while (nextLine != NULL);
    }
    return nameConcat;
}