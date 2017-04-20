#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int lastid;
int *plastid = &lastid;

struct struct_account {
        int id;
        char account_name [25];
        int account_type;
        int amountArray [50][2];

        char day [5];
        char month [5];
        int num;
        int year;

        struct struct_account *next;
    }; typedef struct struct_account ACCOUNT;

void print (ACCOUNT *account) {
    printf("%d\t", account->id);
    printf("%s\t", account->account_name);
    printf("%d\n", account->account_type);
}

void load_all(ACCOUNT *current) {

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

void save_all(ACCOUNT *current) {
    FILE *pFile;
    pFile = fopen("accounts.txt" , "w");
    while(current != NULL) {
        fprintf(pFile,"%d\t", current->id);
        fprintf(pFile,"%s\t", current->account_name);
        fprintf(pFile,"%d\n", current->account_type);
    } 
    fclose (pFile);           
} 

void print_all(ACCOUNT *current) {
    printf("No.\tAccount\t\tType\n");
    while(current != NULL) {
        print(current);
        current = current->next;
    }
}

void add_account(ACCOUNT* current) {

    while(current->next->next != NULL){
        current = current->next;
    }
        printf("Enter the account ID: ");
        scanf("%d", &lastid);
        if(current->id + 1 == lastid){
            current = current->next;
            current->next = malloc(sizeof(ACCOUNT));    
            current->next->next = NULL;  
            current->id = *plastid;  
            printf("Enter the account name: ");
            scanf("%s", current->account_name);
            printf("Enter the account type: \n");
            printf(" 1. Assets\n 2. Liability\n 3. Equity\n 4. Revenue\n 5. Expense\n");
            scanf("%d", &current->account_type);
        }        
        else{
            printf("This ID already exists or is not the next ID in order\n");
        }
}

/*void make_move(ACCOUNT *current){ 
    
    char response[] = "no";
    int source,dest,b=1,a=1,i=0,c=2,j=0;
    int amountArray [50][2];
    
    printf("Do you want to print all accounts? y/n\n");
    scanf("%s", response);
    if (response[0] == 'y'){
        print_all(current);
    }
    printf("Choose account number: \n");
    scanf("%d",&source);
    printf(" 1. Debit or 2. Credit? \n");
    scanf("%d",&dest);
    
    if (dest == 1) {
        do{
            printf("Enter amount: ");
            scanf("%d",&amountArray[a][b]);
            amountArray[a][c] = 0;
            printf("Want to make other entry? y/n\n");
            scanf("%s", response);
            i++;
            a++;
        }while (response[0] == 'y');
        a = 1;
    
        do{
            if(source == current->id){
                print(current);
            }
            current = current->next;
        }while(source == current->id);

        do{
            printf("%d\t", amountArray[a][b]);
            printf("%d\n", amountArray[a][c]);
            a++;
            j++;
        }while (j < i);
    }

    if (dest == 2) {
        do{
            printf("Enter amount: ");
            scanf("%d",&amountArray[a][c]);
            amountArray[a][b] = 0;
            printf("Want to make other entry? y/n\n");
            scanf("%s", response);
            i++;
            a++;
        }while (response[0] == 'y');
        a = 1;

        do{
            if(source == current->id){
                print(current);
            }
            current = current->next;
        }while(source == current->id);

        do{
            printf("%d\t", amountArray[a][b]);
            printf("%d\n", amountArray[a][c]);
            a++;
            j++;
        }while (j < i);
    }
}*/

void journal(ACCOUNT *current) { //JOURNAL 
    
    char response[] = "no";
    char response2[] = "no";
    int a=1,b=1,c=2,j=0;
    char comment[100];
    int source; //array
    int amountArray [50][2];

    //Make a loop to enter multiple logs 
        printf("Do you want to print all accounts? y/n\n");
        scanf("%s", response);
        if (response[0] == 'y'){
            print_all(current);
        }
        printf("Select the debit account number: \n");
        scanf("%d",&source);
        printf("Enter amount: ");
        scanf("%d",&amountArray[a][b]);
        amountArray[a][c] = 0;

        do{
            a++;
            j++;
            printf("Select the credit account number: \n");
            scanf("%d",&source2);
            printf("Enter amount: ");
            scanf("%d",&amountArray[a][b]); 
            amountArray[a][c] = 0;
            printf("Enter another credit account? y/n\n");
            scanf("%s", response);
        }while(response[0] == 'n');


        printf("Do you want to add a comment? y/n\n");
        scanf("%s", response);
        if (response[0] == 'y'){
            printf("Comment: \n");
            scanf("%s",comment);
        a = 1;                
            printf("Date\t\tDescription\t\tRef.\tDebit\tCredit \n");
            printf("Apr %d\t\t%s  \t\t%d\t%d\n",19,current->account_name,current->id,amountArray[a][b]);
            do{ 
                a++;                 
                current = current->next;
                printf("      \t\t\t%s\t%d\t\t%d\n",current->account_name,current->id,amountArray[a][b]);                    
            } while(a == j);
            printf("\t\t%s\n",comment);
        }
        else{
            a = 1;                
            printf("Date\t\tDescription\t\tRef.\tDebit\tCredit \n");
            printf("Apr %d\t\t%s  \t\t%d\t%d\n",19,current->account_name,current->id,amountArray[a][b]);
            do{ 
                a++;                 
                current = current->next;
                printf("      \t\t\t%s\t%d\t\t%d\n",current->account_name,current->id,amountArray[a][b]);                    
            } while(a == j);
            printf("\t\t%s\n",comment);
        }
}

/*void balanceArray() {//matrix ARREGLAR VARIABLES

    int BalanceArray [4][4],i,j,k=1;

    //Stored values into the array
    printf("Input elements in the matrix: \n");
    for(i=1;i<4;i++) {
        for(j=1;j<4;j++) {
            printf("element - [%d],[%d] : ",i,j);
            scanf("%d",&BalanceArray[i][j]);
        }
    }  
    //print all 
    printf("\nThe matrix is : \n\n");
    for(j=1;j<4;j++) {
        printf(" \t%d",k++);
    }
    printf("\n");

    for(i=1;i<4;i++) {
        printf("\n");
        printf("%d\t",i);
        for(j=1;j<4;j++) {
            printf("%d\t",BalanceArray[i][j]);
        }
    }
    
    BalanceArray[3][1]=BalanceArray[3][1] - BalanceArray[3][1] - BalanceArray[3][1];
    BalanceArray[3][2]=BalanceArray[3][2] - BalanceArray[3][2] - BalanceArray[3][2];
    BalanceArray[3][3]=BalanceArray[3][3] - BalanceArray[3][3] - BalanceArray[3][3];
    //Make a more efficent loop

    printf("\n\n");
    printf("Balance\t");
    for(j=1;j<4;j++) {
        printf("%d\t",BalanceArray[1][1] + BalanceArray[2][1] + BalanceArray[3][1]);
    }
    printf("\n");
}*/ 

int main () {

    ACCOUNT* head = NULL;
    head = malloc(sizeof(ACCOUNT));
    head->next = NULL;
    ACCOUNT* current = NULL;
    current = head;

    char response[] = "no";
    int menu_option;

    do {
        printf("Which function do want to do?\n 1. Load \n 2. Print all \n 3. Add account \n 4. Make a move \n 9. Save \n 10. Exit \n");
        scanf("%d",&menu_option);    
        switch (menu_option) {
            case 1:
                load_all(current);                                             
                break; 
            case 2:                          
                print_all(current);             
                break;
            case 3:                          
                do {//add_account
                    add_account(current);        
                    printf("Add other (y/n) \n");
                    scanf("%s", response);
                    if (response[0] == 'y') {
                    }
                } while (response[0] == 'y');            
                break;
            case 4:                          
                journal(current);            
                break;
            case 9:                          
                save_all(current);            
                break;
            case 10:
                printf("Thank you...\n");
                getchar();
                exit(0);        
                break; 
            
            default:
                printf("Not found");
        }    

    } while (menu_option != 10);


    getchar();

}