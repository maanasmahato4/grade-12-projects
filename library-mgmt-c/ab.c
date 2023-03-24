#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct {
char book_name[50];
char book_desc[50];
}library;
int main()
{
int a;
char check[]="n",test1[]="y",test2[]="Y";
char user[40],password[]="b",username[]="a",pass[40];
do{
printf("Enter the username:\n");
scanf("%s",&user);
printf("\nEnter the password:\n");
scanf("%s",&pass);
system("cls");
if(strcmp(username,user)==0&&strcmp(password,pass)==0)
{
do{
FILE *fp;
printf("------------------------WELCOME TO LIBRARY MANAGEMENT SYSTEM---------------------------\n");
printf("1. Add book.\n");
printf("2. Delete book.\n");
printf("3. Search book.\n");
printf("4. View Book list\n");
printf("5. Edit book Record\n");
printf("6. Change password\n");
printf("7. Close application\n");
scanf("%d",&a);
system("cls");
switch (a)
{
case 1:
{
fp=fopen("lms.txt","a+");
printf("enter the book name\n");
scanf("%s",&library.book_name);
printf("enter the book description\n");
scanf("%s",&library.book_desc);
fwrite(&library,sizeof(library),1,fp);
fclose(fp);
break;
}
case 2:
{
char bookname[20];
FILE *fp1;
printf("Enter the book name to delete:\n");
scanf("%s",&bookname);
fp=fopen("lms.txt","r+");
fp1=fopen("newlibrary.txt","w+");
while (fread(&library,sizeof(library),1,fp))
{
 if(strcmp(library.book_name,bookname)!=0)
{
fwrite(&library,sizeof(library),1,fp1);
}
}
fclose(fp);
fclose(fp1);
remove("lms.txt");
rename("newlibrary.txt","lms.txt");
printf("\nBook deleted succesfully\n.");
system("cls");
getch();
break;
}
case 3:
{
char bname[30];
int found=0;
printf("enter the book name\n");
scanf("%s",&bname);
fp=fopen("lms.txt","r+");
while(fread(&library,sizeof(library),1,fp))
{
if(!strcmp(library.book_name,bname))
{
found=1;
break;
}
}
if(found==1)
{
printf("The book is %s\nTis is the description of the book:\n%s\n",library.book_name,library.book_desc);
getch();
}
else
{
printf("The book %s is not in our records\n",bname);
}
getch();
system("cls");
break;
}
case 4:
{
printf("\nBOOK NAME\t BOOK DESCRIPTION\n");
fp=fopen("library.txt","r+");
while(fread(&library,sizeof(library),1,fp))
{
printf("\n%s\t\t%s",library.book_name,library.book_desc);
}
fclose(fp);
getch();
system("cls");
break;
}
case 5:
{
FILE *fp;
FILE *fp1;
char bname[40],tempresult[40],userinput[40];
printf("\nEnter which book description you want to add to:\n");
scanf("%s",&bname);
fp=fopen("lms.txt","r+");
fp1=fopen("copy.txt","w+");
while(fread(&library,sizeof(library),1,fp))
{
if(strcmp(library.book_name,bname)==0)
{
strcpy(tempresult,library.book_desc);
}
if(strcmp(library.book_name,bname)!=0)
{
fwrite(&library,sizeof(library),1,fp1);
}
}
fclose(fp1);
fp1=fopen("copy.txt","a+");
printf("Enter what you want to add:\n");
scanf("%s",&userinput);
strcat(tempresult,userinput);
strcpy(library.book_desc,tempresult);
strcpy(library.book_name,bname);
fwrite(&library,sizeof(library),1,fp1);
fclose(fp);
fclose(fp1);
remove("lms.txt");
rename("copy.txt","lms.txt");
break;
}
case 6:
{
char useripass[40],newpass[40];
printf("Enter old password: ");
scanf("%s",&useripass);
system("cls");
if (strcmp(useripass, password) == 0)
{
printf("Enter new password:");
scanf("%s",&newpass);
system("cls");
printf("Password updated!");
getch();
}
else
{
printf("Password invalid!\n");
getch();
}
break;
}
case 7:
{
break;
}
}
system("cls");
}while(a!=7);
}
else
{
printf("The username or password is wrong.\n\n");
printf("Do you want to continue? \nPress y for yes and n for no:\n");
scanf("%s",check);
system("cls");
}
}while(strcmp(check,test1)==0||strcmp(check,test2)==0);
}

