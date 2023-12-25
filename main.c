#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>
typedef struct horaire {
  int heure;
  int minute;
}
horaire;
typedef struct DATE {
  int JOUR;
  int MOIS;
  int ANNEE;
}
date;
typedef struct Voyageur {
  int IDVOY;
  char NOM[30];
  char PRENOM[30];
  date DATE_DE_NAISSANCE;
  char PASSWORD[30];
}
Voyageur;
int compare(char a[30], char b[30]) {
  int flag = 0, i = 0;
  while (a[i] != '\0' && b[i] != '\0') {
    if (a[i] != b[i]) {
      flag = 1;
      break;
    }
    i++;
  }
  if (flag == 0)
    return 0;
  else
    return 1;
}
int verifierID1(int id_to_check) {

  FILE * file = fopen("reservations.txt", "r");
  if (file == NULL) {
    printf("Erreur lors de l'ouverture du fichier");
    exit(1);
  }
  int id;
  int nom, prenom, jour;
  char des[50];
  char mois[30], annee[30];
  while (fscanf(file, "%d %d/%d/%d %s:%s %s", & id, & nom, & prenom, & jour, & mois, & annee, des) != EOF) {
    if (id == id_to_check) {
      fclose(file);
      return 1;
    }
  }
  fclose(file);
  return 0;
}
int verifierID(int id_to_check) {
  FILE * file = fopen("compt voy.txt", "r");
  if (file == NULL) {
    printf("Erreur lors de l'ouverture du fichier");
    exit(1);
  }
  int id;
  char nom[50], prenom[50], password[50];
  int jour, mois, annee;
  while (fscanf(file, "%d %s %s %d/%d/%d %s", & id, & nom, & prenom, & jour, & mois, & annee, & password) != EOF) {
    if (id == id_to_check) {
      fclose(file);
      return 1;
    }
  }
  fclose(file);
  return 0;
}
void creecompt() {
  Voyageur v;
  FILE * f = fopen("compt voy.txt", "w");
  if (f == NULL) {
    printf("Erreur lors de l'ouverture du fichier");
    exit(1);
  }
  printf("Merci d'entrer votre nom :");
  scanf("%s", & v.NOM);
  printf("Merci d'entrer votre prenom :");
  scanf("%s", & v.PRENOM);
  do {
    printf("Merci d'entrer votre date de naissance (JJ MM AAAA) :");
    scanf("%d%d%d", & v.DATE_DE_NAISSANCE.JOUR, & v.DATE_DE_NAISSANCE.MOIS, & v.DATE_DE_NAISSANCE.ANNEE);
  }
  while ((v.DATE_DE_NAISSANCE.JOUR < 0 || v.DATE_DE_NAISSANCE.JOUR > 31 || v.DATE_DE_NAISSANCE.MOIS < 0 || v.DATE_DE_NAISSANCE.MOIS > 12 || v.DATE_DE_NAISSANCE.ANNEE > 9999) || ((v.DATE_DE_NAISSANCE.MOIS == 2) && v.DATE_DE_NAISSANCE.JOUR > 28));

  printf("Votre Mot De Passe:");
  scanf("%s", & v.PASSWORD);
  do {
    printf("votre CIN (8 chiffre) : ");
    scanf("%d", & v.IDVOY);
    if (verifierID(v.IDVOY) == 1) printf("cin exsite deja, vous etes deja inscrit\n");
  }
  while (verifierID(v.IDVOY) == 1);
  fprintf(f, "%d %s %s %d/%d/%d %s \n", v.IDVOY, v.NOM, v.PRENOM, v.DATE_DE_NAISSANCE.JOUR, v.DATE_DE_NAISSANCE.MOIS, v.DATE_DE_NAISSANCE.ANNEE, v.PASSWORD);
  fclose(f);
  application();
}
int reserver() {
  char destinations[24][30] = {
        "Alkassrine", "Ariana", "Banzart", "Beja", "benarous", "Elkef", "Gabes", "Gafsa",
        "Jendouba", "Kairouan", "Mahdia", "Medenine", "Monastir", "Nabul", "kbili","sfax", "SidiBouzid",
        "Silyanah", "Sousse", "Tataouine", "Touzer", "Tunis", "Zaghwan"};
    char str[30];
    date d;
    int x, c;
    horaire h;
    do {
            printf("Votre CIN ici : ");
            scanf("%d", &x);
    }while (verifierID(x)==0 || verifierID1(x)==1);
    printf("erreur ici ; ");
    FILE *f = fopen("reservations.txt", "a");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(1);
    }
 printf("\t\t\t\t ___________________________________________________________________________ \n");
  printf("\t\t\t\t| 1 : Alkassrine           | 11 : Mahdia            | 17 : Sidi Bouzid      |\n");
  printf("\t\t\t\t| 2 : Ariana               | 12 : Medenine          | 18 : Silyanah         |\n");
  printf("\t\t\t\t| 3 : Banzart              | 13 : Monastir          | 19 : Sousse           |\n");
  printf("\t\t\t\t| 4 : Beja                 | 14 : Nabeul            | 20 : Tataouine        |\n");
  printf("\t\t\t\t| 5 : Ben arous            | 15 : kbili             | 21 : Touzer           |\n");
  printf("\t\t\t\t| 6 : El Kef               | 16 : sfax              | 22 : Tunis            |\n");
  printf("\t\t\t\t| 7 : Gabes                                         | 23 : Zaghwan          |\n");
  printf("\t\t\t\t| 8 : Gafsa                                         | 24 : Tous             |\n");
  printf("\t\t\t\t| 9 : Jendouba                                      | 0  : Retour           |\n");
  printf("\t\t\t\t| 10: Kairouan                                                              |\n");
  printf("\t\t\t\t ______________________________________________________________________________\n");
  printf("\n");
  int c1;
  do {
    printf("Merci de choisir votre commande : ");
    scanf("%d", & c1);
  } while (c1 < 0 || c1 > 23);
  do {
    printf("La date de reservation(JJ MM AAAA):");
    scanf("%d %d %d", & d.JOUR, & d.MOIS, & d.ANNEE);
  }
  while ((d.JOUR < 0 || d.JOUR > 31 || d.MOIS < 0 || d.MOIS > 12 || d.ANNEE != 2024));
  printf("\t\t\t\t _________________________________________________ \n");
  printf("\t\t\t\t|        ------choiser l'heure de depart ------   | \n");
  printf("\t\t\t\t| 1 : 8H                                          | \n");
  printf("\t\t\t\t| 2 : 12H                                         | \n");
  printf("\t\t\t\t| 3 : 17 H                                        | \n");
  printf("\t\t\t\t| 0 : retour  .                                   | \n");
  printf("\t\t\t\t|_________________________________________________| \n");
  printf("\n");
  do {
    printf("Merci de choisir votre commande : ");
    scanf("%d", & c);
  }
  while (c < 0 || c > 3);
  switch (c) {
  case 1:
    h.heure = 8;
    h.minute = 0;
    break;
  case 2:
    h.heure = 12;
    h.minute = 0;
    break;
  case 3:
    h.heure = 17;
    h.minute = 0;
    break;
  case 0:
    application();
    break;
  }
  fprintf(f, "%d %d/%d/%d %d:%d0 %s \n", x, d.JOUR, d.MOIS, d.ANNEE, h.heure, h.minute, destinations[c1 - 1]);
  fclose(f);
  printf("operation de reservation effectuee avec succes");
  application();}
