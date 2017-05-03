//journal.txt

void load_jou(ACCOUNT *current);

void print_jou(ACCOUNT *account);

void print_jou_all(ACCOUNT *current);

void print_current_jou(ACCOUNT *current, int sourceArray[1][40], int fb, int amountArray[40][2], int ee, int fa, char comment[30], char response2[3] );

void save_current_jou(ACCOUNT *current, int jou_count, int sourceArray[1][40], int amountArray[40][2], int ee, int fa, char response2[3], char comment[30] );

void save_in_ledger(ACCOUNT *current, int ee, int sourceArray[1][40], int countArray2[1][50], int amountArray[40][2], int ed, int num_accounts );

void journal(ACCOUNT *current, int ef, int ea, int sourceArray[1][40], int ee, int amountArray[40][2], int ed, int fa, char response2[3], char comment[30], int fb, int jou_count, int countArray2[1][50], int num_accounts);

//void results(ACCOUNT *current, int num_accounts);

