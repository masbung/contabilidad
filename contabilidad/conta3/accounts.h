//ACCOUNTS.txt

struct struct_account {
        int id;
        int id2;
        char account_name [25];
        char account_name2 [25];
        int account_type;
        int balanceArray[100][2];
        int balanceArray2[100][2];
        int jou_count2;
        int jou_count3;
        char comment2[30];
        int generalBalance;

        char month[10]; 
        char day[10]; 
        int num_day;
        int hour;
        int min; 
        int second; 
        int year;

        struct struct_account *next;
    }; typedef struct struct_account ACCOUNT;


void print_acc(ACCOUNT *account);

void print_acc2(ACCOUNT *account);

void load_all_acc(ACCOUNT *current);

void print_all_acc(ACCOUNT *current);

void add_acc(ACCOUNT* current, int *plastid);

void save_all_acc(ACCOUNT *current);
