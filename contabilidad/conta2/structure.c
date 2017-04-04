#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct struct_cuenta {
        int id;
        char account_name [25];
        int balance;
        struct struct_cuenta *next;
    };
typedef struct struct_cuenta CUENTA;

void print (CUENTA *cuenta) {
    printf("%d\t", cuenta->id);
    printf("%s\t", cuenta->account_name);
    printf("(%d)\n", cuenta->balance);
} 

void print_all(CUENTA *current) {        
    while(current != NULL) {
        print(current);
        current = current->next;
    }
}

void add_account(CUENTA* current) {
    while(current->next != NULL) {
         current = current->next;
         printf("NO ES NULO: ");
    }
    printf("Dame el id de la cuenta: ");
    scanf("%d", &current->id );
    printf("Dame el nombre de la cuenta: ");
    scanf("%s", current->account_name);
    printf("Dame el balance de la cuenta: ");
    scanf("%d", &current->balance );
    
    current->next = malloc(sizeof(CUENTA));    
    current->next->next = NULL;
}

int main() {
    CUENTA* head = NULL;
    CUENTA* current = NULL;
    char response[] = "no";

    head = malloc(sizeof(CUENTA));
    head->next = NULL;
    current = head;
    do {                
        add_account(current);        
        printf("Quieres agregar otra (s/n)");
        scanf("%s", response);
        if (response[0] == 's') {
        }
    } while (response[0] == 's');


    print_all(head);

    return 0;
}