#include <stdio.h>
#include <stdlib.h>
#include "options.h"
#include "menu.h"
#include"typedef.h"


void menu(void)
{

    printf("\t\t\t\t\t*************WELCOME TO PHONEBOOK*************");

    printf("\n\n\t\t\t\t\t--------  phonebook_MENU  -------\t\n\n");
    printf("        1.show phonebook list    \t2.Add record  \t3.search  \t4.Edit   \t5.Delete  \t6.Exit\n\n\n");
    printf("Enter the number of option you need:");


    switch((char)getch())
{
    case '1':
        show_list();
    break;

   case '2':
       add_record();
    break;
    case '3':
        search();
    break;

    case '4':
        edit();
    break;

    case '5':
        delete_record();
    break;

    case '6':
        exit_app();
    break;



    default:
                system("cls");
                printf("\n\nEnter 1 to 6 only\n\n\n");
                printf("\t\t\t\t\t***Enter any key to return***");
                getch();
                system("cls");
                menu();
    break;
}
}
