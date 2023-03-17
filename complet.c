//
// Created by Albane Coiffe on 13/03/2023.
//

#include "complet.h"
#include "structure.h"
#include <stdbool.h>
#include <stdio.h>

bool IsComplet (listEtat automate ) {
    bool complet = true;
    int nbLettre = 3;
    while ((nombre.next != NULL) && (complet != false) ){
        int i =0;
        while ((automate.data->listnbTransitions[i] != 0) &&(i<nbLettre - 1)){
            i++;
        }
        if (automate.data->listnbTransitions[i] != 0){
            complet = false;
        }
    }
    return complet;
}