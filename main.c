#include <stdio.h>
#include "get_from_txt.h"


int main() {
    printf("Hello, World!\n");
    char* a = extractLine(4);
    printf("%s",a);

    return 0;
}
