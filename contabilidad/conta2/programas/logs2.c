#include <stdio.h>
#include <stdlib.h>

struct struct_cuenta {
        int id;
        int id2;
        char account_name [25];
        char account_name2 [25];
        int balance;
        int balance2;
        int move;
        struct struct_cuenta *next;
    }; typedef struct struct_cuenta CUENTA;
void print (CUENTA *cuenta) {
    printf("%d\t\t", cuenta->id);
    printf("%s\t\t", cuenta->account_name);
    printf("(%d)\t\t \t", cuenta->balance);
    printf("%d\t\t", cuenta->id2);
    printf("%s\t\t", cuenta->account_name2);
    printf("(%d)\t", cuenta->balance2);
    printf("    %d\n", cuenta->move);
} 

void print_all(CUENTA *current) {
    printf("No.\t\tCuenta\t\tBalance\t\ta\tNo.\t\tCuenta\t\tBalance\tMovimiento\n");
    while(current != NULL) {
        print(current);
        current = current->next;
    }
}

void print_select(CUENTA *current) {

    int id_account;

    printf("Cuenta que quieras saber sus movimientos\n");
    scanf("%d", &id_account);
    printf("No.\t\tCuenta\t\tBalance\t\ta\tNo.\t\tCuenta\t\tBalance\t\tMovimiento\n");
    do{
        if (id_account == current->id || id_account == current->id2){
            print(current);
        }       
        current = current->next;
    }while(current != NULL);
}

    
void load_logs(CUENTA *current) {
    FILE *pFile;
    pFile = fopen("logscopia2.txt" , "r"); 

    if(pFile != NULL) {
        do {
            fscanf(pFile,"%d %s %d %d %s %d %d", &current->id, current->account_name, &current->balance, &current->id2, current->account_name2, &current->balance2, &current->move);
            current->next = malloc(sizeof(CUENTA));
            current = current->next;
            current->next = NULL; 

        } while (!feof(pFile));

    fclose (pFile);
    }
}

int main () {

    CUENTA* head = NULL;
    head = malloc(sizeof(CUENTA));
    head->next = NULL;
    CUENTA* current = NULL;
    current = head;

    int menu_option;

    do {
    printf("Que funcion quieres hacer?\n 1. Cargar \n 2. Todos los logs \n 3. Seleccionar log \n 4. Salir del programa \n");
    scanf("%d",&menu_option);    
    
        switch (menu_option) {
            case 1:
                load_logs(current);            
                break;
            case 2:
                print_all(current);            
                break;
            case 3:
                print_select(current);            
                break;
        }
    } while (menu_option != 4); 

    getchar();
    
}