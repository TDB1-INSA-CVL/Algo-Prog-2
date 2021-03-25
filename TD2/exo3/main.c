#include <stdio.h>
#include <stdlib.h>

int *saisie(int *size) {
    int *tab;

    printf("Combien de notes voulez-vous saisir ?");
    scanf("%i", size);
    tab = malloc(*size * sizeof(int));
    printf("Veuillez saisir %i notes :", *size);
    for (int i = 0; i < *size; ++i) {
        scanf("%i", tab + i);
    }

    return tab;
}

int *insert(int *tab, int *size) {
    int *new_tab;
    *size = *size + 1;
    new_tab = malloc(*size * sizeof(int));
    for (int i = 0; i < *size - 1; ++i) {
        new_tab[i] = tab[i];
    }
    printf("Entrez une valeur :");
    scanf("%i", new_tab + *size - 1);
    free(tab);
    tab = new_tab;
    return tab;
}

int *drop(int *tab, int *size, int ind) {
    int *new_tab, index_passed = 0;
    *size = *size - 1;
    new_tab = malloc(*size * sizeof(int));
    for (int i = 0; i < *size + 1; ++i) {
        if (i == ind)
            index_passed = 1;

        new_tab[i] = tab[i + index_passed];
    }
    free(tab);
    tab = new_tab;
    return tab;
}

int *saisieEntiers(int *size) {
    int value, *tab;
    *size = 1;
    tab = malloc(*size * sizeof(int));
    scanf("%i", tab);
    while (1) {
        scanf("%i", &value);
        if (value == 0)
            break;
        else {
            int *new_tab;
            *size = *size + 1;
            new_tab = malloc(*size * sizeof(int));
            for (int i = 0; i < *size - 1; ++i) {
                new_tab[i] = tab[i];
            }
            new_tab[*size - 1] = value;
            free(tab);
            tab = new_tab;
        }
    }
    return tab;
}

void split(int *tab, int **t1, int **t2, int size, int ind) {
    *t1 = malloc(ind * sizeof(int));
    *t2 = malloc((size - ind) * sizeof(int));

    for (int i = 0; i < ind; ++i) {
        (*t1)[i] = tab[i];
    }

    for (int i = ind; i < size; ++i) {
        (*t2)[i] = tab[i];
    }
}


int main() {
    int size, *tab;

    tab = saisie(&size);
    for (int i = 0; i < size; ++i) {
        printf("%i ", *(tab + i));
    }
    printf("\n");
    tab = insert(tab, &size);
    for (int i = 0; i < size; ++i) {
        printf("%i ", *(tab + i));
    }

    printf("\n");
    tab = drop(tab, &size, 1);
    for (int i = 0; i < size; ++i) {
        printf("%i ", *(tab + i));
    }

    int *tab2, size2;
    printf("\nEntrez des valeurs, 0 pour terminer");
    tab2 = saisieEntiers(&size2);
    for (int i = 0; i < size2; ++i) {
        printf("%i ", *(tab2 + i));
    }

    printf("\n\n\n");

    int *t1, *t2, ind = 3;
    split(tab2, &t1, &t2, size2, ind);
    for (int i = 0; i < ind; ++i) {
        printf("%i ", *(t1 + i));
    }
    printf("\n");
    for (int i = ind; i < size2; ++i) {
        printf("%i ", *(t2 + i));
    }

    return 0;
}