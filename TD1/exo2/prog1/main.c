#include <stdio.h>
#include <stdlib.h>

int main() {
    // p1 = tab+2; => p1 = adresse 2 du tableau
    // valeur1 = 2 - 0 = 2
    // valeur2 = 5 + tab[1] = 6
    printf("valeur1 = 2, valeur2 = 6\n");

    // p1++ = > p1 = tab + 3
    // p1 - tab => tab + 3 - tab => 3
    printf("p1-tab = 3\n");

    // *p1 = 3
    // tab[1] = 1
    // *p1 - tab[1] = 3 - 1 = 2
    printf("*p1-tab[1] = 2\n");

    // p1 = tab + 4 - 1
    // *p1 = 3
    printf("*p1 = 3\n");

    return 0;
}