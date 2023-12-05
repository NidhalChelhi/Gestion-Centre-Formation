#include <stdio.h>
#include <stdlib.h>
#include "bib.h"

int saisirEntier() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n > 0) break;
    }
    return n;
}

DEPARTEMENT *remplissageDepartement(int n) {
    DEPARTEMENT *TABDep;
    printf("\n************************************ REMPLISSAGE PRINCIPALE  ************************************\n");
    TABDep = (DEPARTEMENT *) malloc(n * sizeof(DEPARTEMENT));
    if (!TABDep) exit(-1);
    putchar('\n');
    for (int i = 0; i < n; i++) {
        printf("\n------------------ Saisie de departement num: %d------------------\n", i + 1);
        TABDep[i] = saisieDepartement(i);
    }
    putchar('\n');
    return TABDep;
}

DEPARTEMENT *ajoutDepartement(DEPARTEMENT *TABDep, int n) {
    DEPARTEMENT *TABDep2;
    printf("\n------------------ AJOUT DEPARTEMENT  ------------------\n");
    TABDep2 = (DEPARTEMENT *) realloc(TABDep, (n + 1) * sizeof(DEPARTEMENT));
    if (!TABDep2) exit(-1);
    putchar('\n');
    printf("\n------------------ Saisie de departement num: %d------------------\n", n + 1);
    TABDep2[n] = saisieDepartement(n);
    putchar('\n');
    return TABDep2;
}

DEPARTEMENT saisieDepartement(int k) {
    DEPARTEMENT departement;
    printf("\n donnez code de departement : ");
    scanf("%d", &departement.codeDep);
    printf("\n donnez le nom de departement : ");
    scanf("%s", &departement.nom);
    printf("\n donnez la capacite de departement : ");
    scanf("%d", &departement.capacite);
    printf("\ndonnez les nombres des clients : ");
    scanf("%d", &departement.nbr_client);
    departement.client = (CLIENT *) malloc(departement.nbr_client * sizeof(CLIENT));
    if (!departement.client) exit(-2);
    putchar('\n');
    for (int l = 0; l < departement.nbr_client; l++) //remplissage des clients
    {
        departement.client[l] = saisieClient(l, departement);
    }
    return departement;
}


CLIENT saisieClient(int k, DEPARTEMENT departement) {
    CLIENT client;
    printf("\n------------------ SAISIE du client %d dans le departement %s  ------------------\n",
           k + 1, departement.nom);
    printf("\nDonnez code de client : ");
    scanf("%d", &client.codeClient);
    printf("\nDonnez le nom de client : ");
    scanf("%s", &client.nom);
    printf("\nDonnez l'age de client : ");
    scanf("%d", &client.age);
    printf("\nDonnez le moyenne de client : ");
    scanf("%f", &client.moyenne);
    printf("\nDonnez le nombre de formation de client : ");
    scanf("%d", &client.nbFormations);
    client.formation = (FORMATION *) malloc(client.nbFormations * sizeof(FORMATION));
    if (!client.formation) exit(-3);
    putchar('\n');
    for (int i = 0; i < client.nbFormations; i++) {
        client.formation[i] = saisieFormation(i, client, departement);
    }
    return client;
}


FORMATION saisieFormation(int k, CLIENT client, DEPARTEMENT departement) {
    FORMATION formation;
    printf("\n------------------ SAISIE de la formation %d de client %s dans le departement %s ------------------\n",
           k + 1,
           client.nom, departement.nom);
    printf("\nDonnez le code de formation : ");
    scanf("%d", &formation.codeFormation);
    printf("\nDonnez le nom de formation : ");
    scanf("%s", &formation.nom);
    printf("\nDonnez le prix de formation : ");
    scanf("%f", &formation.prix);
    printf("\nDonnez la note de formation : ");
    scanf("%f", &formation.note);
    return formation;
}


void affichageDepartement(DEPARTEMENT departement) {
    printf("\n------------------ AFFICHAGE du departement %s  ------------------\n",
           departement.nom);
    printf("\nCode Departement: %d\n", departement.codeDep);
    printf("\nNom de Departement: %s\n", departement.nom);
    printf("\nCapacite de Departement: %d\n", departement.capacite);
    printf("\nNombre des clients dans le Departement: %d\n", departement.nbr_client);
    for (int i = 0; i < departement.nbr_client; i++) //affichage des clients
    {
        affichageClient(i, departement.client[i], departement);
    }
    putchar('\n');
}

void affichageClient(int k, CLIENT client, DEPARTEMENT departement) {
    printf("\n------------------ AFFICHAGE du client %d dans le departement %s  ------------------\n",
           k + 1, departement.nom);
    printf("\nCode Client: %d\n", client.codeClient);
    printf("\nNom du Client: %s\n", client.nom);
    printf("\nAge du Client: %d\n", client.age);
    printf("\nMoyenne du Client: %.2f\n", client.moyenne);
    printf("\nNombre de formations du Client: %d\n", client.nbFormations);
    for (int i = 0; i < client.nbFormations; i++) {
        affichageFormation(i, client.formation[i], client, departement);
    }
    putchar('\n');
}

void affichageFormation(int k, FORMATION formation, CLIENT client, DEPARTEMENT departement) {
    printf("\n------------------ AFFICHAGE de la formation %d de client %s dans le departement %s ------------------\n",
           k + 1,
           client.nom, departement.nom);
    printf("\nCode de Formation: %d\n", formation.codeFormation);
    printf("\nNom de Formation: %s\n", formation.nom);
    printf("\nPrix de Formation: %.3f Dt\n", formation.prix);
    printf("\nNote de Formation: %.3f\n", formation.note);
}

