#include <stdio.h>
#include <stdlib.h>

int main() {

    // *p = *tab = tab[0] = 0
    // *q = *(p + 2) = *(tab + 2) = tab[2] = 2
    printf("\n1. *p=0,*q=2");

    // p = adresse de a
    // q = tab[2]
    // q != p
    printf("\n2. p!=q");

    // p = tab + 2
    // q = tab + 5
    // *p = tab[2] = 2
    // *q = tab[5] = 5
    printf("\n3. *p=2,*q=5");

    // p = &tab[8] - *q = (tab + 8) - 5 = tab + 3
    // q = p = tab + 3
    // p++ = tab + 4
    // *p = 4
    // *q = 3
    printf("\n4. *p=4,*q=3");

    return 0;
}