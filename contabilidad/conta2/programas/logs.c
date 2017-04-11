#include <stdio.h>
#include <stdlib.h>

char Month1 [12] = {'J','F','M','A','M','J','J','A','S','O','N','D'};
char Month2 [12] = {'a','e','a','p','a','u','u','u','e','c','o','i'};
char Month3 [12] = {'n','b','r','r','y','n','l','g','p','t','v','c'};

/*
//Te dice que mes corresponde a cada numero pero necesito "pararlo" de alguna forma
char Jan[5] = "Jan";
char Feb[5] = "Feb";
char Mar[5] = "Mar";
char Apr[5] = "Apr";
char May[5] = "May";
char Jun[5] = "Jun";
char Jul[5] = "Jul";
char Aug[5] = "Aug";
char Sep[5] = "Sep";
char Oct[5] = "Oct";
char Nov[5] = "Nov";
char Dic[5] = "Dic";*/

/*void print_select_date(CUENTA *current) {

    / * RANGO DE FECHAS
    int day1, day2, month1, month2, year1, year2;

    printf("Digita a partir de que fecha quieres saber los rangos en formato dia, mes año: 00/00/000 \n");
    scanf("%02d/%02d/%04d",&day1, &month1, &year1);
    printf("Digita hasta que fecha quieres saber los rangos en formato dia, mes año: 00/00/000 \n");
    scanf("%02d/%02d/%04d",&day2, &month2, &year2);

    printf("El rango de fecha que seleccionaste es del %d/%d/%d al %d/%d/%d \n", day1, month1, year1, day2, month2, year2 );* /


    if (compare(Jan,current->month) == 0){
        int compare_month1 = 1;
        printf("%d \n",compare_month1);
    }
    if (compare(Feb,current->month) == 0){
        int compare_month2 = 2;
        printf("%d \n",compare_month2);
    }
    if (compare(Mar,current->month) == 0){
        int compare_month3 = 3;
        printf("%d \n",compare_month3);
    }
    if (compare(Apr,current->month) == 0){
        int compare_month4 = 4;
        printf("%d \n",compare_month4);
    }
    if (compare(May,current->month) == 0){
        int compare_month5 = 5;
        printf("%d \n",compare_month5);
    }
    if (compare(Jun,current->month) == 0){
        int compare_month6 = 6;
        printf("%d \n",compare_month6);
    }
    if (compare(Jul,current->month) == 0){
        int compare_month7 = 7;
        printf("%d \n",compare_month7);
    }
    if (compare(Aug,current->month) == 0){
        int compare_month8 = 8;
        printf("%d \n",compare_month8);
    }
    if (compare(Sep,current->month) == 0){
        int compare_month9 = 9;
        printf("%d \n",compare_month9);
    }
    if (compare(Oct,current->month) == 0){
        int compare_month10 = 10;
        printf("%d \n",compare_month10);
    }
    if (compare(Nov,current->month) == 0){
        int compare_month11 = 11;
        printf("%d \n",compare_month11);
    }
    if (compare(Dic,current->month) == 0){
        int compare_month12 = 12;
        printf("%d \n",compare_month12);
    }

}*/

struct struct_cuenta {
        int id;
        int id2;
        char account_name [25];
        char account_name2 [25];
        int balance;
        int balance2;
        int move;

        char day [5];
        char month [5];
        int num;
        int year;
        int hour;
        int minute;
        int second;

        struct struct_cuenta *next;
    }; typedef struct struct_cuenta CUENTA;
void print (CUENTA *cuenta) {
    printf("%s ", cuenta->day);
    printf("%s ", cuenta->month);
    printf("%d ", cuenta->num);
    printf("%02d:", cuenta->hour);
    printf("%02d:", cuenta->minute);
    printf("%02d ", cuenta->second);
    printf("%d\t", cuenta->year);
    printf("%d\t", cuenta->id);
    printf("%s\t", cuenta->account_name);
    printf("(%d)\t  \t ", cuenta->balance);
    printf("%d\t", cuenta->id2);
    printf("%s\t", cuenta->account_name2);
    printf("(%d)\t", cuenta->balance2);
    printf("    %d\n", cuenta->move);
}

/*int compare(char *a, char *b, char *c, char *d, char *e, char *f){
    int a,b,c = 0;
    int i = 1;
    while ( (a != '\0' && *d != '\0' && *a - *d == 0) && (b != '\0' && *e != '\0' && *b - *e == 0) (c != '\0' && *f != '\0' && *c - *f == 0) ){
        a++;
        b++;
        c++:
        i++;
    } return i;
}*/

void print_all(CUENTA *current) {
    printf("Date\t\t\t\tNo.\tCuenta\tBalance\t a \t No.\tCuenta\tBalance\tMovimiento\n");
    do{
        print(current);
        current = current->next;
    }while(current != NULL);
}

void print_select(CUENTA *current) {

    int id_account;

    printf("Cuenta que quieras saber sus movimientos\n");
    scanf("%d", &id_account);
    printf("Date\t\t\t\tNo.\tCuenta\tBalance\t a \t No.\tCuenta\tBalance\tMovimiento\n");
    do{
        if (id_account == current->id || id_account == current->id2){
            print(current);
        }       
        current = current->next;
    }while(current != NULL);
}

void print_select_date(CUENTA *current) {
    
    int l = 0;
    //int i = 0;
    int a = 5;
    int b = 5;
    int c = 5;

    //while (Month1[l] - current->month[0] == 0 && Month2[l] - current->month[1] == 0 && Month3[l] - current->month[2] == 0);

    printf("%d %d %d", a, b, c);    
    a = Month1[l] - current->month[0];
    b = Month2[l] - current->month[1];
    c = Month3[l] - current->month[2];
    printf("%d %d %d", a, b, c);
    
    /*int l = 0;
    int a = 5;
    while(l <= 3){
        printf("%c%c%c\n",Month1[l],Month2[l],Month3[l]);
        l++;
    }
    printf("%d",l);*/

    /*printf("%d\n",a);
    a = Month1[0] - current->month[0];
    printf("%d\n",a);*/

}


    
void load_logs(CUENTA *current) {
    FILE *pFile;
    pFile = fopen("logscopia.txt" , "r"); 

    if(pFile != NULL) {
        do {
            
            fscanf(pFile,"%s %s %d %02d:%02d:%02d %d %d %s %d %d %s %d %d", current->day, current->month, &current->num, &current->hour, &current->minute, &current->second, &current->year, &current->id, current->account_name, &current->balance, &current->id2, current->account_name2, &current->balance2, &current->move);
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
    printf("Que funcion quieres hacer?\n 1. Cargar \n 2. Todos los logs \n 3. Seleccionar log \n 4. Seleccionar por fecha \n 5. Salir del programa \n");
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
            case 4:
                print_select_date(current);            
                break;
        }
    } while (menu_option != 5); 

    getchar();
    
}