#include <stdio.h>
#include "menu.h"
#include <conio.h>

void main()
{

    MenuPresentation();

    while (1)
    {

        unsigned int selection = 0;
        selection = readOption();

        switch (selection)
        {
        case REMOTEOPENDOOR:
            printf("CURRENT LAMP IS :GREEN ");
            break;
        case LIST_ALL_CARDS:
            listCardDetails();
            break;
        case CHANGE_ACCESS:
            accessChange();
            break;
        case EXIT_MENU:
            // exit(0);
            break;
        case ADD_CARD:

            printf("ADD CARD");
            addCard(5U);
            break;
        case INVALID_CARD:
            printf("CURRENT LAMP IS :RED ");

            break;
        default:
            printf("\n Your choice is not valid. Please choose a valid choice:");
            break;
        }
    }
    getch();
}
