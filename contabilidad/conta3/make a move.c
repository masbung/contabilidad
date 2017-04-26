/*void make_move(ACCOUNT *current){//Debit or credit logic 
    
    char response[] = "no";
    int source,dest;
    int amountArray [50][2];
    
    printf("Do you want to print all accounts? y/n\n");
    scanf("%s", response);
    if (response[0] == 'y'){
        print_all_acc(current);
    }
    printf("Choose account number: \n");
    scanf("%d",&source);
    printf(" 1. Debit or 2. Credit? \n");
    scanf("%d",&dest);
    
    if (dest == 1) {
        do{
            printf("Enter amount: ");
            scanf("%d",&amountArray[a][b]);
            amountArray[a][c] = 0;
            printf("Want to make other entry? y/n\n");
            scanf("%s", response);
            i++;
            a++;
        }while (response[0] == 'y');
        a = 1;
    
        do{
            if(source == current->id){
                print_acc(current);
            }
            current = current->next;
        }while(source == current->id);

        do{
            printf("%d\t", amountArray[a][b]);
            printf("%d\n", amountArray[a][c]);
            a++;
            j++;
        }while (j < i);
    }

    if (dest == 2) {
        do{
            printf("Enter amount: ");
            scanf("%d",&amountArray[a][c]);
            amountArray[a][b] = 0;
            printf("Want to make other entry? y/n\n");
            scanf("%s", response);
            i++;
            a++;
        }while (response[0] == 'y');
        a = 1;

        do{
            if(source == current->id){
                print_acc(current);
            }
            current = current->next;
        }while(source == current->id);

        do{
            printf("%d\t", amountArray[a][b]);
            printf("%d\n", amountArray[a][c]);
            a++;
            j++;
        }while (j < i);
    }
}*/ 
//Este lo mas seguro es que se elimine por que todo debe de ser directo del Journal

/*void balanceArray() {//matrix ARREGLAR VARIABLES

    int BalanceArray [4][4],i,j,y=1;

    //Stored values into the array
    printf("Input elements in the matrix: \n");
    for(i=1;i<4;i++) {
        for(j=1;j<4;j++) {
            printf("element - [%d],[%d] : ",i,j);
            scanf("%d",&BalanceArray[i][j]);
        }
    }  
    //print all 
    printf("\nThe matrix is : \n\n");
    for(j=1;j<4;j++) {
        printf(" \t%d",y++);
    }
    printf("\n");

    for(i=1;i<4;i++) {
        printf("\n");
        printf("%d\t",i);
        for(j=1;j<4;j++) {
            printf("%d\t",BalanceArray[i][j]);
        }
    }
    
    //print balance
    BalanceArray[3][1]=BalanceArray[3][1] - BalanceArray[3][1] - BalanceArray[3][1];
    BalanceArray[3][2]=BalanceArray[3][2] - BalanceArray[3][2] - BalanceArray[3][2];
    BalanceArray[3][3]=BalanceArray[3][3] - BalanceArray[3][3] - BalanceArray[3][3];
    //Make a more efficent loop

    printf("\n\n");
    printf("Balance\t");
    for(j=1;j<4;j++) {
        printf("%d\t",BalanceArray[1][1] + BalanceArray[2][1] + BalanceArray[3][1]);
    }
    printf("\n");
}*/