#include <stdio.h>
#include <stdlib.h>

void triple(float *a) {
    *a = *a * 3;
}

void saisieEntier(char message[], int *a) {
    printf("%s", message);
    scanf("%i", a);
}

void permutation(int *a, int *b, int *c)
{
    int temp = *a;
    *a = *c;
    *c = *b;
    *b = temp;

}

int main() {
    float a = 1;
    int b, c = 1, d = 2, e = 3;

    printf("avant triple : %f\n", a);
    triple(&a);
    printf("apres triple : %f\n", a);

    saisieEntier("Saisir la valeur de b : \n", &b);

    printf("avant permutation c:%i, d:%i, e:%i\n", c, d, e);
    permutation(&c, &d, &e);
    printf("apres permutation c:%i, d:%i, e:%i\n", c, d, e);

    return 0;
}