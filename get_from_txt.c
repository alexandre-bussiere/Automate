//
// Created by bussi on 10/03/2023.
//

#include "get_from_txt.h"


char**** take_Everyting_FromTxt(void){
    int nb_colonne = Nb_Colone();
    int nb_ligne = Nb_Ligne();
    int nb_etat = nb_ligne - 1;
    int nb_alphabet = nb_colonne -2 ;

    char* *** tab = (char****)malloc(nb_ligne * sizeof(char* **));

    if (tab == NULL)
    {
        printf( "Out of memory");
        exit(0);
    }

    for (int i = 0; i < nb_ligne; i++)
    {
        tab[i] = (char* **)malloc(nb_colonne * sizeof(char* *));

        if (tab[i] == NULL)
        {
            printf( "Out of memory");
            exit(0);
        }

        for (int j = 0; j < nb_colonne; j++)
        {
            tab[i][j] = (char* *)malloc(nb_etat * sizeof(char*));
            if (tab[i][j] == NULL)
            {
                printf( "Out of memory");
                exit(0);
            }
            for (int k = 0; k < nb_etat; k++){
                tab[i][j][k]=(char *) malloc(10 * sizeof(char));
            }
        }
    }
//alocation dinamique des ariable

    for (int j = 0; j < nb_ligne; ++j) {
        for (int n = 0; n < nb_colonne; ++n) {
            for (int y = 0; y < nb_etat; y++) {
                tab[j][n][y]=NULL;
            }
        }
    }//initialise tout a NULL

    char delimiteur[] = " ";

    for(int i=0 ;i<nb_ligne ;i++) {
        char *line = extractLine(i+1);
        char *delim_line = strtok(line, delimiteur);
        int k = 0;
        while (delim_line != NULL) {
            tab[i][k][0] = delim_line;
            //printf("'%s'\n",delim_line);
            delim_line = strtok(NULL, delimiteur);
            k++;
        }
    }


        // place the duplicate variable seperated by a , into a 3d space
    for (int j = 0; j < nb_ligne; ++j) {
        for (int n = 0; n < nb_colonne; ++n) {
            for (int i = 0; i <nb_alphabet +1; ++i) {
                if(tab[j][n][i] != NULL) {
                    int longeur_string = strlen(tab[j][n][i]);

                    for (int lenght = 0; lenght <= (longeur_string) - 1; lenght++) {

                        if (tab[j][n][i][lenght] == ',') {
                            char *separators = ",";
                            char *word = tab[j][n][i];
                            char *new_delim_line = strtok(word, separators);
                            int g = 0;
                            while (new_delim_line != NULL) {
                                tab[j][n][g+i] = new_delim_line;
                                //printf("'%s'\n", new_delim_line);
                                new_delim_line = strtok(NULL, new_delim_line);
                                g++;

                            }
                        }
                    }
                }
            }
        }
    }
    


    return tab;
}// -> return toute la ligne n°ligne en forme de tableaux de char*


char* extract_Name_FromLine(int indexLineToExtract){

    char *ligne = (char *) malloc(80 * sizeof(char));
    if (ligne == NULL)
    {
        printf( "Out of memory");
        exit(0);
    }
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

    int nb_Colone=Nb_Colone();
    char *ligne = (char *) malloc(10 * sizeof(char));

    if (ligne == NULL)
    {
        printf( "Out of memory");
        exit(0);
    }

    char* tab= (char *) malloc(100 * sizeof(char));

    if (tab == NULL)
    {
        printf( "Out of memory");
        exit(0);
    }

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
    //printf("%s \n",ligne);
    //printf("%s \n",tab);
    i = 0;
    *tab= '\0';
    fscanf(table, "%s", ligne); // -> sortie du nom
    while ( i < nb_Colone-2 ){

        fscanf(table, "%s", ligne);
        //printf("%s\n ",ligne);
        i++;
        strcat(tab, ligne);
        strcat(tab, " ");
        //printf("%s\n", tab);
    }
    fclose(table);

    return (tab);

} //-> return l'alphabet de base de la ligne envoyer





char* extractLine(int indexLineToExtract){

    int nb_Colone=Nb_Colone();
    char *ligne = (char *) malloc(10 * sizeof(char));

    if (ligne == NULL)
    {
        printf( "Out of memory");
        exit(0);
    }

    char* tab= (char *) malloc(100 * sizeof(char));

    if (tab == NULL)
    {
        printf( "Out of memory");
        exit(0);
    }

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
    //printf("%s \n",ligne);
    //printf("%s \n",tab);
    i = 0;
    *tab= '\0';
    while ( i < nb_Colone ){

        fscanf(table, "%s", ligne);
        //printf("%s\n ",ligne);
        i++;
        strcat(tab, ligne);
        strcat(tab, " ");
        //printf("%s\n", tab);
    }
    fclose(table);

    return (tab);

} //-> return la ligne envoyer





int Nb_Colone(void){

    char *ligne = (char *) malloc(80 * sizeof(char));

    if (ligne == NULL)
    {
        printf( "Out of memory");
        exit(0);
    }

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

int Nb_Ligne()
{
    FILE *table = fopen("../table_transition.txt","r");
    int count_lines = 0;
    char *ligne = (char *) malloc(80 * sizeof(char));

    if (ligne == NULL)
    {
        printf( "Out of memory");
        exit(0);
    }

    //extract character from file and store in chr
    ligne[0] =(char) fgetc(table);
    while (ligne[0] != EOF)
    {
        //Count whenever new line is encountered
        if (ligne[0] == '\n')
        {
            count_lines ++;
        }
        //take next character from file.
        ligne[0] =(char) fgetc(table);
    }
    fclose(table); //close file.
    count_lines ++; // donne le nombre de ligne exact dans un txt (a enlever si vous vouler le nombre de ligne sans la premiere ligne.
    return count_lines;
}