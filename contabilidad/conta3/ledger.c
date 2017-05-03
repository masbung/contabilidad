#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "accounts.h"
#include "ledger.h"

//LEDGER.txt

void save_array(int countArray2[1][50], int num_accounts) {
    int b = 0;
    FILE *pFile;
    pFile = fopen("array.txt" , "w");
    do {
        b++;
        fprintf(pFile,"%d ",countArray2[1][b]);        
    }while(b != num_accounts);
    fclose (pFile);
}

void load_array(int countArray2[1][50], int num_accounts) {
    int c = 0;
    FILE *pFile;
    pFile = fopen("array.txt" , "r");
    do {
        c++;
        fscanf(pFile,"%d",&countArray2[1][c]);        
    }while(c != num_accounts);
    fclose (pFile);
}

/*void load_all_led(ACCOUNT *current,int k, int nl, int nw, int nc, int elt, int ast, int num_accounts, int state, int arr1[30][30], int csum[30], int countArray[1][50], int countArray2[1][50],int aa, int ab, int ac, int ad, int ae, int af, int ag, int stop, int stop2, int bd, int bc) {//LA CUENTA UNO DEBE DE TENER MAS LOGS QUE LAS OTRAS 
    
    char asterisk[5]; //asterisks in ledger 

    nl = nw = nc = elt = ast = stop = stop2 = 0;
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

}*/

void print_led(ACCOUNT *account, int bb, int countArray2[1][50], int bc, int stop, int ba) {

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
    printf("Balance: %d\n",account->generalBalance);

}

void print_led2(ACCOUNT *account) {

    printf("%d\t", account->id);
    printf("%s\t", account->account_name);
    printf("%d\n", account->account_type);
    printf("Balance: %d\n",account->generalBalance);

}

/*void print_all_led(ACCOUNT *current, int ba, int stop2, int num_accounts) {

    load_all_led(current, k, nl, nw, nc, elt, ast, num_accounts, state, arr1, csum, countArray, countArray2,  aa,  ab, ac, ad, ae, af, ag, stop, stop2, bd, bc);

    ba = 1;
    printf("No.\tAccount\t\tType\n");
    stop2 = 0;
    do{
        print_led(current, bb, countArray2, bc, stop, ba);
        current = current->next;
        stop2++;
        ba++;
    }while(stop2 != num_accounts);
}*/

//Extras 

void save_source(int ee, int sourceArray[1][40]) {
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

void load_source(int ee, int sourceArray[1][40]) {
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

void load_journal_count(int jou_count) {

    FILE *pFile;
    pFile = fopen("journal_count.txt" , "r");
    fscanf(pFile,"%d",&jou_count);
    fclose (pFile);
}

void save_journal_count(int jou_count) {

    FILE *pFile;
    pFile = fopen("journal_count.txt" , "w");
    fprintf(pFile,"%d",jou_count);
    fclose (pFile);
}
