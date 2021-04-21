#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYES 100

typedef char texte[100];

typedef struct {
    int num;
    texte nom_rue;
    int code_postal;
    texte localite;
} Adresse;

typedef enum {
    HOMME, FEMME
} Sexe;

typedef struct {
    texte nom;
    texte prenom;
    Adresse adresse;
    Sexe sexe;
} Employe;

typedef struct {
    int nb_employes;
    Employe employes[MAX_EMPLOYES];
} Societe;

Employe saisir_employe_v1() {
    Employe employe;
    char sexe;


    printf("\nSaisir le nom et prenom de l'employe :");
    scanf("%s %s", employe.nom, employe.prenom);

    do {
        printf("Saisie du sexe de l'employe (H/F) :");
        scanf(" %c", &sexe);
    } while (sexe != 'H' && sexe != 'F');

    if (sexe == 'H') {
        employe.sexe = HOMME;
    } else if (sexe == 'F') {
        employe.sexe = FEMME;
    }

    printf("Saisie de l'adresse de l'employe\nNumero de rue :");
    scanf("%i", &employe.adresse.num);
    printf("Nom de rue :");
    scanf("%s", employe.adresse.nom_rue);
    printf("Code postal :");
    scanf("%i", &employe.adresse.code_postal);
    printf("Localite :");
    scanf("%s", employe.adresse.localite);

    return employe;
}

void saisir_employe_v2(Employe *employe) {
    char sexe;

    printf("\nSaisir le nom et prenom de l'employe :");
    scanf("%s %s", employe->nom, employe->prenom);

    do {
        printf("Saisie du sexe de l'employe (H/F) :");
        scanf(" %c", &sexe);
    } while (sexe != 'H' && sexe != 'F');

    if (sexe == 'H') {
        employe->sexe = HOMME;
    } else if (sexe == 'F') {
        employe->sexe = FEMME;
    }

    printf("Saisie de l'adresse de l'employe\nNumero de rue :");
    scanf("%i", &employe->adresse.num);
    printf("Nom de rue :");
    scanf("%s", employe->adresse.nom_rue);
    printf("Code postal :");
    scanf("%i", &employe->adresse.code_postal);
    printf("Localite :");
    scanf("%s", employe->adresse.localite);
}

void affichage_employe(Employe employe) {
    printf("\nNom : %s %s", employe.nom, employe.prenom);

    if (employe.sexe == HOMME) {
        printf("\nSexe : HOMME");
    } else if (employe.sexe == FEMME) {
        printf("\nSexe : FEMME");
    }

    printf("\nAdresse : %i %s %i %s", employe.adresse.num, employe.adresse.nom_rue, employe.adresse.code_postal,
           employe.adresse.localite);
}

void init_societe(Societe *societe) {
    societe->nb_employes = 0;
}

int ajout_employe(Societe *societe, Employe employe) {
    // Il manque la copie des chaine de caracteres
    if (societe->nb_employes >= 100)
        return -1;

    societe->nb_employes++;
    societe->employes[societe->nb_employes - 1] =
            employe;
    return 0;
}

void affichage_societe(Societe societe) {
    printf("Taille de la société : %i employes", societe.nb_employes);
    for (int i = 0; i < societe.nb_employes; ++i) {
        printf("\nAffichage de l'employe %i :", i);
        affichage_employe(societe.employes[i]);
        printf("\n");
    }
}

int recherche_employe(texte nom, texte prenom, Societe societe) {
    for (int i = 0; i < societe.nb_employes; ++i) {
        if (strcmp(societe.employes[i].nom, nom) == 0 && strcmp(societe.employes[i].prenom, prenom) == 0)
            return i;
    }
    return -1;
}

void recherche_employe_message(texte nom, texte prenom, Societe societe) {
    int result = recherche_employe(nom, prenom, societe);
    if (result != -1)
        affichage_employe(societe.employes[result]);
    else
        printf("Non trouve");
}

void supression_employe(texte nom, texte prenom, Societe *societe) {
    int result = recherche_employe(nom, prenom, *societe);
    if (result != -1) {
        societe->employes[result] = societe->employes[societe->nb_employes - 1];
        societe->nb_employes--;
    }
}

int main() {
    Employe employe;
    Societe societe;
    texte nom, prenom;

    init_societe(&societe);

    employe = saisir_employe_v1();
    ajout_employe(&societe, employe);

    saisir_employe_v2(&employe);
    ajout_employe(&societe, employe);

    printf("\n\n\n\n");
    affichage_societe(societe);

    printf("\n\nEntrez le nom et prenom de l'employé a rechercher : ");
    scanf("%s %s", nom, prenom);
    recherche_employe_message(nom, prenom, societe);

    if (recherche_employe(nom, prenom, societe) != -1) {
        supression_employe(nom, prenom, &societe);
    }

    printf("\n\nSupression de l'employe...\n");
    affichage_societe(societe);
    return 0;
}
