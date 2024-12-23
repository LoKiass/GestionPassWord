// Programme gestion password V3
// Cahier des charges : Print une * lors que la personne à bien introduit un charactere, la suprimmer avec un backspace
// Donner un nombre de charactere minium que le user doit frapper (5)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int x = 0, TaillePassword = 10, Flagout = 0, MinimumPass = 5;
    char TPassword[TaillePassword+1];
    //Code pour le mots de passe
    printf("Mots de passe (aucun reflet de la frappe, Taille Max : 10, min 5): ");
    do {
        TPassword[x] = getch();
            if (TPassword[x] == 13) { // Code Enter afin de sortir de programme
                if (x >= MinimumPass) { //Obliger de le verifier sur cette ligne car obliger dans rentre dans la conditions pour ne pas rentre dans celle du else{..}
                    Flagout = 1;
                }
            }
            else if (TPassword[x] == 9 || TPassword[x]== 27 || TPassword[x] == 32) { // Code ASCII touche spéciale
                TPassword[x] = 0;
            }
            else if (TPassword[x] == 8) { // Gestion de la touche retour
                if(x > 0) { // Si x > 0 pour eviter d'effacer le text derrière
                    printf("\b \b");
                    x--;
                }
            }
            else {
                if(x <= TaillePassword - 1) { // Taille maxium du tableau - 1 en comptant le 0
                    printf("*");
                    x++;
                }
            }
        }while (Flagout != 1);
        TPassword[x] = 0; // \0 de clôture d'une chaîne de charactère
        printf("\n--> Votre mots de passe est : %s", TPassword); // Verification du mots de passe finale (Sans debugage)
        printf("\n--> Taille du mdp : %d", strlen(TPassword)); // Verification de la taille finale (Sans debugage)

    getch();
    return 0;
}
