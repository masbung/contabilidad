#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "accounts.h"
#include "ledger.h"
#include "journal.h"

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
    printf("\t\t\t\t%s\t%d\t%d\t\t%d\n",account->account_name, account->id, account->balanceArray[0][1], account->jou_count2);
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

void print_current_jou(ACCOUNT *current, int sourceArray[1][40], int fb, int amountArray[40][2], int ee, int fa, char comment[30], char response2[3] ){

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
        load_source(ee, sourceArray);
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

void save_current_jou(ACCOUNT *current, int jou_count, int sourceArray[1][40], int amountArray[40][2], int ee, int fa, char response2[3], char comment[30] ) {

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
        load_source(ee, sourceArray);
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

    save_journal_count(jou_count);

    fclose (pFile);    
}

void save_in_ledger(ACCOUNT *current, int ee, int sourceArray[1][40], int countArray2[1][50], int amountArray[40][2], int ed, int num_accounts ) {

    //Cambia el nombre de la segunda cuenta al momento de meter dos entradas en el credito
    int ca, stop3, cb, cc=1, cd, stop8=0,ce,stop6;
    int d2,d3;
    FILE *pFile;

    load_all_led( current);
    load_source(ee, sourceArray);
    pFile = fopen("ledger.txt" , "w");
    do{
        printf("Current id: %d\n",current->id);
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
                        //printf("Stop 6: %d\n",stop6);
                        //printf("cb: %d\n",cb);
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
        stop8++;
        if(stop8 == num_accounts){
            fprintf(pFile,"*");
        }
        else{
            fprintf(pFile,"*\n");
        }
        cc++;        
        current = current->next;
    }while(stop8 != num_accounts);

    fclose (pFile);
}

void journal(ACCOUNT *current, int ef, int ea, int sourceArray[1][40], int ee, int amountArray[40][2], int ed, int fa, char response2[3], char comment[30], int fb, int jou_count, int countArray2[1][50], int num_accounts ) {//Scan comment with spaces 

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
        save_source(ee, sourceArray);

        printf("Do you want to add a comment? y/n\n");
        scanf("%s", response2);
        if (response2[0] == 'y'){
            printf("Comment: \n");
            scanf("%s",comment);
            print_current_jou(current, sourceArray, fb, amountArray, ee, fa, comment, response2);
            save_current_jou(current,  jou_count, sourceArray, amountArray, ee, fa, response2, comment);
            save_in_ledger(current, ee, sourceArray, countArray2, amountArray, ed, num_accounts);
        }
        
        else{
            print_current_jou(current, sourceArray, fb, amountArray, ee, fa, comment, response2);
            save_current_jou(current,  jou_count, sourceArray, amountArray, ee, fa, response2, comment);
            save_in_ledger(current, ee, sourceArray, countArray2, amountArray, ed, num_accounts);
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

/*void results(ACCOUNT *current, int num_accounts) {

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
    printf("Num accounts: %d\n",num_accounts);
    }while(aaaa < num_accounts);

}*/