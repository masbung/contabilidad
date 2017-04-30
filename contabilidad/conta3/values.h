//Counter to identify the number of journals made
int jou_count = 0;

//add_acc
int lastid;
int *plastid = &lastid;

//Journal, print_current_jou, save_jou 
int fa = 0;
//print_current_jou
int fb = 0;

//load_all_led
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
// k = getc, nl = new line, nc = new character, elt = espace/line/tab, ast = number of asterisks, num_accounts = total of accounts
int k,nl, nw, nc, elt, ast, num_accounts, state;
int aa, ab, ac, ad, ae, af;
int stop, stop2;
int countArray[1][50];
int countArray2[1][50];

//print_led
int ba, bb, bc;

//save_current_jou
int da = 0;
char response2[] = "no";

//journal
int ea=0, eb=1, ec=2, ed=0, ee=0, ef;
char comment[30];
int sourceArray[1][40]; //Account number 
int amountArray[50][2]; //Amount of move in journal