void tous() {

  FILE * f = fopen("bus.txt", "r");
  if (f == NULL) {
    printf("erreur !\n");
    exit(1);
  }

  int hour;
  char destination[30];
  float price;
  char currency[4];

  while (fscanf(f, "%d:%*d %s %f %s", & hour, destination, & price, currency) == 4) {
    printf("%02d:00 - Destination: %s - Prix de ticket: %.2f %s\n", hour, destination, price, currency);
  }
  fclose(f);
  return 0;
}
void detailsbus() {
  printf("\t\t\t\t ___________________________________________________________________________ \n");
  printf("\t\t\t\t| 1 : Alkassrine           | 11 : Mahdia            | 17 : Sidi Bouzid      |\n");
  printf("\t\t\t\t| 2 : Ariana               | 12 : Medenine          | 18 : Silyanah         |\n");
  printf("\t\t\t\t| 3 : Banzart              | 13 : Monastir          | 19 : Sousse           |\n");
  printf("\t\t\t\t| 4 : Beja                 | 14 : Nabeul            | 20 : Tataouine        |\n");
  printf("\t\t\t\t| 5 : Ben arous            | 15 : kbili             | 21 : Touzer           |\n");
  printf("\t\t\t\t| 6 : El Kef               | 16 : sfax              | 22 : Tunis            |\n");
  printf("\t\t\t\t| 7 : Gabes                                         | 23 : Zaghwan          |\n");
  printf("\t\t\t\t| 8 : Gafsa                                         | 24 : Tous             |\n");
  printf("\t\t\t\t| 9 : Jendouba                                      | 0  : Retour           |\n");
  printf("\t\t\t\t| 10: Kairouan                                                              |\n");
  printf("\t\t\t\t ______________________________________________________________________________\n");
  printf("\n");
  int c;
  do {
    printf("Merci de choisir votre commande : ");
    scanf("%d", & c);
  } while (c < 0 || c > 24);
   char destinations[24][30] = {
        "Alkassrine", "Ariana", "Banzart", "Beja", "benarous", "Elkef", "Gabes", "Gafsa",
        "Jendouba", "Kairouan", "Mahdia", "Medenine", "Monastir", "Nabul", "kbili", "SidiBouzid",
        "Silyanah", "Sousse", "Tataouine", "Touzer", "Tunis", "Zaghwan"};
  FILE * f = fopen("bus.txt", "r");
  if (f == NULL) {
    printf("Erreur lors de l'ouverture du fichier");
    exit(1);
  }
  if (c >= 1 && c < 23) {
    printf("Les bus disponibles pour %s sont :\n", destinations[c - 1]);

    FILE * f = fopen("bus.txt", "r");
    if (f == NULL) {
      printf("Erreur lors de l'ouverture du fichier");
      exit(1);
    }
    char hour[30];
    char price[30];
    char destination[30];
    char currency[30];
    while (fscanf(f, "%s %s %s %s", hour, destination, price, currency) == 4) {
      if (compare(destination, destinations[c - 1]) == 0) {
        printf("%s - Destination: %s - Prix de ticket : %s %s\n", hour, destination, price, currency);
      }
    }
    fclose(f);

  } else if (c == 0) {
    application();
    return 1;
  } else if (c == 24) {
    tous();
    application();
  } else {
    exit(1);
  }
  application();
}

