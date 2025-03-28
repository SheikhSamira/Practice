#include<stdio.h>
#include <stdlib.h>
#include <string.h>
struct Transaction {
    char code[6];
    char type[20];
    float amount;
    char password[20];
};
FILE *file;
FILE *fptr;
double readBalance() {
    FILE *file = fopen("Balance.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open balance file for reading.\n");
        return -1.0;
    }
    double balance;
    if (fscanf(file, "%lf", &balance) != 1) {
        fclose(file);
        printf("Error: Could not read balance from file.\n");
        return -1.0;
    }
    fclose(file);
    return balance;
}
int writeBalance(double newBalance) {
    file = fopen("Balance.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open balance file for writing.\n");
        return 0;
    }

    fprintf(file, "%.2lf", newBalance);
    fclose(file);
    return 1;
}

void sendMoney(FILE *fptr) {
    fptr=fopen("bkash_data.txt", "a+");
   if (fptr==NULL)
    {
        printf("Error opening file.\n");
    }
    struct Transaction transaction;
    strcpy(transaction.type, "Send Money");
    char recipientName[50];
    printf("Enter recipient's mobile no: ");
    scanf("%s", recipientName);
    printf("Enter amount: ");
    scanf("%f", &transaction.amount);
    char reference[20];
    printf("Reference: ");
    scanf("%s",reference);
    float balance=readBalance(file);
    if (transaction.amount > balance) {
        printf("Insufficient balance to perform the transaction.\n");
        return;
    }
    strcpy(transaction.password,"19923");
    while(1){
        char num[6];
        printf("Enter the password= ");
        scanf("%s",&num);
        int z=strcmp(num,transaction.password);
        if(z==0){
            break;
        }
        else{
            printf("Invalid Password\n");
        }
    }
    double newBalance=balance-transaction.amount;
            writeBalance(newBalance);
         fprintf(fptr, "%s %.2f to %s and reference is %s\n", transaction.type, transaction.amount, recipientName,reference);
         printf("Money sent successfully to %s. Amount: %.2f and reference is %s\n", recipientName, transaction.amount, reference);
          printf("New Balance=%lf\n",newBalance);
          fclose(fptr);
}
void mobileRecharge(FILE *fptr) {
    fptr=fopen("bkash_data.txt", "a+");
   if (fptr==NULL)
    {
        printf("Error opening file.\n");
    }
    struct Transaction transaction;
    strcpy(transaction.type, "Mobile Recharge");
     char mobileNumber[20];
    printf("Enter mobile number: ");
    scanf("%s", mobileNumber);
    printf("Enter amount: ");
    scanf("%f", &transaction.amount);
    float balance=readBalance(file);
    if (transaction.amount > balance) {
        printf("Insufficient balance to perform the recharge.\n");
        return;
    }
    strcpy(transaction.password,"19923");
    while(1){
        char num[6];
        printf("Enter the password= ");
        scanf("%s",&num);
        int z=strcmp(num,transaction.password);
        if(z==0){
            break;
        }
        else{
            printf("Invalid Password\n");
        }
    }
    double newBalance=balance-transaction.amount;
    writeBalance(newBalance);
    fprintf(fptr, "%s %.2f for mobile number %s\n", transaction.type,transaction.amount,mobileNumber);
    printf("Mobile recharge of %.2f done for mobile number %s.\n",transaction.amount,mobileNumber);
    printf("New Balance=%lf\n",newBalance);
    fclose(fptr);
}
void makePayment(FILE *fptr) {
    fptr=fopen("bkash_data.txt", "a+");
   if (fptr==NULL)
    {
        printf("Error opening file.\n");
    }
    struct Transaction transaction;
    strcpy(transaction.type, "Make Payment");
    char recipientName[50];
    printf("Enter Merchant Account: ");
    scanf("%s", recipientName);
    printf("Enter amount: ");
    scanf("%f", &transaction.amount);
    char reference[30];
    printf("Enter reference: ");
    scanf("%s",reference);
    float balance=readBalance(file);
    if (transaction.amount>balance) {
        printf("Insufficient balance to make the payment.\n");
        return;
    }
    strcpy(transaction.password,"19923");
    while(1){
        char num[6];
        printf("Enter the password= ");
        scanf("%s",&num);
        int z=strcmp(num,transaction.password);
        if(z==0){
            break;
        }
        else{
            printf("Invalid Password\n");
        }
    }
    double newBalance=balance-transaction.amount;
    writeBalance(newBalance);
    fprintf(fptr, "%s %.2f to %s and reference is %s.\n",transaction.type,transaction.amount,recipientName,reference);
    printf("Payment of %.2f made to %s and reference is %s.\n",transaction.amount,recipientName,reference);
    printf("New Balance=%lf\n",newBalance);
    fclose(fptr);
}
void cashOut(FILE *fptr) {
    fptr=fopen("bkash_data.txt", "a+");
   if (fptr==NULL)
    {
        printf("Error opening file.\n");
    }
    struct Transaction transaction;
    strcpy(transaction.type, "Cash Out");
    printf("Enter amount: ");
    scanf("%f", &transaction.amount);
    float balance=readBalance(file);
    if (transaction.amount > balance) {
        printf("Insufficient balance for cash out.\n");
        return;
    }
    strcpy(transaction.password,"19923");
    while(1){
        char num[6];
        printf("Enter the password= ");
        scanf("%s",&num);
        int z=strcmp(num,transaction.password);
        if(z==0){
            break;
        }
        else{
            printf("Invalid Password\n");
        }
    }
    double newBalance=balance-transaction.amount;
    writeBalance(newBalance);
    fprintf(fptr, "%s %.2f\n", transaction.type, transaction.amount);
    printf("Cash out of %.2f successful.\n", transaction.amount);
    printf("New Balance=%lf\n",newBalance);
    fclose(fptr);
}
void payBill(FILE *fptr) {
    fptr=fopen("bkash_data.txt", "a+");
   if (fptr==NULL)
    {
        printf("Error opening file.\n");
    }
    struct Transaction transaction;
    strcpy(transaction.type, "Pay Bill");
    printf("Enter amount: ");
    scanf("%f", &transaction.amount);
    float balance=readBalance(file);
    if (transaction.amount > balance) {
        printf("Insufficient balance to pay the bill.\n");
        return;
    }
    char billRecipient[50];
    printf("Enter bill recipient's name: ");
    scanf("%s", billRecipient);
    strcpy(transaction.password,"19923");
    while(1){
        char num[6];
        printf("Enter the password= ");
        scanf("%s",&num);
        int z=strcmp(num,transaction.password);
        if(z==0){
            break;
        }
        else{
            printf("Invalid Password\n");
        }
    }
     double newBalance=balance-transaction.amount;
    writeBalance(newBalance);
    fprintf(fptr, "%s %.2f for %s\n", transaction.type, transaction.amount, billRecipient);
    printf("Bill payment of %.2f for %s completed.\n", transaction.amount, billRecipient);
    printf("New Balance=%lf",newBalance);
    fclose(fptr);
}
int main()
{
   fptr=fopen("bkash_data.txt", "a+");
   if (fptr==NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    struct Transaction transaction;
    strcpy(transaction.code,"*247#");
    while(1){
        char num[6];
        printf("Enter the code= ");
        scanf("%s",num);
        int z=strcmp(num,transaction.code);
        if(z==0){
            break;
        }
        else{
            printf("Invalid Code\n");
        }
    }
   int choice;
   while(choice!=6)
   {
        printf("1. Send Money\n");
        printf("2. Mobile Recharge\n");
        printf("3. Make Payment\n");
        printf("4. Cash Out\n");
        printf("5. Pay Bill\n");
        printf("6. Exit\n");
        printf("Select an option:\n");
        scanf("%d", &choice);
            if(choice==1){
                sendMoney(fptr);
            }
            else if(choice==2)
            {
                mobileRecharge(fptr);
            }
            else if(choice==3)
            {
                makePayment(fptr);
            }
            else if(choice==4)
            {
                cashOut(fptr);
            }
            else if(choice==5)
            {
                payBill(fptr);
            }
            else if(choice==6)
            {
                printf("Exiting from bKash\n");
            }

            else{
                printf("Invalid choice.Please select a valid option.\n");
            }
   }
         fclose(fptr);
return 0;
}
