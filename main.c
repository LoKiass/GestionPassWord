// Programme gestion password V1.1
// Cahier des charges : Ajout de securité au programme (Gestion des touches spéciale et du backspace)
// +Gestion espace, suprimmer le charactère précedent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int x = 0, TaillePassword = 10, Flagout = 0;
    char TPassword[TaillePassword+1];
    //Code pour le mots de passe
    printf("Mots de passe (aucun reflet de la frappe, Taille Max : 10): ");
    do {
        TPassword[x] = getch();
            if (TPassword[x] == 13) { // Code Enter afin de sortir de programme
                Flagout = 1;
            }
            else if (TPassword[x] == 9 || TPassword[x]== 27 || TPassword[x] == 32) { // Code ASCII touche spéciale
                TPassword[x] = 0;
                x--;
            }
            else if (TPassword[x] == 8) { // Gestion de la touche retour
                if(x > 0) {
                    x--;
                }
            }
            else {
                if(x <= TaillePassword - 1) { // Taille maxium du tableau - 1 en comptant le 0
                    x++;
                }
            }
        }while (Flagout != 1);
        TPassword[x] = 0;
        printf("\n--> Votre mots de passe est : %s", TPassword); // Verification du mots de passe finale (Sans debugage)
        printf("\n--> Taille du mdp : %d", strlen(TPassword)); // Verification de la taille finale (Sans debugage)

    getch();
    return 0;
}