void supp(int deleteID) {
    char deleteIDString[9];
    snprintf(deleteIDString, sizeof(deleteIDString), "%08d", deleteID);
    FILE *file = fopen("reservations.txt", "r");
    if (file == NULL) {
        printf("Cannot open file %s\n", "reservations.txt");
        exit(1);
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Cannot create temporary file\n");
        fclose(file);
        exit(1);
    }

    char line[1000];
    char id[9];

    while (fgets(line, sizeof(line), file) != NULL) {
        strncpy(id, line, 8);

    }
        if (strcmp(id, deleteIDString) != 0) {
            fputs(line, tempFile);

    }

    fclose(file);
    fclose(tempFile);

    if (remove("reservation.txt") != 0) {
        printf("Error deleting the file\n");
        exit(1);
    }

    if (rename("temp.txt", "reservations.txt") != 0) {
        printf("Error renaming the file\n");
        exit(1);
    }
printf("Annulation effectue avec succee");
application();
}
void modifdes(int modifyID) {
  printf("votre nouvelle destination est: \n");
      printf("\t\t\t\t ___________________________________________________________________________ \n");
  printf("\t\t\t\t| 1 : Alkassrine           | 11 : Mahdia            | 17 : Sidi Bouzid      |\n");
  printf("\t\t\t\t| 2 : Ariana               | 12 : Medenine          | 18 : Silyanah         |\n");
  printf("\t\t\t\t| 3 : Banzart              | 13 : Monastir          | 19 : Sousse           |\n");
  printf("\t\t\t\t| 4 : Beja                 | 14 : Nabeul            | 20 : Tataouine        |\n");
  printf("\t\t\t\t| 5 : Ben arous            | 15 : kbili             | 21 : Touzer           |\n");
  printf("\t\t\t\t| 6 : El Kef               | 16 : sfax              | 22 : Tunis            |\n");
  printf("\t\t\t\t| 7 : Gabes                                         | 23 : Zaghwan          |\n");
  printf("\t\t\t\t| 8 : Gafsa                                         | 24 : Tous             |\n");
  printf("\t\t\t\t| 9 : Jendouba                                      | 0  : Retour           |\n");
  printf("\t\t\t\t| 10: Kairouan                                                              |\n");
  printf("\t\t\t\t ______________________________________________________________________________\n");
  printf("\n");
  int c;
  do {
    printf("Merci de choisir votre commande : ");
    scanf("%d", & c);
  } while (c < 0 || c > 24);
   char destinations[24][30] = {
        "Alkassrine", "Ariana", "Banzart", "Beja", "benarous", "Elkef", "Gabes", "Gafsa",
        "Jendouba", "Kairouan", "Mahdia", "Medenine", "Monastir", "Nabul", "kbili","sfax", "SidiBouzid",
        "Silyanah", "Sousse", "Tataouine", "Touzer", "Tunis", "Zaghwan"};
    char modifyIDString[9];
    snprintf(modifyIDString, sizeof(modifyIDString), "%08d", modifyID);

    FILE *file = fopen("reservations.txt", "r");
    if (file == NULL) {
        printf("Cannot open file %s\n", "reservations.txt");
        exit(1);
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Cannot create temporary file\n");
        fclose(file);
        exit(1);
    }

    char line[1000];
    char id[9];
    char date[20];
    char time[10];
    char destination[50];

    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%8s %19s %8s %[^\n]", id, date, time, destination);

        if (compare(id, modifyIDString) == 0) {
            strncpy(destination, destinations[c-1], sizeof(destination));
            fprintf(tempFile, "%s %s %s %s\n", id, date, time, destinations[c-1]);
        } else {

            fputs(line, tempFile);
        }
    }
    fclose(file);
    fclose(tempFile);
    if (remove("reservations.txt") != 0) {
        printf("Erreur lors de la suppression du fichier\n");
        exit(1);
    }
    if (rename("temp.txt", "reservations.txt") != 0) {
        printf("Erreur lors du renommage du fichier temporaire\n");
        exit(1);
    }
