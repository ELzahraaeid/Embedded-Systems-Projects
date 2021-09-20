#include <stdio.h>
#include"implement_struct.h"






//clean the screan to choose another option
void clear_window()
{

    printf("\n\n Enter any key to clean the screen and choose another option");
    getch();
    system("cls");
    menu();
}

//reading phonebook list
void show_list()
{
    struct record r;
    FILE *f;
    char line[500];

    f=fopen("phonebook.txt","r");
    if(f==NULL)
        {
        printf("\n error in openning(file doesn't exist):\n");
        printf("\n Enter any key to clean the screen and choose **add record** option to add the first record to create the file :\n");
        getch();
        system("cls");
        menu();
        }

    printf("\n\n\t\t\tName\t\t\tmail\t\t\t\tphone\n");
    while (fgets(line, sizeof(line), f)) {
        //sscanf(line, "%s\t%[^\t]\t%s\t%s", &(r.name), &(r.email), &(r.phone) );
        //sscanf(line, "%[^\t]%s\t[^\t]%s\t%s", &(r.name), &(r.email), &(r.phone) );
        sscanf(line, "%[^\t]\t%[^\t]\t%s", &(r.name), &(r.email), &(r.phone) );
        printf("\t\t\t%s\t\t %s\t\t %s \n", r.name,r.email,r.phone);
      }
    fclose(f);
    clear_window();

}



//adding phonebook record
void add_record()
{
    struct record r;
    FILE *f;



    printf("\n\nname:");
    gets(r.name);

    printf("\nemail:");
    gets(r.email);

    printf("\nphone:");

    gets(r.phone);
    f= fopen ("phonebook.txt", "a");
    fprintf(f, "%s\t%s\t%s\n", r.name, r.email, r.phone);
    fclose(f);
    clear_window();

}



//searching for record

void search()
{
            int inter=0;
            char line[500];
            struct record r;
            FILE *f;
            char r_search[50];
            printf("\n\nenter name or phone for search:\n");
            gets(r_search);
            f=fopen("phonebook.txt","r");

        if(f==NULL)
        {
            printf("\n error in opening");
            exit(1);

        }

        while (fgets(line, sizeof(line), f))
            {
            sscanf(line, "%[^\t]\t%[^\t]\t%s", &(r.name),&(r.email)  ,&(r.phone) );

            if((strcmp(r.name,r_search)==0)||(strcmp(r.phone,r_search)==0)){
            printf("Name\t\tmail\t\tphone\n");
            printf("%s\t %s\t %s \n", r.name,r.email,r.phone);
            inter=1;
            }
          }
        if (inter==0)
        {
            printf("\n\t\t\trecord not found");
        }

        fclose(f);
        clear_window();
}


//edit record
void edit()
{
  char line[500];
  struct record r,new_rec;
  int enter=0;
  char phone_to_modify[100];
  FILE *f;
  f=fopen("phonebook.txt","r");
  FILE *temp;
  temp=fopen("temp.txt","a");
  if(f==NULL)
		{
			printf("CONTACT'S DATA NOT ADDED YET.");
			exit(1);
		}

    printf("\nEnter  phone TO modify its record:\n");
    gets(phone_to_modify);

    while (fgets(line, sizeof(line), f))
        {
        sscanf(line, "%[^\t]\t%[^\t]\t%s", &(r.name),&(r.email)  ,&(r.phone) );

        if(strcmp(r.phone,phone_to_modify)==0)
            {


             printf("\n Enter name:");
             gets(new_rec.name);
             printf("\n Enter email:");
             gets(new_rec.email);
             printf("\n Enter phone:");
             gets(new_rec.phone);

             fprintf(temp, "%s\t%s\t%s\n", new_rec.name, new_rec.email, new_rec.phone);

             enter=1;

        }
        else
        {

            fprintf(temp, "%s\t%s\t%s\n", r.name, r.email, r.phone);


        }

      }
    fclose(f);
	fclose(temp);
    if (enter==0)
    {
        printf("record not found\n");
        remove("temp.txt");
    }
    else
    {
        remove("phonebook.txt");
        rename("temp.txt","phonebook.txt");
        printf("successfully updating");
    }

clear_window();

}

//delete record
void delete_record()
{
  char line[500];
  struct record r;
  int enter=0;
  char phone_to_del[30];
  FILE *f;
  f=fopen("phonebook.txt","r");
  FILE *temp;
  temp=fopen("temp.txt","a");
  if(f==NULL)
		{
			printf("CONTACT'S DATA NOT ADDED YET.");
			exit(1);
		}

    printf("\nEnter  phone TO delete its record:\n");
    gets(phone_to_del);

    while (fgets(line, sizeof(line), f))
        {
        sscanf(line, "%[^\t]\t%[^\t]\t%s", &(r.name),&(r.email)  ,&(r.phone) );

        if(strcmp(r.phone,phone_to_del)==0)
            {
             enter=1;

            }
        else
        {

            fprintf(temp, "%s\t%s\t%s\n", r.name, r.email, r.phone);


        }

      }
    fclose(f);
	fclose(temp);
    if (enter==0)
    {
        printf("record not found\n");
        remove("temp.txt");
    }
    else
    {
        remove("phonebook.txt");
        rename("temp.txt","phonebook.txt");
        printf("successfully deleting");
    }

clear_window();
}

