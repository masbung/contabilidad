#include <stdio.h>

int main (){
    FILE *pFile;
    char line[100];
    pFile = fopen ("data2.txt","r");

    if(pFile != NULL){
        while (!feof(pFile)){
            fgets(line,100,pFile);
            printf ("%s",line);
        }
    }

    else 
        printf ("No pudo abrir el archivo");

    getchar();
}