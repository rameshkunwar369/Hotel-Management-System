#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct customer
{
    char name[100];
    int roomNo;
    char date[20];
    char address[100];
} c;

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

void mainMenu()
{
    system("CLS");
    printf("\n");
    printf("\n");
    printf("\t================================  HOTEL MANAGEMENT SYSTEM  ================================\n");
    printf("\n");

    // mainScreenOption();
    int ch;
    while (1)
    {
        printf("\n\n");
        printf(" \n Enter 1 -> Book a room");
        printf("\n------------------------");
        printf(" \n Enter 2 -> View Customer Record");
        printf("\n----------------------------------");
        // printf(" \n Enter 3 -> Delete Customer Record");
        // printf("\n-----------------------------------");
        printf(" \n Enter 3 -> Search Customer Record");
        printf("\n-----------------------------------");
        printf(" \n Enter 4 -> Edit Customer Record");
        printf("\n-----------------------");
        printf(" \n Enter 0 -> Exit");
        printf("\n-----------------");
        printf("\n");

        printf("\t\t *Please enter your choice for menu*:");
        scanf("%d", &ch);
        // switch (ch)
        // {
        // case 0:
        //     exit(0);
        //     break;
        // case 1:
        //     bookARoom();
        //     break;
        // case 2:
        //     viewCustomerRecord();
        //     break;
        // case 3:
        //     searchCustomerRecord();
        //     // searchCustomerRecord();
        //     break;
        // case 4:
        //     editRecord();
        //     break;

        // default:
        //     printf("Please choose a valid option.");
        //     break;
        // }
    }
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