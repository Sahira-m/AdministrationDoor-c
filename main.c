#include <stdio.h>
#include "menu.h"
#include <conio.h>
/*
  printf("Admin menu\n");
    printf("1. Remote open door\n");
    printf("2. List all cards in system\n");
    printf("3. Add remove access\n");
    printf("4. Exit\n");
    printf("9. FAKE TEST SCAN CARD\n");*/
#define REMOTEOPENDOOR 1U
#define LIST_ALL_CARDS 2U
#define CHANGE_ACCESS 3U
#define EXIT_MENU 4U
#define INVALID_CARD 5U
#define ADD_CARD 5U
void main()
{

    MenuPresentation();

    while (1)
    {

        unsigned int selection = 0;
        selection = get();
        // scanf("\t\t %d", &selection);
        printf("Selected option is %d\n", selection);

        switch (selection)
        {
        case REMOTEOPENDOOR:
            printf("CURRENT LAMP IS :GREEN ");
            /*cardDetailsMethod();*/ break;
        case LIST_ALL_CARDS:
            listCardDetails();
            break;
        case CHANGE_ACCESS:
            accessChange();
            /* code */
            break;

        case EXIT_MENU:
            /* code */
            break;
        case INVALID_CARD:
            printf("CURRENT LAMP IS :RED ");
            /* code */
            break;
            /*default:
              continue;*/
        }
    }
    getch();
    // return 0;
}
