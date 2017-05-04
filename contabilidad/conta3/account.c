#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "values.h"
#include "accounts.h"
#include "ledger.h"
#include "journal.h"

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
                        add_acc(current, plastid);        
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
    ag = 1;
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
    save_array(countArray2, num_accounts);
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
        bd = countArray2[1][ag];
    if(current->balanceArray[0][1] == 0 && current->balanceArray[0][2] == 0){

        current->generalBalance = 0;        
    }
    else{
        //Sum of Column to make balance
        bc = 0;
        stop = 0;
        do{
            arr1[bc][0] = current->balanceArray[bc][1];
            arr1[bc][1] = current->balanceArray[bc][2];
            bc++;
            stop++;
        }while(stop != bd);

        for(i=0;i<bd;i++) {
        csum[i]=0;
        for(j=0;j<bd;j++)
            csum[i]=csum[i]+arr1[j][i];
        }
        current->generalBalance = csum[0] - csum[1];
    }
        //printf("ag: %d\n",ag);
        //printf("bd: %d\n",bd);
        load_array(countArray2, num_accounts);
        //printf("countArray2[1][1]: %d\n",countArray2[1][1]);
        //printf("countArray2[1][2]: %d\n",countArray2[1][2]);
        //printf("countArray2[1][3]: %d\n",countArray2[1][3]);
        //printf("countArray2[1][4]: %d\n",countArray2[1][4]);
        //printf("countArray2[1][5]: %d\n",countArray2[1][5]);
        ag++;        
        current->next = malloc(sizeof(ACCOUNT));
        current = current->next;
        current->next = NULL;
    }while(!feof(pFile));



    fclose (pFile);

}

void print_all_led(ACCOUNT *current) {

    load_all_led(current);
    printf("num_accounts: %d\n",num_accounts);

    ba = 1;
    printf("No.\tAccount\t\tType\n");
    stop2 = 0;
    do{
        print_led(current, bb, countArray2, bc, stop, ba);
        current = current->next;
        stop2++;
        ba++;
    }while(stop2 != num_accounts);
}

void print_all_led2(ACCOUNT *current) {

    int trial = 0;

    load_all_led(current);
    printf("num_accounts: %d\n",num_accounts);

    printf("No.\tAccount\t\tType\n");
    stop2 = 0;
    do{
        print_led2(current);
        trial = trial + current->generalBalance;
        current = current->next;
        stop2++;
        // printf("countArray2[1][1]: %d\n",countArray2[1][1]);
        // printf("countArray2[1][2]: %d\n",countArray2[1][2]);
        // printf("countArray2[1][3]: %d\n",countArray2[1][3]);
        // printf("countArray2[1][4]: %d\n",countArray2[1][4]);
        // printf("countArray2[1][5]: %d\n",countArray2[1][5]);
    }while(stop2 != num_accounts);
    printf("\n");
    printf("Trial balance: %d\n",trial);
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
                    journal(current, ef, ea, sourceArray, ee, amountArray, ed, fa, response2, comment, fb, jou_count, countArray2, num_accounts);            
                    break;
            }
        } while (menu_logs != 3);
        return 0;
}

void results(ACCOUNT *current) {

    int aaaa = 0;
    
    printf("No.\tAccount\t\tType\tBalance\n");
    do{
        load_all_led(current);
        aaaa++;
        do{
            if(current->account_type == aaaa){
                print_acc2(current);
            }
            current = current->next;
        }while(current->next != NULL);
    }while(aaaa < num_accounts);

}


int main () {

    ACCOUNT* head = NULL;
    head = malloc(sizeof(ACCOUNT));
    head->next = NULL;
    ACCOUNT* current = NULL;
    current = head;

    int menu_option;

    load_journal_count(jou_count);

    do {
        printf("Which function do you want to do?\n 1. Account menu \n 2. Ledger menu \n 3. Journal menu \n 4. Results \n 9. Exit \n");
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
            case 9:
                printf("Thank you...\n");
                getchar();
                exit(0);        
                break; 
            
            default:
                printf("Not found\n");
        }    

    } while (menu_option != 9);

    getchar();

}
