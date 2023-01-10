#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <dirent.h>

struct book
{
    char book[50], content[1024];
};

int main()
{
    FILE *fp;
    struct book s;
    DIR *dir;
    struct dirent *entry;
    int i;

    // user login
    char username[10];
    char password[10];
    char usernameCheck[] = "admin";
    char pass[] = "pass";

    // change pass
    char oldpass[50], newpass[50];

    printf("\tUser Login!\n\n");
    printf("\tEnter Name: ");
    scanf("%s", username);
    printf("\tEnter Password: ");
    scanf("%s", password);

    if (strcmp(username, usernameCheck) == 0 && strcmp(password, pass) == 0)
    {
        int opt, loop = 1;
        printf("\t******Welcome to Library Management System!******\n\n");
        printf("\tChoose the options below: \n");
        printf("\t1.Add Book\n\t2.View Book\n\t3.Edit Book Record\n");
        printf("\t4.Delete Book\n\t5.View all books\n\t6.Search Book\n\t7.Change Password\n\t8.Close Applicattion\n");
        printf("\n");
        while (loop != 0)
        {
            printf("\n\tchoose option: ");
            scanf("%d", &opt);
            switch (opt)
            {
            case 1:
                // add book
                printf("\tEnter book name to be added: ");
                fflush(stdin);
                gets(s.book);
                if ((fp = fopen(s.book, "r")) != NULL)
                {
                    printf("\tBook with name=%s already exists!\n", s.book);
                }
                else
                {
                    fp = fopen(s.book, "w+");
                    printf("\tEnter the content for the book: \n");
                    fflush(stdin);
                    printf("\t");
                    gets(s.content);
                    fprintf(fp, "%s", s.content);
                }
                fclose(fp);
                break;
            case 2:
                // view book
                printf("\tEnter book name: ");
                fflush(stdin);
                gets(s.book);
                if ((fp = fopen(s.book, "r")) == NULL)
                {
                    printf("\tBook doesn't exist!\n");
                }
                else
                {
                    fp = fopen(s.book, "r");
                    printf("\t%s :\n", s.book);
                    printf("\t");
                    while (fscanf(fp, "%s", s.content) != EOF)
                    {
                        printf("%s ", s.content);
                    }
                    printf("\n");
                }
                fclose(fp);
                break;
            case 3:
                // edit book
                printf("\tEnter book name: ");
                fflush(stdin);
                gets(s.book);
                if ((fp = fopen(s.book, "r")) == NULL)
                {
                    printf("\tBook doesn't exist!\n");
                }
                else
                {
                    fp = fopen(s.book, "a+");
                    printf("\tEnter additional content for the book: \n");
                    fflush(stdin);
                    printf("\t");
                    gets(s.content);
                    fprintf(fp, "\n%s", s.content);
                }
                fclose(fp);
                break;
            case 4:
                // delete book
                printf("\tBook to delete: ");
                fflush(stdin);
                gets(s.book);
                if ((fp = fopen(s.book, "r")) == NULL)
                {
                    printf("\tBook doesn't exist!\n");
                }
                fclose(fp);
                remove(s.book);
                printf("\n\tBook deleted!\n");
                break;
            case 5:
                // view all books
                // opening current directory
                dir = opendir(".");
                char *exclude[] = {"main.c", "main.exe"};
                if (dir == NULL)
                {
                    printf("\tNo Books in the directory!\n");
                }
                while ((entry = readdir(dir)) != NULL)
                {
                    // Check if the file name is in the exclude list
                    int exclude_file = 0;
                    for (i = 0; i < sizeof(exclude) / sizeof(exclude[0]); i++)
                    {
                        if (strcmp(entry->d_name, exclude[i]) == 0)
                        {
                            exclude_file = 1;
                            break;
                        }
                    }
                    if (!exclude_file)
                    {
                        printf("\t%s\n", entry->d_name);
                    }
                }
                closedir(dir);
                break;
            case 6:
                // search book
                printf("\tenter book name: ");
                fflush(stdin);
                gets(s.book);

                if ((fp = fopen(s.book, "r")) == NULL)
                {
                    printf("\tBook doesn't exist!\n", s.book);
                }
                else if ((fp = fopen(s.book, "r")) != NULL)
                {
                    fp = fopen(s.book, "r");
                    printf("\tBook with name %s exists!\n", s.book);
                    printf("\t%s :\n", s.book);
                    printf("\t");
                    while (fscanf(fp, "%s", s.content) != EOF)
                    {
                        printf("%s ", s.content);
                    }
                }
                fclose(fp);
                break;
            case 7:
                // change password
                printf("\tEnter old password: ");
                fflush(stdin);
                gets(oldpass);
                if (strcmp(oldpass, pass) == 0)
                {
                    printf("\n\tenter new password: ");
                    fflush(stdin);
                    gets(newpass);
                    printf("\n\tpassword has been updated!");
                }
                else
                {
                    printf("\tWrong Credentials!\n");
                }
                break;
            case 8:
                // close application
                loop--;
                break;
            default:
                printf("\tThat option does not exist!\n");
                break;
            }
        }
    }
    else
    {
        printf("\tInvalid Credentials!");
    }
}