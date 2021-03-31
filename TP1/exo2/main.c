#include <stdio.h>

void min_maj(char *c) {
    if (*c >= 'a' && *c <= 'z')
        *c = *c + 'A' - 'a';
    else if (*c >= 'A' && *c <= 'Z')
        *c = *c + 'a' - 'A';
    printf("Dans min_maj : %p | %c\n", c, *c);
}

int main() {
    char c;
    printf("Saisissez un caractere.\n");
    c = getchar();
    printf("Avant min_maj : %p | %c\n", &c, c);
    min_maj(&c);
    printf("Apres min_maj : %p | %c\n", &c, c);
    printf("Le nouveau caractere est : %c.\n", c);
    return 0;
}


// 1 La fonction min_maj ne retourne pas / ne modifie pas la valeur de c
// 2 On remarque que c est modifier correctement dans la fonction min_maj mais qu'il est stocké dans une autre adresse memoire
// 3 Avec le pointeur, l'adresse memoire de c est la meme dans main et dans min_maj