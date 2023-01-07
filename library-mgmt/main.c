#include <stdio.h>
#include <conio.h>
#include <string.h>

#define contentSize 1024

void addBook();
void viewBook();
void editBook();
void deleteBook();
void searchBook();
void changePass();

int main()
{
    char adminName[10];
    char password[10];
    char username[] = "admin";
    char pass[] = "root";

    printf("User Login!\n\n");
    printf("Enter Name: ");
    scanf("%s", adminName);
    printf("Enter Password: ");
    scanf("%s", password);

    if (strcmp(adminName, username) == 0 && strcmp(password, pass) == 0)
    {
        int opt, loop = 1;
        printf("Welcome to Library Management System!\n\n");
        printf("Choose the options below: \n");
        printf("1.Add Book\n2.View Book\n3.Edit Book Record\n");
        printf("4.Delete Book\n5.Search Book\n6.Change Password\n7.Close Applicattion\n");
        printf("\n");
        while (loop != 0)
        {
            printf("\noption: ");
            scanf("%d", &opt);
            switch (opt)
            {
            case 1:
                addBook();
                break;
            case 2:
                viewBook();
                break;
            case 3:
                editBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                searchBook();
                break;
            case 6:
                changePass();
                break;
            case 7:
                loop--;
                break;
            default:
                printf("That option does not exist!\n");
                break;
            }
        }
    }
    else
    {
        printf("Invalid Credentials!");
    }
}

void addBook()
{
    FILE *fp;
    char book[50];
    char content[500];
    printf("Enter name of new book: ");
    fflush(stdin);
    gets(book);
    if ((fp = fopen(book, "r")) != NULL)
    {
        printf("Book with name=%s already exists!\n", book);
    }
    else
    {
        fp = fopen(book, "w+");
        printf("Enter the content for the book: \n");
        fflush(stdin);
        gets(content);
        fprintf(fp, "%s", content);
    }
    fclose(fp);
}

void viewBook()
{
    FILE *fp;
    char book[50];
    char content[contentSize];
    printf("Enter book name: ");
    fflush(stdin);
    gets(book);
    if ((fp = fopen(book, "r")) == NULL)
    {
        printf("Book doesn't exist!\n");
    }
    else
    {
        fp = fopen(book, "r");
        printf("%s :\n", book);
        while (fscanf(fp, "%s", content) != EOF)
        {
            printf("%s ", content);
        }
        printf("\n");
    }
    fclose(fp);
}
void editBook()
{
    FILE *fp;
    char book[50];
    char newContent[contentSize];
    printf("Enter book name: ");
    fflush(stdin);
    gets(book);
    if ((fp = fopen(book, "r")) == NULL)
    {
        printf("Book doesn't exist!\n");
    }
    else
    {
        fp = fopen(book, "a+");
        printf("Enter additional content for the book: \n");
        fflush(stdin);
        gets(newContent);
        fprintf(fp, "\n%s", newContent);
    }
    fclose(fp);
}
void deleteBook()
{
    FILE *fp;
    char book[50];
    printf("Book to delete: ");
    fflush(stdin);
    gets(book);
    if ((fp = fopen(book, "r")) == NULL)
    {
        printf("Book doesn't exist!\n");
    }
    fclose(fp);
    remove(book);
}
void searchBook()
{
    FILE *fp;
    char book[50];
    char content[contentSize];
    printf("enter book name: ");
    fflush(stdin);
    gets(book);

    if ((fp = fopen(book, "r")) == NULL)
    {
        printf("Book doesn't exist!\n", book);
    }
    else if ((fp = fopen(book, "r")) != NULL)
    {
        fp = fopen(book, "r");
        printf("Book with name %s exists!\n", book);
        printf("%s :\n", book);
        while (fscanf(fp, "%s", content) != EOF)
        {
            printf("%s ", content);
        }
    }
    fclose(fp);
}
void changePass()
{
    char oldpass[50], newpass[50];
    char pass[] = "root";
    printf("Enter old password: ");
    fflush(stdin);
    gets(oldpass);
    if (strcmp(oldpass, pass) == 0)
    {
        printf("\nenter new password: ");
        fflush(stdin);
        gets(newpass);
        printf("\npassword has been updated!");
    }
    else
    {
        printf("Wrong Credentials!\n");
    }
}