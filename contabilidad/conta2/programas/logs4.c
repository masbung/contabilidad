#include <stdio.h>
#include <stdlib.h>

/*int num1, num2;
int *pnum1 = &num1;
int *pnum2 = &num2;*/
char day [5];
char month [5];
int num, hour,min,year;
int *pnum = &num;
int *phour = &hour;
int *pyear = &year;

struct time {
  int hour;
  int minute;
  int second;
};

struct time when;

 
void load_logs() {
    

    /*char c;
    int i = 0;*/
    
    FILE *pFile;
    pFile = fopen("logscopia4.txt" , "r"); 

    if(pFile != NULL) {
        do {

            fscanf(pFile,"%s %s %d %02d:%02d:%02d %d", day, month, &num, &when.hour, &when.minute, &when.second, &year);
            //fscanf(pFile,"%s %s %d %d", day, month, &num, &hour);

        } while (!feof(pFile));

    fclose (pFile);
    }
}

void print_all() {
    printf("Hey\n");
    printf("%s %s %d %d:%d:%d %d\n",day, month, *pnum, when.hour, when.minute, when.second, *pyear);
    //printf("The hour is = %d:%d:%d\n",when.hour, when.minute, when.second);
    //printf("%d %s %d \n", *pnum1, name, *pnum2);
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