#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>   // for upper and lowercase
#include <stdbool.h> // boolean
struct customer
{
    char name[100];
    int roomNo;
    char date[20];
    char address[100];
    char phoneNumber[10];
    char nationality[20];
    char email[20];
    char period[20];
} s;

void mainMenu(void);
void welcomeScreen()
{

    printf("\t\t*******************************************************\n");
    printf("\t\t*                                                     *\n");
    printf("\t\t*       -----------------------------------           *\n");
    printf("\t\t*        WELCOME TO HOTEL MANAGEMENT SYSTEM           *\n");
    printf("\t\t*       -----------------------------------           *\n");
    printf("\t\t*                                                     *\n");
    printf("\t\t*                                                     *\n");
    printf("\t\t*                                                     *\n");
    printf("\t\t*       Developed By:                                 *\n");
    printf("\t\t*       -------------                                 *\n");

    printf("\t\t*\t    Ramesh Kunwar                             *\n");
    printf("\t\t*\t    Sami Tamang                               *\n");
    printf("\t\t*\t    Pramod Thapa                              *\n");
    printf("\t\t*\t    Rishav Maharjan                           *\n");
    printf("\t\t*                                                     *\n");

    printf("\t\t*******************************************************\n\n\n");
}

void bookARoom()
{

    char continueToAdd[2];
    do
    {
        system("cls");
        FILE *f;
        char test;
        f = fopen("add.txt", "a+");

        printf("\n Enter Customer Details:");
        printf("\n**************************");
        printf("\n Enter Room number:\n");
        scanf("\n%d", &s.roomNo);

        printf("Enter Name:\n");
        scanf("%s", s.name);

        printf("Enter Address:\n");
        scanf("%s", s.address);

        printf("Enter Phone Number:\n");
        scanf("%s", s.phoneNumber);
        printf("Enter Nationality:\n");
        scanf("%s", s.nationality);
        printf("Enter Email:\n");
        scanf(" %s", s.email);
        printf("Enter Period(\'x\'days):\n");
        scanf("%s", &s.period);

        fwrite(&s, sizeof(s), 1, f);
        printf("\n\n1 Room is successfully booked!!");

        fclose(f);

        printf("Do you want to add more User. [y/n]: ");

        scanf("%s", continueToAdd);
        if (strcmp(continueToAdd, "n") == 0)
        {
            mainMenu();
            break;
        }

    } while (strcmp(continueToAdd, "y") == 0);
}

void viewCustomerRecord()
{

    FILE *f;
    int i;
    f = fopen("add.txt", "r");

    system("cls");
    printf("ROOM    ");
    printf("NAME\t ");
    printf("\tADDRESS ");
    printf("\tPHONENUMBER ");
    printf("\tNATIONALITY ");
    printf("\tEMAIL ");
    printf("\t\t  PERIOD ");

    for (i = 0; i < 118; i++)
        printf("-");
    while (fread(&s, sizeof(s), 1, f) == 1)
    {

        printf("\n%d \t%s \t\t%s \t%s \t%s  \t%s  \t     %s  \t  ", s.roomNo, s.name, s.address, s.phoneNumber, s.nationality, s.email, s.period);
    }
    printf("\n");
    for (i = 0; i < 118; i++)
        printf("-");

    fclose(f);
    getch();
    mainMenu();
}

void search()
{
    system("cls");
    // searchCode();
    FILE *f;
    int roomnumber;
    int flag = 1;
    f = fopen("add.txt", "r+");

    printf("\nEnter Room number of the customer to search its details: ");
    scanf("%d", &roomnumber);
    printf("\n");
    while (fread(&s, sizeof(s), 1, f) == 1)
    {
        if (s.roomNo == roomnumber)
        {
            flag = 0;
            printf("\n\tRecord Found\n ");
            printf("\nRoom Number:\t%d", s.roomNo);
            printf("\nName:\t%s", s.name);
            printf("\nAddress:\t%s", s.address);
            printf("\nPhone number:\t%s", s.phoneNumber);
            printf("\nNationality:\t%s", s.nationality);
            printf("\nEmail:\t%s", s.email);
            printf("\nPeriod:\t%s", s.period);
            // printf("\nArrival date:\t%s",s.arrivaldate);
            printf("\n");
            flag = 0;
            break;
        }
        printf("\n");
    }
    if (flag == 1)
    {
        printf("\n\tRequested Customer could not be found!\n");
    }
    fclose(f);
    getch();
    mainMenu();
}
void mainMenu()
{

    system("CLS");
    printf("\n");
    printf("\n");
    printf("\t================================  HOTEL MANAGEMENT SYSTEM  ================================\n");
    printf("\n");

    int ch;

    printf("\n\n");
    printf(" \n Enter 1 -> Book a room");
    printf("\n------------------------");
    printf(" \n Enter 2 -> View Customer Record");
    printf("\n----------------------------------");

    printf(" \n Enter 3 -> Search Customer Record");
    printf("\n-----------------------------------");

    printf(" \n Enter 0 -> Exit");
    printf("\n-----------------");
    printf("\n");

    printf("\t\t *Please enter your choice for menu*:");
    scanf("%d", &ch);

    switch (ch)
    {
    case 0:
        exit(0);
        break;
    case 1:
        bookARoom();
        break;
    case 2:
        viewCustomerRecord();
        break;
    case 3:

        search();
        break;

    default:
        printf("Please choose a valid option.");
        break;
    }
    // }
}

void login()
{

    char defaultLoginId[100] = "ramesh";
    char defaultLoginPw[100] = "root";
    char loginId[100];
    char loginPw[100];
    do
    {
        printf("\tEnter Login Id: ");
        scanf("%s", loginId);
        printf("\tEnter Login Password: ");
        scanf("%s", loginPw);
        if ((strcmp(loginId, defaultLoginId) == 0) && (strcmp(loginPw, defaultLoginPw) == 0))
        {

            // mainScreen();
            system("cls");
            mainMenu();
        }

    } while (strcmp(loginId, defaultLoginId) != 0 && strcmp(loginPw, defaultLoginPw) != 0);
}

void main()
{
    // printf("Hello");

    welcomeScreen();
    login();

    getch();
}
