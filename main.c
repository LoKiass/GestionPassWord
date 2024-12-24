// Programme gestion password V6
// Optimisation + Gestion erreur charactere speciale
#include <ctype.h>
#include <stdio.h>
#include <string.h>
void GestionPasswordAndLogin(char*, int);

int main(void) {
    int TaillePassword = 10;
    char TPassword[TaillePassword+1];
    //Code pour le mots de passe
    printf("Mots de passe (aucun reflet de la frappe): ");
    GestionPasswordAndLogin(TPassword, TaillePassword); // Notre pointeur pointe maintenant le début de l'adresse de notre tableau
    printf("\n--> Votre mots de passe est : %s", TPassword); // Verification du mots de passe finale (Sans debugage)
    printf("\n--> Taille du mdp : %d", strlen(TPassword)); // Verification de la taille finale (Sans debugage)

    getch();
    return 0;
}

void GestionPasswordAndLogin(char *Ptab, int TaillePasswordGPAL) {
    int Flagout = 0, MinimumPass = 5, FlagComplex = 0, y = 0, x = 0;
    char ErrMessage[80+1];
    do {
        Ptab[x] = getch();
        if (Ptab[x] == 13) { // Code Enter afin de sortir de programme
            if (x >= MinimumPass) { //Obliger de le verifier sur cette ligne car obliger dans rentre dans la conditions pour ne pas rentre dans celle du else{..}
                for (y = 0; y != x; y++) {
                    if (islower(Ptab[y])) { // Changement de bit : XXX1 (1)
                        FlagComplex |= 1;
                    }
                    else if(isupper(Ptab[y])) { // Changement de bit : XX1X (2)
                        FlagComplex |= 2;
                    }
                    else if(ispunct(Ptab[y])) { // Changement de bit : X1XX (4)
                        FlagComplex |= 4;
                    }
                    else if(isdigit(Ptab[y])) { // Changement de bit : X111 (8)
                        FlagComplex |= 8;
                    }
                }
                if (FlagComplex == 15) { // 8+4+2+1 = 15
                    Flagout = 1;
                }
                else {
                    ErrMessage[0] = 0;
                    strcat(ErrMessage, "  --> Manquant : ");
                    if (!(FlagComplex & 1)) {
                        strcat(ErrMessage, "Min - ");
                    }
                    if (!(FlagComplex & 2)) {
                        strcat(ErrMessage, "Maj - ");
                    }
                    if (!(FlagComplex & 4)) {
                        strcat(ErrMessage, "Punct - ");
                    }
                    if (!(FlagComplex & 8)) {
                        strcat(ErrMessage, "Digit - ");
                    }
                    printf("%s", ErrMessage);
                    getch();
                    for(y = 0; y < strlen(ErrMessage); y++) {
                        printf("\b \b");
                    }

                }
            }
        }
        else if (Ptab[x] == 9 || Ptab[x]== 27 || Ptab[x] == 32) { // Code ASCII touche spéciale
            Ptab[x] = 0;
        }
        else if (Ptab[x] == 8) { // Gestion de la touche retour
            if(x > 0) { // Si x > 0 pour eviter d'effacer le text derrière
                printf("\b \b");
                x--;
            }
        }
        else {
            if(x <= TaillePasswordGPAL - 1) { // Taille maxium du tableau - 1 en comptant le 0
                printf("*");
                x++;
            }
        }
    }while (Flagout != 1);
    Ptab[x] = 0;
}
