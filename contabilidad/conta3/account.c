#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Make a function that load and saves everything

//Counter to identify the number of journals made
int jou_count = 0;

//add_acc
int lastid;
int *plastid = &lastid;

//Journal, print_current_jou, save_jou 
int fa = 0;
//print_current_jou
int fb = 0;

//load_all_led
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
// k = getc, nl = new line, nc = new character, elt = espace/line/tab, ast = number of asterisks, num_accounts = total of accounts
int k,nl, nw, nc, elt, ast, num_accounts, state;
int aa, ab, ac, ad, ae, af;
int stop, stop2;
int countArray[1][50];
int countArray2[1][50];

//print_led
int ba, bb, bc;

//save_jou
int da = 0;

//journal
int ea=0, eb=1, ec=2, ed=0, ee=0;
char comment[30];
int sourceArray[1][40]; //Account number 
int amountArray[50][2]; //Amount of move in journal

//account.txt

struct struct_account {
        int id;
        char account_name [25];
        int account_type;
        int jou_count;
        int balanceArray [100][2];

        struct struct_account *next;
    }; typedef struct struct_account ACCOUNT;

void print_acc(ACCOUNT *account) {
    printf("%d\t", account->id);
    printf("%s\t", account->account_name);
    printf("%d\n", account->account_type);
}

void print_all_acc(ACCOUNT *current) {
    printf("No.\tAccount\t\tType\n");
    while(current != NULL) {
        print_acc(current);
        current = current->next;
    }
}

