//
// Created by bussi on 10/03/2023.
//

#ifndef AUTOMATE_GET_FROM_TXT_H
#define AUTOMATE_GET_FROM_TXT_H

#include "stdio.h"
#include "stdlib.h"

char*** take_Everyting_FromTxt(void);// -> return toute la ligne n°ligne en forme de tableaux de char*
char* extract_Name_FormeFromLine(int indexLineToExtract); //-> return le nom de la ligne envoyer
char* extract_alphabet_FromLine(int indexLineToExtract); //-> return l'alphabet de base de la ligne envoyer
char** extractLine(int indexLineToExtract); //-> return la ligne envoyer


#endif //AUTOMATE_GET_FROM_TXT_H
