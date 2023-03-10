//
// Created by bussi on 10/03/2023.
//

#include "get_from_txt.h"

char*** take_Everyting_FromTxt(void){

}// -> return toute la ligne n°ligne en forme de tableaux de char*

char* extract_Name_FormeFromLine(int indexLineToExtract){

    char *ligne = (char *) malloc(80 * sizeof(char));
    int i = 0;
    FILE *table = fopen("../table_transition.txt","r");

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

} //-> return le nom de la ligne envoyer

char* extract_alphabet_FromLine(int indexLineToExtract){

    char *ligne = (char *) malloc(80 * sizeof(char));
    int i = 0;
    FILE *table = fopen("../table_transition.txt","r");

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
        ligne[0] = (char) fgetc(table);
        fscanf(table, "%s", ligne);// sort le premier terme
        // printf("\n%s", ligne);
    }
    fclose(table);
    return ligne;

} //-> return l'alphabet de base de la ligne envoyer





char* extractLine(int indexLineToExtract){

    char *ligne = (char *) malloc(10 * sizeof(char));
    char *alphabet = (char *) malloc(200 * sizeof(char));
    int i = 0;
    FILE *table = fopen("../table_transition.txt","r");

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
    ligne[0] = (char) fgetc(table);
    //alphabet = "-";
    while (*ligne != '\n') { // avance jusqu'a la fin de la 1er ligne
        fscanf(table, "%s", ligne);
        strcat (alphabet , ligne);
        ligne[0] = (char) fgetc(table);
        printf("%s", ligne);
    }
    fclose(table);
    return (alphabet);
} //-> return la ligne envoyer





int Nb_Colone(void){

    char *ligne = (char *) malloc(80 * sizeof(char));
    int i = 0;
    FILE *table = fopen("../table_transition.txt","r");

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

} // -> sort le nombre de colone dans le txt
