#include <stdio.h>
#include <stdlib.h>

int num1, num2;
int *pnum1 = &num1;
int *pnum2 = &num2;
char name [25];
char first_line[50];
 
void load_logs() {

    char c;
    int i = 0;
    
    FILE *pFile;
    pFile = fopen("logscopia3.txt" , "r"); 

    if(pFile != NULL) {
        do {
            do  {
                c = fgetc(pFile);
                if ( c != EOF && c != ' ' && c != '\n'){
                    first_line[i] = c;
                }
                i = i + 1;
            } while (c == '*');
            first_line[i-1] = '\0';
            i=0;

            fscanf(pFile,"%d %s %d", &num1, name, &num2);

        } while (!feof(pFile));

    fclose (pFile);
    }
}

void print_all() {
    printf("%d %s %d \n", *pnum1, name, *pnum2);
}

int main () {

    int menu_option;

    do {
    printf("Que funcion quieres hacer?\n 1. Cargar \n 2. Todos los logs \n 3. Seleccionar log \n 4. Salir del programa \n");
    scanf("%d",&menu_option);    
    
        switch (menu_option) {
            case 1:
                load_logs();            
                break;
            case 2:
                print_all();            
                break;
        }
    } while (menu_option != 4); 

    getchar();
    
}