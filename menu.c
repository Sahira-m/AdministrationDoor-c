#include <stdio.h>
#include <dos.h>
#include <time.h>
#include <string.h>
#include <conio.h>
// creating a structure for card
typedef struct
{
    char *cardNumbr;
    char access;

} card;

card cardSystem[] = {

    {"1212",
     1},
    {"1213",
     0

    }};
void listCardDetails()
{

    printf("All cards in System\n");
    char msgAcess[40] = "Access available on";
    char msgNoAcess[40] = "No access ";
    char msg[40];
    char i;

    for (i = 0; i < 2; i++)
    {

        if (cardSystem[i].access == 1)
        {
            strcpy(msg, msgAcess);
        }
        else
        {
            strcpy(msg, msgNoAcess);
        }

        printf("%s %s\n", cardSystem[i].cardNumbr, msg);
    }
    getch();
}

void cardDetailsCheckMethod()
{
}
unsigned int get()
{
    unsigned int option;
    // scanf("%c", &option);
    // return (option);
    printf("\n Enter Your choice");
    // getc(option);
    scanf("%d", &option);
    return option;
}

void MenuPresentation(void)
{

    printf("\t\t***Admin menu ***\n");
    printf("\tEnter your choice \n");
    printf("\t PRESS 1. Remote open door\n");
    printf("\t PRESS 2 List all cards in system\n");
    printf("\t PRESS 3. Add remove access\n");
    printf("\t PRESS 4. Exit\n", ' ');
    printf("\t PRESS 9. FAKE TEST SCAN CARD\n");

    // printf("%10s***********\n");
}

void accessChange(void)
{
    char readCardNumber[4];
    char i;
    char cardfound = 0;
    printf("Enter the card number\n");
    scanf("%s", &readCardNumber);
    for (i = 0; i < 2; i++)
    {
        if (!strcmp(readCardNumber, cardSystem[i].cardNumbr))
        {

            printf("Card found");
            cardfound = 1;
            break;
        }
    }

    if (cardfound == 1)
    {
        printf("Current access is \n");
        printf("Enter one to change access \n");
    }
    else
    {
        printf("Sorry Card Number you have entered is invalid \n");
    }
}