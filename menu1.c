#include <stdio.h>
#include <time.h>
#include "menu1.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
static void list(void);
struct Card
{
    unsigned int cardNumber;
    unsigned int access;
    char *dates;
    struct Card *next;
};
struct Card *head = NULL;
struct Card *current = NULL;

char isrecordEmpty()
{
    return head == NULL;
}
unsigned int readOption()
{
    unsigned int option;
    printf("\t \t \n  Enter Your choice    :");
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
        if (choice == ADD_CARD)
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

int myeof(FILE *f)
{
    int c;
    c = fgetc(f);
    if (c == EOF)
        return 1;
    ungetc(c, f);
    return 0;
}
void listCardDetails()
{
    FILE *pfile = fopen("record.txt", "r");
    struct Card *temp = malloc(sizeof(struct Card));
    fseek(pfile, SEEK_SET, 0);
    int count = 0;

    fflush(pfile);

    if (pfile != NULL)
    {

        while (!myeof(pfile))
        {
            count++;
            temp->dates = (char *)malloc(100);
            fscanf(pfile, "%d  %d %25[^\n]", &temp->cardNumber, &temp->access, temp->dates);

            printf("%d  %d %s\n", temp->cardNumber, temp->access, temp->dates);
        }
    }
    fclose(pfile);
}
void MenuPresentation(void)
{

    printf("\t\t \t\t*** ADMIN MENU ***\n");
    printf("\t\t\tEnter your choice \n");
    printf("\t\t PRESS 1. REMOTE OPEN DOOR\n");
    printf("\t\t PRESS 2 LIST ALL CARDS IN SYSTEM\n");
    printf("\t\t PRESS 3. ADD CARDS\n");
    printf("\t\t PRESS 4. EXIT\n");
    printf("\t\t PRESS 9. FAKE TEST SCAN CARD");
}
void pushCard(int new_data, char *dates, unsigned int access)
{

    struct Card *current = head;
    printf("%s", dates);
    if (current == NULL)
    {
        current = (struct Card *)malloc(sizeof(struct Card));
        if (current == NULL)
        {
            printf("Memory Allocation failed");
        }
        current->cardNumber = new_data;
        current->dates = (char *)malloc(20);
        strcpy(current->dates, dates);
        current->access = access;
        current->next = NULL;
        printf(" Added first element");
        head = current;
        FILE *input = fopen("record.txt", "a");
        fprintf(input, "%d  %d %s ", current->cardNumber, current->access, current->dates);
        fclose(input);
        printf("/n Your enterde card number added to file Succefully");
    }
    else
    {

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = (struct Card *)malloc(sizeof(struct Card));

        current->next->cardNumber = new_data;
        current->next->dates = (char *)malloc(20);
        strcpy(current->next->dates, dates);
        current->next->access = access;

        current->next->next = NULL;
        FILE *input = fopen("record.txt", "a");
        printf("test %d %s %d ", current->next->cardNumber, current->next->dates, current->next->access);
        fprintf(input, "%d  %d %s ", current->next->cardNumber, current->next->access, current->next->dates);
        fclose(input);
        printf("\n Your enterde card number added to file Succefully");
    }
}

void list()
{
    struct Card *current = head;
    char empty;
    printf(" Inside Print list `\n");
    if (current == NULL)
        printf(" Empty Record `\n");
    while (current != NULL)
    {
        printf("%d\t", current->cardNumber);

        if (current->access)
        {
            printf("ACCESS AVAILABLE ON ");
        }
        else
        {
            printf("ACCESS  NOT AVAILABLE ON");
        }
        printf("%s", current->dates);
        printf("\n");
        current = current->next;
    }
}

void addCard()
{

    char dates[20];
    unsigned int readCardNumber;
    char cardnumberUpdatestatus = 0;
    printf("Enter Card number 0000-9999\n");
    scanf("%d", &readCardNumber);
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strcpy(dates, asctime(tm));
    pushCard(readCardNumber, dates, ACCESS_TRUE);
    list();
}
// branch commit