printf("modification effecue avec succee \n")  ;
application();
}
void modifheure(int modifyID) {
  printf("Heure de reservation est: \n");
  printf("\t\t\t\t ________________________________________________________________________\n");
  printf("\t\t\t\t| 1 : 8H           | 11 : 12H            | 17 : 17H                       |\n");
  printf("\t\t\t\t|                                                                         |\n");
  printf("\t\t\t\t|_________________________________________________________________________ \n");
  printf("\n");
  int c;
  do {
    printf("Merci de choisir votre commande : ");
    scanf("%d", & c);
  } while (c < 0 || c > 24);
   char heure[24][30] = {"08:00","12:00","17:00"};
    char modifyIDString[9];
    snprintf(modifyIDString, sizeof(modifyIDString), "%08d", modifyID);

    FILE *file = fopen("reservations.txt", "r");
    if (file == NULL) {
        printf("Cannot open file %s\n", "reservations.txt");
        exit(1);
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Cannot create temporary file\n");
        fclose(file);
        exit(1);
    }

    char line[1000];
    char id[9];
    char date[20];
    char time[10];
    char destination[50];

    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%8s %19s %8s %[^\n]", id, date, time, destination);

        if (compare(id, modifyIDString) == 0) {
            strncpy(time, heure[c-1], sizeof(time));
            fprintf(tempFile, "%s %s %s %s\n", id, date, time, destination);
        } else {

            fputs(line, tempFile);
        }
    }
    fclose(file);
    fclose(tempFile);
    if (remove("reservations.txt") != 0) {
        printf("Erreur lors de la suppression du fichier\n");
        exit(1);
    }
    if (rename("temp.txt", "reservations.txt") != 0) {
        printf("Erreur lors du renommage du fichier temporaire\n");
        exit(1);
    }
