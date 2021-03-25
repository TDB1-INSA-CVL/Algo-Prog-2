#include <stdio.h>
#include <stdlib.h>

void saisie1(int *t, int n) {
    int i = 0;
    t = (int *) malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        t[i] = i;
}

int *saisie2(int n) {
    int *t;
    int i = 0;
    t = (int *) malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        t[i] = i;
    return t;
}

void saisie3(int **t, int n) {
    int i = 0;
    *t = (int *) malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        (*t)[i] = i;
}


int main() {
    int size;
    int *tab;

    scanf("%i", &size);
    tab = malloc(size * sizeof(int));

    for (int i = 0; i < size; ++i) {
        scanf("%i", tab + i);
    }

    for (int i = 0; i < size; ++i) {
        printf("%i", *(tab + i));
    }
    free(tab);

    printf("\n\n");

    // Programme 1 Non ok car tab1 n'est pas initalisé
    // int *tab1;
    // saisie1(tab1, 4);

    // Programme 2 OK
    int *tab2 = saisie2(4);
    for (int i = 0; i < 4; ++i) {
        printf("%i", *(tab2 + i));
    }
    free(tab2);

    printf("\n");
    // Programme 3 ok car on passe l'adresse du pointeur et le pointeur est initaliser par la fonction
    int* tab3;
    saisie3(&tab3 , 4);
    for (int i = 0; i < 4; ++i) {
        printf("%i", *(tab3 + i));
    }
    free(tab3);
    
    return 0;
}