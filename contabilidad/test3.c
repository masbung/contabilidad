#include <stdio.h>

int main (){

    char g_account_name[10][100];
    int c;
    int r = 0;
    int i = 0;
    FILE *pFile;
    pFile = fopen("data2.txt" , "r"); 

    if(pFile != NULL) {
        do {
            do  {
                c = fgetc(pFile);
                if ( c != EOF && c != ' ') {
                    g_account_name[r][i] = c;
                    printf ("%c",g_account_name[r][i]); 
                }
                i = i + 1;
            } while (c != EOF && c != ' '); /* (!feof(pFile)) */
            g_account_name[r][i] = '\0';
            r = r + 1;
            i = 0;
        } while (c != EOF);
    } 
    else 
        printf ("No pudo abrir el archivo");

    fclose (pFile);

    for (int l = 0; l < r; l++) {
        printf("%s\n", g_account_name[l]);
    }

    getchar();
}