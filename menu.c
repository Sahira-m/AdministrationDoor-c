#include <stdio.h>
#include <dos.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "menu.h"

// static int functionLastIndex(unsigned int);
typedef struct
{
    int cardNumber;
    int access;
    char dates[20];

} Card;
unsigned int readOption()
{
    unsigned int option;
    printf("\t \t Enter Your choice    :");
    scanf("%d", &option);
    return option;
}

int functionLastIndex(unsigned int choice)
{
    int lastIndexStored;
    FILE *filesRead;
    int ch;
    FILE *filewrite;
    filesRead = fopen("Max.txt", "r");
    if (NULL == filesRead)
    {
        lastIndexStored = 0;
        printf(" index in 1:%d", lastIndexStored);
    }
    else
    {
        ch = getw(filesRead);
        if (choice == 5)
        {
            lastIndexStored = ch + 1;
        }
        else
        {
            lastIndexStored = ch;
        }
    }
    fclose(filesRead);
    filewrite = fopen("Max.txt", "w");
    putw(lastIndexStored, filewrite);
    fclose(filewrite);

    return lastIndexStored;
}

void listCardDetails()
{
    Card card[1000];
    int index;
    FILE *cardReads;
    fopen_s(&cardReads, "data.bin", "rb");
    char accesString[3];
    printf(" \n All cards in System");
    char msgAcess[40] = "Access available on";
    char msgNoAcess[40] = "No access ";
    char msg[40];
    if (cardReads == NULL)
    {
        index = 0;
    }
    else
    {
        index = functionLastIndex(0);
    }
    for (int i = 0; i < index; i++)
    {

        if (card[i].access == 1)
        {
            strcpy(msg, msgAcess);
        }
        else
        {
            strcpy(msg, msgNoAcess);
        }
    }

    int j = 0;

    if (cardReads == NULL)
    {
        printf("File is Empty");
    }
    else
    {
        for (int i = 0; i <= index; i++)
        {
            fread(&card[i], sizeof(Card), 1, cardReads);
            card[i].access ? strcpy(accesString, "Yes") : strcpy(accesString, "No");
            printf("\n Card Number:%d  Date: %s   Access:%s", card[i].cardNumber, card[i].dates, accesString);
        }
        fclose(cardReads);
    }
    getch();
}

void MenuPresentation(void)
{

    printf("\t\t \t\t*** ADMIN MENU ***\n");
    printf("\t\t\tEnter your choice \n");
    printf("\t\t PRESS 1. REMOTE OPEN DOOR\n");
    printf("\t\t PRESS 2 LIST ALL CARDS IN SYSTEM\n");
    printf("\t\t PRESS 3. ADD or REMOVE ACCESS\n");
    printf("\t\t PRESS 4. EXIT\n");
    printf("\t\t PRESS 5. ADD CARDS \n", ' ');
    printf("\t\t PRESS 9. FAKE TEST SCAN CARD\n");
}

void accessChange(void)
{
    Card card[1000];
    unsigned int readCardNumber;
    int index = functionLastIndex(0U);
    int access, changeAcces, indexValue;
    FILE *cardReads;
    fopen_s(&cardReads, "data.bin", "rb");
    char cardfound = 0;
    printf("Enter the card number\n");
    scanf("%d", &readCardNumber);

    for (int i = 0; i < index; i++)
    {
        fread(&card[i], sizeof(Card), 1, cardReads);
        if (readCardNumber == card[i].cardNumber)
        {
            printf("Card found");
            cardfound = 1;
            access = card[i].access;
            indexValue = i;
            break;
        }
    }

    if (cardfound == 1)
    {
        printf("\n Current access is %d", access);
        printf("Enter one to change access \n");
        scanf("%d", &changeAcces);
        FILE *input = fopen("data.bin", "ab");
        card[indexValue].access = 1;
        fwrite(&card, sizeof(Card), 1, input);
    }
    else
    {
        printf("Sorry Card Number you have entered is invalid \n");
    }
}
char CheckifCardexist(unsigned int readCardNumber)
{
    FILE *cardReads;
    Card card[1000];
    int i = 0;
    char cardnumberUpdatestatus = 0;
    int index = functionLastIndex(0);
    fopen_s(&cardReads, "data.bin", "rb");
    if (cardReads == NULL)
    {

        cardnumberUpdatestatus = 0;
    }
    while (i <= index)
    {
        fread(&card[i], sizeof(Card), 1, cardReads);
        if (card[i].cardNumber == readCardNumber)
        {
            printf("Card Number exist\n");
            cardnumberUpdatestatus = 1;
            break;
        }
        else
        {
            cardnumberUpdatestatus = 0;
            break;
        }

        i++;
    }
    fclose(cardReads);
    printf(" fun ret status%d", cardnumberUpdatestatus);
    return cardnumberUpdatestatus;
}

void addCard(unsigned int choice)
{
    int index = functionLastIndex(choice);
    printf("Last index is:%d", index);
    int result, i = 0;
    Card card;
    unsigned int readCardNumber;
    char cardnumberUpdatestatus = 0;
    printf("Enter Card number 0-9999\n");
    scanf("%d", &readCardNumber);
    result = CheckifCardexist(readCardNumber);
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    card.cardNumber = readCardNumber;
    card.access = 1;
    strcpy(card.dates, asctime(tm));
    FILE *input = fopen("data.bin", "ab");
    printf(" result :%d ", result);
    if (result = 0)
    {
        printf("\n The card number already exist");
    }
    else
    {
        fwrite(&card, sizeof(Card), 1, input);
    }
    fclose(input);
    i++;
}
