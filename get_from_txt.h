//
// Created by bussi on 10/03/2023.
//

#ifndef AUTOMATE_GET_FROM_TXT_H
#define AUTOMATE_GET_FROM_TXT_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char**** take_Everyting_FromTxt(void);// -> return toute la ligne n°ligne en forme de tableaux de char*
char* extract_Name_FromLine(int indexLineToExtract); //-> return le nom de la ligne envoyer                         DONE
char* extract_alphabet_FromLine(int indexLineToExtract); //-> return l'alphabet de base de la ligne envoyer         DONE
char* extractLine(int indexLineToExtract); //-> return la ligne envoyer                                             DONE

int Nb_Colone(void); // -> sort le nombre de colone dans le txt                                                     DONE
int Nb_Ligne(void); // -> sort le nombre de ligne dans le txt                                                       DONE


#endif //AUTOMATE_GET_FROM_TXT_H
