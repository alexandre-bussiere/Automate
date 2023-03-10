#include <stdio.h>
#include "get_from_txt.h"


int main() {
    printf("Hello, World!\n");
    char* nom = extract_Name_FormeFromLine(3);
    printf("%s",nom);
    return 0;
}
