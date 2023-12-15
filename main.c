#include <stdio.h>
#include "bib.h"
#include <stdlib.h>
#include <conio.h>

void main() {
    DEPARTEMENT *TABDep;
    int n;
    printf("\nDonnez le nombre de departements: ");
    n = saisirEntier();
    int main_choice;
    int second_choice;
    menu_principale:
    printf("\n************************************ MENU ************************************");
    printf("\n1- Remplissage");
    printf("\n2- Affichage");
    printf("\n3- Traitement1");
    printf("\n4- Traitement2");
    printf("\n5- Traitement3");
    printf("\n6- QUITTER");
    printf("\nDonnez votre choix: ");
    scanf("%d", &main_choice);

    switch (main_choice) {
        case 1:
        menu_remplissage:
            printf("\n************************************ MENU Remplissage ************************************");
            printf("\n1- Remplissage Departement");
            printf("\n2- Ajout Departement");
            printf("\n3- RETOUR");
            printf("\n4- QUITTER");
            printf("\nDonnez votre choix: ");
            scanf("%d", &second_choice);
            switch (second_choice) {
                case 1:
                    TABDep = remplissageDepartement(n);
                    goto menu_remplissage;
                case 2:
                    TABDep = ajoutDepartement(TABDep, n);
                    n+=1;
                    goto menu_remplissage;
                case 3:
                    goto menu_principale;
                case 4:
                    exit(0);
                default:
                    printf("\nchoix invalide\n");
            }
            break;
        case 2:
            printf("\n************************************ Affichage ************************************\n");
            for (int i = 0; i < n; i++) {
                affichageDepartement(*(TABDep+i));
            }
            goto menu_principale;
        case 3:
            printf("\n------------------ AFFICHAGE de la formation la plus chere  ------------------\n");
            affichagefFormationPlusChere(n,TABDep);
            goto menu_principale;
        case 4:
            printf("\n------------------- TRAITEMENT 2: Affichage des bilans des clients -------------------\n");
            affichageBilansClients(n,TABDep);
            goto menu_principale;
        case 5:
            printf("\nTraitement 3 Not Available Yet\n");
            goto menu_principale;
        case 6:
            exit(0);
        default:
            printf("\nchoix invalide\n");
    }

    //    FORMATION *max;
//    int  indice_client = 0, indice_departement = 0, code;
//    float prix_totale = 0, max_moy;

    /*printf("\n************************************ LES TRAITEMENTS ************************************\n");
    putchar('\n');


    printf("\n------------------- TRAITEMENT 1: Affichage de la formation la plus chere -------------------\n");
    putchar('\n');
    max = (TABDep[0].client + 0)->formation;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < TABDep[i].nbr_client; j++) {
            for (int k = 0; k < (TABDep[i].client + j)->nbFormations; k++) {
                if (max->prix < ((TABDep[i].client + j)->formation + k)->prix) {
                    max = ((TABDep[i].client + j)->formation + k);
                }
            }
        }
    }
    printf("\n la formation la plus chere avec le code = %d et de nom : %s \n", max->codeFormation, max->nom);
    putchar('\n');


    printf("\n------------------- TRAITEMENT 2: Affichage des bilans des clients -------------------\n");
    putchar('\n');
    printf("\n ------Voici les bilans des clients------\n");
    putchar('\n');
    for (int i = 0; i < n; i++) {
        printf("\n -----voici les bilants des client de departement %d-----\n", i + 1);
        for (int j = 0; j < TABDep[i].nbr_client; j++) {
            printf("\n------bilan de client %d------\n", j + 1);
            printf("\n le code de client %d est egale a %d \n", j + 1, (TABDep[i].client + j)->codeClient);
            printf("\n le nom de client %d c'est %s \n", j + 1, (TABDep[i].client + j)->nom);
            printf("\n  l'addresse de client %d c'est %s \n", j + 1, (TABDep[i].client + j)->adresse);
            printf("\n  l'age de client %d : %d \n", j + 1, (TABDep[i].client + j)->age);
            printf("\n  la moyenne de client %d est egale a %.3f \n", j + 1, (TABDep[i].client + j)->moyenne);
            printf("\n  le nombre de formation de client %d est egale a %d \n", j + 1,
                   (TABDep[i].client + j)->nbFormations);
            for (int k = 0; k < (TABDep[i].client + j)->nbFormations; k++) {
                prix_totale += ((TABDep[i].client + j)->formation + k)->prix;
            }
            printf("\n le cout totale de ses formation est egale a : %.3f dt", prix_totale);
            prix_totale = 0;
            putchar('\n');
        }
    }
    putchar('\n');



    printf("\n------------------- TRAITEMENT 3: Affichage de meilleur client d'un departement -------------------\n");
    putchar('\n');
    printf("\nDonner le code de departement: ");
    scanf("%d", &code);
    for (int i = 0; i < n; ++i) {
        if (code == TABDep[i].codeDep) {
            max_moy = (TABDep[i].client + 0)->moyenne;
            for (int j = 1; j < TABDep[i].nbr_client; ++j) {
                if (max_moy < (TABDep[i].client + j)->moyenne) {
                    max_moy = (TABDep[i].client + j)->moyenne;
                    indice_client = j;
                    indice_departement = i;
                }
            }
        }

    }
    printf("\nLe meilleur client de departement %d avec le code %d est %s et son propre code est egale à %d",
           indice_departement + 1, code, (TABDep[indice_departement].client + indice_client)->nom,
           (TABDep[indice_departement].client + indice_client)->codeClient);*/

    getch();
}
