#include <stdio.h>
#include <stdlib.h>

char g_account_name[10][100];
int g_balance[10];

void save(char AccountName[100], int balance) {
    FILE *pFile;
    pFile = fopen("data.txt" , "a"); 
    fprintf (pFile,"%s",AccountName);
    fprintf (pFile,"\t %d",balance);
    fprintf (pFile," \n");
    fclose (pFile);                  
}

void load() {
    char c;
    FILE *pFile;
    char temp_account_name[100];
    pFile = fopen("data.txt" , "r"); 

    if (pFile != NULL) {
        int r = 0; /* row o line */
        do {
            c = fgetc(pFile);
            int i = 0; /* indice del caracter */
            while (c != ' ') {
                g_account_name[r][i] = c;
                i = i + 1;
            }
            i = i + 1; /* brinco el espacio */
            printf("%s\n", g_account_name[r]);
            /* ahora el numero */
            while (c >= '0' && c <= '9') {
                i = i + 1;
            }
            /* ahora el enter */
            while (c != '\n' || c != EOF) {
                i = i + 1;
            } 
        } while (c != EOF);
        fclose (pFile);
    }
    else
        printf ("No se pudo abrir el archivo. \n");        
}

void list_accounts() {
    load();
}

void add_account() {
    char AccountName [100];
    int balance;

    printf("Nombre de la cuenta:");
    scanf ("%s",AccountName);            
    printf("Balance:");
    scanf ("%d",&balance);  
    save(AccountName, balance);
}

int main () { 
    int menu_option;     
    
    do {
        printf("Que funcion quieres hacer?\n 1. Listar cuentas \n 2. Agregar cuentas \n 3. Realizar un movimiento \n 4. Salir del programa\n");
        scanf("%d",&menu_option);    
        switch (menu_option) {
            case 1:                          
                list_accounts();              
                break; 
            case 2:
                add_account();                     
                break;  
            case 4:
                printf("Gracias...\n");
                getchar();
                exit(0);        
                break;
            default:
                printf("No encontrado");
        }    
        getchar();
    } while (menu_option != 4);
} 

