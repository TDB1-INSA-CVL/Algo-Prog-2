#include <stdio.h>
#include <stdlib.h>


int *saisie_polynome() {
    int *tab, i, size;

    printf("\nDegre du polynome :");
    scanf("%i", &size);
    size += 1;

    tab = malloc(size * sizeof(int));

    *tab = size;
    for (i = 0; i < size; ++i) {
        printf("Coefficient x^%i :", i);
        scanf("%i", tab + i + 1);
    }
    return tab;
}

void affichage_polynome(int *tab) {
    int i;
    printf("%i*x^%i", *(tab + *tab), *tab - 1);
    for (i = *tab - 1; i >= 1; --i) {
        printf(" + %i*x^%i", *(tab + i), i - 1);
    }
}

int *difference_polynome(int *poly_1, int *poly_2) {
    int i, *diff_poly, *poly_3, *tab_1, size_small, size_big;
    if (*poly_1 < *poly_2) {
        tab_1 = poly_1;
        size_big = *poly_2;
        size_small = *poly_1;
    } else {
        tab_1 = poly_2;
        size_big = *poly_1;
        size_small = *poly_2;
    }

    poly_3 = malloc(size_big * sizeof(int));
    *poly_3 = size_big;
    for (i = 1; i < size_small + 1; ++i) {
        *(poly_3 + i) = *(tab_1 + i);
    }
    for (i = size_small + 1; i <= size_big + 1; ++i) {
        *(poly_3 + i) = 0;
    }

    diff_poly = malloc(size_big * sizeof(int));
    *diff_poly = size_big;
    if (tab_1 == poly_1) {
        for (i = 1; i <= size_big; ++i) {
            *(diff_poly + i) = *(poly_3 + i) - *(poly_2 + i);
        }
    } else {
        for (i = 1; i <= size_big; ++i) {
            *(diff_poly + i) = *(poly_1 + i) - *(poly_3 + i);
        }
    }

    free(poly_3);
    return diff_poly;
}

int calcul_horner(int x, int *poly) {
    int i, result = *(poly + *poly) * x + *(poly + *poly - 1);

    for (i = *poly - 2; i > 0; --i) {
        result = result * x + *(poly + i);
    }
    return result;
}

int est_racine(int x, int *poly) {
    return calcul_horner(x, poly) == 0;
}

int main() {
    int *poly_1, *poly_2, *poly_3, x;

    poly_1 = saisie_polynome();
    printf("\n");
    affichage_polynome(poly_1);

    printf("\n");

    poly_2 = saisie_polynome();
    printf("\n");
    affichage_polynome(poly_2);

    printf("\n\n");
    poly_3 = difference_polynome(poly_1, poly_2);
    affichage_polynome(poly_3);;
    

    printf("\n\n");

    printf("x :");
    scanf("%i", &x);
    printf("%i\n", calcul_horner(x, poly_1));

    printf("racine du polynome :");
    scanf("%i", &x);
    printf("%i", est_racine(x, poly_1));

    return 0;
}
