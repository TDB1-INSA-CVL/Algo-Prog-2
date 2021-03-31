#include <stdio.h>

int main() {
    int x1, x2, x3, *p1 = &x1, *p2 = &x2, *p3 = &x3;

    for (int i = 0; i < 2; ++i) {
        printf("Donnez 3 valeurs entieres\n");
        scanf("%i %i %i", &x1, &x2, &x3);
        printf("x1 : %p | %i\nx2 : %p | %i\nx3 : %p | %i\n", &x1, x1, &x2, x2, &x3, x3);
    }

    for (int i = 0; i < 2; ++i) {
        printf("Donnez 3 valeurs entieres\n");
        scanf("%i %i %i", &x1, &x2, &x3);
        printf("x1 : %p | %i\nx2 : %p | %i\nx3 : %p | %i\n", p1, *p1, p2, *p2, p3, *p3);
    }

    // On remerque que l'adresse memoire des variables ne change pas.


    return 0;
}