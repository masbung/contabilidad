#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "accounts.h"

//ACCOUNTS.txt
void print_acc(ACCOUNT *account) {
    printf("%d\t", account->id);
    printf("%s\t", account->account_name);
    printf("%d\n", account->account_type);
}

void print_acc2(ACCOUNT *account) {
    printf("%d\t", account->id);
    printf("%s\t", account->account_name);
    printf("%d\t", account->account_type);
    printf("%d\n", account->generalBalance);
}

void load_all_acc(ACCOUNT *current) {

    FILE *pFile;
    pFile = fopen("accounts.txt" , "r");
    do{
        fscanf(pFile,"%d %s %d", &current->id, current->account_name, &current->account_type);
        current->next = malloc(sizeof(ACCOUNT));
        current = current->next;
        current->next = NULL;
    }while(!feof(pFile));
    fclose (pFile);
}

void print_all_acc(ACCOUNT *current) {

    load_all_acc(current);

    printf("No.\tAccount\t\tType\n");
    while(current->next != NULL) {
        print_acc(current);
        current = current->next;
    }
}

void add_acc(ACCOUNT* current, int *plastid) {

    load_all_acc(current);
    while(current->next->next != NULL){
        current = current->next;
    }
        printf("Enter the account ID: ");
        scanf("%d", plastid); // &lastid);
        if(current->id + 1 == *plastid){
            current = current->next;
            current->next = malloc(sizeof(ACCOUNT));    
            current->next->next = NULL;  
            current->id = *plastid;  
            printf("Enter the account name: ");
            scanf("%s", current->account_name);
            printf("Enter the account type: \n");
            printf(" 1. Assets\n 2. Liability\n 3. Equity\n 4. Revenue\n 5. Expense\n");
            scanf("%d", &current->account_type);

            FILE *pFile;
            pFile = fopen("ledger.txt" , "a");

            fprintf(pFile,"%d ", current->id);
            fprintf(pFile,"%s ", current->account_name);
            fprintf(pFile,"%d\n", current->account_type);
            fprintf(pFile,"%d %d\n", 0, 0);
            fprintf(pFile,"*");
            fprintf(pFile,"\n");

            fclose (pFile);

            pFile = fopen("accounts.txt" , "a");

            fprintf(pFile,"\n");
            fprintf(pFile,"%d\t", current->id);
            fprintf(pFile,"%s\t", current->account_name);
            fprintf(pFile,"%d", current->account_type);

            fclose (pFile);
        }        
        else{
            printf("This ID already exists or is not the next ID in order\n");
        }
    
}

void save_all_acc(ACCOUNT *current) {
    FILE *pFile;
    pFile = fopen("accounts.txt" , "w");
    while(current->next != NULL) {
        fprintf(pFile,"%d\t", current->id);
        fprintf(pFile,"%s\t", current->account_name);
        fprintf(pFile,"%d\n", current->account_type);
        current = current->next;
    } 
    fclose (pFile);           
}

