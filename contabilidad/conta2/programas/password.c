#include <stdio.h>
#include <stdlib.h>

char password [10], l=' ';
char str [10], m=' ';

int lenght (char *s){
    char *start = s;
    while (*s) s++;
    return s - start;
}

void trim(char *s){
    while (*s) s++; 
    while(*s == ' ' || *s == '\0' || *s == '\n') s--;
    *(s+1) = '\0';
}

int compare(char *s, char*t){
    while (*s != '\0' && *t != '\0' && *s - *t == 0){
        s++;
        t++;
    } return *s - *t;
}

int old_password (){

    int i=0;
    printf("Password?");
    while (i<=9){
        str[i]=getch();
        m=str[i];
        if(m==13) break;
        else printf("*");
        i++;
    }
    str[i]='\0';
    i=0;
    trim(str);
    compare (str, password);
}

int password_pass1(){
    FILE * fPointer;
    fPointer = fopen ("password1.txt", "r");
    while (!feof(fPointer)){
    fgets (password, 10, fPointer);
    }
    old_password();
    if (compare(str,password) == 0){
        printf ("\nAcceso conseguido\n");
    menu();
    }else {
        printf("Accesso denegado\n");
    }
    fclose(fPointer);
    return 0;
}

int password_pass2(){
    FILE * fPointer;
    fPointer = fopen ("password2.txt", "r");
    while (!feof(fPointer)){
    fgets (password, 10, fPointer);
    }
    old_password();
    if (compare(str,password) == 0){
        printf ("\nAcceso conseguido\n");
    menu();
    }else {
        printf("Accesso denegado\n");
    }
    fclose(fPointer);
    return 0;
}

int new_password(){
    int i=0;
    printf("\n Enter the password [max length 10] : ");
    while (i<=9){
    password[i]=getch();
    l=password[i];
    if(l==13) break;
    else printf("*");
    i++;
    }
    password[i]='\0';
    i=0;
    FILE *pFile;
    pFile = fopen("password3.txt" , "w");
    fprintf (pFile,"%s",password);
    fclose (pFile);
    return 0;
}

int access(){

    char c;
    int user_id;

    printf("ID");
    scanf("%d", &user_id);

    if (user_id == 1){
    FILE * fPointer;
    fPointer = fopen ("password1.txt","r");
    if (fPointer != NULL){
        do{
            c = fgetc(fPointer);
            if (c != EOF && c != ' ' && c != '\n'){
            password_pass1();
            } 
            else{
            new_password();
            }
        }while(1>2);
    }
    fclose(fPointer);
    return 0;
    }
    else{
    FILE * fPointer;
    fPointer = fopen ("password2.txt","r");
    if (fPointer != NULL){
        do{
            c = fgetc(fPointer);
            if (c != EOF && c != ' ' && c != '\n'){
            password_pass2();
            } 
            else{
            new_password();
            }
        }while(1>2);
    }
    fclose(fPointer);
    return 0;

    }
}


int menu(){
    int menu_option; 
    do {
        printf("Menu... 1 2 3 4");
        scanf("%d",&menu_option);    
        switch (menu_option) {
            case 1:                          
                printf("Uno\n");              
                break; 
            case 2:
                printf("Dos\n");                       
                break;
            case 3:
                printf("Tres");                       
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
    return 0;
}


int main (){

    access();

}