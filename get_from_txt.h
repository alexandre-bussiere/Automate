//
// Created by bussi on 10/03/2023.
//

#ifndef AUTOMATE_GET_FROM_TXT_H
#define AUTOMATE_GET_FROM_TXT_H

char*** take_Everyting_FromTxt(void);// -> return toute la ligne n°ligne en forme de tableaux de char*
char* extractAgreeFormeFromLine(int indexLineToExtract); //-> return la forme fléchis de la ligne envoyer
char* extractBaseFormeFromLine(int indexLineToExtract); //-> return la forme de base de la ligne envoyer
char* extractInformationFromLine(int indexLineToExtract); //-> return les informations de la ligne envoyer


#endif //AUTOMATE_GET_FROM_TXT_H
