#include <stdio.h>
#include <stdlib.h>

int main() {
    //QA
    /*
    int x;
    scanf("%i", &x);
    printf("%i a l'adresse %p", x, &x);
    */

    //QB
    /*
    int x;
    int *px = &x;
    scanf("%i", px);
    printf("%i a l'adresse %p", *px, px);
    */

    //QC
    /*
    int tab[5];
    for (int i = 0; i < 5; ++i) {
        scanf("%i", &tab[i]);
    }
    for (int i = 0; i < 5; ++i) {
        printf("%i a l'adresse %p", tab[i], &tab[i]);
    }
    */

    //QD
    /*
    int tab[10];

    for (int i = 0; i < 10; ++i) {
        scanf("%i", tab + i);
    }
    for (int i = 0; i < 10; ++i) {
        printf("%i a l'adresse %p", *(tab + i), tab + i);
    }
    */

    return 0;
}