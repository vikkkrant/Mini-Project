#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void optionSelecter(int number);
void openAccount();
void checkAccountBalance();
void getAccountDetails();
void makeTransactions();
void delay(unsigned int mseconds);
int main()
{
    int select;

    while (1)
    {
        printf("\n\n\n\t\t ### WELCOME TO BANKING SYSTEM ###\n\n");
        printf("\tSELECT ONE OF THE OPTION FROM THIS [1-5]\n");
        printf("\t[1] Open a account\n");
        printf("\t[2] Check account balance\n");
        printf("\t[3] Get account information\n");
        printf("\t[4] Make Transaction\n\n");
        printf("\t[5] Exit\n\n");
        printf("\t Select one of the option provided above : ");
        scanf("%d", &select);
        optionSelecter(select);
    }
    return 0;
}

void openAccount()
{
    system("cls");
    printf("Lets Open a account Whooo!!\n\n");

    FILE *fp = fopen("database.csv", "a+");

    if (!fp)
    {
        printf("Can't open file\n");
    }

    char name[50], email[200];
    int account_num, balance;

    printf("\tAccount Holder's Name : ");
    scanf("%s", name);
    printf("\tAccount Holder's Account Number : ");
    scanf("%d", &account_num);
    printf("\tAccount Holder's email-address : ");
    scanf("%s", email);
    printf("\tAccount Holder's Intial Balance amount : ");
    scanf("%d", &balance);

    fprintf(fp, "%s, %d, %s, %d\n", name, account_num, email, balance);
    system("cls");
    printf("\nSuccessfully created new account !!");
    delay(3000);
    fclose(fp);
    system("cls");
}

void checkAccountBalance()
{
    system("cls");
    printf("View your Account Balance\n\n");
    FILE *fp = fopen("database.csv", "a+");

    if (!fp)
    {
        printf("Can't open file\n");
    }

    char email[200];
    printf("\tEnter Account Holder's Email address to view the balance : ");
    scanf("%s", email);

    char buffer[1024];

    int row = 0;
    int column = 0;
    int flag = 0;

    while (fgets(buffer, 1024, fp))
    {
        column = 0;
        row++;

        if (row == 1)
        {
            continue;
        }

        char *value = strtok(buffer, ", ");
        char nameStore[50];
        char emailStore[200];
        while (value)
        {

            if (column == 0)
            {
                strcpy(nameStore, value);
            }
            if (column == 2)
            {
                strcpy(emailStore, value);
            }
            if (column == 3)
            {
                if (strcmp(emailStore, email) == 0)
                {
                    flag = 1;
                    printf("\n\tAccount Holder's Name : %s\n", nameStore);
                    printf("\tAccount Holder's Balance : %s\n ", value);
                    break;
                    break;
                }
            }
            value = strtok(NULL, ", ");
            column++;
        }
        printf("\n");
    }
    if (flag != 1)
    {
        printf("\n\tAccount doesn't Exists");
    }
    fclose(fp);
}

void getAccountDetails()
{
    system("cls");
    printf("Get your account Information\n\n");
    FILE *fp = fopen("database.csv", "a+");

    if (!fp)
    {
        printf("Can't open file\n");
    }

    char email[200];
    printf("\tEnter Account Holder's Email address to get account details: ");
    scanf("%s", email);

    char buffer[1024];

    int row = 0;
    int column = 0;
    int flag = 0;
    while (fgets(buffer, 1024, fp))
    {
        column = 0;
        row++;

        if (row == 1)
        {
            continue;
        }

        char *value = strtok(buffer, ", ");
        char nameStore[50];
        char acc_num[100];
        char emailStore[200];
        char balanceStore[200];
        while (value)
        {
            if (column == 0)
            {
                strcpy(nameStore, value);
            }

            if (column == 1)
            {
                strcpy(acc_num, value);
            }

            if (column == 3)
            {
                strcpy(balanceStore, value);
            }
            if (column == 2)
            {
                if (strcmp(value, email) == 0)
                {
                    flag = 1;
                    printf("\n\n\tAccount Holder's Name : %s\n", nameStore);
                    printf("\tAccount Holder's Account Number : %s\n", acc_num);
                    printf("\tAccount Holder's Email address : %s\n", email);
                    printf("\tAccount Balance : %s\n", balanceStore);
                    break;
                    break;
                }
            }
            value = strtok(NULL, ", ");
            column++;
        }
    }
    if (flag != 1)
    {
        printf("\n\tAccount doesn't Exists");
    }
    fclose(fp);
}

void makeTransactions()
{
    system("cls");
    printf("Make Transaction to any account number\n\n");
    FILE *fp = fopen("database.csv", "a+");

    if (!fp)
    {
        printf("Can't open file\n");
    }

    char email[200];
    printf("\tEnter Account Holder's Email address to make transaction ");
    scanf("%s", email);

    char emailTo[200];
    printf("\tEnter Account Holders's Email to whom you are sending money ");
    scanf("%s", emailTo);

    char amount[200];

    char buffer[1024];

    int row = 0;
    int column = 0;
    int flag = 0;

    while (fgets(buffer, 1024, fp))
    {
        column = 0;
        row++;

        if (row == 1)
        {
            continue;
        }

        char *value = strtok(buffer, ", ");
        char nameStore[50];
        char emailStore[200];
        while (value)
        {

            if (column == 0)
            {
                strcpy(nameStore, value);
            }
            if (column == 2)
            {
                strcpy(emailStore, value);
            }
            if (column == 3)
            {
                if (strcmp(emailStore, email) == 0)
                {
                    flag = 1;
                    printf("\n\tAccount Holder's Name : %s\n", nameStore);
                    printf("\tAccount Holder's Balance : %s\n ", value);

                    printf("\n");

                    printf("Enter amount to be paid ");
                    scanf("%s", &amount);

                    printf("%s succesfully paid to  %s's account\n", amount, emailTo);

                    int val;
                    val = atoi(value);

                    int val2;
                    val2 = atoi(amount);

                    int amountLeft = val - val2;

                    printf("New Balance is %d ",amountLeft);
                }
            }
            value = strtok(NULL, ", ");
            column++;
        }
    }
    if (flag != 1)
    {
        printf("\n\tAccount doesn't Exists");
    }
    fclose(fp);
}

void optionSelecter(int number)
{
    switch (number)
    {
    case 1:
        openAccount();
        break;
    case 2:
        checkAccountBalance();
        break;
    case 3:
        getAccountDetails();
        break;
    case 4:
        makeTransactions();
        break;
    case 5:
        system("cls");
        printf("\n\n\tHave a nice day bye!!\n\n");
        exit(0);
    default:
        printf("\tPlease select the correct number [1-5]\n");
        break;
    }
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
}