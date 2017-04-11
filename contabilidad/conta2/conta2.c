#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "password.h"
#include "accounting.h"
#include "logs.h"

int main() {

    CUENTA* head = NULL;
    head = malloc(sizeof(CUENTA));
    head->next = NULL;
    CUENTA* current = NULL;
    current = head;

    char response[] = "no";
    int menu_option;

    char c;
    int user_id;

    printf("ID\n");
    scanf("%d", &user_id);
    if (user_id == 1){
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
                        printf("Que funcion quieres hacer?\n 1. Listar cuentas \n 2. Agregar cuentas \n 3. Realizar un movimiento \n 4. Salir del programa \n 5. Guardar \n 6. Cargar \n 7. Menu logs \n");
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
                            case 7: 
                                logsmenu();
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
    else{
        FILE * fPointer;
        fPointer = fopen ("password.txt","r");
        if (fPointer != NULL){
            do{
                c = fgetc(fPointer);
                if (c != EOF && c != ' ' && c != '\n'){
                    fclose(fPointer);
                //pasword_pass-begin HACER MENU
                    FILE * fPointer;
                    fPointer = fopen ("password_id2.txt", "r");
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
}


    