void load_all_acc(ACCOUNT *current) {//load all ACCOUNTS. Hacer una funcion que efectivamente cargue todo

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

void save_all_acc(ACCOUNT *current) {//save all ACCOUNTS. Hacer una funcion que efectivamente guarde todo
    FILE *pFile;
    pFile = fopen("accounts.txt" , "w");
    while(current != NULL) {
        fprintf(pFile,"%d\t", current->id);
        fprintf(pFile,"%s\t", current->account_name);
        fprintf(pFile,"%d\n", current->account_type);
        current = current->next;
    } 
    fclose (pFile);           
}

void add_acc(ACCOUNT* current) {//Done

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


//ledger.txt

void load_all_led(ACCOUNT *current) {//LA CUENTA UNO DEBE DE TENER MAS LOGS QUE LAS OTRAS - DONE
    
    char asterisk[5]; //asterisks in ledger 

    int nl = nw = nc = elt = ast = stop = stop2 = 0;
    aa = 1;
    state = OUT;

    FILE *pFile;
    pFile = fopen("ledger.txt" , "r");
    while((k = fgetc(pFile)) != EOF){
        ++nc;
        if (k == '\n')
            ++nl;
        if (k == ' ' || k == '\n' || k == '\t'){
            state = OUT;
            ++elt;
        }
        if (k == '*'){
            countArray[1][aa] = nl;
            aa++;
            ast++;
            }
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    
    //Asign values
    nw = nw - 1;
    nw = nw - ast;
    num_accounts = elt - nw;
    ab = 1;
    ac = 2;
    countArray2[1][1] = countArray[1][1] - 1;
    do{
        countArray2[1][ac] = countArray[1][ac] - countArray[1][ab] - 2;
        ab++;
        ac++;
        stop2++;
    }while(stop2 != num_accounts);
    fclose (pFile);

    pFile = fopen("ledger.txt" , "r");
    do{
        af = 1;
        ae = countArray2[1][af];
        fscanf(pFile,"%d %s %d", &current->id, current->account_name, &current->account_type);
        stop = 0;
        ad = 0;
        do{
            fscanf(pFile,"%d %d", &current->balanceArray[ad][1], &current->balanceArray[ad][2]);
            ad++;
            stop++;
        }while(stop != ae);
        af++;
        fscanf(pFile,"%s", asterisk);
        current->next = malloc(sizeof(ACCOUNT));
        current = current->next;
        current->next = NULL;
    }while(!feof(pFile));

    fclose (pFile);
}

void print_led(ACCOUNT *account) {

    bb = countArray2[1][ba];
    printf("%d\t", account->id);
    printf("%s\t", account->account_name);
    printf("%d\n", account->account_type);
    stop = 0;
    bc = 0;
    do{
        printf("%d %d\n", account->balanceArray[bc][1], account->balanceArray[bc][2]);
        bc++;
        stop++;
    }while(stop != bb); 
}

void print_all_led(ACCOUNT *current) {
    ba = 1;
    printf("No.\tAccount\t\tType\n");
    stop2 = 0;
    do{
        print_led(current);
        current = current->next;
        stop2++;
        ba++;
    }while(stop2 != num_accounts);
}

//Extras 

void save_source() {
    int a = 0;
    FILE *pFile;
    pFile = fopen("source.txt" , "w");
    ee = ee + 1;
    do {
        fprintf(pFile,"%d ",sourceArray[1][a]);
        a++;
    }while(a != ee);
    fclose (pFile);
}

void load_source() {
    int a = 0;
    FILE *pFile;
    pFile = fopen("source.txt" , "r");
    ee = ee + 1;
    do {
        fscanf(pFile,"%d ",&sourceArray[1][a]);
        a++;
    }while(!feof(pFile));
    fclose (pFile);
}

void clear_source() {
    FILE *pFile;
    pFile = fopen("source.txt" , "w");
    fprintf(pFile," ");
    fclose (pFile);
}

void load_journal_count() {

    FILE *pFile;
    pFile = fopen("journal_count.txt" , "r");
    fscanf(pFile,"%d",&jou_count);
    fclose (pFile);
}

void save_journal_count() {

    FILE *pFile;
    pFile = fopen("journal_count.txt" , "w");
    fprintf(pFile,"%d",jou_count);
    fclose (pFile);
}


//journal.txt

//Load and print all journal

/*Add operations made in the Journal to accounts*/
void save_all_jou(ACCOUNT *current) {

    FILE *pFile;
    pFile = fopen("ledger.txt" , "w");
    //Numero de cuenta de debito menor que credito 
    fprintf(pFile,"%d %s %d \n",current->id,current->account_name,current->account_type);
    fprintf(pFile,"%d\t",current->balanceArray[0][1]);
    fprintf(pFile,"%d\n",current->balanceArray[0][2]);
    fprintf(pFile,"%d\t",amountArray[1][1]);
    fprintf(pFile,"%d\n",amountArray[1][2]);
    fprintf(pFile,"*\n");

    current = current->next;

    fprintf(pFile,"%d %s %d \n",current->id,current->account_name,current->account_type);       
    fprintf(pFile,"%d\t",current->balanceArray[0][1]);
    fprintf(pFile,"%d\n",current->balanceArray[0][2]);
    fprintf(pFile,"%d\t",amountArray[2][2]);
    fprintf(pFile,"%d\n",amountArray[2][1]);
    fprintf(pFile,"*\n");

    fclose (pFile); 

    /*
    //Numero de cuenta de debito mayor que credito 
    / *printf("%d %s %d \n",current->id,current->account_name,current->account_type);
    printf("%d\t",current->balanceArray[0][1]);
    printf("%d\n",current->balanceArray[0][2]);
    printf("%d\t",current->balanceArray[1][1]);
    printf("%d\n",current->balanceArray[1][2]);
    printf("%d\t",amountArray[2][2]);
    printf("%d\n",amountArray[2][1]);
    printf("%d\t",amountArray[3][2]);
    printf("%d\n",amountArray[3][1]);
    printf("*\n");
    current = current->next;
    printf("%d %s %d \n",current->id,current->account_name,current->account_type);       
    printf("%d\t",current->balanceArray[0][1]);
    printf("%d\n",current->balanceArray[0][2]);
    printf("%d\t",amountArray[1][1]);
    printf("%d\n",amountArray[1][2]);
    printf("*\n");* / 
    */
}

void print_current_jou(ACCOUNT *current) {

    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    int d2 = 0;
    int zz = 0;
    while(sourceArray[1][d2] != current->id){
            current = current->next;
        }
    fb++;
    printf("Date\t\t\t\tDescription\t\tRef.\tDebit\tCredit \n");
    printf("%s \t\t\t\t%s  \t\t%d\t%d\n",asctime (timeinfo),current->account_name,current->id,amountArray[fb][1]);
    do{
        d2++;
        load_all_led(current);
        load_source();
        while(sourceArray[1][d2] != current->id){
            current = current->next;
        }
        fb++;
        zz++;                 
        printf("      \t\t\t\t\t%s\t%d\t\t%d\n",current->account_name,current->id,amountArray[fb][1]);
    } while(zz != fa);
    printf("      \t\t\t\t%s\n",comment);    
}

void save_jou(ACCOUNT *current) {

    FILE *pFile;
    pFile = fopen("journal.txt" , "a");
    jou_count++;
    
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    int d2 = 0;
    int zz = 0;
    while(sourceArray[1][d2] != current->id){
            current = current->next;
        }
    da++;
    fprintf(pFile,"Date\t\t\t\t\t\tDescription\t\tRef.\tDebit\tCredit \n");
    fprintf(pFile,"%s \t\t\t\t\t\t\t%s  \t\t%d\t\t%d\n",asctime (timeinfo),current->account_name,current->id,amountArray[da][1]);
    do{
        d2++;
        load_all_led(current);
        load_source();
        while(sourceArray[1][d2] != current->id){
            current = current->next;
        }
        da++;
        zz++;                 
        fprintf(pFile,"      \t\t\t\t\t\t\t%s\t%d\t\t\t\t%d\t\t%d\n",current->account_name,current->id,amountArray[da][1],jou_count);
    } while(zz != fa);
    fprintf(pFile,"    \t\t\t\t\t\t%s\n",comment);

    save_journal_count();

    fclose (pFile);    
}

void journal(ACCOUNT *current) {//Scan comment with spaces 

    char response[] = "no";

    do{
        printf("Do you want to print all accounts? y/n\n");
        scanf("%s", response);
        if (response[0] == 'y'){
            print_all_acc(current);
        }
        ea++;
        printf("Select the debit account number: \n");
        scanf("%d",&sourceArray[1][ee]);
        printf("Enter amount: ");
        scanf("%d",&amountArray[ea][eb]);
        amountArray[ea][ec] = 0;
        printf("amountArray[%d][%d]: %d\n", ea, eb, amountArray[ea][eb]);
        do{
            ea++;
            ed++;
            ee++;
            fa++;
            printf("Select the credit account number: \n");
            scanf("%d",&sourceArray[1][ee]);
            printf("Enter amount: ");
            scanf("%d",&amountArray[ea][eb]); 
            amountArray[ea][ec] = 0;
            printf("Enter another credit account? y/n\n");
            scanf("%s", response);
        }while(response[0] == 'y');
        save_source();

        printf("Do you want to add a comment? y/n\n");
        scanf("%s", response);
        if (response[0] == 'y'){
            printf("Comment: \n");
            scanf("%s",comment);
            print_current_jou(current);
            save_jou(current);
            save_all_jou(current);
        }
        
        else{
            comment[30] = ' ';
            print_current_jou(current);
            save_jou(current);
            save_all_jou(current);
        }
        printf("Do you want to make another log?? y/n\n");
        scanf("%s", response);
        clear_source();
        ee = 0;
        fa = 0;
    }while(response[0] == 'y');
}




int main () {

    ACCOUNT* head = NULL;
    head = malloc(sizeof(ACCOUNT));
    head->next = NULL;
    ACCOUNT* current = NULL;
    current = head;

    char response[] = "no";
    int menu_option;

    load_journal_count();

    do {
        printf("Which function do want to do?\n 1. Load accounts \n 2. Print all accounts \n 3. Add account \n 4. Load ledger \n 5. Print all ledger \n 6. Load journal \n 7. Print all journal \n 8. Journal \n 9. Save accounts \n 10. Exit \n");
        scanf("%d",&menu_option);    
        switch (menu_option) {
            case 1:
                load_all_acc(current);                                             
                break; 
            case 2:                          
                print_all_acc(current);             
                break;
            case 3:                          
                do {
                    add_acc(current);        
                    printf("Add other (y/n) \n");
                    scanf("%s", response);
                    if (response[0] == 'y') {
                    }
                } while (response[0] == 'y');            
                break;
            case 4:                          
                load_all_led(current);            
                break;
            case 5:                          
                print_all_led(current);           
                break;
            case 6:                          
                //balanceArray();           
                break;
            case 7:                          
                //print_all_jou(current);           
                break;
            case 8:                          
                journal(current);           
                break;
            case 9:                          
                save_all_acc(current);            
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