printf("modification effecue avec succee \n")  ;
application();
}
void modifdate(int modifyID) {

     date d;
      do {
    printf("La Nouvelle date de reservation(JJ MM AAAA):");
    scanf("%d %d %d", & d.JOUR, & d.MOIS, & d.ANNEE);
  }
  while ((d.JOUR < 0 || d.JOUR > 31 || d.MOIS < 0 || d.MOIS > 12 || d.ANNEE != 2024));
    char modifyIDString[9];
    char modifyIDdate[100];
    snprintf(modifyIDString, sizeof(modifyIDString), "%08d", modifyID);
     snprintf(modifyIDdate, sizeof(modifyIDString), "%d/%d/%d", d.JOUR,d.MOIS,d.ANNEE);
    FILE *file = fopen("reservation.txt", "r");
    if (file == NULL) {
        printf("Cannot open file %s\n", "reservations.txt");
        exit(1);
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Cannot create temporary file\n");
        fclose(file);
        exit(1);
    }
    char line[1000];
    char id[9];
    char date[20];
    char time[10];
    char destination[50];
    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%8s %19s %8s %[^\n]", id, date, time, destination);
        if (compare(id, modifyIDString) == 0) {
            strncpy(date, modifyIDdate, sizeof(date));
            fprintf(tempFile, "%s %s %s %s\n", id, date, time, destination);
        } else {

            fputs(line, tempFile);
        }
    }
    fclose(file);
    fclose(tempFile);
    if (remove("reservations.txt") != 0) {
        printf("Erreur lors de la suppression du fichier\n");
        exit(1);
    }
    if (rename("temp.txt", "reservations.txt") != 0) {
        printf("Erreur lors du renommage du fichier temporaire\n");
        exit(1);
    }
printf("modification effecue avec succee \n")  ;
application();
}
void modifier(int y) {
  int x;
  if (y==0){
  do {
    printf("Votre CIN ici : ");
    scanf("%d", & x);
    if (verifierID1(x) == 0) {
      printf("Aucune reservation sous ce N°CIN \n");
      application();
    }
  }while (verifierID1(x) == 0) ;}
    printf("\t\t\t\t _________________________________________________ \n");
  printf("\t\t\t\t|       ----modifier une reservation ----         | \n");
  printf("\t\t\t\t| 1 : annuler votre reservation                   | \n");
  printf("\t\t\t\t| 2 : modifier la date de reservation             | \n");
  printf("\t\t\t\t| 3 : modifier l'heure de reservation             | \n");
  printf("\t\t\t\t| 4 : modifier la destination                     | \n");
  printf("\t\t\t\t| 0 : retour.                                     | \n");
  printf("\t\t\t\t|_________________________________________________| \n");
  printf("\n");
  int c;
  do {
    printf("Merci de choisir votre commande : ");
    scanf("%d", & c);
  } while (c < 0 || c > 4);
  switch (c) {
  case 1:
    if (y==0) supp(x);
    else supp(y);
    break;
   case 2:
        if (y==0) modifdate(x);
        else modifdate(y);
        break ;
  case 3:
    if (y==0) modifheure(x);
    else modifheure(y);
    break;
  case 4:
    if (y==0)   modifdes(x);
    else   modifdes(y);
    break;
  case 0:
    application();
    break;}
}

void application() {
  printf("\t\t\t\t _________________________________________________ \n");
  printf("\t\t\t\t|        ----Bienvenue Sur E-Bus Manouba ----     | \n");
  printf("\t\t\t\t| 1 : creer un compt voyageur                     | \n");
  printf("\t\t\t\t| 2 : cree une nouvelle reservation               | \n");
  printf("\t\t\t\t| 3 : afficher les details des bus                | \n");
  printf("\t\t\t\t| 4 : modifier les details d'une reservation      | \n");
  printf("\t\t\t\t| 0 : Quitter.                                    | \n");
  printf("\t\t\t\t|_________________________________________________| \n");
  printf("\n");
  int c;
  do {
    printf("Merci de choisir votre commande : ");
    scanf("%d", & c);
  } while (c < 0 || c > 4);
  commande(c);
}
int main() {
  application();
}
void commande(int x) {
  switch (x) {
  case 1:
    creecompt();
    break;
  case 2:
    reserver();
    break;
  case 3:
    detailsbus();
    break;
  case 4:
    modifier(0);
  case 0:
    exit(1);
  }
}
