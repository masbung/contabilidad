int qty;
int *pqty = &qty;

int lastid;
int *plastid = &lastid;

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
    printf("%d\t\t", cuenta->id);
    printf("%s\t\t", cuenta->account_name);
    printf("(%d)\n", cuenta->balance);
}

void log1 (CUENTA *current) {

    time_t rawtime;
    struct tm * timeinfo;

    FILE *pFile;
    pFile = fopen("logs.txt" , "a");
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    fprintf (pFile,"%s\t\t\t\t\t\t\t%d\t\t",asctime (timeinfo),current->id);
    fprintf(pFile,"%s\t\t", current->account_name);
    fprintf(pFile,"%d\t", current->balance);
    
    fclose (pFile);           
}

int log2 (CUENTA *current) {

    FILE *pFile;
    pFile = fopen("logs.txt" , "a");
    fprintf(pFile,"\t\t\t\t%d\t\t", current->id);
    fprintf(pFile,"%s\t\t", current->account_name);
    fprintf(pFile,"%d\t", current->balance);
    fprintf(pFile,"\t\t%d \t",*pqty);
    fprintf(pFile,"\n");
    
    fclose (pFile);
    return 0;            
}

void log3 (CUENTA *current) {

    FILE *pFile;
    pFile = fopen("logs.txt" , "a");
    fprintf(pFile,"\t\t\t\t%d\t\t", current->id);
    fprintf(pFile,"%s\t\t", current->account_name);
    fprintf(pFile,"%d\t", current->balance);
    fprintf(pFile,"\t\t%d \t",*pqty);
    fprintf(pFile,"\n");
    
    fclose (pFile);         
}

int log4 (CUENTA *current) {

    time_t rawtime;
    struct tm * timeinfo;

    FILE *pFile;
    pFile = fopen("logs.txt" , "a");
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    fprintf (pFile,"%s\t\t\t\t\t\t\t",asctime (timeinfo));
    fprintf(pFile,"%d\t\t", current->id);
    fprintf(pFile,"%s\t\t", current->account_name);
    fprintf(pFile,"%d\t", current->balance);
    
    fclose (pFile);
    return 0;   
}

void add_account(CUENTA* current) {

    while(current->next->next->next != NULL){
        current = current->next;
    }
        printf("Dame el id de la cuenta: ");
        scanf("%d", &lastid);
        if(current->id + 1 == lastid){
            current = current->next;
            current->next = malloc(sizeof(CUENTA));    
            current->next->next = NULL;  
            current->id = *plastid;  
            printf("Dame el nombre de la cuenta: ");
            scanf("%s", current->account_name);
            printf("Dame el balance de la cuenta: ");
            scanf("%d", &current->balance );
        }        
        else{
            printf("Ese ID ya existe o no es el siguiente en la lista de cuentas\n");
        }
}

void print_all(CUENTA *current) {
    printf("No.\t\tCuenta\t\tBalance\n");
    while(current != NULL) {
        print(current);
        current = current->next;
    }
}

void save_all(CUENTA *current) {
    FILE *pFile;
    pFile = fopen("accounts.txt" , "w");
    while(current != NULL) {
        fprintf(pFile,"%d\t", current->id);
        fprintf(pFile,"%s\t", current->account_name);
        fprintf(pFile,"%d\n", current->balance);
        current = current->next;
    } 
    fclose (pFile);           
}

void load_all(CUENTA *current) {

    FILE *pFile;
    pFile = fopen("accounts.txt" , "r");
    do{
        fscanf(pFile,"%d %s %d", &current->id, current->account_name, &current->balance);
        current->next = malloc(sizeof(CUENTA));
        current = current->next;
        current->next = NULL;
    }while(!feof(pFile));
    fclose (pFile);
} 
    

void make_move(CUENTA *current){ //Que va a pasar cuando sean muchas cuentas?
    
    char response[] = "no";
    int source,dest;
    int updated = 0;
    
    printf("Quieres imrpimir todas las cuentas? s/n\n");
    scanf("%s", response);
    if (response[0] == 's'){
    print_all(current);}
    printf("Elige el numero de cuenta de retiro: ");
    scanf("%d",&source);
    printf("Elige el numero de cuenta de deposito: ");
    scanf("%d",&dest);
    printf("Elige la cantidad a mover: ");
    scanf("%d",&qty);

    if(source<dest){
        do {
            if (current->id == source){
                current->balance = current->balance - qty;
                log1(current);
            }
            if (current->id == dest){
                current->balance = current->balance + qty;
                log2(current);
            }
            updated++;
            current = current->next;
        }while (updated < 5 && current->next !=NULL); 
        //Aqui
    }
    else{
        do{
            if (current->id == source){
                    current->balance = current->balance - qty;
                    log3(current);
                }

            if (current->id == dest){
                    current->balance = current->balance + qty;
                    log4(current);
                }

                updated++;
                current = current->next;
        }while (updated < 5 && current->next !=NULL); 
        //Aqui
    }
} 
