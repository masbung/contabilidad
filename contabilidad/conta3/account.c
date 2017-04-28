#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

//save_current_jou
int da = 0;
char response2[] = "no";

//journal
int ea=0, eb=1, ec=2, ed=0, ee=0, ef;
char comment[30];
int sourceArray[1][40]; //Account number 
int amountArray[50][2]; //Amount of move in journal

//ACCOUNTS.txt

struct struct_account {
        int id;
        int id2;
        char account_name [25];
        char account_name2 [25];
        int account_type;
        int balanceArray[100][2];
        int balanceArray2[100][2];
        int jou_count2;
        int jou_count3;
        char comment2[30];

        char month[10]; 
        char day[10]; 
        int num_day;
        int hour;
        int min; 
        int second; 
        int year;

        struct struct_account *next;
    }; typedef struct struct_account ACCOUNT;
void print_acc(ACCOUNT *account) {
    printf("%d\t", account->id);
    printf("%s\t", account->account_name);
    printf("%d\n", account->account_type);
}

void print_all_acc(ACCOUNT *current) {
    printf("No.\tAccount\t\tType\n");
    while(current->next != NULL) {
        print_acc(current);
        current = current->next;
    }
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

void add_acc(ACCOUNT* current) {

    load_all_acc(current);
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

int account_menu(){
    ACCOUNT* head = NULL;
    head = malloc(sizeof(ACCOUNT));
    head->next = NULL;
    ACCOUNT* current = NULL;
    current = head;

    char response[] = "no";
    int menu_logs;

    do {
        printf("Which function do you want to do?\n 1. Load accounts \n 2. Print all accounts \n 3. Add acount \n 4. Save accounts \n 5. Main menu \n");
        scanf("%d",&menu_logs);    
        
            switch (menu_logs) {
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
                    save_all_acc(current);            
                    break;
            }
        } while (menu_logs != 5);
        return 0;
}


//LEDGER.txt

void load_all_led(ACCOUNT *current) {//LA CUENTA UNO DEBE DE TENER MAS LOGS QUE LAS OTRAS 
    
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

    /*printf(" k: %d\n nl: %d\n nw: %d\n nc: %d\n elt: %d\n ast: %d\n num_accounts: %d\n state: %d\n aa: %d\n ab: %d\n ac: %d\n ad: %d\n ae: %d\n af: %d\n",k,nl, nw, nc, elt, ast, num_accounts, state, aa, ab, ac, ad, ae, af);
    printf("countArray2[1][1]: %d\n",countArray2[1][1]);
    printf("countArray2[1][2]: %d\n",countArray2[1][2]);
    printf("countArray2[1][3]: %d\n",countArray2[1][3]);
    printf("countArray2[1][4]: %d\n",countArray2[1][4]);
    printf("countArray2[1][5]: %d\n",countArray2[1][5]);
    printf("countArray2[1][6]: %d\n",countArray2[1][6]);
    printf("countArray2[1][7]: %d\n",countArray2[1][7]);*/

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

int ledger_menu(){
    ACCOUNT* head = NULL;
    head = malloc(sizeof(ACCOUNT));
    head->next = NULL;
    ACCOUNT* current = NULL;
    current = head;

    int menu_logs;

    do {
        printf("Which function do you want to do?\n 1. Load ledger \n 2. Print all ledger \n 3. Main menu \n");
        scanf("%d",&menu_logs);    
        
            switch (menu_logs) {
                case 1:
                    load_all_led(current);            
                    break;
                case 2:
                    print_all_led(current);            
                    break;
            }
        } while (menu_logs != 3);
        return 0;
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

void load_jou(ACCOUNT *current) {

    char date_j[10]; 
    char description_j[10];
    char acc_j[10];
    char debit_j[10];
    char credit_j[10];
    char ref_j[10];
    
    FILE *pFile;

    pFile = fopen("journal.txt" , "r");

    fscanf(pFile,"%s %s %s %s %s %s", date_j, description_j, acc_j, debit_j, credit_j, ref_j);
    
    do{
        fscanf(pFile,"%s %s %d %02d:%02d:%02d %d", current->month, current->day, &current->num_day, &current->hour, &current->min, &current->second, &current->year);
        fscanf(pFile,"%s %d %d %d",current->account_name, &current->id, &current->balanceArray[0][1], &current->jou_count2);
        fscanf(pFile,"%s %d %d %d",current->account_name2, &current->id2, &current->balanceArray2[0][2], &current->jou_count3);
        fscanf(pFile,"%s",current->comment2);
        current->next = malloc(sizeof(ACCOUNT));
        current = current->next;
        current->next = NULL;
    }while (!feof(pFile));

    fclose (pFile);
    
}

void print_jou(ACCOUNT *account) {  

    printf("\n");
    printf("%s %s %d %02d:%02d:%02d %d", account->month, account->day, account->num_day, account->hour, account->min, account->second, account->year);
    printf("\t\t\t%s\t%d\t%d\t\t%d\n",account->account_name, account->id, account->balanceArray[0][1], account->jou_count2);
    printf("\t\t\t\t\t\t   %s\t%d\t\t%d\t%d\n",account->account_name2, account->id2, account->balanceArray2[0][2], account->jou_count3);
    printf("      \t\t\t\t%s\n",account->comment2);
}

void print_jou_all(ACCOUNT *current) {

    printf("Date                            Coment          Description     Acc.    Debit  Credit  Ref.\n");
    while(current->next->next != NULL) {
        print_jou(current);
        current = current->next;
    }

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
    if (response2[0] == 'y'){
        printf("      \t\t\t\t%s\n",comment);
    }
    else{
        printf("      \t\t\t\t.\n");    
    }
}

void save_current_jou(ACCOUNT *current) {

    FILE *pFile;
    pFile = fopen("journal.txt" , "a");
    jou_count++;
    
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    int d2 = 0;
    int da = 0;
    int zz = 0;
    while(sourceArray[1][d2] != current->id){
            current = current->next;
        }
    da++;
    //fprintf(pFile,"Date\t\t\t\t\t\tDescription\t\tAcc.\tDebit\tCredit\tRef.\n");
    fprintf(pFile,"\n");
    fprintf(pFile,"%s \t\t\t\t\t\t\t%s  \t\t%d\t\t%d\t\t\t\t%d\n",asctime (timeinfo),current->account_name,current->id,amountArray[da][1],jou_count);
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
    if (response2[0] == 'y'){
        fprintf(pFile,"      \t\t\t\t%s\n",comment);
    }
    else{
        fprintf(pFile,"      \t\t\t\t.\n");    
    }

    save_journal_count();

    fclose (pFile);    
}

/*void save_in_ledger(ACCOUNT *current) {

    //Cambia el nombre de la segunda cuenta al momento de meter dos entradas en el credito
    int d2;
    int ca, stop3, cb, cc=1, cd=1, stop8=0;
    FILE *pFile;

    if( ( sourceArray[1][0] > sourceArray[1][1] && sourceArray[1][0] < sourceArray[1][2] ) || ( sourceArray[1][0] < sourceArray[1][1] && sourceArray[1][0] > sourceArray[1][2] ) ) {
        printf("Yeah\n");
        load_all_led(current);
        load_source();
        pFile = fopen("ledger.txt" , "w");
        do{
            ca=0;
            stop3=0;
            cb = countArray2[1][cc];
            fprintf(pFile,"%d %s %d \n",current->id,current->account_name,current->account_type);
            
            do{
                fprintf(pFile,"%d\t",current->balanceArray[ca][1]);
                fprintf(pFile,"%d\n",current->balanceArray[ca][2]);
                ca++;
                stop3++;
            }while(stop3 != cb);
            
            if(current->id == sourceArray[1][0]){
                fprintf(pFile,"%d\t",amountArray[1][1]);
                fprintf(pFile,"%d\n",amountArray[1][2]);
            }
            if(current->id == sourceArray[1][1]){
                fprintf(pFile,"%d\t",amountArray[2][2]);
                fprintf(pFile,"%d\n",amountArray[2][1]);
            }
            if(current->id == sourceArray[1][2]){
                fprintf(pFile,"%d\t",amountArray[3][2]);
                fprintf(pFile,"%d\n",amountArray[3][1]);
            }
            fprintf(pFile,"*\n");
            cc++;
            stop8++;
            current = current->next;
        }while(stop8 != num_accounts);
    }

    else{
        load_all_led(current);
        load_source();
        pFile = fopen("ledger.txt" , "w");
        do{
            d2 = 0;
            ca=0;
            stop3=0;
            cb = countArray2[1][cc];
            fprintf(pFile,"%d %s %d \n",current->id,current->account_name,current->account_type);
            
            do{
                if(current->id == sourceArray[1][0]){
                    if(current->balanceArray[ca][1] == 0){
                        current->balanceArray[ca][1] = amountArray[cd][1];
                        current->balanceArray[ca][2] = amountArray[cd][2];
                    }                    
                //fprintf(pFile,"%d\t",current->balanceArray[ca][1]);
                //fprintf(pFile,"%d\n",amountArray[cd][2]);
                //cd++;
                }
                fprintf(pFile,"%d\t",current->balanceArray[ca][1]);
                fprintf(pFile,"%d\n",current->balanceArray[ca][2]);
                ca++;
                
                stop3++;
            }while(stop3 != cb);

            / *if(current->id == sourceArray[1][0]){
                if(current->balanceArray[ca][1] == 0){
                    current->balanceArray[ca][1] = amountArray[cd][1];
                    current->balanceArray[ca][2] = amountArray[cd][2];
                    fprintf(pFile,"%d\t",current->balanceArray[ca][1]);
                    fprintf(pFile,"%d\n",current->balanceArray[ca][2]);
                }                    
                //fprintf(pFile,"%d\t",current->balanceArray[ca][1]);
                //fprintf(pFile,"%d\n",amountArray[cd][2]);
                cd++;
            }* /
            
            do{
            d2++;
            //cd++;
                if(current->id == sourceArray[1][d2]){
                    cd++;
                    fprintf(pFile,"%d\t",amountArray[cd][2]);
                    fprintf(pFile,"%d\n",amountArray[cd][1]);                    
                }
            }while(d2 != ed);
            fprintf(pFile,"*\n");
            cc++;
            stop8++;
            current = current->next;
        }while(stop8 != num_accounts);
    }

    fclose (pFile);
}*/
//Change balance 0 0 if it matchs an amount

void save_in_ledger(ACCOUNT *current) {

    //Cambia el nombre de la segunda cuenta al momento de meter dos entradas en el credito
    int d2;
    int ca, stop3, cb, cc=1, cd=1, stop8=0;
    FILE *pFile;

    if( ( sourceArray[1][0] > sourceArray[1][1] && sourceArray[1][0] < sourceArray[1][2] ) || ( sourceArray[1][0] < sourceArray[1][1] && sourceArray[1][0] > sourceArray[1][2] ) ) {
        printf("Yeah\n");
        load_all_led(current);
        load_source();
        pFile = fopen("ledger.txt" , "w");
        do{
            ca=0;
            stop3=0;
            cb = countArray2[1][cc];
            fprintf(pFile,"%d %s %d \n",current->id,current->account_name,current->account_type);
            
            do{
                fprintf(pFile,"%d\t",current->balanceArray[ca][1]);
                fprintf(pFile,"%d\n",current->balanceArray[ca][2]);
                ca++;
                stop3++;
            }while(stop3 != cb);
            
            if(current->id == sourceArray[1][0]){
                fprintf(pFile,"%d\t",amountArray[1][1]);
                fprintf(pFile,"%d\n",amountArray[1][2]);
            }
            if(current->id == sourceArray[1][1]){
                fprintf(pFile,"%d\t",amountArray[2][2]);
                fprintf(pFile,"%d\n",amountArray[2][1]);
            }
            if(current->id == sourceArray[1][2]){
                fprintf(pFile,"%d\t",amountArray[3][2]);
                fprintf(pFile,"%d\n",amountArray[3][1]);
            }
            fprintf(pFile,"*\n");
            cc++;
            stop8++;
            current = current->next;
        }while(stop8 != num_accounts);
    }

    else{
        load_all_led(current);
        load_source();
        pFile = fopen("ledger.txt" , "w");
        do{
            d2 = 0;
            ca=0;
            stop3=0;
            cb = countArray2[1][cc];
            fprintf(pFile,"%d %s %d \n",current->id,current->account_name,current->account_type);
            
            do{
                fprintf(pFile,"%d\t",current->balanceArray[ca][1]);
                fprintf(pFile,"%d\n",current->balanceArray[ca][2]);
                ca++;
                stop3++;
            }while(stop3 != cb);

            if(current->id == sourceArray[1][0]){
                fprintf(pFile,"%d\t",amountArray[cd][1]);
                fprintf(pFile,"%d\n",amountArray[cd][2]);
                cd++;
            }

            do{
            d2++;
                if(current->id == sourceArray[1][d2]){
                    fprintf(pFile,"%d\t",amountArray[cd][2]);
                    fprintf(pFile,"%d\n",amountArray[cd][1]);
                    cd++;
                }
            }while(d2 != ed);
            fprintf(pFile,"*\n");
            cc++;
            stop8++;
            current = current->next;
        }while(stop8 != num_accounts);
    }

    fclose (pFile);
}

void journal(ACCOUNT *current) {//Scan comment with spaces 

    char response[] = "no";            
    load_all_led(current);            
    do{
        ef=0;
        printf("Do you want to print all accounts? y/n\n");
        scanf("%s", response);
        if (response[0] == 'y'){
            load_all_acc(current);
            print_all_acc(current);
        }
        ea++;
        printf("Select the debit account number: \n");
        scanf("%d",&sourceArray[1][ee]);
        printf("Enter amount: ");
        scanf("%d",&amountArray[ea][eb]);
        amountArray[ea][ec] = 0;
        ef++;
        do{
            ea++;
            ed++;
            ee++;
            fa++;
            ef++;
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
        scanf("%s", response2);
        if (response2[0] == 'y'){
            printf("Comment: \n");
            scanf("%s",comment);
            print_current_jou(current);
            save_current_jou(current);
            save_in_ledger(current);
        }
        
        else{
            print_current_jou(current);
            save_current_jou(current);
            save_in_ledger(current);
        }
        printf("Do you want to make another log?? y/n\n");
        scanf("%s", response);
        clear_source();
        ee = 0;
        ea = 0;
        fa = 0;
        fb = 0; 
    }while(response[0] == 'y');
}

int journal_menu(){
    ACCOUNT* head = NULL;
    head = malloc(sizeof(ACCOUNT));
    head->next = NULL;
    ACCOUNT* current = NULL;
    current = head;

    
    int menu_logs;

    do {
        printf("Which function do you want to do?\n 1. Load journal \n 2. Print all journal \n 3. Journal \n 4. Main menu \n");
        scanf("%d",&menu_logs);    
        
            switch (menu_logs) {
                case 1:
                    load_jou(current);            
                    break;
                case 2:
                    print_jou_all(current);            
                    break;
                case 3:
                    journal(current);            
                    break;
            }
        } while (menu_logs != 4);
        return 0;
}



/*void test(ACCOUNT *current) {
    load_all_acc(current);
    printf("Current id->: %d\n",current->id);
    current->id = current->next->id;
    printf("Current id->: %d\n",current->id);
    current->id = current->id;
    load_all_acc(current);
    printf("Current id->: %d\n",current->id);
    current = current->next;
    printf("Current id->: %d\n",current->id);

}*/

void balanceArray() {//matrix ARREGLAR VARIABLES

    int BalanceArray5[4][4],i,j,y=1;

    //Stored values into the array
    printf("Input elements in the matrix: \n");
    for(i=1;i<4;i++) {
        for(j=1;j<4;j++) {
            printf("element - [%d],[%d] : ",i,j);
            scanf("%d",&BalanceArray5[i][j]);
        }
    }  
    //print all 
    printf("\nThe matrix is : \n\n");
    for(j=1;j<4;j++) {
        printf(" \t%d",y++);
    }
    printf("\n");

    for(i=1;i<4;i++) {
        printf("\n");
        printf("%d\t",i);
        for(j=1;j<4;j++) {
            printf("%d\t",BalanceArray5[i][j]);
        }
    }
    
    //print balance
    BalanceArray5[3][1]=BalanceArray5[3][1] - BalanceArray5[3][1] - BalanceArray5[3][1];
    BalanceArray5[3][2]=BalanceArray5[3][2] - BalanceArray5[3][2] - BalanceArray5[3][2];
    BalanceArray5[3][3]=BalanceArray5[3][3] - BalanceArray5[3][3] - BalanceArray5[3][3];
    //Make a more efficent loop

    printf("\n\n");
    printf("Balance\t");
    for(j=1;j<4;j++) {
        printf("%d\t",BalanceArray5[1][1] + BalanceArray5[2][1] + BalanceArray5[3][1]);
    }
    printf("\n");
}


int main () {

    ACCOUNT* head = NULL;
    head = malloc(sizeof(ACCOUNT));
    head->next = NULL;
    ACCOUNT* current = NULL;
    current = head;

    //char response[] = "no";
    int menu_option;

    load_journal_count();

    do {
        printf("Which function do you want to do?\n 1. Account menu \n 2. Ledger menu \n 3. Journal menu \n 4. Balance Array \n 10. Exit \n");
        scanf("%d",&menu_option);    
        switch (menu_option) {
            case 1:
                account_menu(current);                                             
                break; 
            case 2:                          
                ledger_menu(current);
                break;
            case 3:
                journal_menu(current);                                     
                break;
            case 4:                          
                balanceArray();            
                break;
            case 9:                          
                //balanceArray();            
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