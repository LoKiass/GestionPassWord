// Programme gestion password V1
// Cahier des charges : La frappe de l'utilisateur ne doit pas ce refleter sr l'ecran, un utilisateur doit rentrer
// un mots de passe à la fois sans aucune contrainte mais aussi sans aucune securité de frappe, stocker le mdp
// dans un tableau et ensuite le reaffichier à la fin
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int x, TaillePassword = 20, Flagout = 0;
    char TPassword[TaillePassword+1];
    //Mode d'emploie
    printf("Mode d'emploi :\n\t --> Enter : Valide votre mots de passe");
    getch();
    system("cls");

    //Code pour le mots de passe
    printf("Mots de passe (aucun reflet de la frappe): ");
    for(x=0; Flagout != 1; x++) {
        TPassword[x] = getch();
        if (TPassword[x] == 13) { // Code Enter afin de sortir de programme
            Flagout = 1;
        }
    }
    printf("\n--> Votre mots de passe est : %s", TPassword);
    getch();

}
