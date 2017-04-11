void load_logs(CUENTA *current) {
    FILE *pFile;
    pFile = fopen("logs.txt" , "r"); 

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

void print_logs (CUENTA *cuenta) {
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

void print_all_logs(CUENTA *current) {
    printf("Date\t\t\t\tNo.\tCuenta\tBalance\t a \t No.\tCuenta\tBalance\tMovimiento\n");
    do{
        print_logs(current);
        current = current->next;
    }while(current != NULL);
}

void print_select_logs(CUENTA *current) {

    int id_account;

    printf("Cuenta que quieras saber sus movimientos\n");
    scanf("%d", &id_account);
    printf("Date\t\t\t\tNo.\tCuenta\tBalance\t a \t No.\tCuenta\tBalance\tMovimiento\n");
    do{
        if (id_account == current->id || id_account == current->id2){
            print_logs(current);
        }       
        current = current->next;
    }while(current != NULL);
}

int logsmenu(){
    CUENTA* head = NULL;
    head = malloc(sizeof(CUENTA));
    head->next = NULL;
    CUENTA* current = NULL;
    current = head;

    int menu_logs;

    do {
        printf("Que funcion quieres hacer?\n 1. Cargar \n 2. Todos los logs \n 3. Seleccionar log \n 4. Menu principal \n");
        scanf("%d",&menu_logs);    
        
            switch (menu_logs) {
                case 1:
                    load_logs(current);            
                    break;
                case 2:
                    print_all_logs(current);            
                    break;
                case 3:
                    print_select_logs(current);            
                    break;
            }
        } while (menu_logs != 4);
        return 0;
}