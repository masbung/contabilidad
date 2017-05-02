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

int new_password(){
    int i=0;
    printf("\n Digita una contrasena [maximo 10 letras o numeros]: ");
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
    pFile = fopen("password.txt" , "w");
    fprintf (pFile,"%s",password);
    fclose (pFile);
    return 0;
}

int old_password (){

    int i=0;
    printf("Contrasena?");
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
    return 0;
}