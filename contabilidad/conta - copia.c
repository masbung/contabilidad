#include <stdio.h>
#include <stdlib.h>

char g_account_name[10][100];
int g_balance[10];

void save(char AccountName[100], int balance) {
    FILE *pFile;
    pFile = fopen("data.txt" , "a"); 
    fprintf (pFile,AccountName);
    fprintf (pFile,"\t %d",balance);
    fprintf (pFile," \n");
    fclose (pFile);                  
}

void load() {
    char c;
    FILE *pFile;
    pFile = fopen("data.txt" , "r");   

    if (pFile != NULL) {
        do {
            c = fgetc(pFile);
            printf("%c", c);
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

