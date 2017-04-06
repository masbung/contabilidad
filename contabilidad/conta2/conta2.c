#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "password.h"

//contabilidad

int qty;
int *pqty = &qty; //Declare a pointer with *

struct struct_cuenta {
        int id;
        char account_name [25];
        int balance;
        struct struct_cuenta *next;
        struct struct_cuenta *previous;
    }; typedef struct struct_cuenta CUENTA;

void print (CUENTA *cuenta) {
    printf("%d\t\t", cuenta->id);
    printf("%s\t\t", cuenta->account_name);
    printf("(%d)\n", cuenta->balance);
} 

void log1 (CUENTA *current) {

    time_t rawtime;
    struct tm * timeinfo;

    FILE *pFile;
    pFile = fopen("logs.txt" , "a");
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    fprintf (pFile,asctime (timeinfo) );

    fprintf(pFile,"Cuenta de retiro:\n");
    fprintf(pFile,"No.\t\tCuenta\t\tBalance\n");
    fprintf(pFile,"%d\t\t", current->id);
    fprintf(pFile,"%s\t\t", current->account_name);
    fprintf(pFile,"%d\n", current->balance);
    
    fclose (pFile);           
}

int log2 (CUENTA *current) {//si la cuenta de deposito es la primera en seleccionar no imprime bien la fecha

    FILE *pFile;
    pFile = fopen("logs.txt" , "a");
    fprintf(pFile,"Cuenta de deposito:\n");
    fprintf(pFile,"No.\t\tCuenta\t\tBalance\n");
    fprintf(pFile,"%d\t\t", current->id);
    fprintf(pFile,"%s\t\t", current->account_name);
    fprintf(pFile,"%d\n", current->balance);
    fprintf(pFile,"Cantidad del movimiento %d \n",*pqty);
    fprintf(pFile,"\n");
    
    fclose (pFile);           
}

void add_account(CUENTA* current) {//Como se puede hacer que no pueda repetir el ID???
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

void print_all(CUENTA *current) {
    printf("No.\t\tCuenta\t\tBalance\n");
    while(current != NULL) {
        print(current);
        current = current->next;
    }
}

void save_all(CUENTA *current) {
    FILE *pFile;
    pFile = fopen("accounts.txt" , "w");
    while(current != NULL) {
        fprintf(pFile,"%d\t", current->id);
        fprintf(pFile,"%s\t", current->account_name);
        fprintf(pFile,"%d\n", current->balance);
        current = current->next;
    } 
    fclose (pFile);           
}

void load_all(CUENTA *current) {

    FILE *pFile;
    pFile = fopen("accounts.txt" , "r");
    do{
        fscanf(pFile,"%d %s %d", &current->id, current->account_name, &current->balance);
        current->next = malloc(sizeof(CUENTA));
        current = current->next;
        current->next = NULL;
    }while(!feof(pFile));
    fclose (pFile);
} 
    

void make_move(CUENTA *current){ 
    
    char response[] = "no";
    int source,dest;
    int updated = 0;

    /*int qty;
    int *pqty = pty; //Declare a pointer with **/
    
    printf("Quieres imrpimir todas las cuentas? s/n\n");
    scanf("%s", response);
    if (response[0] == 's'){
    print_all(current);}
    printf("Elige el numero de cuenta de retiro: ");
    scanf("%d",&source);
    printf("Elige el numero de cuenta de deposito: ");
    scanf("%d",&dest);
    printf("Elige la cantidad a mover: ");
    scanf("%d",&qty);
    
        do {
            if (current->id == source){
                current->balance = current->balance - qty;
                log1(current);
            }
            if (current->id == dest){
                current->balance = current->balance + qty;
                log2(current);
            }
            updated++;
            current = current->next;
        }while (updated < 3 && current->next !=NULL); 
        //Que va a pasar cuando sean muchas cuentas?
}
        

int main() {

    CUENTA* head = NULL;
    head = malloc(sizeof(CUENTA));
    head->next = NULL;
    CUENTA* current = NULL;
    current = head;

    char response[] = "no";
    int menu_option;

    char c;

    FILE * fPointer;
    fPointer = fopen ("password.txt","r");
    if (fPointer != NULL){
        do{
            c = fgetc(fPointer);
            if (c != EOF && c != ' ' && c != '\n'){
                fclose(fPointer);
            //pasword_pass-begin HACER MENU
                FILE * fPointer;
                fPointer = fopen ("password.txt", "r");
                while (!feof(fPointer)){
                fgets (password, 10, fPointer);
                }
                old_password ();
                if (compare(str,password) == 0){
                    printf("\nAccesso permitido\n\n");
            
                    do {
                    printf("Que funcion quieres hacer?\n 1. Listar cuentas \n 2. Agregar cuentas \n 3. Realizar un movimiento \n 4. Salir del programa \n 5. Guardar \n 6. Cargar\n");
                    scanf("%d",&menu_option);    
                    switch (menu_option) {
                        case 1:                          
                            print_all(current);            
                            break; 
                        case 2:
                            do {                
                                add_account(current);        
                                printf("Quieres agregar otra (s/n)");
                                scanf("%s", response);
                                if (response[0] == 's') {
                                }
                            } while (response[0] == 's');                   
                            break;
                        case 3:
                            make_move(current);                    
                            break;   
                        case 4:
                            printf("Gracias...\n");
                            getchar();
                            exit(0);        
                            break;
                        case 5: 
                            save_all(current);
                            break;
                        case 6: 
                            load_all(current);
                            break;
                        default:
                            printf("No encontrado");
                    }    
        
                } while (menu_option != 4);
                }

                else
                printf("Accesso denegado\n");
                fclose(fPointer);
                return 0;
                }
            //password_pass-ends 
            else{
            new_password();
            }
        }while(1>2);
    }
}


    