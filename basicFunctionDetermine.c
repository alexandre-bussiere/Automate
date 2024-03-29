//
// Created by maelwenn on 22/03/23.
//

#include "basicFunctionDetermine.h"

char *copyString(char *s) { // copie une chaine de caractère
    int i;
    char *s2;
    s2 = (char *) malloc(20);

    for (i = 0; s[i] != '\0'; i++) {
        s2[i] = s[i];
    }
    s2[i] = '\0';
    return s2;
}

bool isCharInString(char characterToVerify, char *string) { // regarde si le caractère envoyer est dans la chaine de caractère envoyer
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        if (string[i] == characterToVerify) {
            return true;
        }
    }
    return false;
}

bool areStringTheSame(char *string1, char *string2) { // compare 2 string, but here 120=012
    int length1 = strlen(string1), count = 0;
    if (length1 != strlen(string2)) {
        return false;
    }
    for (int i = 0; i < length1; i++) {
        if (isCharInString(string1[i], string2)) {
            count++;
        }
    }
    if (count == length1) {
        return true;
    }
    return false;
}

Etat *findSimilarEtat(listEtat *currentAutomate, char *nameEtat) { // renvoie l'adresse de l'état avec le nom demander
    listEtat *temp = currentAutomate;
    while ((temp != NULL) && (!areStringTheSame(temp->data->nom, nameEtat))) {
        temp = temp->next;
    }
    if (temp != NULL) {
        return temp->data;
    }
    return NULL;
}

void updateListnbTransitions(Etat *currentEtat) { // met a jour le tableau contenant le nombre de transition pour chaque lettre de l'aphabet
    int nbColumn = Nb_Colone() - 2;
    int count = 0;
    for (int i = 0; i < nbColumn; i++) {
        Transitions *nextLine = currentEtat->listTransitions[i];
        if (nextLine != NULL) {
            do {
                count++;
                if (nextLine != NULL) {
                    nextLine = nextLine->next; // parcours liste chaine contenant les transitions
                }
            } while (nextLine != NULL);
        }
        currentEtat->listnbTransitions[i] = count;
        count = 0;
    }
}

void updateListTransitions(listEtat *currentAutomate) { // met a jour le tableau contenant les transitions pour chaque lettre de l'aphabet
    int nbColumn = Nb_Colone() - 2;
    Etat *currentEtat = currentAutomate->data;
    listEtat *nextLine = currentAutomate;
    Etat *etatToPointTo;
    char *nameCurrentTransition;

    do {
        nextLine = nextLine->next; // parcours liste chaine contenant les états
        for (int i = 0; i < nbColumn; i++) {
            int nbTransition = currentEtat->listnbTransitions[i];
            if (nbTransition != 0) {
                nameCurrentTransition = concatNameTransition(currentEtat->listTransitions[i]);
                etatToPointTo = findSimilarEtat(currentAutomate, nameCurrentTransition);
                currentEtat->listTransitions[i]->data = etatToPointTo;
                currentEtat->listTransitions[i]->next = NULL;
                currentEtat->listnbTransitions[i] = 1;
            }
        }
        if (nextLine != NULL) {
            currentEtat = nextLine->data; // aller au prochaine état
        }
    } while ((nextLine != NULL));
}

Etat *combine2Etat(Etat *firstEtat, Etat *secondEtat) { // combine les 2 états envoyer
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
    if ((firstEtat->entree) && (secondEtat->entree)) {
        newCombineEtat->entree = true;
    }
    if ((firstEtat->sortie) || (secondEtat->sortie)) {
        newCombineEtat->sortie = true;
    }

    return newCombineEtat;
}

Etat *combineEveryEntry(listEtat *automate) { // combine toutes les entrée de l'automate envoyer
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
    combineEntry->entree = true;
    return combineEntry;
}

Etat *combineEveryEtatFromTransitions(Transitions *listCurrentTransitions) {// combine tout les états de la liste de transition envoyer
    Etat *combineEtat = NULL;
    if ((listCurrentTransitions != NULL) || (listCurrentTransitions->data != NULL)) {
        Etat *currentEtat = listCurrentTransitions->data;
        listEtat *nextLine = listCurrentTransitions;
        do {
            nextLine = nextLine->next; // parcours liste chaine contenant les états
            if (combineEtat == NULL) {
                combineEtat = currentEtat;
            } else {
                combineEtat = combine2Etat(combineEtat, currentEtat);
            }

            if (nextLine != NULL) {
                currentEtat = nextLine->data; // aller au prochaine état
            }
        } while (nextLine != NULL);
    }
    return combineEtat;
}

char *concatNameTransition(Transitions *listCurrentTransitions) { // combine le nom de touts les états de la liste de transition envoyer
    char *nameConcat = NULL;
    if ((listCurrentTransitions != NULL) || (listCurrentTransitions->data != NULL)) {
        Etat *currentEtat = listCurrentTransitions->data;
        listEtat *nextLine = listCurrentTransitions;
        do {
            nextLine = nextLine->next; // parcours liste chaine contenant les états
            if (nameConcat == NULL) {
                nameConcat = copyString(currentEtat->nom);
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


void addEtatEndAutomate(listEtat *automate, Etat *etatToAdd) { // ajoute l'état envoyer a la fin de l'automate envoyer
    listEtat *temp = automate;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    Transitions *temp2 = creerTransition();
    temp2->data = etatToAdd;
    temp->next = temp2;
}
