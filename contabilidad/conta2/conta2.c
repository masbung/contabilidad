#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


int main () { 
    int menu_option;     
    load_all();
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
            case 3:
                make_move();                    
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