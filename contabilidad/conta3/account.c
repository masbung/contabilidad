#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "values.h"

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
        int generalBalance;

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
        printf("Which function do you want to do?\n 1. Print all accounts \n 2. Add acount \n 3. Main menu \n");
        scanf("%d",&menu_logs);    
        
            switch (menu_logs) {
                case 1:
                    print_all_acc(current);            
                    break;
                case 2:
                    do {
                        add_acc(current);        
                        printf("Add other (y/n) \n");
                        scanf("%s", response);
                        if (response[0] == 'y') {
                        }
                    } while (response[0] == 'y');             
                    break;
            }
        } while (menu_logs != 3);
        return 0;
}


//LEDGER.txt

void load_all_led(ACCOUNT *current) {//LA CUENTA UNO DEBE DE TENER MAS LOGS QUE LAS OTRAS 
    
    char asterisk[5]; //asterisks in ledger 

    int nl = nw = nc = elt = ast = stop = stop2 = 0;
    int i,j;
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

    if(current->balanceArray[0][1] > 1 || current->balanceArray[0][2] > 1){

        //Sum of Column to make balance
        bc = 0;
        stop = 0;
        do{
            arr1[bc][0] = current->balanceArray[bc][1];
            arr1[bc][1] = current->balanceArray[bc][2];
            bc++;
            stop++;
        }while(stop != bb);

        for(i=0;i<bb;i++) {
        csum[i]=0;
        for(j=0;j<bb;j++)
            csum[i]=csum[i]+arr1[j][i];
        }
        current->generalBalance = csum[0] - csum[1];
        //printf("Balance: %d\n",account->generalBalance);
        //printf("\n");
    }
    else{
        current->generalBalance = 0;
        //printf("Balance: %d\n",account->generalBalance);
        //printf("\n");
    }


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

void print_led2(ACCOUNT *account) {

    int i,j;

    bb = countArray2[1][ba];
    printf("%d\t", account->id);
    printf("%s\t", account->account_name);
    printf("%d\n", account->account_type);

    if(account->balanceArray[0][1] > 1 || account->balanceArray[0][2] > 1){

        //Sum of Column to make balance
        bc = 0;
        stop = 0;
        do{
            arr1[bc][0] = account->balanceArray[bc][1];
            arr1[bc][1] = account->balanceArray[bc][2];
            bc++;
            stop++;
        }while(stop != bb);

        for(i=0;i<bb;i++) {
        csum[i]=0;
        for(j=0;j<bb;j++)
            csum[i]=csum[i]+arr1[j][i];
        }
        account->generalBalance = csum[0] - csum[1];
        printf("Balance: %d\n",account->generalBalance);
        printf("\n");
    }
    else{
        account->generalBalance = 0;
        printf("Balance: %d\n",account->generalBalance);
        printf("\n");
    }
}

void print_led3(ACCOUNT *account) {

    int i,j;

    bb = countArray2[1][ba];
    //printf("%d\t", account->id);
    //printf("%s\t", account->account_name);
    //printf("%d\n", account->account_type);

    if(account->balanceArray[0][1] > 1 || account->balanceArray[0][2] > 1){

        //Sum of Column to make balance
        bc = 0;
        stop = 0;
        do{
            arr1[bc][0] = account->balanceArray[bc][1];
            arr1[bc][1] = account->balanceArray[bc][2];
            bc++;
            stop++;
        }while(stop != bb);

        for(i=0;i<bb;i++) {
        csum[i]=0;
        for(j=0;j<bb;j++)
            csum[i]=csum[i]+arr1[j][i];
        }
        account->generalBalance = csum[0] - csum[1];
        //printf("Balance: %d\n",account->generalBalance);
        //printf("\n");
    }
    else{
        account->generalBalance = 0;
        //printf("Balance: %d\n",account->generalBalance);
        //printf("\n");
    }
}

void print_all_led(ACCOUNT *current) {

    load_all_led(current);

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

void print_all_led2(ACCOUNT *current) {

    load_all_led(current);

    ba = 1;
    printf("No.\tAccount\t\tType\n");
    stop2 = 0;
    do{
        print_led2(current);
        current = current->next;
        stop2++;
        ba++;
    }while(stop2 != num_accounts);
}

void print_all_led3(ACCOUNT *current) {

    load_all_led(current);

    ba = 1;
    //printf("No.\tAccount\t\tType\n");
    stop2 = 0;
    do{
        print_led3(current);
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
        printf("Which function do you want to do?\n 1. Print all ledger \n 2. Print general ledger \n 3. Main menu \n");
        scanf("%d",&menu_logs);    
        
            switch (menu_logs) {
                case 1:
                    print_all_led(current);            
                    break;
                case 2:
                    print_all_led2(current);            
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

    load_jou(current);

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

void save_in_ledger(ACCOUNT *current) {

    //Cambia el nombre de la segunda cuenta al momento de meter dos entradas en el credito
    int ca, stop3, cb, cc=1, cd, stop8=0,ce,stop6;
    int d2,d3;
    FILE *pFile;

    load_all_led(current);
    load_source();
    pFile = fopen("ledger.txt" , "w");
    do{
        ca=0;
        stop3=0;
        cd = 1;
        d2 = 0;
        ce = 0;
        d3 = 0;
        stop6=0;
        cb = countArray2[1][cc];
        fprintf(pFile,"%d %s %d \n",current->id,current->account_name,current->account_type);
        
        if(current->balanceArray[0][1] == 0 && current->balanceArray[0][2] == 0){
            if(current->id == sourceArray[1][0]){ 
                fprintf(pFile,"%d\t",amountArray[1][1]);
                fprintf(pFile,"%d\n",amountArray[1][2]);
            }
            else{
                do{
                    ce++;
                    d3++;
                    if(current->id == sourceArray[1][d3]){
                        fprintf(pFile,"%d\t",amountArray[ce][2]);
                        fprintf(pFile,"%d\n",amountArray[ce][1]);
                    }
                    else{
                        fprintf(pFile,"%d\t",current->balanceArray[ca][1]);
                        fprintf(pFile,"%d\n",current->balanceArray[ca][2]);
                        ca++;
                        stop6++;
                        printf("Stop 6: %d\n",stop6);
                        printf("cb: %d\n",cb);
                    }
                }while(d3 != cb);
            }    
        }
        else{
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
            else{
                do{
                    cd++;
                    d2++;
                    if(current->id == sourceArray[1][d2]){
                        fprintf(pFile,"%d\t",amountArray[cd][2]);
                        fprintf(pFile,"%d\n",amountArray[cd][1]);
                    }
                }while(d2 != ed);
            }
        }

        /*do{
            fprintf(pFile,"%d\t",current->balanceArray[ca][1]);
            fprintf(pFile,"%d\n",current->balanceArray[ca][2]);
            ca++;
            stop3++;
        }while(stop3 != cb);

        
        if(current->id == sourceArray[1][0]){        
            fprintf(pFile,"%d\t",amountArray[1][1]);
            fprintf(pFile,"%d\n",amountArray[1][2]);
        }
        else{
            do{
                cd++;
                d2++;
                if(current->id == sourceArray[1][d2]){
                    fprintf(pFile,"%d\t",amountArray[cd][2]);
                    fprintf(pFile,"%d\n",amountArray[cd][1]);
                }
            }while(d2 != ed);
        }*/

        fprintf(pFile,"*\n");
        cc++;
        stop8++;
        current = current->next;
    }while(stop8 != num_accounts);

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
}*/
//Original

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
        //printf("sourceArray[1][ee]): %d\n",sourceArray[1][ee]);
        //printf("e: %d\n",ee);
        printf("Enter amount: ");
        scanf("%d",&amountArray[ea][1]);
        //printf("amountArray[ea][1]): %d\n",amountArray[ea][1]);
        //printf("ea: %d\n",ea);
        amountArray[ea][2] = 0;
        ef++;
        do{
            ea++;
            ed++;
            ee++;
            fa++;
            ef++;
            printf("Select the credit account number: \n");
            scanf("%d",&sourceArray[1][ee]);
            //printf("sourceArray[1][ee]): %d\n",sourceArray[1][ee]);
            //printf("e: %d\n",ee);
            printf("Enter amount: ");            
            scanf("%d",&amountArray[ea][1]);
            //printf("amountArray[ea][1]): %d\n",amountArray[ea][1]);
            //printf("ea: %d\n",ea); 
            amountArray[ea][2] = 0;
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
        printf("Number of moves: %d\n",ed);
        printf("Do you want to make another log?? y/n\n");
        scanf("%s", response);
        clear_source();
        ee = 0;
        ea = 0;
        fa = 0;
        fb = 0; 
        ed = 0;
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
        printf("Which function do you want to do?\n 1. Print all journal \n 2. Journal entry \n 3. Main menu \n");
        scanf("%d",&menu_logs);    
        
            switch (menu_logs) {
                case 1:
                    print_jou_all(current);            
                    break;
                case 2:
                    journal(current);            
                    break;
            }
        } while (menu_logs != 3);
        return 0;
}

void results(ACCOUNT *current) {

    int aaaa = 0;
    load_all_led(current);

    printf("Num accounts: %d\n",num_accounts);
    printf("No.\tAccount\t\tType\tBalance\n");
    do{
        load_all_acc(current);
        print_all_led3(current);
        aaaa++;
        do{
            if(current->account_type == aaaa){
                print_acc2(current);
            }
            current = current->next;
        }while(current->next != NULL);
    }while(aaaa != num_accounts);

    //return 0;
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

void balanceArray() {

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

    int menu_option;

    load_journal_count();

    do {
        printf("Which function do you want to do?\n 1. Account menu \n 2. Ledger menu \n 3. Journal menu \n 4. Results \n 5. Balance Array \n 10. Exit \n");
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
                results(current);            
                break;
            case 5:                          
                balanceArray();            
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