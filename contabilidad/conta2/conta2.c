#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct struct_cuenta {//funcion de structure.c
        int id;
        char account_name [25];
        int balance;
        struct struct_cuenta *next;
    }; typedef struct struct_cuenta CUENTA;

void print (CUENTA *cuenta) {//funcion de structure.c
    printf("%d\t", cuenta->id);
    printf("%s\t", cuenta->account_name);
    printf("(%d)\n", cuenta->balance);
} 

void print_all(CUENTA *current) {//funcion de structure.c
    while(current != NULL) {
        print(current);
        current = current->next;
    }
}

void add_account(CUENTA* current) {//funcion de structure.c
    while(current->next != NULL){
        current = current->next;
    }
        printf("Dame el id de la cuenta: ");
        scanf("%d", &current->id );
        printf("Dame el nombre de la cuenta: ");
        scanf("%s", current->account_name);
        printf("Dame el balance de la cuenta: ");
        scanf("%d", &current->balance );
        
        current->next = malloc(sizeof(CUENTA));    
        current->next->next = NULL;
}


int clear(){ //main de structure.c
    CUENTA* head = NULL;
    head = malloc(sizeof(CUENTA));
    head->next = NULL;
    CUENTA* current = NULL;
    current = head;
    char response[] = "no";
    do {                
        add_account(current);        
        printf("Quieres agregar otra (s/n)");
        scanf("%s", response);
        if (response[0] == 's') {
        }
    } while (response[0] == 's');
    return 0;
}

void load_all() {
    char c;
    int r; //add
    r = 0;
    int i = 0;
    accounts_count = 0;
    FILE *pFile;
    pFile = fopen("accounts.txt" , "r"); 
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

int main() {

    CUENTA* head = NULL;
    CUENTA* current = NULL;

    head = malloc(sizeof(CUENTA));
    head->next = NULL;
    current = head;

int menu_option;     
    do {
        printf("Que funcion quieres hacer?\n 1. Listar cuentas \n 2. Agregar cuentas \n 3. Realizar un movimiento \n 4. Salir del programa\n");
        scanf("%d",&menu_option);    
        switch (menu_option) {
            case 1:                          
                list_accounts();             
                break; 
            case 2:
                clear();                     
                break;
            case 3:
                //make_move();                    
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

    getchar();
}