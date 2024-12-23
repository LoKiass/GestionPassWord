// Programme gestion password V5
// Faire un outils pour le gestion MDP et tous afficher dans le main

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int GestionPasswordAndLogin(char*, int);

int main(void) {
    int x = 0, TaillePassword = 10;
    char TPassword[TaillePassword+1], *Ptab;
    //Code pour le mots de passe
    printf("Mots de passe (aucun reflet de la frappe, Taille Max : 10, Minimum 5 charactere donc 1 maj, 1 min, 1 ponctuation et 1 digit): ");
    x = GestionPasswordAndLogin(TPassword, TaillePassword); // Notre pointeur pointe maintenant le début de l'adresse de notre tableau
    TPassword[x] = 0; // \0 de clôture d'une chaîne de charactère
    printf("\n--> Votre mots de passe est : %s", TPassword); // Verification du mots de passe finale (Sans debugage)
    printf("\n--> Taille du mdp : %d", strlen(TPassword)); // Verification de la taille finale (Sans debugage)

    getch();
    return 0;
}

int GestionPasswordAndLogin(char *Ptab, int TaillePasswordGPAL) {
    int Flagout = 0, MinimumPass = 5, FlagComplex = 0, y = 0, x = 0;
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
    return x;
}
