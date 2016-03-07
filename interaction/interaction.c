#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
//Attention il faut compilet avec l'option -lncurses
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char c, t[10];
	int i;

	//pour ncurses
	initscr();

        printw("--------\n");
	printw("| MENU |\n");
	printw("--------\n");
	printw("\n\n");
        printw("Choix A\n");
        printw("Choix B\n");
        printw("\n");
        printw("Quitter Q\n");
        printw("\n\n");
	printw("Votre choix ? ");

	// pour voir les printw à cause de ncurses
	refresh();

	c='\0';
	while (c != 'Q')
	{
		c=getch();
                move(14,0);
                printw("                                                        ");
                move(14,0);
                // On efface les eventuelles trace de la ligne suivante

		switch (c)
		{
			case 'A' :
				printw("Vous avez choisi l'option A\n");
				break;
                        case 'B' :
				printw("Vous avez choisi l'option B\n");
                                break;
                        case 'Q' :
                                break;
                        default  :
				printw("Cette option n'existe pas :(\n");
				break;
		}
		// Repositionnement du curseur juste derriere "Votre choix ? "
		// Le coin supérieur gauche à comme coordonnées 0,0 (ligne,colonne)
		move(11,14);
	}	

	printw("\nA bientôt !\n");
	refresh();
	//delay de 2 secondes (exprimé en microsecondes) - sinon il y a simplement sleep
	usleep(2000000);

        //pour restaurer la console normale
        endwin();
	
	return 0;
}
