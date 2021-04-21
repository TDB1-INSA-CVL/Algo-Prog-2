#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
    APPLE,
    PC,
    WORKSTATION
} Type;

typedef struct {
    unsigned long long numero;
    Type type;
    char microprocesseur[20];
    int freq;
    int ram;
    int disque_space;
} Ordinateur;


typedef struct {
    char nom[3];
    Ordinateur *ordinateur;
    int nbre_ordinateur;
    int etage;
} Salle;

void affichage_salles(Salle salles[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%s (etage %i) : %i ordinateurs\n", salles[i].nom, salles[i].etage, salles[i].nbre_ordinateur);
        for (int j = 0; j < salles[i].nbre_ordinateur; ++j) {

            printf(" - Numero : %llu (", salles[i].ordinateur[j].numero);
            switch (salles[i].ordinateur[j].type) {
                case APPLE:
                    printf("APPLE");
                    break;
                case PC:
                    printf("PC");
                    break;
                case WORKSTATION:
                    printf("WORKSTATION");
                    break;
            }
            printf(") => Proc : %s\t\tFreq : %i\t\tRAM : %i\t\tEspace disque : %i\n",
                   salles[i].ordinateur[j].microprocesseur,
                   salles[i].ordinateur[j].freq,
                   salles[i].ordinateur[j].ram,
                   salles[i].ordinateur[j].disque_space);
        }
    }
}

int main() {
    Salle salles[100], salle1, salle2;
    Ordinateur ordinateur1, ordinateur2, ordinateur3;

    ordinateur1.type = APPLE;
    ordinateur1.disque_space = 100;
    ordinateur1.freq = 1000;
    strcpy(ordinateur1.microprocesseur, "This one");
    ordinateur1.numero = 1;
    ordinateur1.ram = 128;

    salle1.ordinateur = malloc(sizeof(Ordinateur) * 1);
    salle1.ordinateur[0] = ordinateur1;
    salle1.nbre_ordinateur = 1;
    strcpy(salle1.nom, "H01");
    salle1.etage = 2;

    salles[0] = salle1;

    ordinateur2.type = PC;
    ordinateur2.disque_space = 200;
    ordinateur2.freq = 2000;
    strcpy(ordinateur2.microprocesseur, "Another one");
    ordinateur2.numero = 2;
    ordinateur2.ram = 1284;

    ordinateur3.type = WORKSTATION;
    ordinateur3.disque_space = 300;
    ordinateur3.freq = 3000;
    strcpy(ordinateur3.microprocesseur, "Last one");
    ordinateur3.numero = 3;
    ordinateur3.ram = 84;

    salle2.ordinateur = malloc(sizeof(Ordinateur) * 2);
    salle2.ordinateur[0] = ordinateur2;
    salle2.ordinateur[1] = ordinateur3;
    salle2.nbre_ordinateur = 2;
    strcpy(salle2.nom, "H02");
    salle2.etage = 3;

    salles[1] = salle2;

    affichage_salles(salles, 2);
    return 0;
}
