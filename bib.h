struct formation {
    int codeFormation;
    char nom[50];
    float prix;
    float note;
};
typedef struct formation FORMATION;


struct client {
    int codeClient;
    char nom[50];
    int age;
    int nbFormations;
    FORMATION *formation;
    float moyenne;
};
typedef struct client CLIENT;


struct departement {
    int codeDep;
    char nom[50];
    int capacite;
    int nbr_client;
    CLIENT *client;
};
typedef struct departement DEPARTEMENT;

int saisirEntier();

DEPARTEMENT *remplissageDepartement(int n);


DEPARTEMENT saisieDepartement(int k);

CLIENT saisieClient(int k, DEPARTEMENT departement);

FORMATION saisieFormation(int k, CLIENT client, DEPARTEMENT departement);

void affichageDepartement(DEPARTEMENT departement);

void affichageClient(int k, CLIENT client, DEPARTEMENT departement);

void affichageFormation(int k, FORMATION formation, CLIENT client, DEPARTEMENT departement);
void affichagefFormationPlusChere(int n,DEPARTEMENT* departement);
void affichageBilansClients(int n,DEPARTEMENT *departement);

DEPARTEMENT *ajoutDepartement(DEPARTEMENT *TABDep, int n);

