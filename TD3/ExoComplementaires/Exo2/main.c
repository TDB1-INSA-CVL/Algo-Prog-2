#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef enum {
    INCISIVE,
    CANINE,
    PREMOLAIRE,
    MOLAIRE,
    ABSENTE
} Type;

typedef enum {
    RESINE,
    BRIDGE,
    COURONNE,
    AUCUN
} Soin;

typedef struct {
    int numero;
    Type type;
    Soin soin;
} Dent;

typedef struct {
    char nom[20];
    char prenom[20];
    Date date_detartrage;
    Dent machoire_basse[16];
    Dent machoire_haute[16];
} Patient;

void saisie_dent(Dent *dent) {
    char c;
    printf("Numero de la dent : ");
    scanf("%i", &dent->numero);
    printf("Type de dent (I/C/P/M/A) : ");
    scanf(" %c", &c);
    switch (c) {
        case 'I':
            dent->type = INCISIVE;
            break;
        case 'C':
            dent->type = CANINE;
            break;
        case 'P':
            dent->type = PREMOLAIRE;
            break;
        case 'M':
            dent->type = MOLAIRE;
            break;
        case 'A':
            dent->type = ABSENTE;
            break;
    }
    printf("Soin sur la dent (R/B/C/A) : ");
    scanf(" %c", &c);
    switch (c) {
        case 'R':
            dent->soin = RESINE;
            break;
        case 'B':
            dent->soin = BRIDGE;
            break;
        case 'C':
            dent->soin = COURONNE;
            break;
        case 'A':
            dent->soin = AUCUN;
            break;

    }
}

void saisie_patient(Patient *patient) {
    Dent dent;
    printf("Entrer le nom et prenom du patient : ");
    scanf("%s %s", patient->nom, patient->prenom);
    printf("Saisir la date du dernier detartrage (JJ MM AAAA) : ");
    scanf("%i %i %i", &patient->date_detartrage.jour, &patient->date_detartrage.mois, &patient->date_detartrage.annee);
    printf("Saisie de la machoire basse : ");
    for (int i = 0; i < 2; ++i) {
        printf("\nDent %i\n", i);
        saisie_dent(&dent);
        patient->machoire_basse[i] = dent;
    }
    printf("Saisie de la machoire haute : ");
    for (int i = 0; i < 2; ++i) {
        printf("\nDent %i\n", i);
        saisie_dent(&dent);
        patient->machoire_haute[i] = dent;
    }
}

int main() {
    Patient patient;
    saisie_patient(&patient);
    return 0;
}
