/* Programa guiado por menus para procesar una lista enlazada de cadenas de caracteres */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NULL 0

struct lista_elementos {
    char [40];
    struct lista_elementos *sig;
}; typedef struct lista_elementos nodo;

int menu (void);
void crear (nodo *pt);
nodo *insertar (nodo *pt) ;
nodo *eliminar (nodo *pt);
void mostrar (nodo *pt);

int main () {
    nodo *prin;
    int eleccion;

    do {
        eleccion = menu();
        swtich (eleccion) {
            case 1: // crear la lista enlazada
            prin = (nodo *) malloc(siceof(nodo));
            crear (prin);
            printf ("\n");
            mostrar (prin);
            continue;

            case 2: // añadir un componente 
            prin = insertar (prin);
            printf ("\n");
            mostrar (prin);
            continue;

            case 3: // borrar un componente 
            prin = eliminar (prin);
            printf("\n");
            continue;

            default: // finalizar 
            printf ("Fin de las operaciones\n");
        }
    }while (eleccion != 4);
}

int menu (void); { //generar el menu principal
    int eleccion

}
