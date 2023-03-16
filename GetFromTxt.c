//
// Created by tmKla on 16/03/2023.
//

#include "GetFromTxt.h"
int Nb_Colone(void) {

    char *ligne = (char *) malloc(80 * sizeof(char));
    int i = 0;
    FILE *table = fopen("../table_transition.txt", "r");

    if (table == NULL) {
        printf("Error fichier introuvable");
        return 0;
    }

    while (*ligne != '\n') { // avance jusqu'a la fin de la 1er ligne
        fscanf(table, "%s", ligne);
        ligne[0] = (char) fgetc(table);
        //printf("%s", ligne);
        i++;
    }
    ligne[0] = (char) fgetc(table);
    fclose(table);
    return i;

}

char *extract_alphabet_FromLine(int indexLineToExtract) {

    int nb_Colone = Nb_Colone();
    char *ligne = (char *) malloc(10 * sizeof(char));
    char *tab = (char *) malloc(100 * sizeof(char));
    int i = 0;
    FILE *table = fopen("../table_transition.txt", "r");

    if (table == NULL) {
        printf("Error fichier introuvable");
        return " ";
    }

    while (i < indexLineToExtract - 1) { // avance jusqu'a la ligne indexLineToExtract
        ligne[0] = (char) fgetc(table);
        //printf("%s", ligne);
        if (*ligne == '\n') {
            i++;
        }
    }
    //printf("%s \n",ligne);
    //printf("%s \n",tab);
    i = 0;
    *tab = '\0';
    fscanf(table, "%s", ligne); // -> sortie du nom
    while (i < nb_Colone - 2) {

        fscanf(table, "%s", ligne);
        //printf("%s\n ",ligne);
        i++;
        strcat(tab, ligne);
        strcat(tab, " ");
        //printf("%s\n", tab);
    }
    fclose(table);

    return (tab);

}

char *extract_Name_FromLine(int indexLineToExtract) {

    char *ligne = (char *) malloc(80 * sizeof(char));
    int i = 0;
    FILE *table = fopen("../table_transition.txt", "r");

    if (table == NULL) {
        printf("Error fichier introuvable");
        return " ";
    }

    while (i < indexLineToExtract - 1) { // avance jusqu'a la ligne indexLineToExtract
        ligne[0] = (char) fgetc(table);
        // printf("%s", ligne);
        if (*ligne == '\n') {
            i++;
        }
        fscanf(table, "%s", ligne);// sort le premier terme
        // printf("\n%s", ligne);
    }
    fclose(table);
    return ligne;

}

char ***getListLiaison(int indexLine, int nblettre) {
    char ***list = malloc(nblettre);
    char *ligne;
    ligne = extract_alphabet_FromLine(indexLine);
    int size = strlen(ligne);
    char Ligne[size], *listliaison[nblettre];
    strcpy(Ligne, ligne);
    listliaison[0] = strtok(Ligne, " ");
    for (int i = 1; i < nblettre; i++) {
        listliaison[i] = strtok(NULL, " ");
    }
    for (int i = 0; i < nblettre; i++) {
        size = strlen(listliaison[i]);
        list[i] = malloc(size);
        char *Noms;
        Noms = strtok(listliaison[i], ",");
        int j = 0;
        while (Noms != NULL) {
            list[i][j] = malloc(strlen(Noms));
            strcpy(list[i][j], Noms);
            j++;
            Noms = strtok(NULL, ",");

        }
        list[i][j] = NULL;
    }
    return list;
}