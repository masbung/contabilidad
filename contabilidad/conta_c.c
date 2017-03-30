#include <stdio.h>
#include <stdlib.h>

char g_account_name[10][100];
int g_balance[10];
int r;
int accounts_count;

void save(char AccountName[100], int balance) {
    FILE *pFile;
    pFile = fopen("data.txt" , "a"); 
    fprintf (pFile,"\n%s",AccountName);
    fprintf (pFile," %d",balance);
    fclose (pFile);                  
}

void load() {
    char c;
    r = 0;
    int i = 0;
    accounts_count = 0;
    FILE *pFile;
    //char temp_account_name[100];
    /* pFile = fopen("data.txt" , "r"); */
    pFile = fopen("data.txt" , "r"); 

    if(pFile != NULL) {
        do {
            do  {
                c = fgetc(pFile);
                if ( c != EOF && c != ' ' && c != '\n') {
                    g_account_name[r][i] = c;
                }
                i = i + 1;
            } while (c != EOF && c != ' ' && c != '\n');
            g_account_name[r][i-1] = '\0';
            i = 0;
            /*
            c = fgetc(pFile);
            while (c >= '0' && c <= '9') {
                c = fgetc(pFile);

            }
            g_balance[r]=0;
            */
            
            fscanf (pFile,"%d",&g_balance[r]);
            c = fgetc(pFile);  

            r = r + 1;
        } while (c != EOF);
    } 
    else 
        printf ("No se pudo abrir el archivo. \n");

    fclose (pFile);
    accounts_count = r;    
}

void list_accounts() {
    /* load();  esto NO se debe hacer, porque pierde lo que tenia en memoria */
    for (int r = 0; r < accounts_count; r++) {
        printf("%d. %s (%d)\n",r, g_account_name[r], g_balance[r]);
    }
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
    load();
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
