#include <stdio.h>
#include "afficherAutomate.h"
#


int main() {
    listEtat* Automate= creerAutomate("abcd");
    displayAutomate(Automate,"abcd");


    return 0;
}
