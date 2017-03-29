#include <stdio.h>
#include <string.h>

//Si reconoce los tabs 

int main ()
{
    char buf[] ="Hola	Como	Estas";
    int i = 0;
    char *p = strtok (buf, "\t");
    char *array[3];

    while (p != NULL)
    {
        array[i++] = p;
        p = strtok (NULL, "\t");
    }

    for (i = 0; i < 3; ++i) 
        printf("%s \n", array[i]);
        
    return 0;
    
}