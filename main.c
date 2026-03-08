#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<stdbool.h>
#include <time.h>
#include<string.h>
#include <ctype.h>
#define MAX_WITHDRAW_LIMIT 2000
#define MIN_WITHDRAW 10
#define MIN_DEPOSIT 10
#define MAX_DEPOSIT_LIMIT 100000
#define MAX_LEND_LIMIT 50000
#define MIN_LEND 1000
#define RANK_WIDTH 26
#define COMMENT_WIDTH 56


char *filename="C:\\Users\\user\\Desktop\\Professionnel\\clients_data_encrypted_bin.bin.txt"; // DATA CLIENT STORED IN THIS FILE ||
//const char *filename_comments="C:\\Users\\user\\Desktop\\Professionnel\\comments.bin.txt";
void encrypt(char tab[],int id,int len,int key){
    for(int i=0;i<len;i++){
        int val = id * i;
        tab[i]=(tab[i]+val)^key;
    }
}
void decrypt(char tab[],int id,int len,int key){
    for(int i=0;i<len;i++){
          int val = id * i;
          tab[i]=(tab[i]^key)-val;
    }
}
unsigned int encrypt_num(unsigned int x, unsigned int key,int id) {
    x*=id;
    x = ~x;
    x = x ^ key;
    x = x + (key << 3);
    x = ((x << 5) | (x >> 27));
    x = x ^ 0x5F5F5F5F;
    return x;
}
unsigned int decrypt_num(unsigned int x, unsigned int key,int id) {
    x = x ^ 0x5F5F5F5F;
    x = ((x >> 5) | (x << 27));
    x = x - (key << 3);
    x = x ^ key;
    x = ~x;
    x/=id;
    return x;
}

void header(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsole,10);
 system("cls");
    printf("\n");
    printf("************************************************************\n");
    printf("*");
    SetConsoleTextAttribute(hConsole,7);
    printf("                       HT-BANK SYSTEM                     ");
    SetConsoleTextAttribute(hConsole,10);
    printf("*\n");
    printf("*                                                          *\n");
    printf("************************************************************\n");
  SetConsoleTextAttribute(hConsole,6);
  }
void wait(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,10);
system("cls");
//printf("|");
//sleep(1);
//printf("-");
//sleep(1);
printf("|");
sleep(1);
printf("-");
sleep(1);
printf("|");
    SetConsoleTextAttribute(hConsole,7);


}

typedef struct {
int number; // to put the client in a sorted list
int id; // unique
char name[30];
char card_code_n[20];
int age;
char birth[20];
char adress[50];
int reg_before;
char last_entrence[40];
char register_date[40];
int current_money;
int amount_deposit;
int amount_withdraw;
int current_debits;
char phone[15];
char password[30];
int active;

}client_data;
typedef struct {
    int id;
    char com[300];
    int type; // 1 for transcration , 0 for client reports
}comment;
typedef struct {
int id_sender;
int id_receiver;
long long code;
int amount;
bool statue;
bool code_;
}transfer;

void entry(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,10);
    printf("\n\n");
    printf("************************************************************\n");
    printf("*                                                          *\n");
    printf("*");
    SetConsoleTextAttribute(hConsole,7);
    printf("                 WELCOME TO HT-BANK SYSTEM                ");
    SetConsoleTextAttribute(hConsole,10);
    printf("*\n");
    printf("*                                                          *\n");
    printf("*     Secure. Fast. Reliable. Built with pure C power.     *\n");
    printf("*                                                          *\n");
    printf("************************************************************\n");

}
int choose_service(){
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int choose;
    do {
header();
printf("\n-------------------| USERS SECTION ");
service_box();
   scanf("%d",&choose);
   }while(choose!=1 && choose!=2 && choose!=3 && choose!=4);
   return choose;
}

void service_box(){
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 6);
printf("\n\n  _________________________________");
printf("\n |                                 |");
printf("\n |");
SetConsoleTextAttribute(hConsole, 10);
printf("       \xB2 USERS OPTION \xB2          ");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |_________________________________|");
printf("\n |                                 |");

printf("\n |  1 ");
SetConsoleTextAttribute(hConsole, 7);
printf("-> Client                    ");
SetConsoleTextAttribute(hConsole, 6);
printf("|");

printf("\n |  2 ");
SetConsoleTextAttribute(hConsole, 7);
printf("-> Admin                     ");
SetConsoleTextAttribute(hConsole, 6);
printf("|");

printf("\n |  3 ");
SetConsoleTextAttribute(hConsole, 7);
printf("-> Special Orders            ");
SetConsoleTextAttribute(hConsole, 6);
printf("|");

printf("\n |  4 ");
SetConsoleTextAttribute(hConsole, 7);
printf("-> Exit Program              ");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |_________________________________|\n\n");

printf("|| ");
SetConsoleTextAttribute(hConsole, 7);

}

void click(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

SetConsoleTextAttribute(hConsole, 6);
printf("\n\n   >-------------------------<");
printf("\n  /                           \\");
SetConsoleTextAttribute(hConsole, 10);
printf("\n|\\                            /|");

printf("\n| |->  ");
SetConsoleTextAttribute(hConsole, 7);
printf("CLICK ");
SetConsoleTextAttribute(hConsole, 4);
printf("ENTER");
SetConsoleTextAttribute(hConsole, 7);
printf(" BUTTON");
SetConsoleTextAttribute(hConsole, 10);
printf("  <-| |");
printf("\n|/                            \\|");
SetConsoleTextAttribute(hConsole, 6);
printf("\n  \\                           /");
printf("\n   >-------------------------<");
getchar();
}
void client(){
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

                int choose;
        do{
            do{
                                     header();
                                     printf("\n-------------------| ACCESS SECTION ");
                               account_access_box();
                                   scanf("%d",&choose);
                }while(choose!=1 &&choose!=2 &&choose!=3 && choose!=4);
                  switch(choose){

                  case 1: register_();
                  break;
                  case 2:log_in();
                        break;
                  case 3 :about_ht();
                        break;

                  }

        }while(choose!=4 );

}
int try_again_v1(){
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     int choose;
    do{
             SetConsoleTextAttribute(hConsole, 6);
printf("\n\n  ___________________________");
  printf("\n |                           |");
printf("\n |");
SetConsoleTextAttribute(hConsole, 10);
printf("        Try again  ?       ");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |___________________________|");
 printf("\n |                           |");

printf("\n |  1 ");
SetConsoleTextAttribute(hConsole, 7);
printf("->  for Accept   ");
SetConsoleTextAttribute(hConsole, 10);
printf("(yes) ");
SetConsoleTextAttribute(hConsole, 6);
printf("|");
printf("\n |                           |");
printf("\n |  0 ");
SetConsoleTextAttribute(hConsole, 7);
printf("->  for deny     ");
SetConsoleTextAttribute(hConsole, 4);
printf("(No)  ");
SetConsoleTextAttribute(hConsole, 6);
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |___________________________|\n\n");

printf("|| ");
SetConsoleTextAttribute(hConsole, 7);

       scanf("%d",&choose);
    } while(choose!=1 && choose!=0);

    return choose;
}


void account_access_box(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 6);
printf("\n\n  _________________________________");
printf("\n |                                 |");
printf("\n |");
SetConsoleTextAttribute(hConsole, 10);
printf("       \xB2 ACCOUNT ACCESS \xB2        ");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |_________________________________|");
printf("\n |                                 |");

printf("\n |  1 ");
SetConsoleTextAttribute(hConsole, 7);
printf("-> Register (free)           ");
SetConsoleTextAttribute(hConsole, 6);
printf("|");

printf("\n |  2 ");
SetConsoleTextAttribute(hConsole, 7);
printf("-> Log in to your account    ");
SetConsoleTextAttribute(hConsole, 6);
printf("|");

printf("\n |  3 ");
SetConsoleTextAttribute(hConsole, 7);
printf("-> Policy Information        ");
SetConsoleTextAttribute(hConsole, 6);
printf("|");

printf("\n |  4 ");
SetConsoleTextAttribute(hConsole, 7);
printf("-> Return to Home Page       ");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |_________________________________|\n\n");

printf("|| ");
SetConsoleTextAttribute(hConsole, 7);

}

client_data *receive_data_reg(client_data *p){
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole,6);
printf("||\n||  ");
SetConsoleTextAttribute(hConsole,14);
printf("FULL NAME                  : ");
SetConsoleTextAttribute(hConsole,7);
scanf(" %[^\n]s",p->name);
SetConsoleTextAttribute(hConsole,6);
printf("||\n||  ");
SetConsoleTextAttribute(hConsole,14);
printf("AGE                        : ");
SetConsoleTextAttribute(hConsole,7);
scanf("%d",&p->age);
SetConsoleTextAttribute(hConsole,6);
printf("||\n||  ");
SetConsoleTextAttribute(hConsole,14);
printf("ADRESS                     : ");
SetConsoleTextAttribute(hConsole,7);
scanf(" %[^\n]s",p->adress);
SetConsoleTextAttribute(hConsole,6);
printf("||\n||  ");
SetConsoleTextAttribute(hConsole,14);
printf("NATIONAL CARD CODE         : ");
SetConsoleTextAttribute(hConsole,7);
scanf(" %[^\n]s",p->card_code_n);
SetConsoleTextAttribute(hConsole,6);
printf("||\n||  ");
SetConsoleTextAttribute(hConsole,14);
printf("BIRTHDAY (day mounth year) : ");
SetConsoleTextAttribute(hConsole,7);
scanf(" %[^\n]s",p->birth);
SetConsoleTextAttribute(hConsole,6);
printf("||\n||  ");
SetConsoleTextAttribute(hConsole,14);
printf("PERSONNAL NUMBER           : ");
SetConsoleTextAttribute(hConsole,7);
scanf(" %[^\n]s",p->phone);
SetConsoleTextAttribute(hConsole,6);
return p;
}


void pass_box_sig(char buffer[]){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, 6);
printf("\n\n  ___________________________________\n |");
SetConsoleTextAttribute(hConsole, 10);
printf("___                            ____");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |   ");
SetConsoleTextAttribute(hConsole, 10);
printf("\\");
SetConsoleTextAttribute(hConsole, 6);
printf("---<");
SetConsoleTextAttribute(hConsole, 7);
printf(" Enter   ");
SetConsoleTextAttribute(hConsole, 4);
printf("Password ");
SetConsoleTextAttribute(hConsole, 6);
printf(">---");
SetConsoleTextAttribute(hConsole, 10);
printf("/");
SetConsoleTextAttribute(hConsole, 6);
printf("    |\n |\\   ");
SetConsoleTextAttribute(hConsole, 10);
printf("\\------------------------/    ");
SetConsoleTextAttribute(hConsole, 6);
printf("/|\n ");
SetConsoleTextAttribute(hConsole, 14);
printf("|_");
SetConsoleTextAttribute(hConsole, 6);
printf("\\_______________________________/");
SetConsoleTextAttribute(hConsole, 14);
printf("_|");
SetConsoleTextAttribute(hConsole, 14);
printf("\n |      ");
SetConsoleTextAttribute(hConsole, 6);
printf("\\                      /     ");
SetConsoleTextAttribute(hConsole, 14);
printf("|");
SetConsoleTextAttribute(hConsole, 14);
printf("\n |");
SetConsoleTextAttribute(hConsole, 14);
printf("------");
SetConsoleTextAttribute(hConsole, 6);
printf("|");
SetConsoleTextAttribute(hConsole, 4);
printf("(");

SetConsoleTextAttribute(hConsole, 4);
printf("%s",buffer);

SetConsoleTextAttribute(hConsole, 4);
printf(")");
SetConsoleTextAttribute(hConsole, 6);
printf("|");
SetConsoleTextAttribute(hConsole, 14);
printf("------");
SetConsoleTextAttribute(hConsole, 14);
printf("|\n |______");
SetConsoleTextAttribute(hConsole, 6);
printf("\\____________________/");
SetConsoleTextAttribute(hConsole, 14);
printf("_______|\n\n");
SetConsoleTextAttribute(hConsole, 6);
printf("||");

SetConsoleTextAttribute(hConsole, 7);

}
void pass_box_sig_conf(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, 6);
printf("\n\n  ___________________________________\n |");
SetConsoleTextAttribute(hConsole, 10);
printf("___                            ____");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |   ");
SetConsoleTextAttribute(hConsole, 10);
printf("\\");
SetConsoleTextAttribute(hConsole, 6);
printf("---<");
SetConsoleTextAttribute(hConsole, 7);
printf(" Confirm ");
SetConsoleTextAttribute(hConsole, 4);
printf("Password ");
SetConsoleTextAttribute(hConsole, 6);
printf(">---");
SetConsoleTextAttribute(hConsole, 10);
printf("/");
SetConsoleTextAttribute(hConsole, 6);
printf("    |\n |\\   ");
SetConsoleTextAttribute(hConsole, 10);
printf("\\------------------------/    ");
SetConsoleTextAttribute(hConsole, 6);
printf("/|\n ");
SetConsoleTextAttribute(hConsole, 14);
printf("|_");
SetConsoleTextAttribute(hConsole, 6);
printf("\\_______________________________/");
SetConsoleTextAttribute(hConsole, 14);
printf("_|");
SetConsoleTextAttribute(hConsole, 14);
printf("\n |      ");
SetConsoleTextAttribute(hConsole, 6);
printf("\\                      /     ");
SetConsoleTextAttribute(hConsole, 14);
printf("|");
SetConsoleTextAttribute(hConsole, 14);
printf("\n |");
SetConsoleTextAttribute(hConsole, 14);
printf("------");
SetConsoleTextAttribute(hConsole, 6);
printf("|");
SetConsoleTextAttribute(hConsole, 4);
printf("(");

SetConsoleTextAttribute(hConsole, 4);
printf(" ---|\\_______/|--- ");

SetConsoleTextAttribute(hConsole, 4);
printf(")");
SetConsoleTextAttribute(hConsole, 6);
printf("|");
SetConsoleTextAttribute(hConsole, 14);
printf("------");
SetConsoleTextAttribute(hConsole, 14);
printf("|\n |______");
SetConsoleTextAttribute(hConsole, 6);
printf("\\____________________/");
SetConsoleTextAttribute(hConsole, 14);
printf("_______|\n\n");
SetConsoleTextAttribute(hConsole, 6);
printf("||");

SetConsoleTextAttribute(hConsole, 7);

}

void register_(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
char temp[20];
client_data *p=(client_data*)malloc(sizeof(client_data));
 if (p == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
header();
printf("\n-------------------| REGISTER SECTION ");
top_reg_box();
p=receive_data_reg(p);
buttom_reg_box();
getchar();
click();
int tmp_;
do{
       header();
       printf("\n-------------------| REGISTER SECTION ");
    bool_first_sig();
     SetConsoleTextAttribute(hConsole,7);
    scanf("%d",&tmp_);
}while(tmp_!=1 && tmp_!=0);
if(tmp_==1)p->reg_before=1;
else p->reg_before=0;
time_t date;
time(&date);
strcpy(p->last_entrence,ctime(&date));
strcpy(p->register_date,ctime(&date));
p->register_date[strcspn(p->register_date, "\n")] = '\0';
p->last_entrence[strcspn(p->last_entrence, "\n")] = '\0';

char buffer[19];
strcpy(buffer,"  min 8 characters ");
do{
do{
        header();
    printf("\n-------------------| REGISTER SECTION ");
    pass_box_sig(buffer);
    scanf(" %[^\n]s",p->password);
    if (strcspn(p->password, " \t\n\r") != strlen(p->password))strcpy(buffer,"   Without spaces  ");
     else if(strlen(p->password)>18)strcpy(buffer," max 18 characters ");
     else if(strlen(p->password)<8)strcpy(buffer,"  min 8 characters ");
}while(strlen(p->password)<8 || strlen(p->password)>18 || strcspn(p->password," ")!=strlen(p->password));


 header();
    printf("\n-------------------| REGISTER SECTION ");
    pass_box_sig_conf();
scanf(" %[^\n]s",temp);
if(strcmp(p->password,temp)!=0){

         header();
    printf("\n-------------------| REGISTER SECTION ");
   conf_fail();
       getchar();
        click();

         header();
    printf("\n-------------------| REGISTER SECTION ");
    int choos=try_again_v1();
    if(choos==0){
        header();
         printf("\n-------------------| REGISTER SECTION ");
         free(p);
         reg_fail();
         getchar();
         click();
         return;
    }

                            }
else break;
}while(true);
p->amount_deposit=0;
p->amount_withdraw=0;
p->current_debits=0;
p->current_money=0;
p->active=1;

 int id_last = last_id("C:\\Users\\user\\Desktop\\Professionnel\\clients_data_encrypted_bin.bin.txt");
//printf("\n---%d\n",id_last);
//click();
p->id=id_last+1;

comment *tmpo=(comment*)malloc(sizeof(comment));
tmpo->id=p->id;
tmpo->type=1;
snprintf(tmpo->com, sizeof(tmpo->com), "%-20s |           %s ","Account created", p->register_date);
write_comments(tmpo,"C:\\Users\\user\\Desktop\\Professionnel\\comments.bin.txt");
free(tmpo);

storage_ENC(p);

wait();
header();
printf("\n-------------------| REGISTER SECTION ");
//printf("\n\n-----REGISTRATION COMPLETED----------");
ur_id_box(p->id);
//printf("\n\nMAKE SURE TO LOG IN !!");

free(p);
getchar();
click();

}


void reg_fail(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, 6);
printf("\n\n __________________________\n");
     printf("|                          |  \n|   ");
 SetConsoleTextAttribute(hConsole, 7);
     printf("Registration");
      SetConsoleTextAttribute(hConsole, 4);
     printf(" Failed");
       SetConsoleTextAttribute(hConsole, 6);
     printf("    |\n|__________________________|\n");



SetConsoleTextAttribute(hConsole, 7);

}
void conf_fail(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, 6);
printf("\n\n __________________________\n");
     printf("|                          |  \n|   ");
       SetConsoleTextAttribute(hConsole, 7);
     printf("Confirmation");
       SetConsoleTextAttribute(hConsole, 4);
     printf(" Failed");
       SetConsoleTextAttribute(hConsole, 6);
     printf("    |\n|__________________________|\n");

SetConsoleTextAttribute(hConsole, 7);
}
void bool_first_sig(){


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 6);
printf("\n\n  _____________________________________________________");
printf("\n |                                                     |");
printf("\n |");
SetConsoleTextAttribute(hConsole, 10);
printf("        Is it your first account in a BANK  ?        ");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |_____________________________________________________|");
 printf("\n |                                                     |");

printf("\n |  1 ");
SetConsoleTextAttribute(hConsole, 7);
printf("->  for Accept   ");
SetConsoleTextAttribute(hConsole, 10);
printf("(yes)                           ");
SetConsoleTextAttribute(hConsole, 6);
printf("|");
printf("\n |                                                     |");
printf("\n |  2 ");
SetConsoleTextAttribute(hConsole, 7);
printf("->  for deny     ");
SetConsoleTextAttribute(hConsole, 4);
printf("(No)                            ");
SetConsoleTextAttribute(hConsole, 6);
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |_____________________________________________________|\n\n");

printf("|| ");
SetConsoleTextAttribute(hConsole, 7);

}
void top_reg_box(){

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
printf("\n\n");
SetConsoleTextAttribute(hConsole,14);
printf("                       ______________\n                      /     ");
SetConsoleTextAttribute(hConsole,4);
printf("\\||/");
SetConsoleTextAttribute(hConsole,14);
printf("     \\       ");
SetConsoleTextAttribute(hConsole,6);
printf("\n  _/-----------------");
SetConsoleTextAttribute(hConsole,14);
printf("/       ");
SetConsoleTextAttribute(hConsole,4);
printf("||");
SetConsoleTextAttribute(hConsole,14);
printf("       \\");
SetConsoleTextAttribute(hConsole,6);

printf("------------------\\\n");

printf("_/______/-----------");
SetConsoleTextAttribute(hConsole,14);
printf("|________");
SetConsoleTextAttribute(hConsole,4);
printf("/\\");
SetConsoleTextAttribute(hConsole,14);
printf("________|");
SetConsoleTextAttribute(hConsole,6);
printf("-----------\\______\\_\n|_/                                                      \\_|\n");
printf("||                                                  \n");

}

void buttom_reg_box(){

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole,6);
printf("||\n");
printf("||                   ");
SetConsoleTextAttribute(hConsole,14);
printf("__________________                   ");
SetConsoleTextAttribute(hConsole,6);
printf("__\n| \\_________________");
SetConsoleTextAttribute(hConsole,14);
printf("|                  |");
SetConsoleTextAttribute(hConsole,6);
printf("_________________/ |\n");


SetConsoleTextAttribute(hConsole,6);
printf("\\______\\_-----------");
SetConsoleTextAttribute(hConsole,14);
printf("\\________");
SetConsoleTextAttribute(hConsole,4);
printf("/\\");
SetConsoleTextAttribute(hConsole,14);
printf("________/");
SetConsoleTextAttribute(hConsole,6);
printf("-----------_/______/\n");







}
void ur_id_box(int id) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    char buffer[100];
    sprintf(buffer, "Your Id : %d", id);   // text with ID
    int len = strlen(buffer);

    char reminder[] = "Remember it";
    int len2 = strlen(reminder);

    char title[] = "Reg Completed";        // Top message
    int len3 = strlen(title);

    // Find widest line
    int maxLen = len;
    if (len2 > maxLen) maxLen = len2;
    if (len3 > maxLen) maxLen = len3;

    int width = maxLen + 4; // + padding

    // Top border
    SetConsoleTextAttribute(hConsole, 6);
    printf("\n\n ");
    for (int i = 0; i < width; i++) printf("_");
    printf("\n");

     printf("|");
    for (int i = 0; i < width; i++) printf(" ");
    printf("|\n");



    // Title line centered
    int totalPadding = maxLen - len3;
    int leftPadding = totalPadding / 2;
    int rightPadding = totalPadding - leftPadding;

    printf("| ");
    for (int i = 0; i < leftPadding; i++) printf(" ");
    SetConsoleTextAttribute(hConsole, 14); // cyan/blue for title
    printf(" %s", title);
    for (int i = 0; i < rightPadding; i++) printf(" ");
   SetConsoleTextAttribute(hConsole, 6);
    printf("  |\n");
     printf("|");
    for (int i = 0; i < width; i++) printf("_");
    printf("|\n");

    // Empty spacing row
    printf("|");
    for (int i = 0; i < width; i++) printf(" ");
    printf("|\n");

    // Line with ID
    printf("| ");
    SetConsoleTextAttribute(hConsole, 7); // white
    printf("  Your Id : ");
    SetConsoleTextAttribute(hConsole, 10); // green
    printf("%d", id);
    int used = strlen("Your Id : ") + (int)snprintf(NULL, 0, "%d", id);
    for (int i = used; i < maxLen; i++) printf(" ");
   SetConsoleTextAttribute(hConsole, 6);
    printf(" |\n");

     printf("|");
    for (int i = 0; i < width; i++) printf("_");
    printf("|\n");


    // Line with "Remember it" centered
    totalPadding = maxLen - len2;
    leftPadding = totalPadding / 2;
    rightPadding = totalPadding - leftPadding;
 printf("|");
    for (int i = 0; i < width; i++) printf(" ");
    printf("|\n");
    printf("|  ");
    for (int i = 0; i < leftPadding; i++) printf(" ");
    SetConsoleTextAttribute(hConsole, 14); // yellow
    printf("%s", reminder);
    for (int i = 0; i < rightPadding; i++) printf(" ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("  |\n");

    // Bottom border
    printf("|");
    for (int i = 0; i < width; i++) printf("_");
    printf("|\n");

    SetConsoleTextAttribute(hConsole, 7); // reset
}

client_data *encrypt_all_data(client_data *p){
int key=0xAA;
  encrypt(p->name,p->id,strlen(p->name),key);
  encrypt(p->adress,p->id,strlen(p->adress),key);
  encrypt(p->card_code_n,p->id,strlen(p->card_code_n),key);
    // ENCRYPT DATA (CHAR)
  encrypt(p->phone,p->id,strlen(p->phone),key);

  encrypt(p->password,p->id,strlen(p->password),key);
  encrypt(p->birth,p->id,strlen(p->birth),key);
  encrypt(p->register_date,p->id,strlen(p->register_date),key);
  encrypt(p->last_entrence,p->id,strlen(p->last_entrence),key);

 p->age= encrypt_num(p->age,key,p->id);
  p->amount_deposit=encrypt_num(p->amount_deposit,key,p->id);
  p->amount_withdraw=encrypt_num(p->amount_withdraw,key,p->id);    // ENCRYPT DATA (NUM);
 p->current_debits=encrypt_num(p->current_debits,key,p->id);
  p->active=encrypt_num(p->active,key,p->id);
 p->reg_before=encrypt_num(p->reg_before,key,p->id);
 return p;
}
void storage_ENC(client_data *p){
  p=encrypt_all_data(p);
  p->number=last_num("C:\\Users\\user\\Desktop\\Professionnel\\clients_data_encrypted_bin.bin.txt");
   ++p->number;
  writing_BINARY(p,"C:\\Users\\user\\Desktop\\Professionnel\\clients_data_encrypted_bin.bin.txt");
}
int last_id(char *filename){
    client_data p1;

FILE *w=fopen(filename,"rb");
  if (w==NULL) {
        return 0;
    }
    int id_=0;
while(fread(&p1,sizeof(client_data),1,w)==1)id_=p1.id;
fclose(w);
return id_;

}
int last_num(char *filename){
   client_data p1;

FILE *w=fopen(filename,"rb");
  if (w==NULL) {
        return 0;
    }
    int num=0;
while(fread(&p1,sizeof(client_data),1,w)==1)num=p1.number;
fclose(w);
return num;

}
void writing_BINARY(client_data *p,char *filename){
   FILE *w=fopen(filename,"ab");
   if(w==NULL){
     perror("SYSTEM ERROR (FILE OPENING FAILED)");
    exit(1);
   }
    size_t written=fwrite(p,sizeof(client_data),1,w);
    if(written!=1){
        perror("WRITTING IN FILE FAILED ");
        exit(1);
    }
     fclose(w);
}
client_data *decrypt_all_data(client_data *p){

 int key=0xAA;
            decrypt(p->name,p->id,strlen(p->name),key);
             decrypt(p->adress,p->id,strlen(p->adress),key);
             decrypt(p->card_code_n,p->id,strlen(p->card_code_n),key);   // DECRYPTION DATA TYPE CHAR ;
             decrypt(p->phone,p->id,strlen(p->phone),key);
             decrypt(p->password,p->id,strlen(p->password),key);
             decrypt(p->birth,p->id,strlen(p->birth),key);
             decrypt(p->last_entrence,p->id,strlen(p->last_entrence),key);
             decrypt(p->register_date,p->id,strlen(p->register_date),key);

            p->age= decrypt_num(p->age,key,p->id);
            p->amount_deposit=decrypt_num(p->amount_deposit,key,p->id);
            p->amount_withdraw=decrypt_num(p->amount_withdraw,key,p->id);    // ENCRYPT DATA (NUM);
            p->current_debits=decrypt_num(p->current_debits,key,p->id);
              p->active=decrypt_num(p->active,key,p->id);
              p->reg_before=decrypt_num(p->reg_before,key,p->id);

           return p;




}
client_data *extract_client_data(char *filename,int id_){

      client_data *p=(client_data*)malloc(sizeof(client_data));
     if(p==NULL){
    perror("ALLOCATION FAILED !");
exit(1);
}
FILE *w=fopen(filename,"rb");
if(w==NULL){
perror("OPENING FILE FAILED !");
exit(1);
}
while(fread(p,sizeof(client_data),1,w)==1){
    if(p->id==id_){
          p=decrypt_all_data(p);
        fclose(w);
        return p;

    }
}
fclose(w);
free(p);
return NULL;
}
void log_in(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int verif;
int max_id=last_id("C:\\Users\\user\\Desktop\\Professionnel\\clients_data_encrypted_bin.bin.txt");
SetConsoleTextAttribute(hConsole,7);

do{
      header();
      printf("\n-------------------| LOG IN SECTION \n\n");
      id_box(max_id);
    scanf("%d",&verif);
    if(verif==0)return ;
}while(verif<1 || verif>max_id );
int attemp=3;
char tmp[30];
client_data *id2data=extract_client_data("C:\\Users\\user\\Desktop\\Professionnel\\clients_data_encrypted_bin.bin.txt",verif);
if(id2data==NULL){
    printf("CLIENT NOT FOUND! ");
    free(id2data);
}

else {
                int key=0xAA;
                //decrypt(id2data->password,verif,strlen(id2data->password),key);
                    do{
                header();
            printf("\n-------------------| LOG IN SECTION ");
           pass_attemp_box(attemp);
                scanf(" %[^\n]s",tmp);
               // printf("---\n%s\n",id2data->password);
               //click();
                    if(strcmp(id2data->password,tmp)==0){
                    header();
                    printf("\n-------------------| LOG IN SECTION ");
                    log_in_succ();
                    getchar();
                    click();
                                    break;
                                                    }
                    else{
                                log_in_fail();
                                        getchar();
                                        click();
                                                --attemp;
                                }
                }while(attemp>0);

                            if(attemp<=0){
                                header();
                                printf("\n-------------------| LOG IN SECTION ");
                                SetConsoleTextAttribute(hConsole,7);


                                access_denied();
                                //getchar();
                                click();
                                       }
                        else{
                        time_t date;
                        time(&date);
                        strcpy(id2data->last_entrence,ctime(&date));
                        id2data->last_entrence[strcspn(id2data->last_entrence, "\n")] = '\0';
                        write_edit(id2data,filename);
                        account(id2data);
                                }
}
}

void log_in_succ(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, 6);
printf("\n\n __________________________\n");
     printf("|                          |  \n|");
 SetConsoleTextAttribute(hConsole, 7);
     printf("   Log In ");
      SetConsoleTextAttribute(hConsole, 10);
     printf("  Succeded  ");
       SetConsoleTextAttribute(hConsole, 6);
     printf("    |\n|__________________________|\n");
SetConsoleTextAttribute(hConsole, 7);

}
void log_in_fail(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, 6);
printf("\n\n __________________________\n");
     printf("|                          |  \n|");
 SetConsoleTextAttribute(hConsole, 7);
     printf("    Log In ");
      SetConsoleTextAttribute(hConsole, 4);
     printf("  Failed   ");
       SetConsoleTextAttribute(hConsole, 6);
     printf("    |\n|__________________________|\n");
SetConsoleTextAttribute(hConsole, 7);

}
void access_denied(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsole,6);
printf("\n\n  _______________________________________________");
printf("\n |                                               |");
printf("\n |");
SetConsoleTextAttribute(hConsole, 7); // Red = danger
printf("       ACCESS DENIED");
SetConsoleTextAttribute(hConsole, 4);
printf(" - ");
SetConsoleTextAttribute(hConsole, 7);
printf("ATTEMPTS EXCEEDED       ");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |_______________________________________________|");

printf("\n |                                               |");
printf("\n | ");
SetConsoleTextAttribute(hConsole, 7);
printf("    You have finished the allowed attempts    ");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n | ");
SetConsoleTextAttribute(hConsole, 7);
printf("  If you encounter problems, write a report   ");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n | ");
SetConsoleTextAttribute(hConsole, 7);
printf("            (");
SetConsoleTextAttribute(hConsole, 10);
printf(" in  Contact Section ");
SetConsoleTextAttribute(hConsole, 7);
printf(")           ");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |_______________________________________________|\n\n");
SetConsoleTextAttribute(hConsole, 7);
}
void pass_attemp_box(int attemp){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(hConsole, 6);
printf("\n  _________________________________");
printf("\n |                                 |");
printf("\n |");
SetConsoleTextAttribute(hConsole, 7);
printf("         ENTER ");
SetConsoleTextAttribute(hConsole, 10);
printf("PASSWORD          ");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |_________________________________|");

printf("\n |                                 |");
printf("\n | ");
SetConsoleTextAttribute(hConsole, 7);
printf("     Attempts remaining: ");
SetConsoleTextAttribute(hConsole, 4);
printf("%d", attemp);
SetConsoleTextAttribute(hConsole, 6);
printf("      |");
printf("\n |_________________________________|\n\n");

printf("|| ");
SetConsoleTextAttribute(hConsole, 7);
}
void id_box(int max_id){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int box_width = 44; // inner width (between the |   |)
char msg[100];
// main message with max_id inside
 snprintf(msg, sizeof(msg), "TYPE YOUR ID ( 1-%d )", max_id);
int msg_len = strlen(msg);
int left_pad = (box_width - msg_len) / 2;
int right_pad = box_width - msg_len - left_pad;

SetConsoleTextAttribute(hConsole, 6);
printf("\n  ");
for(int i=0; i<box_width; i++) printf("_");
printf("\n |");

// top empty space
for(int i=0; i<box_width; i++) printf(" ");
printf("|\n |");

// centered message
for(int i=0; i<left_pad; i++) printf(" ");
SetConsoleTextAttribute(hConsole, 10);
printf("%s", msg);
SetConsoleTextAttribute(hConsole, 6);
for(int i=0; i<right_pad; i++) printf(" ");
printf("|\n |");

for(int i=0; i<box_width; i++) printf("_");     ////
printf("|\n |");
for(int i=0; i<box_width; i++) printf(" ");
printf("|\n |");
char return_msg[] = "If you want to return, type 0 ";
int return_len = strlen(return_msg);
left_pad = (box_width - return_len) / 2;
right_pad = box_width - return_len - left_pad;

for(int i=0; i<left_pad; i++) printf(" ");
SetConsoleTextAttribute(hConsole, 7);
printf("%s", return_msg);
SetConsoleTextAttribute(hConsole, 6);
for(int i=0; i<right_pad; i++) printf(" ");
printf("|\n |");

for(int i=0; i<box_width; i++) printf("_");
printf("|\n\n|| ");
SetConsoleTextAttribute(hConsole, 7);

}
void after_header(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

printf("\n\n\n______________________________________________________________________________\n");
      printf("                                                                              |\n");
SetConsoleTextAttribute(hConsole,7);
      printf("Welcome to ");
SetConsoleTextAttribute(hConsole,10);
printf("Ht bank");
SetConsoleTextAttribute(hConsole,7);
printf(" applicaton ,                                               ");
SetConsoleTextAttribute(hConsole,6);
printf("|");
SetConsoleTextAttribute(hConsole,7);
printf("\n\"Where trust meets code, and dreams unfold — HT Bank, your future in bold.\" ");
SetConsoleTextAttribute(hConsole,6);
printf("|");
printf("\n______________________________________________________________________________|\n");
SetConsoleTextAttribute(hConsole,7);
}
void menu_account_section(){
                                                     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                                                       SetConsoleTextAttribute(hConsole, 6);
                                                    printf("\n  _________________________________");
                                              printf("\n |                                 |");
                                              printf("\n |");
                                                            SetConsoleTextAttribute(hConsole, 10);
                                                printf("        \xB2 HT BANK MENU \xB2         "); // \xB2 = double vertical bar (Windows box char)
                                                      SetConsoleTextAttribute(hConsole, 6);
                                                    printf("|\n |_________________________________|");
                                                  //  SetConsoleTextAttribute(hConsole, 7);
                                                    printf("\n |                                 |");


                                                    printf("\n |  1 ");
                                                     SetConsoleTextAttribute(hConsole, 7);
                                                    printf("-> Menu                      ");
                                                     SetConsoleTextAttribute(hConsole, 6);


                                                    printf("|\n |  2 ");
                                                     SetConsoleTextAttribute(hConsole, 7);
                                                    printf("-> Transfer Money            ");
                                                    SetConsoleTextAttribute(hConsole, 6);

                                                    printf("|\n |  3 ");
                                                    SetConsoleTextAttribute(hConsole, 7);
                                                    printf("-> Account Information       ");
                                                    SetConsoleTextAttribute(hConsole, 6);
                                                    printf("|\n |  4 ");
                                                     SetConsoleTextAttribute(hConsole, 7);
                                                    printf("-> About HT Bank             ");
                                                     SetConsoleTextAttribute(hConsole, 6);
                                                printf("|\n |  5 ");
                                                 SetConsoleTextAttribute(hConsole, 7);
                                                printf("-> Reports                   ");
                                                SetConsoleTextAttribute(hConsole, 6);
                                                printf("|\n |  6 ");
                                                 SetConsoleTextAttribute(hConsole, 7);
                                                printf("-> Disconnect                ");
                                                 SetConsoleTextAttribute(hConsole, 6);
                                                        printf("|\n |_________________________________|\n\n");



                                                    printf("|| ");
                                                    SetConsoleTextAttribute(hConsole,7);

}
void account(client_data *p){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      int choose;
      do{
             do {
                                                       header();
                                                    printf("\n-------------------| ACCOUNT SECTION ");
                                                   after_header();
                                                   // getchar();
                                                   // click();
                                                     menu_account_section();
                                                    scanf("%d",&choose);
                                                    while(getchar() != '\n');    // Clean the buffer
                                                        }while(choose<1 || choose>6);
                        switch(choose){
                       case 1: menu(p);
                           break;
                       case 2:transfer_(p);
                           break;
                       case 3:info(p);
                           break;
                       case 4:about_ht();
                           break;
                       case 5:report(p);
                        break;
                                }
      }while(choose!=6);
}

void report(client_data *p){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int choose;
do{
    do{
    header();
    printf("\n-------------------| Reports");
    menu_report();
    scanf("%d",&choose);
       }while(choose!=3 && choose!=2 && choose!=1);
switch(choose){
case 1:write_reports(p);
    break;
case 2:read_reports(p);
    break;
}
   }while(choose!=3);
}

void write_reports(client_data *p){
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
char mess[256];
do{
header();
printf("\n-------------------| Reports / Writing");
write_report_box();
scanf(" %[^\n]s",mess);
}while(strlen(mess)>250);
comment *c=(comment*)malloc(sizeof(comment));
c->type=0;
c->id=p->id;
strcpy(c->com,mess);

//c=transform2table_com(c);

header();
printf("\n-------------------| Reports / Writing");
int choose=confirm();
if(choose==0){
header();
printf("\n-------------------| Reports / Writing");
write_rep_fail();
click();
free(c);
return;
}
write_comments(c,"C:\\Users\\user\\Desktop\\Professionnel\\comments.bin.txt");
free(c);
 header();
printf("\n-------------------| Reports / Writing");
write_rep_succ();
SetConsoleTextAttribute(hConsole, 7);
click();
}
void write_report_box(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, 6);
printf("\n\n  ___________________________________\n |");
SetConsoleTextAttribute(hConsole, 10);
printf("___                            ____");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |   ");
SetConsoleTextAttribute(hConsole, 10);
printf("\\");
SetConsoleTextAttribute(hConsole, 6);
printf("---<");
SetConsoleTextAttribute(hConsole, 7);
printf(" Write the ");
SetConsoleTextAttribute(hConsole, 4);
printf("Report ");
SetConsoleTextAttribute(hConsole, 6);
printf(">---");
SetConsoleTextAttribute(hConsole, 10);
printf("/");
SetConsoleTextAttribute(hConsole, 6);
printf("    |\n |\\   ");
SetConsoleTextAttribute(hConsole, 10);
printf("\\------------------------/    ");
SetConsoleTextAttribute(hConsole, 6);
printf("/|\n ");
SetConsoleTextAttribute(hConsole, 14);
printf("|_");
SetConsoleTextAttribute(hConsole, 6);
printf("\\_______________________________/");
SetConsoleTextAttribute(hConsole, 14);
printf("_|");
SetConsoleTextAttribute(hConsole, 14);
printf("\n |      ");
SetConsoleTextAttribute(hConsole, 6);
printf("\\                      /     ");
SetConsoleTextAttribute(hConsole, 14);
printf("|");
SetConsoleTextAttribute(hConsole, 14);
printf("\n |");
SetConsoleTextAttribute(hConsole, 14);
printf("------");
SetConsoleTextAttribute(hConsole, 6);
printf("|");
SetConsoleTextAttribute(hConsole, 4);
printf("( ");
SetConsoleTextAttribute(hConsole, 7);
printf("Max ");
SetConsoleTextAttribute(hConsole, 4);
printf("250 ");
SetConsoleTextAttribute(hConsole, 7);
printf("Characters");
SetConsoleTextAttribute(hConsole, 4);
printf(")");
SetConsoleTextAttribute(hConsole, 6);
printf("|");
SetConsoleTextAttribute(hConsole, 14);
printf("------");
SetConsoleTextAttribute(hConsole, 14);
printf("|\n |______");
SetConsoleTextAttribute(hConsole, 6);
printf("\\____________________/");
SetConsoleTextAttribute(hConsole, 14);
printf("_______|\n\n");
SetConsoleTextAttribute(hConsole, 6);
printf("||");
SetConsoleTextAttribute(hConsole, 7);

}
void write_rep_succ(){
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);
printf("\n\n ___________________________________\n|                                   |\n|");
 SetConsoleTextAttribute(hConsole, 7);
printf(" Writing Report Operation");
 SetConsoleTextAttribute(hConsole, 10);
printf(" Succeded");
 SetConsoleTextAttribute(hConsole, 6);
printf(" |\n|___________________________________|");
 SetConsoleTextAttribute(hConsole, 7);

}
void write_rep_fail(){
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 6);
printf("\n\n ___________________________________\n|                                   |\n|");
SetConsoleTextAttribute(hConsole, 7);
printf(" Writing Report Operation");
SetConsoleTextAttribute(hConsole, 12);   // red color
printf(" Failed");
SetConsoleTextAttribute(hConsole, 6);
printf("  |\n|___________________________________|");

SetConsoleTextAttribute(hConsole, 7);
}

//comment *transform2table_com(comment *c){




void read_reports(client_data *p){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
header();
printf("\n-------------------| Reports / History  ");

    SetConsoleTextAttribute(hConsole, 7);
int read_bool=read_comments(p->id,"C:\\Users\\user\\Desktop\\Professionnel\\comments.bin.txt",0); // function that read the comments of type 1 (trans );
SetConsoleTextAttribute(hConsole, 6);
getchar();
click();
}

void menu_report(){
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 6);
    printf("\n  _________________________________");
    printf("\n |                                 |");
    printf("\n |");
    SetConsoleTextAttribute(hConsole, 10);
    printf("        \xB2 REPORT MENU \xB2          "); // Title
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n |_________________________________|");
    printf("\n |                                 |");

    printf("\n |  1 ");
    SetConsoleTextAttribute(hConsole, 7);
    printf("-> Write Report              ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|");

    printf("\n |  2 ");
    SetConsoleTextAttribute(hConsole, 7);
    printf("-> Reports History           ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|");

    printf("\n |  3 ");
    SetConsoleTextAttribute(hConsole, 7);
    printf("-> Return                    ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|");

    printf("\n |_________________________________|\n\n");

    printf("|| ");
    SetConsoleTextAttribute(hConsole, 7);
    }

void about_ht(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int choose;
do{
    do{
        header();
printf("\n-------------------| About HT ");
    menu_about_ht();
    scanf("%d",&choose);
}while(choose!=1 && choose!=2 && choose!=3 && choose!=4 && choose!=5);
switch(choose){

case 1 :
    page1();
    break;
case 2 :
    page2();
     break;
case 3 :
    page3();
     break;

case 4 :
    page4();
     break;
}
}while(choose!=5);
}
void menu_about_ht(){

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole,6);
printf("\n\n  _________________________________");
printf("\n |                                 |");
printf("\n |      ");
SetConsoleTextAttribute(hConsole,10);
printf("\xB2 HT BANK MENU \xB2           ");
SetConsoleTextAttribute(hConsole,6);
printf("|\n |_________________________________|");

printf("\n |                                 |");
SetConsoleTextAttribute(hConsole,6);
printf("\n |  1 ");
SetConsoleTextAttribute(hConsole,7);
printf("-> What is HT Bank?          ");
SetConsoleTextAttribute(hConsole,6);
printf("|\n |  2 ");
SetConsoleTextAttribute(hConsole,7);
printf("-> Why Choose HT Bank?       ");
SetConsoleTextAttribute(hConsole,6);
printf("|\n |  3 ");
SetConsoleTextAttribute(hConsole,7);
printf("-> Our Services              ");
SetConsoleTextAttribute(hConsole,6);
printf("|\n |  4 ");
SetConsoleTextAttribute(hConsole,7);
printf("-> Our Policy                ");
SetConsoleTextAttribute(hConsole,6);
printf("|\n |  5 ");
SetConsoleTextAttribute(hConsole,7);
printf("-> Return                    ");
SetConsoleTextAttribute(hConsole,6);
printf("|\n |_________________________________|");

printf("\n\n|| ");
SetConsoleTextAttribute(hConsole,7);

}

void page1() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    header();
    printf("\n-------------------| HT Bank Guide ");


    SetConsoleTextAttribute(hConsole, 6);
    printf("\n\n  =============================================================\n");
    printf("  ||                                                         ||\n");
    printf("  ||                  ");
    SetConsoleTextAttribute(hConsole, 10);
    printf("WHAT IS HT BANK?                       ");
    SetConsoleTextAttribute(hConsole, 6);
     printf("||\n  ||                                                         ||\n");
   printf("  =============================================================\n");
   printf("  ||                                                         ||\n  || ");
   SetConsoleTextAttribute(hConsole, 7);
    printf("HT Bank is a modern financial institution that blends   ");
       SetConsoleTextAttribute(hConsole, 6);
    printf("||\n  || ");
     SetConsoleTextAttribute(hConsole, 7);
    printf("innovation, security, and customer-first values. More   ");
     SetConsoleTextAttribute(hConsole, 6);
    printf("||\n  || ");
     SetConsoleTextAttribute(hConsole, 7);
   printf("than a bank, it is a financial partner that grows with  ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("||\n  || ");
     SetConsoleTextAttribute(hConsole, 7);
    printf("individuals, entrepreneurs, and businesses.             ");
     SetConsoleTextAttribute(hConsole, 6);
    printf("||\n  ||                                                         ||\n  || ");
     SetConsoleTextAttribute(hConsole, 7);
    printf("Our foundation rests on TRUST, TRANSPARENCY, and        ");
     SetConsoleTextAttribute(hConsole, 6);
    printf("||\n  || ");
     SetConsoleTextAttribute(hConsole, 7);
    printf("TECHNOLOGY, ensuring safety, clarity, and efficiency.   ");
     SetConsoleTextAttribute(hConsole, 6);
    printf("||\n  || ");
     SetConsoleTextAttribute(hConsole, 7);
    printf("HT Bank represents financial freedom and prosperity.    ");
     SetConsoleTextAttribute(hConsole, 6);
    printf("||\n  ||                                                         ||\n");
    printf("  =============================================================\n");
    getchar();
    click();

}
void page2() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    header();
    printf("\n-------------------| HT Bank Guide ");
    SetConsoleTextAttribute(hConsole, 6);
   printf("\n\n  =============================================================\n");
   printf("  ||                                                         || ");
    printf("\n  ||                 ");
    SetConsoleTextAttribute(hConsole, 10);
    printf("WHY CHOOSE HT BANK?                     ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("||\n  ||                                                         || \n");
     printf("  =============================================================\n");
     printf("  ||                                                         ||\n  || ");
    SetConsoleTextAttribute(hConsole, 7);
    printf("HT Bank stands out through three key advantages:        ");
     SetConsoleTextAttribute(hConsole, 6);
    printf("||\n  ||                                                         ||\n  || ");
    SetConsoleTextAttribute(hConsole, 14);
    printf("- INNOVATION:");
     SetConsoleTextAttribute(hConsole, 7);
    printf(" Smart digital platforms and AI solutions. ");
     SetConsoleTextAttribute(hConsole, 6);
    printf("||\n  || ");
     SetConsoleTextAttribute(hConsole, 14);
    printf("- SECURITY :");
     SetConsoleTextAttribute(hConsole, 7);
    printf(" Multi-layer protection & global standards. ");
     SetConsoleTextAttribute(hConsole, 6);
    printf("||\n  || ");
     SetConsoleTextAttribute(hConsole, 14);
printf("- SERVICE  :");
 SetConsoleTextAttribute(hConsole, 7);
printf(" Personalized support for each client.      ");
 SetConsoleTextAttribute(hConsole, 6);
    printf("||\n  ||                                                         ||\n  || ");
     SetConsoleTextAttribute(hConsole, 7);
    printf("With competitive rates, friendly apps, and an           ");
     SetConsoleTextAttribute(hConsole, 6);
    printf("||\n  || ");
     SetConsoleTextAttribute(hConsole, 7);
    printf("international network, HT Bank is your trusted partner. ");
     SetConsoleTextAttribute(hConsole, 6);

    printf("||");
     printf("\n  ||                                                         || ");
    printf("\n  =============================================================\n");
    getchar();
    click();
}
void page3() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);
     header();
    printf("\n-------------------| HT Bank Guide ");
    SetConsoleTextAttribute(hConsole, 6);
   printf("\n\n  =============================================================\n");
    printf("  ||                                                         ||\n");
    printf("  ||                      OUR SERVICES                       ||\n");
     printf("  ||                                                         || ");
   printf("\n  =============================================================\n");
   printf("  ||                                                         ||\n  || ");
   SetConsoleTextAttribute(hConsole, 14);
    printf("- Personal Banking  :");
    SetConsoleTextAttribute(hConsole, 7);
    printf(" Savings, accounts, investments.   ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("||\n  || ");
    SetConsoleTextAttribute(hConsole, 14);
    printf("- Business Banking  :");
    SetConsoleTextAttribute(hConsole, 7);
    printf(" Loans, payroll, merchant tools.   ");
     SetConsoleTextAttribute(hConsole, 6);
    printf("||\n  || ");
     SetConsoleTextAttribute(hConsole, 14);
    printf("- Digital Banking   :");
     SetConsoleTextAttribute(hConsole, 7);
    printf(" Mobile apps & instant transfers.  ");
     SetConsoleTextAttribute(hConsole, 6);

    printf("||\n  || ");
         SetConsoleTextAttribute(hConsole, 14);
    printf("- Wealth Management :");
         SetConsoleTextAttribute(hConsole, 7);
    printf(" Investments & retirement plans.   ");
         SetConsoleTextAttribute(hConsole, 6);

    printf("||\n  ||");
     SetConsoleTextAttribute(hConsole, 14);
    printf(" - International     :");
     SetConsoleTextAttribute(hConsole, 7);
    printf(" Currency exchange, global trades. ");
     SetConsoleTextAttribute(hConsole, 6);

    printf("||\n  || ");
    SetConsoleTextAttribute(hConsole, 14);
    printf("- Credit & Loans    :");
    SetConsoleTextAttribute(hConsole, 7);
    printf(" Flexible personal & business use. ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("||\n  ||                                                         ||\n  || ");
    SetConsoleTextAttribute(hConsole, 14);
    printf("Every service is efficient, secure, and future-driven");
    SetConsoleTextAttribute(hConsole, 6);
    printf(".  ||\n  ||                                                         ||\n ");
    printf(" =============================================================\n");
  getchar();
  click();
}
void page4() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);
    header();
    printf("\n-------------------| HT Bank Guide ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("\n\n  =============================================================\n");
    printf("  ||                                                         ||\n");
    printf("  ||                       ");
    SetConsoleTextAttribute(hConsole, 10);
    printf("OUR POLICY                        ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("||\n  ||                                                         ||\n");
    printf("  =============================================================\n");
    printf("  ||                                                         ||\n  || ");

    SetConsoleTextAttribute(hConsole, 14);
    printf("- Transparency   :");
    SetConsoleTextAttribute(hConsole, 7);
    printf(" Clear terms & fair interest rates.   ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("||\n  || ");

    SetConsoleTextAttribute(hConsole, 14);
    printf("- Security       :");
    SetConsoleTextAttribute(hConsole, 7);
    printf(" Advanced cybersecurity protections.  ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("||\n  || ");

    SetConsoleTextAttribute(hConsole, 14);
    printf("- Customer First :");
    SetConsoleTextAttribute(hConsole, 7);
    printf(" Prioritizing trust & satisfaction.   ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("||\n  || ");

    SetConsoleTextAttribute(hConsole, 14);
    printf("- Sustainability :");
    SetConsoleTextAttribute(hConsole, 7);
    printf(" Eco-friendly initiatives supported.  ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("||\n  || ");

    SetConsoleTextAttribute(hConsole, 14);
    printf("- Equality       :");
    SetConsoleTextAttribute(hConsole, 7);
    printf(" Equal service for all clients.       ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("||\n  ||                                                         ||\n  || ");

    SetConsoleTextAttribute(hConsole, 14);
    printf(" Our policies guarantee safety, respect, and growth");
    SetConsoleTextAttribute(hConsole, 6);
    printf(".    ||\n  ||                                                         ||\n ");
    printf(" =============================================================\n");

    getchar();
    click();
}


void menu_menu_section(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole,6);
printf("\n\n  _________________________________");
printf("\n |                                 |");
printf("\n |      ");
SetConsoleTextAttribute(hConsole,10);
printf("\xB2 HT BANK SERVICES \xB2       ");
SetConsoleTextAttribute(hConsole,6);
printf("|\n |_________________________________|");
printf("\n |                                 ");

SetConsoleTextAttribute(hConsole,6);
printf("|\n |  1 ");
SetConsoleTextAttribute(hConsole,7);
printf("-> Balance                   ");
SetConsoleTextAttribute(hConsole,6);
printf("|\n |  2 ");
SetConsoleTextAttribute(hConsole,7);
printf("-> Withdraw                  ");
SetConsoleTextAttribute(hConsole,6);
printf("|\n |  3 ");
SetConsoleTextAttribute(hConsole,7);
printf("-> Deposit                   ");
SetConsoleTextAttribute(hConsole,6);
printf("|\n |  4 ");
SetConsoleTextAttribute(hConsole,7);
printf("-> Lend                      ");
SetConsoleTextAttribute(hConsole,6);
printf("|\n |  5 ");
SetConsoleTextAttribute(hConsole,7);
printf("-> Debits                    ");
SetConsoleTextAttribute(hConsole,6);
printf("|\n |  6 ");
SetConsoleTextAttribute(hConsole,7);
printf("-> Return                    ");
SetConsoleTextAttribute(hConsole,6);
printf("|\n |_________________________________|\n\n");
 printf("|| ");
                                                    SetConsoleTextAttribute(hConsole,7);

}
void menu(client_data *p){
      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
       int choose;
       do{
                    do{
          header();
                                                    printf("\n-------------------| MENU SECTION ");
                                                    menu_menu_section();
                                                    scanf("%d",&choose);



       }while(choose!=1 &&choose!=2 &&choose!=3 &&choose!=4 &&choose!=5 && choose!=6 );
       switch(choose){

   case 1:balance(p);

    break;
    case 2:withdraw(p);
    break;
    case 3:Deposit(p);
    break;
    case 4:lend(p);
    break;
    case 5:
        debit(p);
    break;
    case 6:
    break;


       }

       }while(choose!=6);
}

int try_again(){
      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                          int tmp_choose;
                            // SetConsoleTextAttribute(hConsole,6);
                            //  printf("|");
                                  SetConsoleTextAttribute(hConsole,10);
                              printf("\n--------\n");
                              SetConsoleTextAttribute(hConsole,7);
                              printf("Type ");
                              SetConsoleTextAttribute(hConsole,10);
                              printf("1");
                              SetConsoleTextAttribute(hConsole,7);
                              printf(" to Try again ");
                              SetConsoleTextAttribute(hConsole,6);
                              printf("|");
                              printf(" Type ");
                              SetConsoleTextAttribute(hConsole,10);
                              printf("0 ");
                              SetConsoleTextAttribute(hConsole,7);
                              printf("to return to ");
                              SetConsoleTextAttribute(hConsole,6);
                              printf("MENU SECTION");
                              printf("\n________________________________\n") ;
                              do{
                                 printf("\n||");
                                 SetConsoleTextAttribute(hConsole,7);
                                 scanf("%d",&tmp_choose);
                              }while(tmp_choose!=1 && tmp_choose!=0);
                              return tmp_choose;
                              }
 int confirm(){

                              HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                          int tmp_choose;
                                  SetConsoleTextAttribute(hConsole,6);
                 printf("\n  _____________________________________");
                 printf("\n |                                     |");

                 printf("\n |");
                 SetConsoleTextAttribute(hConsole,7);
                 printf("Type  ");
                 SetConsoleTextAttribute(hConsole,10);
                 printf("0");
                 SetConsoleTextAttribute(hConsole,7);
                 printf(" to deny ");
                 SetConsoleTextAttribute(hConsole,6);
                 printf("||");
                  SetConsoleTextAttribute(hConsole,7);
                 printf(" Type ");
                 SetConsoleTextAttribute(hConsole,10);
                 printf("1");
                 SetConsoleTextAttribute(hConsole,7);
                 printf(" to confirm ");
                 SetConsoleTextAttribute(hConsole,6);

                 printf("|\n |_____________________________________|");
                           do{
                                 printf("\n\n||");
                                 SetConsoleTextAttribute(hConsole,7);
                                 scanf("%d",&tmp_choose);
                                 while(getchar() != '\n');
                              }while(tmp_choose!=1 && tmp_choose!=0);
                              return tmp_choose;
                              }
void new_balence(client_data *p){
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole,6);
                       printf("\n  _____________________________________");
                           printf("\nYour New Balance: ");
                          SetConsoleTextAttribute(hConsole, 10);
                            printf("%d $", p->current_money);
                               SetConsoleTextAttribute(hConsole,6);
                         printf("\n  _____________________________________\n");
                         SetConsoleTextAttribute(hConsole, 7);
                        // getchar();
                         click();

}

void lend(client_data *p){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   char year_tab[4];
    strncpy(year_tab,p->last_entrence+20,4);// To go directly to the year
    int current_year=atoi(year_tab);
    strncpy(year_tab,p->register_date+20,4);// To go directly to the year
    int first_year=atoi(year_tab),time_interval=current_year-first_year;


    // i will remove the condition : time_interval<1 temporary !!

   if(p->current_debits>100 || p->active==0 || p->age<18 || p->amount_deposit<5000 || p->current_money<1000 ){
    header();
       printf("\n-------------------| LEND SECTION ");
       Cond_false();
    getchar();
    click();
   }
   else {
    int lend_,tmp_choose;
  do{
       header();
       printf("\n-------------------| LEND SECTION ");

                      print_balance_box(p->current_money);
                         SetConsoleTextAttribute(hConsole,7);
                        enter_the_amount_lend();
                        scanf("%d",&lend_);
                       if(lend_<MIN_LEND ||lend_>MAX_LEND_LIMIT){
                           header();
                           printf("\n-------------------| LEND SECTION ");
                           lend_limit(70);
                              tmp_choose=try_again_v1();
                              if(tmp_choose==0){
                                  header();
                                    printf("\n-------------------| LEND SECTION ");
                                   lend_fail();
                                getchar();
                                 click();
                                return ;
                              }
                       }
                       else break;
            }while(lend_<MIN_LEND || lend_>MAX_LEND_LIMIT);
                                    header();
                                   printf("\n-------------------| LEND SECTION ");
                                  tmp_choose=confirm();
                              if(tmp_choose==0){
                                    header();
                                   printf("\n-------------------| LEND SECTION ");
                              lend_fail();
                                click();

                               return ;
                              }
                    p->current_money+=lend_;
                    p->current_debits+=lend_;
                     comment *tmpo=(comment*)malloc(sizeof(comment));
                             tmpo->id=p->id;
                               tmpo->type=1;
                              snprintf(tmpo->com, sizeof(tmpo->com), "%-20s | %6d |  %s ","LEND",lend_,p->last_entrence);
                           write_comments(tmpo,"C:\\Users\\user\\Desktop\\Professionnel\\comments.bin.txt");
                               free(tmpo);

                         write_edit(p,filename);
                               SetConsoleTextAttribute(hConsole,10);
                               wait();
                               header();
                                printf("\n-------------------| LEND SECTION ");
                              print_balance_box(p->current_money);
                              lend_succ();
                               // getchar();
                                click();

         }
   }
void Deposit(client_data *p){
          HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            int dep,tmp_choose;
            do{
                    header();
                 printf("\n-------------------| DEPOSIT SECTION ");
                       print_balance_box(p->current_money);
                         SetConsoleTextAttribute(hConsole,7);
                       enter_the_amount_dep();
                       scanf("%d",&dep);
                       if(dep<MIN_DEPOSIT){
                        header();
                       printf("\n-------------------| DEPOSIT SECTION ");
                              depos_limit(69);
                              tmp_choose=try_again_v1();
                            if(tmp_choose==0){
                                    header();
                                      printf("\n-------------------| DEPOSIT SECTION ");
                                    depos_fail();
                                getchar();
                                 click();
                              //  wait();
                                return ;
                              }
                       }

            }while(dep<MIN_DEPOSIT);

            if(dep>=MAX_DEPOSIT_LIMIT){
                header();
                 printf("\n-------------------| DEPOSIT SECTION ");;
                  printNoticeBox();
                 getchar();
                 click();
            }
              //wait();
                header();
                printf("\n-------------------| DEPOSIT SECTION ");
                              tmp_choose=confirm();
                              if(tmp_choose==0){
                                    header();
                                    printf("\n-------------------| DEPOSIT SECTION ");
                                   depos_fail();
                                click();
                                //wait();
                               return ;
                              }
                               p->current_money+=dep;
                               p->amount_deposit+=dep;
                               comment *tmpo=(comment*)malloc(sizeof(comment));
                             tmpo->id=p->id;
                               tmpo->type=1;
                              snprintf(tmpo->com, sizeof(tmpo->com), "%-20s | %6d |  %s ","DEPOSIT",dep,p->last_entrence);
                           write_comments(tmpo,"C:\\Users\\user\\Desktop\\Professionnel\\comments.bin.txt");
                               free(tmpo);
                               write_edit(p,filename);

                               //wait();
                               header();
                                printf("\n-------------------| DEPOSIT SECTION ");
                                print_balance_box(p->current_money);
                                dep_succ();
                               // getchar();
                                click();





}
void withdraw(client_data *p){
          HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

          if(p->current_money<=0){
                  header();
        printf("\n-------------------| WITHDRAW SECTION ");
          zero_with();
            getchar();
            click();
            return ;
          }
                int withdraw_;
                int tmp_choose;
                  do{
                    header();
                  printf("\n-------------------| WITHDRAW SECTION ");
                      print_balance_box(p->current_money);
                         SetConsoleTextAttribute(hConsole,7);
                         enter_the_amount_wdraw();
                         scanf("%d",&withdraw_);
                       if((withdraw_<10 || withdraw_>MAX_WITHDRAW_LIMIT)|| withdraw_>p->current_money){
                             wait();
                             header();
                            printf("\n-------------------| WITHDRAW SECTION ");

                        if(withdraw_<10 || withdraw_>MAX_WITHDRAW_LIMIT){
                              withd_fail_more2less(69);
                              tmp_choose=try_again_v1();
                              if(tmp_choose==0){
                                    header();
                                    printf("\n-------------------| WITHDRAW SECTION \n\n");
                                    with_fail();
                                   getchar();
                                  click();
                               // wait();
                                return ;
                              }
                        }
                        else{
                                    print_balance_box(p->current_money);
                                    out_balence_with();
                                   tmp_choose=try_again();
                              if(tmp_choose==0){
                           header();
                                    printf("\n-------------------| WITHDRAW SECTION \n\n");
                                    with_fail();
                                getchar();
                                 click();
                                wait();
                               return ;
                              }
                        }
                       }
                }while((withdraw_<10 || withdraw_>MAX_WITHDRAW_LIMIT)|| withdraw_>p->current_money);

                wait();
                header();
                printf("\n-------------------| WITHDRAW SECTION \n\n");

                                 tmp_choose=confirm();
                              if(tmp_choose==0){
                                    header();
                                    printf("\n-------------------| WITHDRAW SECTION \n\n");
                                    with_fail();
                                click();
                                //wait();
                               return ;
                              }
                               p->current_money-=withdraw_;
                               p->amount_withdraw+=withdraw_;
                               comment *tmpo=(comment*)malloc(sizeof(comment));
                             tmpo->id=p->id;
                               tmpo->type=1;
                              snprintf(tmpo->com, sizeof(tmpo->com), "%-20s | %6d |  %s ","WITHDRAW",withdraw_,p->last_entrence);
                            //  printf("--------------------> BUG");
                            //  click();
                             // click();
                           write_comments(tmpo,"C:\\Users\\user\\Desktop\\Professionnel\\comments.bin.txt");
                               free(tmpo);
                              //  printf("--------------------> BUG");
                             // click();
                             // click();
                               write_edit(p,filename);
                              // SetConsoleTextAttribute(hConsole,10);
                               //wait();
                                header();
                                printf("\n-------------------| WITHDRAW SECTION ");

                                 with_succ();
                                 print_balance_box(p->current_money);
                                // getchar();
                                 click();


                               //new_balence(p);
}
void Cond_false(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 printf("\n\n __________________________\n");
    printf("|                          |\n");
    printf("|   ");
      SetConsoleTextAttribute(hConsole, 4);
    printf("LEND OPERATION FAILED  ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n|                          |\n");
    printf("|__________________________|\n");
    printf("|                          |\n");

    printf("|     ");
    SetConsoleTextAttribute(hConsole, 10);
    printf("Condition not met    ");
     SetConsoleTextAttribute(hConsole, 6);
    printf("|\n|  ");
    SetConsoleTextAttribute(hConsole, 7);
    printf("You can report this in  ");
    SetConsoleTextAttribute(hConsole, 6);

    printf("|\n|      ");
    SetConsoleTextAttribute(hConsole, 7);
    printf("Contact Section     ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n|                          |\n");
    printf("|__________________________|\n");
    }
void dep_succ(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole,6);
 printf("\n ___________________________________\n|                                   |\n|    ");
 SetConsoleTextAttribute(hConsole,7);
   printf("Deposit Operation ");
   SetConsoleTextAttribute(hConsole,10);
   printf("Succeded");
   SetConsoleTextAttribute(hConsole,6);
   printf("     |\n|___________________________________|");
   SetConsoleTextAttribute(hConsole,7);
   }
void printNoticeBox() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);
    printf("\n\n ____________________________________________________________________________________________________ \n");
    printf("|                                                                                                    ");
   SetConsoleTextAttribute(hConsole, 6);
    printf("|\n|");
     SetConsoleTextAttribute(hConsole, 7);
     printf("                                                                                                    ");
   SetConsoleTextAttribute(hConsole, 6);
    printf("|\n|");
     SetConsoleTextAttribute(hConsole, 7);
    printf("  NOTICE: ");
    SetConsoleTextAttribute(hConsole, 10);
    printf("Verification Required                                                                     ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n|");
    SetConsoleTextAttribute(hConsole, 7);
    printf("                                                                                                    ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n|");
     SetConsoleTextAttribute(hConsole, 7);
    printf("  Your deposit exceeds the threshold amount and must comply with regulatory requirements.           ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n|");
     SetConsoleTextAttribute(hConsole, 7);
    printf("                                                                                                    ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n|");
     SetConsoleTextAttribute(hConsole, 7);
    printf("  To proceed, please provide valid documentation proving the source of your funds. This is required ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n|");
     SetConsoleTextAttribute(hConsole, 7);
    printf("  under KYC (Know Your Customer) and Anti-Money Laundering (AML) regulations to ensure safe and     ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n|");
     SetConsoleTextAttribute(hConsole, 7);
    printf("  lawful banking operations.                                                                        ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n|");
     SetConsoleTextAttribute(hConsole, 7);
    printf("                                                                                                    ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n|");
     SetConsoleTextAttribute(hConsole, 7);
    printf("  Accepted documents may include:                                                                   ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n|");
     SetConsoleTextAttribute(hConsole, 7);
    printf("   - Recent payslips or tax returns                                                                 ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n|");
     SetConsoleTextAttribute(hConsole, 7);
    printf("   - Sale contracts (e.g., property or vehicle)                                                     ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n|");
     SetConsoleTextAttribute(hConsole, 7);
    printf("   - Bank statements showing fund origin                                                            ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n|");
     SetConsoleTextAttribute(hConsole, 7);
    printf("   - Government-issued transaction permits                                                          ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n|");
     SetConsoleTextAttribute(hConsole, 7);
    printf("                                                                                                    ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n|");
     SetConsoleTextAttribute(hConsole, 7);
    printf("  Your cooperation helps us maintain a secure and transparent financial system.                     ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n|");
     SetConsoleTextAttribute(hConsole, 7);
    printf("  Thank you for banking with HT Bank.                                                               ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n|");
     SetConsoleTextAttribute(hConsole, 7);
    printf("                                                                                                    ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n|");
     SetConsoleTextAttribute(hConsole, 7);
    printf("  You Can Send all of this information To OUR official email : ");
    SetConsoleTextAttribute(hConsole, 10);
    printf("htBank@gmail.com                     ");
    SetConsoleTextAttribute(hConsole, 6);
   printf("|\n|");
    printf("                                                                                                    ");
    printf("|\n|");
    printf("____________________________________________________________________________________________________|\n\n");
    SetConsoleTextAttribute(hConsole, 7); // Reset color
}
void depos_fail(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,6);
printf("\n\n ______________________________________\n|                                      |\n|      ");
  SetConsoleTextAttribute(hConsole,7);
  printf(" Deposit Operation");
  SetConsoleTextAttribute(hConsole,4);
  printf(" Failed       ");
   SetConsoleTextAttribute(hConsole,6);
  printf("|\n|______________________________________|\n");
   SetConsoleTextAttribute(hConsole,7);
   }
void depos_limit(int BOX_WIDTH){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
char message[200];

// Compose the message
snprintf(message, sizeof(message),
         "You can't DEPOSIT less than %d $ or more than %d $",
         MIN_DEPOSIT, MAX_DEPOSIT_LIMIT);

int msg_len = strlen(message);
int padding = (BOX_WIDTH - 2 - msg_len) / 2; // 2 for borders

printf("\n\n ");
SetConsoleTextAttribute(hConsole, 6);

// Top border
for (int i = 0; i < BOX_WIDTH - 2; i++) printf("_");
printf("\n|");
for (int i = 0; i < BOX_WIDTH - 2; i++) printf(" ");
printf("|\n|");

// Left padding
for (int i = 0; i < padding; i++) printf(" ");

// Print the message with colors
SetConsoleTextAttribute(hConsole, 7);
for (int j = 0; j < msg_len; j++) {
    if (isdigit(message[j]) || message[j] == '$') {
        SetConsoleTextAttribute(hConsole, 10); // Green for numbers & $
        printf("%c", message[j]);
        SetConsoleTextAttribute(hConsole, 7);
    } else {
        printf("%c", message[j]);
    }
}

// Right padding (in case of odd space difference)
SetConsoleTextAttribute(hConsole, 6);
for (int i = 0; i < BOX_WIDTH - 2 - msg_len - padding; i++) printf(" ");
printf("|\n");

// Bottom border
printf("|");
for (int i = 0; i < BOX_WIDTH - 2; i++) printf("_");
printf("|\n");
}
void zero_with(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(hConsole,6);
printf("\n\n _________________________________\n|                                 |\n|    ");
   SetConsoleTextAttribute(hConsole,7);
   printf("Withdraw Operation ");
   SetConsoleTextAttribute(hConsole,4);
   printf("Failed");
   SetConsoleTextAttribute(hConsole,6);
   printf("    |\n|_________________________________|\n|                                 |\n|     ");
    SetConsoleTextAttribute(hConsole,7);
   printf("No ");
    SetConsoleTextAttribute(hConsole,10);
   printf("Funds");
    SetConsoleTextAttribute(hConsole,7);
   printf(" In The Account");
   SetConsoleTextAttribute(hConsole,6);
   printf("     |\n|_________________________________|\n");
   }
void out_balence_with(){
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsole,6);
   printf("\n\n _________________________________________________\n|                                                 |\n|    ");
   SetConsoleTextAttribute(hConsole,7);
   printf("You Can't Withdraw More Than Your ");
   SetConsoleTextAttribute(hConsole,10);
   printf("Balence");
   SetConsoleTextAttribute(hConsole,6);
   printf("    |\n|_________________________________________________|\n");
   }
void with_fail(){
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(hConsole,6);
printf("\n\n ______________________________________\n|                                      |\n|      ");
   SetConsoleTextAttribute(hConsole,7);
  printf("Withdraw Operation");
   SetConsoleTextAttribute(hConsole,4);
  printf(" Failed       ");
   SetConsoleTextAttribute(hConsole,6);
  printf("|\n|______________________________________|\n");
   SetConsoleTextAttribute(hConsole,7);


}
void withd_fail_more2less(int BOX_WIDTH ){
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 char message[200];

    // Compose the message
    snprintf(message, sizeof(message),
             "You can't withdraw less than %d $ or more than %d $",
             MIN_WITHDRAW, MAX_WITHDRAW_LIMIT);

    int msg_len = strlen(message);
    int padding = (BOX_WIDTH - 2 - msg_len) / 2; // 2 for borders

    printf("\n\n ");
     SetConsoleTextAttribute(hConsole,6);
    for (int i = 0; i < BOX_WIDTH-2; i++) printf("_");
    printf("\n|");
    for (int i = 0; i < BOX_WIDTH-2; i++) printf(" ");
    printf("|\n|");

    // Left padding
    for (int i = 0; i < padding; i++) printf(" ");


   SetConsoleTextAttribute(hConsole,7);
    for(int j=0;j<msg_len;j++){
        if(isdigit(message[j]) || message=='$'){
            SetConsoleTextAttribute(hConsole,10);
            printf("%c",message[j]);
            SetConsoleTextAttribute(hConsole,7);
        }
        else  printf("%c",message[j]);
    }

    // Right padding (in case of odd space difference)
    SetConsoleTextAttribute(hConsole,6);
    for (int i = 0; i < BOX_WIDTH - 2 - msg_len - padding; i++) printf(" ");
    printf("|\n");

    printf("|");
    for (int i = 0; i < BOX_WIDTH - 2; i++) printf("_");
    printf("|\n");

    }
void with_succ(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole,6);
 printf("\n\n ___________________________________\n|                                   |\n|    ");
 SetConsoleTextAttribute(hConsole,7);
   printf("Withdraw Operation ");
   SetConsoleTextAttribute(hConsole,10);
   printf("succeded");
   SetConsoleTextAttribute(hConsole,6);
   printf("    |\n|___________________________________|");
   SetConsoleTextAttribute(hConsole,7);
}

void lend_limit(int BOX_WIDTH ) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char message[200];
    snprintf(message, sizeof(message),
             "You can't LEND less than %d $ or more than %d $",
             MIN_LEND, MAX_LEND_LIMIT);

    int msg_len = strlen(message);
    int padding = (BOX_WIDTH - 2 - msg_len) / 2;

    // Top border
    SetConsoleTextAttribute(hConsole, 6);
    printf("\n\n ");
    for (int i = 0; i < BOX_WIDTH - 2; i++) printf("_");
    printf("\n|");
    for (int i = 0; i < BOX_WIDTH - 2; i++) printf(" ");
    printf("|\n|");

    // Left padding
    for (int i = 0; i < padding; i++) printf(" ");

    // Print message with color
    SetConsoleTextAttribute(hConsole, 7);
    for (int j = 0; j < msg_len; j++) {
        if (isdigit(message[j]) || message[j] == '$') {
            SetConsoleTextAttribute(hConsole, 10); // numbers & $ → green
            printf("%c", message[j]);
            SetConsoleTextAttribute(hConsole, 7);
        } else if (strstr(message, "LEND") &&
                   j >= (strstr(message, "LEND") - message) &&
                   j < (strstr(message, "LEND") - message + 4)) {
            SetConsoleTextAttribute(hConsole, 14); // LEND → yellow
            printf("%c", message[j]);
            SetConsoleTextAttribute(hConsole, 7);
        } else {
            printf("%c", message[j]);
        }
    }

    // Right padding
    SetConsoleTextAttribute(hConsole, 6);
    for (int i = 0; i < BOX_WIDTH - 2 - msg_len - padding; i++) printf(" ");
    printf("|\n");

    // Bottom border
    printf("|");
    for (int i = 0; i < BOX_WIDTH - 2; i++) printf("_");
    printf("|\n");

    SetConsoleTextAttribute(hConsole, 7); // reset
}
void lend_fail(){
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsole,6);
printf("\n\n ______________________________________\n|                                      |\n|      ");
  SetConsoleTextAttribute(hConsole,7);
  printf("  Lend Operation");
  SetConsoleTextAttribute(hConsole,4);
  printf(" Failed         ");
  SetConsoleTextAttribute(hConsole,6);
  printf("|\n|______________________________________|\n");
  SetConsoleTextAttribute(hConsole,7);
  }
void lend_succ(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole,6);
 printf("\n\n ___________________________________\n|                                   |\n|    ");
 SetConsoleTextAttribute(hConsole,7);
   printf("  Lend Operation ");
 SetConsoleTextAttribute(hConsole,10);
   printf("succeded  ");
  SetConsoleTextAttribute(hConsole,6);
   printf("    |\n|___________________________________|");
   SetConsoleTextAttribute(hConsole,7);
   }

void balance(client_data *p){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    header();
      printf("\n-------------------| MENU SECTION ");
       print_balance_box(p->current_money);
       getchar();
       click();
}
void print_balance_box(int balance) {
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,7);
    char bal_text[64];
    // Prepare the balance text (fixing the spelling: "Balance")
    snprintf(bal_text, sizeof(bal_text), "Your Current Balance : %d $", balance);

    // decide minimum inner width (space inside the |   | )
    const int MIN_INNER = 33;

    // compute the inner width needed for the longest line
    int needed = (int)strlen(bal_text);
    int inner_width = (needed > MIN_INNER) ? needed : MIN_INNER;

    // outer width is inner + 2 for the side spaces we want to print
    int total_width = inner_width + 2; // keep a single space padding left & right

    // Print top border
    printf("\n\n ");
     SetConsoleTextAttribute(hConsole,6);
    for (int i = 0; i < total_width; ++i) putchar('_');
    printf("\n");

    // Empty line inside the box
    printf("|");
    for (int i = 0; i < total_width; ++i) putchar(' ');
    printf("|\n");

    // Print centered balance line
    int text_len = (int)strlen(bal_text);
    int left_pad = (total_width - text_len) / 2;
    int right_pad = total_width - text_len - left_pad;

    printf("|");
     SetConsoleTextAttribute(hConsole,7);
    for (int i = 0; i < left_pad; ++i) putchar(' ');


    //printf("%s", bal_text);
     SetConsoleTextAttribute(hConsole,7);
    for(int j=0;j<needed;j++){
        if(isdigit(bal_text[j]) ||bal_text[j]=='$'){
             SetConsoleTextAttribute(hConsole,10);
             printf("%c",bal_text[j]);
              SetConsoleTextAttribute(hConsole,7);
        }
        else  printf("%c",bal_text[j]);
    }
    SetConsoleTextAttribute(hConsole,6);
    for (int i = 0; i < right_pad; ++i) putchar(' ');
    printf("|\n");
    // Empty line inside the box
    printf("|");
    for (int i = 0; i < total_width; ++i) putchar(' ');
    printf("|\n");
    // Bottom border
    printf("|");
    for (int i = 0; i < total_width; ++i) putchar('_');
    printf("|\n");
                  SetConsoleTextAttribute(hConsole,7);
}

void debit(client_data *p){
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 if(p->current_debits<=0){
     header();
 printf("\n-------------------| DEBITS SECTION ");
zero_debit();
    getchar();
    click();
    return ;
 }
 int deb,tmp_choose,invalid;
 do{
    invalid=0;
    header();
 printf("\n-------------------| DEBITS SECTION ");
 bal_deb_bar(p->current_money,p->current_debits);
 enter_the_amount_debi(p->current_debits);
 scanf("%d",&deb);

 if(deb<=0){
     header();
 printf("\n-------------------| DEBITS SECTION ");
   neg_input_deb();
     invalid=1;
 }
 else if(deb>p->current_debits){
         header();
 printf("\n-------------------| DEBITS SECTION ");
                       print_limit_deb(p->current_debits);
                              invalid=1;
 }
 else if(deb>p->current_money){
      header();
 printf("\n-------------------| DEBITS SECTION \n\n");
                            printf("\n________________________________\n") ;
                            SetConsoleTextAttribute(hConsole,7);
                              printf("You can't depass your balence :  ");
                              SetConsoleTextAttribute(hConsole,10);
                              printf("%d $ ",p->current_money);
                              invalid=1;
 }

      if (invalid) {
                              tmp_choose=try_again_v1();
                              if(tmp_choose==0){
                                  header();
                printf("\n-------------------| DEBITS SECTION ");
                                    deb_fail();
                                getchar();
                                 click();
                                wait();
                                return ;
                              }

      }
}while(deb<0 || deb>p->current_money || deb>p->current_debits);

                               header();
                              printf("\n-------------------| DEBITS SECTION ");
                              tmp_choose=confirm();
                              if(tmp_choose==0){
                                    header();
                printf("\n-------------------| DEBITS SECTION ");
                                    deb_fail();
                                    getchar();
                                click();
                               return ;
                              }
                    p->current_money-=deb;
                    p->current_debits-=deb;
                    comment *tmpo=(comment*)malloc(sizeof(comment));
                             tmpo->id=p->id;
                               tmpo->type=1;
                              snprintf(tmpo->com, sizeof(tmpo->com), "%-20s | %6d |  %s ","DEBIT",deb,p->last_entrence);
                           write_comments(tmpo,"C:\\Users\\user\\Desktop\\Professionnel\\comments.bin.txt");
                               free(tmpo);
                    write_edit(p,filename);
                               SetConsoleTextAttribute(hConsole,10);
                               wait();
                               header();
                                printf("\n-------------------|DEBITS SECTION ");
                                print_balance_box(p->current_money);
                                deb_succ();
                                getchar();
                                click();


}



void print_limit_deb(int debit) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char message[100];

    // Build the message
    snprintf(message, sizeof(message), "You can't pay more than %d $", debit);
    int msg_len = strlen(message);
    int boxWidth = msg_len + 4; // 2 spaces padding on each side

    // Top border
    SetConsoleTextAttribute(hConsole, 6);
    printf("\n\n ");
    for (int i = 0; i < boxWidth; i++) printf("_");
    printf("\n");

    printf("|");
    for (int i = 0; i < boxWidth; i++) printf(" ");
    printf("|\n");

    // Message line
    printf("|  ");
    SetConsoleTextAttribute(hConsole, 7);
    for (int i = 0; i < msg_len; i++) {
        if (isdigit(message[i]) || message[i] == '$') {
            SetConsoleTextAttribute(hConsole, 10); // green
            printf("%c", message[i]);
            SetConsoleTextAttribute(hConsole, 7);
        } else {
            printf("%c", message[i]);
        }
    }
    SetConsoleTextAttribute(hConsole, 6);
    printf("  |\n");
    printf("|");
    for (int i = 0; i < boxWidth; i++) printf(" ");
    printf("|\n");
    // Bottom border
    printf("|");
    for (int i = 0; i < boxWidth; i++) printf("_");
    printf("|");
    SetConsoleTextAttribute(hConsole, 7); // reset color
}
void zero_debit(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(hConsole,6);
 printf("\n\n _______________________________________\n");
 printf("|                                       |\n");
 printf("|    ");
 SetConsoleTextAttribute(hConsole,7);
 printf("You don't have ");
 SetConsoleTextAttribute(hConsole,4);
 printf("any debits");
 SetConsoleTextAttribute(hConsole,7);
 printf(" to buy   ");
 SetConsoleTextAttribute(hConsole,6);
  printf("|\n|                                       |\n");
  printf("|_______________________________________|\n");
    SetConsoleTextAttribute(hConsole,7);
    }
void deb_fail(){
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,6);
printf("\n\n ______________________________________\n|                                      |\n|      ");
SetConsoleTextAttribute(hConsole,7);
  printf("   Debit Purchase ");
 SetConsoleTextAttribute(hConsole,4);
  printf("Failed        ");
   SetConsoleTextAttribute(hConsole,6);
  printf("|\n|______________________________________|\n");
SetConsoleTextAttribute(hConsole,7);
}
void neg_input_deb(){
      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole,6);
 printf("\n\n ______________________________________\n|                                      |\n|    ");

 SetConsoleTextAttribute(hConsole,7);
   printf("Only ");
 SetConsoleTextAttribute(hConsole,10);
   printf("Positive ");
SetConsoleTextAttribute(hConsole,7);
   printf("Numbers Allowed");

   SetConsoleTextAttribute(hConsole,6);
   printf("     |\n|______________________________________|");
  SetConsoleTextAttribute(hConsole,7);
  }
void bal_deb_bar(int balance, int debit) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char line1[100], line2[100];

    // Build the two content lines
    snprintf(line1, sizeof(line1), "Your Balance : %d $", balance);
    snprintf(line2, sizeof(line2), "Your DEBITS  : %d $", debit);

    // Find the max line length
    int len1 = strlen(line1);
    int len2 = strlen(line2);
    int maxLen = (len1 > len2 ? len1 : len2);

    int boxWidth = maxLen + 7; // +6 for padding and borders

    // Top border
    SetConsoleTextAttribute(hConsole, 6);
    printf("\n\n ");
    for (int i = 0; i < boxWidth; i++) printf("_");

    printf("\n|");
   for (int i = 0; i < boxWidth; i++) printf(" ");
   printf("|\n");


    // Line 1
    printf("| ");
    SetConsoleTextAttribute(hConsole, 7);
    printf(" Your Balance : ");
    SetConsoleTextAttribute(hConsole, 10);
    printf("%d $", balance);
    int space1 = boxWidth - 2 - len1;
    for (int i = 0; i < space1; i++) printf(" ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n");

    // Divider
    printf("|");
    for (int i = 0; i < boxWidth; i++) printf("_");
    printf("|\n|");

   for (int i = 0; i < boxWidth; i++) printf(" ");
   printf("|\n");

    // Line 2
    printf("| ");
    SetConsoleTextAttribute(hConsole, 7);
    printf(" Your DEBITS  : ");
    SetConsoleTextAttribute(hConsole, 10);
    printf("%d $", debit);
    int space2 = boxWidth - 2 - len2;
    for (int i = 0; i < space2; i++) printf(" ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n");

    // Bottom border
    printf("|");
    for (int i = 0; i < boxWidth; i++) printf("_");
    printf("|");

    SetConsoleTextAttribute(hConsole, 7); // reset
}
void deb_succ(){
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,6);
printf(" ______________________________________\n|                                      |\n|      ");
SetConsoleTextAttribute(hConsole,7);
  printf("  Debit Purchase ");
 SetConsoleTextAttribute(hConsole,10);
  printf("Succeded       ");
   SetConsoleTextAttribute(hConsole,6);
  printf("|\n|______________________________________|\n");
SetConsoleTextAttribute(hConsole,7);
}
void enter_the_amount_debi(int debit){
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, 6);
printf("\n  ___________________________________\n |");
SetConsoleTextAttribute(hConsole, 10);
printf("___                            ____");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |   ");
SetConsoleTextAttribute(hConsole, 10);
printf("\\");
SetConsoleTextAttribute(hConsole, 6);
printf("---<");
SetConsoleTextAttribute(hConsole, 7);
printf(" Enter The ");
SetConsoleTextAttribute(hConsole, 4);
printf("Amount ");
SetConsoleTextAttribute(hConsole, 6);
printf(">---");
SetConsoleTextAttribute(hConsole, 10);
printf("/");
SetConsoleTextAttribute(hConsole, 6);
printf("    |\n |\\   ");
SetConsoleTextAttribute(hConsole, 10);
printf("\\------------------------/    ");
SetConsoleTextAttribute(hConsole, 6);
printf("/|\n ");
SetConsoleTextAttribute(hConsole, 14);
printf("|_");
SetConsoleTextAttribute(hConsole, 6);
printf("\\_______________________________/");
SetConsoleTextAttribute(hConsole, 14);
printf("_|");
SetConsoleTextAttribute(hConsole, 14);
printf("\n |      ");
SetConsoleTextAttribute(hConsole, 6);
printf("\\                      /     ");
SetConsoleTextAttribute(hConsole, 14);
printf("|");
SetConsoleTextAttribute(hConsole, 14);
printf("\n |");
SetConsoleTextAttribute(hConsole, 14);
printf("------");
SetConsoleTextAttribute(hConsole, 6);
printf("|");
SetConsoleTextAttribute(hConsole, 4);
char buffer[50];
snprintf(buffer, sizeof(buffer), "1-%d $", debit); // the middle text

int totalWidth = 21;  // fixed width you want
int contentLen = strlen(buffer) + 4; // +4 for "( " and " )"
int padding = (totalWidth - contentLen) / 2;

// Left spaces
for (int i = 0; i < padding; i++) printf(" ");

// Print ( 1-debit )
//SetConsoleTextAttribute(hConsole, 7);
//printf("( %s )", buffer);
SetConsoleTextAttribute(hConsole, 6);
printf("( ");

for(int j=0;j<strlen(buffer);j++){
     SetConsoleTextAttribute(hConsole, 7);
    if(buffer[j]=='$'){
        SetConsoleTextAttribute(hConsole, 10);
        printf("$");
        SetConsoleTextAttribute(hConsole, 7);

    }
    else if(isdigit(buffer[j])){
        SetConsoleTextAttribute(hConsole, 14);
        printf("%c",buffer[j]);
        SetConsoleTextAttribute(hConsole, 7);

    }
    else printf("%c",buffer[j]);


}
SetConsoleTextAttribute(hConsole, 6);
printf(" )");
SetConsoleTextAttribute(hConsole, 7);

// Right spaces (in case of odd difference)
for (int i = 0; i < totalWidth - contentLen - padding; i++) printf(" ");
SetConsoleTextAttribute(hConsole, 6);
printf("|");
SetConsoleTextAttribute(hConsole, 14);
printf("------");
SetConsoleTextAttribute(hConsole, 14);
printf("|\n |______");
SetConsoleTextAttribute(hConsole, 6);
printf("\\____________________/");
SetConsoleTextAttribute(hConsole, 14);
printf("_______|\n\n");
SetConsoleTextAttribute(hConsole, 6);
printf("||");
SetConsoleTextAttribute(hConsole, 7);
               }
void enter_the_amount_dep(){
               HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
              SetConsoleTextAttribute(hConsole, 6);
               printf(" \n  _________________________________");
               printf("\n |                                 |");
               printf("\n |  ");
               SetConsoleTextAttribute(hConsole,7);
               printf("Enter the amount to ");
              SetConsoleTextAttribute(hConsole,10);
               printf("deposit ");
              SetConsoleTextAttribute(hConsole, 7);
               printf(":");
                SetConsoleTextAttribute(hConsole, 6);
               printf("  |\n |_________________________________|\n\n");
               printf("||");
               SetConsoleTextAttribute(hConsole, 7);
               }
void enter_the_amount_wdraw(){
               HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
              SetConsoleTextAttribute(hConsole, 6);
               printf("\n  _________________________________");
               printf("\n |                                 |");
               printf("\n |  ");
                SetConsoleTextAttribute(hConsole, 7);
               printf("Enter The Amount To ");
               SetConsoleTextAttribute(hConsole,10);
               printf("Withdraw");
                SetConsoleTextAttribute(hConsole, 6);
               printf("   |\n |_________________________________|\n\n");
               printf("||");
               SetConsoleTextAttribute(hConsole, 7);
               }
void enter_the_amount_lend(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
              SetConsoleTextAttribute(hConsole, 6);
               printf("\n  ______________________________");
               printf("\n |                              |");
               printf("\n |  ");
              SetConsoleTextAttribute(hConsole, 7);
               printf("Enter The Amount To ");
           SetConsoleTextAttribute(hConsole,10);
               printf("Lend  ");
              SetConsoleTextAttribute(hConsole, 6);
               printf("  |\n |______________________________|\n\n");
               printf("||");
               SetConsoleTextAttribute(hConsole, 7);


}

void write_edit(client_data *p, char *filename){
    client_data *tmp = (client_data*)malloc(sizeof(client_data));
    if(tmp == NULL){
         perror("SYSTEM ERROR (ALLOCATION MEMORY FAILED)");
        exit(1);
    }
    char *filename_tmp = "C:\\Users\\user\\Desktop\\Professionnel\\tmp_bin.txt";
    FILE *w = fopen(filename_tmp, "wb");
    FILE *r = fopen(filename, "rb");

    if(w == NULL){
         perror("SYSTEM ERROR (FILE OPENING FAILED)");
        exit(1);
    }
    if(r == NULL){
         perror("SYSTEM ERROR (FILE OPENING FAILED)");
        exit(1);
    }

    client_data *p_encrypted = encrypt_all_data(p);

while (fread(tmp, sizeof(client_data), 1, r) == 1){
        if(tmp->id != p->id){
            fwrite(tmp, sizeof(client_data), 1, w);
        }
        else {
            fwrite(p_encrypted, sizeof(client_data), 1, w);
        }
    }
   p=decrypt_all_data(p);
    free(tmp);
    fclose(w);
    fclose(r);


    if (remove(filename) != 0) {
        perror("Failed to remove original file");
        exit(1);
    }

    if (rename(filename_tmp, filename) != 0) {
        perror("Failed to rename temp file");
        exit(1);
    }
}

void menu_info(){
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    SetConsoleTextAttribute(hConsole, 6);
    printf("\n\n  _________________________________");
    printf("\n |                                 |");
    printf("\n |      ");
    SetConsoleTextAttribute(hConsole, 10);
    printf("  \xB2 HT BANK MENU \xB2         ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n |_________________________________|");

    printf("\n |                                 |");
    printf("\n |  1 ");
    SetConsoleTextAttribute(hConsole, 7);
    printf("-> Balance & Debits          ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n |  2 ");
    SetConsoleTextAttribute(hConsole, 7);
    printf("-> Account Info              ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n |  3 ");
    SetConsoleTextAttribute(hConsole, 7);
    printf("-> Transaction               ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n |  4 ");
    SetConsoleTextAttribute(hConsole, 7);
    printf("-> Change Pass               ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n |  5 ");
    SetConsoleTextAttribute(hConsole, 7);
    printf("-> Return                    ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n |_________________________________|\n\n");
    printf("||");

    SetConsoleTextAttribute(hConsole, 7);

}
int choose_info(){
int choose;

do{
    menu_info();
    scanf("%d",&choose);
}while(choose!=1 && choose!=2 && choose!=3 && choose!=4 && choose!=5);
return choose;


}
void info(client_data *p){

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int choose;
do{

header();
printf("\n-------------------| INFO IN SECTION ");
 choose=choose_info();
switch(choose){

case 1:balence_debits(p);
         break;
case 2:client_info(p);
         break;

case 3:transaction(p);
         break;

case 4:edit_pass(p);
         break;

}

}while(choose!=5);

}

void balence_debits(client_data *p){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  header();
  printf("\n-------------------| INFO IN SECTION / Balence and Debits ");
 printf("\n\n|____________________/\n|");
       SetConsoleTextAttribute(hConsole,7);
       printf(" Balance : ");
         SetConsoleTextAttribute(hConsole,10);
       printf("%d ",p->current_money);
       SetConsoleTextAttribute(hConsole,7);
       printf("$");
          SetConsoleTextAttribute(hConsole,6);
       printf("\n|____________________\n|");
        //printf("\n\n_____________________\n");
       SetConsoleTextAttribute(hConsole,7);
       printf(" Debits : ");
         SetConsoleTextAttribute(hConsole,4);
       printf("%d ",p->current_debits);
       SetConsoleTextAttribute(hConsole,7);
       printf("$");
          SetConsoleTextAttribute(hConsole,6);
         printf("\n|____________________\n");
           printf("                     \\");
            SetConsoleTextAttribute(hConsole,7);
            getchar();
            click();
}
void client_info(client_data *p){

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
header();
printf("\n-------------------| INFO SECTION / account info  ");
info_sec(p);
     int choose;
     int k=1;
     do{
            if(k==0){
                header();
                printf("\n-------------------| INFO SECTION / account info  ");
            }
        print_file_choose();
        scanf("%d",&choose);
        k=0;

     }while(choose!=0 && choose!=1);
     if(choose==1){
         char filepath[260];
do{
    header();
printf("\n-------------------| INFO SECTION / transaction info / print ");
print_file_box();
scanf("%d",&choose);
}while(choose!=1 && choose!=0);

    if(choose==0)print_info(p,"C:\\Users\\user\\Desktop\\output\\result1.txt");
else {
    header();
    printf("\n-------------------| INFO SECTION / transaction info / print ");
    path_box();
      if (scanf(" %[^\n]s",filepath)!=1) {
        perror("Error reading input");
        return ;
    }
   //  filepath[strcspn(filepath, "\n")] = '\0';
     print_info(p,filepath);
}




     }


//print_file_box();
getchar();
click();


}
void print_info(client_data *p,char *filename_print){
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    FILE *fw=fopen(filename_print,"w");
    if (!fw) {
        perror("Error opening file");
        return ;
    }
       fprintf(fw,
"+==========================================================+\n"
"|           H T   B A N K   C L I E N T   D A T A          |\n"
"+==========================================================+\n"
"| File Type  : TEXT (.txt)                                 |\n"
"| Export Date: %-43s |\n"
"| Generated  : HT Bank Management System v1.0              |\n"
"+----------------------------------------------------------+\n"
"| ID             : %-40d|\n"
"| NAME           : %-40s|\n"
"| CARD CODE      : %-40s|\n"
"| AGE            : %-40d|\n"
"| BIRTH DATE     : %-40s|\n"
"| ADDRESS        : %-40s|\n"
"| REGISTERED     : %-40s|\n"
"| LAST ENTRANCE  : %-40s|\n"
"| CURRENT MONEY  : %-40d|\n"
"| DEPOSIT AMOUNT : %-40d|\n"
"| WITHDRAW AMOUNT: %-40d|\n"
"| CURRENT DEBITS : %-40d|\n"
"| PHONE          : %-40s|\n"
"| ACTIVE STATUS  : %-40s|\n"
"+==========================================================+\n",
        p->last_entrence,
        p->id,
        p->name,
        p->card_code_n,
        p->age,
        p->birth,
        p->adress,
        p->register_date,
        p->last_entrence,
        p->current_money,
        p->amount_deposit,
        p->amount_withdraw,
        p->current_debits,
        p->phone,
        (p->active ? "Active" : "Inactive")
    );
    fclose(fw);
   wait();
   header();
   printf("\n-------------------| INFO SECTION / account info / print ");

  SetConsoleTextAttribute(hConsole, 6);
   printf("\n\n ______________________________\n|                              |\n|  ");
   SetConsoleTextAttribute(hConsole, 7);
   printf("EXPORTING IN FILE ");
    SetConsoleTextAttribute(hConsole, 10);
   printf("SUCCEDED");
   SetConsoleTextAttribute(hConsole, 6);
   printf("  |\n|______________________________|\n");




}

void info_sec(client_data *p){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 6);
printf("\n\n>-----------------------------------<\n\n");
   SetConsoleTextAttribute(hConsole, 10);
    printf("%-20s: ", "ID");
    SetConsoleTextAttribute(hConsole, 7);
    printf("%d\n",p->id);

  SetConsoleTextAttribute(hConsole, 10);
    printf("%-20s: ", "NAME");
   SetConsoleTextAttribute(hConsole, 7);
    printf("%s\n", p->name);

    SetConsoleTextAttribute(hConsole, 10);
    printf("%-20s: ", "NATIONAL CARD CODE");
    SetConsoleTextAttribute(hConsole, 7);
    printf("%s\n",p->card_code_n);

   SetConsoleTextAttribute(hConsole, 10);
    printf("%-20s: ", "AGE");
  SetConsoleTextAttribute(hConsole, 7);
    printf("%d\n", p->age);

    SetConsoleTextAttribute(hConsole, 10);
    printf("%-20s: ", "BIRTHDAY");
    SetConsoleTextAttribute(hConsole, 7);
    printf("%s\n",p->birth);

    SetConsoleTextAttribute(hConsole, 10);
    printf("%-20s: ", "ADDRESS");
    SetConsoleTextAttribute(hConsole, 7);
    printf("%s\n",p->adress);

   SetConsoleTextAttribute(hConsole, 10);
    printf("%-20s: ", "REGISTER DAY");
    SetConsoleTextAttribute(hConsole, 7);
    printf("%s\n", p->register_date);

  SetConsoleTextAttribute(hConsole, 10);
    printf("%-20s: ", "LAST ENTRANCE");
    SetConsoleTextAttribute(hConsole, 7);
    printf("%s\n", p->last_entrence);

    SetConsoleTextAttribute(hConsole, 10);
    printf("%-20s: ", "PHONE");
   SetConsoleTextAttribute(hConsole, 7);
    printf("%s\n", p->phone);

   SetConsoleTextAttribute(hConsole, 10);
    printf("%-20s: ", "STATUS");
       SetConsoleTextAttribute(hConsole, 7);
    if(p->active==0) printf("%s\n","inactive");
    else printf("%s","active");

    SetConsoleTextAttribute(hConsole, 6); // reset
printf("\n\n>-----------------------------------<\n\n");


}

comment *encrypt_comment(comment *c){
 int key=0xAA;
 encrypt(c->com,c->id,strlen(c->com),key);
 return c;
}
comment *decrypt_comment(comment *c){
 int key=0xAA;
 decrypt(c->com,c->id,strlen(c->com),key);
 return c;
}

void transaction(client_data *p){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
header();
printf("\n-------------------| INFO SECTION / transaction info  ");
SetConsoleTextAttribute(hConsole, 6);
printf("\n\n   >-------------------------------------------------------<\n");
printf("  /                                                         \\\n");
printf(" |\\                                                         /|\n");
    SetConsoleTextAttribute(hConsole, 7);
int read_bool=read_comments(p->id,"C:\\Users\\user\\Desktop\\Professionnel\\comments.bin.txt",1); // function that read the comments of type 1 (trans );
SetConsoleTextAttribute(hConsole, 6);
printf(" |/                                                         \\|\n");
printf("  \\                                                         /\n");
printf("   >-------------------------------------------------------<\n\n");
    if(read_bool==1){
         int choose;
     int k=1;
     do{
            if(k==0){
                header();
                printf("\n-------------------| INFO SECTION / transaction info  ");
            }
        print_file_choose();
        scanf("%d",&choose);
        k=0;
     }while(choose!=0 && choose!=1);
     if(choose==1)print_file_trans(p,1);
    }
SetConsoleTextAttribute(hConsole, 7);
getchar();
click();
}

void print_file_trans(client_data *p,int type_){
    int choose;
     char filepath[260];
do{
    header();
printf("\n-------------------| INFO SECTION / transaction info / print ");
print_file_box();
scanf("%d",&choose);
}while(choose!=1 && choose!=0);
if(choose==0)print_in_file(p,"C:\\Users\\user\\Desktop\\Professionnel\\comments.bin.txt","C:\\Users\\user\\Desktop\\output\\result.txt",1);
else {
    header();
    printf("\n-------------------| INFO SECTION / transaction info / print ");
    path_box();
      if (scanf(" %[^\n]s",filepath)!=1) {
        perror("Error reading input");
        return ;
    }
     print_in_file(p,"C:\\Users\\user\\Desktop\\Professionnel\\comments.bin.txt",filepath,1);
}


}

void path_box(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 6);
 printf("\n\n _________________________________________________________________________");
    printf("\n|                                                                         |");
    printf("\n| ");
     SetConsoleTextAttribute(hConsole, 7);
    printf("ENTER THE ");
    SetConsoleTextAttribute(hConsole, 10);
    printf("PATH");
    SetConsoleTextAttribute(hConsole, 7);
    printf(" OF THE EXPORT FILE ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|");
    SetConsoleTextAttribute(hConsole, 7);
    printf(" BE SURE TO WRITE");
    SetConsoleTextAttribute(hConsole, 4);
    printf("\\\\");
    printf(" INSTEAD OF ");
    SetConsoleTextAttribute(hConsole, 4);
    printf(" \\");
    SetConsoleTextAttribute(hConsole, 6);
    printf(" |");
    printf("\n|_________________________________________________________________________|");
    printf("\n\n||");
    SetConsoleTextAttribute(hConsole, 7);
}
void print_in_file(client_data *p,const char *filename_comments,const char *filename_print,int type_){

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    FILE *fr=fopen(filename_comments,"rb");

     if (!fr) {
        perror("Error opening file");
        return ;
    }
    FILE *fw=fopen(filename_print,"w");
    if (!fw) {
        perror("Error opening file");
        return ;
    }

    fprintf(fw,
"+==========================================================+\n"
"|           H T   B A N K   T R A N S A C T I O N S        |\n"
"+==========================================================+\n"
"| File Type  : TEXT (.txt)                                 |\n"
"| Export Date: %s                    |\n"
"| ID         : %-44d|\n"
"| NAME       : %-44s|\n"
"| Generated  : HT Bank Management System v1.0              |\n"
"+----------------------------------------------------------+\n"
"|  This document contains a record of all transactions.    |\n"
"|  All amounts are in USD ($) unless otherwise stated.     |\n"
"|  Please store this file securely.                        |\n"
"+----------------------------------------------------------+\n"
"| TYPE                | AMOUNT | DATE / TIME               |\n"
"+---------------------+--------+---------------------------+\n",
p->last_entrence,p->id,p->name);
    comment *c=(comment*)malloc(sizeof(comment));
    while(fread(c,sizeof(comment),1,fr)==1){
        if(c->id==p->id){
            if(c->type==type_){
             decrypt_comment(c);
             fprintf(fw,"|%s|\n",c->com);


            }

        }
    }
    free(c);
    fprintf(fw,"+---------------------+--------+---------------------------+\n");
    fclose(fr);
    fclose(fw);
   wait();
   header();
   printf("\n-------------------| INFO SECTION / transaction info / print ");

  SetConsoleTextAttribute(hConsole, 6);
   printf("\n\n ______________________________\n|                              |\n|  ");
   SetConsoleTextAttribute(hConsole, 7);
   printf("EXPORTING IN FILE ");
    SetConsoleTextAttribute(hConsole, 10);
   printf("SUCCEDED");
   SetConsoleTextAttribute(hConsole, 6);
   printf("  |\n|______________________________|\n");
}
void print_file_box(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 6); // Yellow/Gold border
printf("\n\n  _________________________________");
printf("\n |                                 |");
printf("\n |");
SetConsoleTextAttribute(hConsole, 10); // Green title
printf("       \xB2 FILE LOCATION \xB2         ");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |_________________________________|");
printf("\n |                                 |");

printf("\n |  1 ");
SetConsoleTextAttribute(hConsole, 7); // White text
printf("-> Enter path manually       ");
SetConsoleTextAttribute(hConsole, 6);
printf("|");

printf("\n |  0 ");
SetConsoleTextAttribute(hConsole, 7);
printf("-> Use output folder         ");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |_________________________________|\n\n");
printf("||");
SetConsoleTextAttribute(hConsole, 7);
 // Reset colo}
}
void print_file_choose(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 6); // Yellow/Gold border
 printf("\n\n ___________________________________");
printf("\n |                                 |");
printf("\n |");
SetConsoleTextAttribute(hConsole, 10); // Green title
printf("      \xB2 CHOOSE YOUR ACTION \xB2     ");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |_________________________________|");
printf("\n |                                 |");

printf("\n |  1 ");
SetConsoleTextAttribute(hConsole, 7); // White text
printf("-> Print it                  ");
SetConsoleTextAttribute(hConsole, 6);
printf("|");

printf("\n |  0 ");
SetConsoleTextAttribute(hConsole, 7);
printf("-> Return to info section    ");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |_________________________________|\n\n");

printf("||");
SetConsoleTextAttribute(hConsole, 7); // Reset to normal


}
void write_comments(comment *p1,const char *filename_comments){

     FILE *fp = fopen(filename_comments, "rb");
    if (!fp) {
    // File doesn't exist yet
    FILE *fw = fopen(filename_comments, "wb");
    if (!fw) {
               perror("Opening File failed !");
               return;
     }
     comment *p1_encrypted=encrypt_comment(p1);
     fwrite(p1_encrypted, sizeof(comment), 1, fw);
    fclose(fw);
    return;
}
    FILE *fw = fopen("records_tmp.bin", "wb");
    if (!fw) {
        perror("Error opening file");
        fclose(fp);
        return ;
    }
    comment r;
   int inserted=0;
   comment *p1_encrypted=encrypt_comment(p1);

        while (fread(&r, sizeof(comment), 1, fp) == 1) {
    if (!inserted && r.id >= p1_encrypted->id) {
        fwrite(p1_encrypted, sizeof(comment), 1, fw);
        inserted = 1;
    }
    fwrite(&r, sizeof(comment), 1, fw);
}
if (!inserted) {
    fwrite(p1_encrypted, sizeof(comment), 1, fw);
}
      // p1= decrypt_comment(p1_encrypted);
       fclose(fp);
       fclose(fw);
    remove(filename_comments);
    rename("records_tmp.bin",filename_comments);
    //free(p1_encrypted);
}
int read_comments(int id_,const char *filename_comments,int type_){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    FILE *fr=fopen(filename_comments,"rb");
     if (!fr) {
        perror("Error opening file");
        return 0;
    }

    int k=0;
    comment *c=(comment*)malloc(sizeof(comment));
    while(fread(c,sizeof(comment),1,fr)==1){
        if(c->id==id_){
            if(c->type==type_){
               if(type_==1){
                     SetConsoleTextAttribute(hConsole, 6);
                printf(" | ");
                SetConsoleTextAttribute(hConsole, 7);
                c=decrypt_comment(c);
                printf("%s", c->com);
                SetConsoleTextAttribute(hConsole, 6);
                printf("|\n");
                SetConsoleTextAttribute(hConsole, 7);
                k=1;
               }
               else{
                // Type 0 : for reports
                if(k==0)report_head();
                k+=1;
                decrypt_comment(c);
                print_type_0(c,k);
               }
            }
        }
    }
    if(k==0 && type_==0){

        zero_report_box();
        fclose(fr);
        free(c);
        return 0;

       // printf(" | There is no data stored for client id_%d |\n");
    }
    else if(k==0 && type_==1){
   zero_trans_box();
   fclose(fr);
    free(c);
   return 0;
    }

    fclose(fr);
    free(c);
    return 1;
}

void zero_trans_box(){
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(hConsole, 6);
    printf(" | |");
    SetConsoleTextAttribute(hConsole, 10);
    printf("-->          ");
    SetConsoleTextAttribute(hConsole, 4);
    printf("Zero    ");
    SetConsoleTextAttribute(hConsole, 7);
    printf("Transaction    Stored          ");
    SetConsoleTextAttribute(hConsole, 10);
    printf("<--");
    SetConsoleTextAttribute(hConsole, 6);
    printf("| |\n");
    }
void zero_report_box(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 6);
printf("\n\n  ___________________________________\n |");
SetConsoleTextAttribute(hConsole, 10);
printf("___                            ____");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |   ");
SetConsoleTextAttribute(hConsole, 10);
printf("\\");
SetConsoleTextAttribute(hConsole, 6);
printf("-<");
SetConsoleTextAttribute(hConsole, 7);
printf("  Zero ");
SetConsoleTextAttribute(hConsole, 4);
printf("Report");
SetConsoleTextAttribute(hConsole, 7);
printf(" Writed  ");
SetConsoleTextAttribute(hConsole, 6);
printf(">-");
SetConsoleTextAttribute(hConsole, 10);
printf("/");
SetConsoleTextAttribute(hConsole, 6);
printf("    |\n |\\   ");
SetConsoleTextAttribute(hConsole, 10);
printf("\\------------------------/    ");
SetConsoleTextAttribute(hConsole, 6);
printf("/|\n ");
SetConsoleTextAttribute(hConsole, 14);
printf("|_");
SetConsoleTextAttribute(hConsole, 6);
printf("\\_______________________________/");
SetConsoleTextAttribute(hConsole, 14);
printf("_|");
SetConsoleTextAttribute(hConsole, 14);

}

void report_head(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(hConsole, 6);
    printf("\n\n _____________________________________________________________________________________\n|                          |                                                          |\n|         ");
    SetConsoleTextAttribute(hConsole, 14);
    printf("RANKING");
    SetConsoleTextAttribute(hConsole, 6);
    printf("          |                        ");
    SetConsoleTextAttribute(hConsole, 14);
    printf("REPORT");
    SetConsoleTextAttribute(hConsole, 6);
    printf("                            |\n|__________________________|__________________________________________________________|\n");
    SetConsoleTextAttribute(hConsole, 7);
}
void print_type_0(comment *c, int rank) {
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int length = strlen(c->com);

    SetConsoleTextAttribute(hConsole, 6);
    printf("|");
    SetConsoleTextAttribute(hConsole, 10);
    printf(" %-*d ", RANK_WIDTH - 2, rank);
    SetConsoleTextAttribute(hConsole, 6);
    printf("| ");

    for (int i = 0; i < length; i++) {
        SetConsoleTextAttribute(hConsole, 7);
        putchar(c->com[i]);

        // wrap line after COMMENT_WIDTH characters
        if ((i + 1) % COMMENT_WIDTH == 0 && i != length - 1) {



            if(isalpha(c->com[i]) && isalpha(c->com[i+1])){
                SetConsoleTextAttribute(hConsole, 14);
                printf("-");
                SetConsoleTextAttribute(hConsole, 6);
                 printf("|\n| %-*s | ", RANK_WIDTH - 2, "");
            }
            else{
               SetConsoleTextAttribute(hConsole, 6);
                 printf(" |\n| %-*s | ", RANK_WIDTH - 2, "");
            }






        }
    }

    // padding for last line
    int remaining = COMMENT_WIDTH - (length % COMMENT_WIDTH);
    if (remaining != COMMENT_WIDTH) {
        for (int i = 0; i < remaining; i++) putchar(' ');
        //printf(" ");
    }
    SetConsoleTextAttribute(hConsole, 6);
    printf(" |\n");

    // bottom border of row
    printf("|%.*s|%.*s|\n",
           RANK_WIDTH, "__________________________",
           COMMENT_WIDTH + 4, "__________________________________________________________");
}


void edit_pass(client_data *p){
   char tmp[25],confirm_tmp[25];
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   int choose;
   do{
       header();
printf("\n-------------------| INFO SECTION / Edit password  ");
old_pass_box();
    scanf(" %[^\n]s",tmp);
    if(strcmp(p->password,tmp)!=0){
        printf(" \n-->YOU ENTRED THE WRONG PASSWORD<--");
        choose=try_again();
        if(choose==0){
                               SetConsoleTextAttribute(hConsole,10);
                                printf("\n\n---- DEPOSIT OPERATION CANCELED ----");
                                SetConsoleTextAttribute(hConsole,7);
                                getchar();
                                 click();
                                wait();
                                return ;
        }
    }
   }while(strcmp(p->password,tmp)!=0);
    printf(" \n-->YOU ENTRED THE RIGHT PASSWORD<--");
    getchar();
    click();
    int verif=1;
    do{
         header();
    printf("\n-------------------| INFO SECTION / Edit password  ");
    new_pass_box();
    scanf(" %[^\n]s",tmp);
    if(strlen(tmp)<8){
            printf("\n\n--> 8 Characters Minimum <--");
            verif=0;
            getchar();
            click();
            continue;
    }
    if(strcmp(tmp,p->password)==0){
          printf("\n\n--> Same password <--");
           verif=0;
            getchar();
            click();
            continue;
    }
    confirm_box();
    scanf(" %[^\n]s",confirm_tmp);
    if(strcmp(tmp,confirm_tmp)!=0){
           printf("\n\n--> Wrong Confirmation <--");
            choose=try_again();
        if(choose==0){
                               SetConsoleTextAttribute(hConsole,10);
                                printf("\n\n---- DEPOSIT OPERATION CANCELED ----");
                                SetConsoleTextAttribute(hConsole,7);
                                getchar();
                                 click();
                                wait();
                                return ;
        }
        verif=0;
        continue;
                     }
    }while(verif==0);
    printf("\n\n--> Rignt Confirmation <--");
    getchar();
    click();
    header();
    printf("\n-------------------| INFO SECTION / Edit password  ");
   choose=confirm();
    if(choose==0){
                                    SetConsoleTextAttribute(hConsole,10);
                                printf("\n\n---- EDIT PASSWORD OPERATION CANCELED ----");
                                SetConsoleTextAttribute(hConsole,7);
                                click();
                                wait();
                               return ;
                              }
    wait();
    header();
    printf("\n-------------------| INFO SECTION / Edit password  ");
    strcpy(p->password,tmp);
    write_edit(p,filename);
    pass_edit_succ();
    //getchar();
    click();
SetConsoleTextAttribute(hConsole, 7);
}
void old_pass_box(){
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 6);
printf("\n\n   >---------------------------------<");
printf("\n  /                                   \\");
SetConsoleTextAttribute(hConsole, 10);
printf("\n|\\                                    /|");

printf("\n| |->  ");
SetConsoleTextAttribute(hConsole, 7);
printf("ENTER THE ");
SetConsoleTextAttribute(hConsole, 4);
printf("CURRENT");
SetConsoleTextAttribute(hConsole, 7);
printf(" PASSWORD");
SetConsoleTextAttribute(hConsole, 10);
printf("  <-| |");
printf("\n|/                                    \\|");
SetConsoleTextAttribute(hConsole, 6);
printf("\n  \\                                   /");
printf("\n   >---------------------------------<");
printf("\n\n||");
SetConsoleTextAttribute(hConsole, 7);

}
void new_pass_box(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 6);
 printf("\n\n   >-------------------------<");
printf("\n  /                           \\");
SetConsoleTextAttribute(hConsole, 10);
printf("\n|\\                            /|");
printf("\n| |->  ");
SetConsoleTextAttribute(hConsole, 7);
printf("ENTER ");
SetConsoleTextAttribute(hConsole, 10);
printf("NEW");
SetConsoleTextAttribute(hConsole, 7);
printf(" PASSWORD");
SetConsoleTextAttribute(hConsole, 10);
printf("  <-| |");
printf("\n|/                            \\|");
SetConsoleTextAttribute(hConsole, 6);
printf("\n  \\                           /");
printf("\n   >-------------------------<");
printf("\n\n||");
SetConsoleTextAttribute(hConsole, 7);
}

void confirm_box(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    header();
    printf("\n-------------------| INFO SECTION / Edit password  ");
SetConsoleTextAttribute(hConsole, 6);
printf("\n\n   >-----------------------<");
printf("\n  /                         \\");
SetConsoleTextAttribute(hConsole, 10);
printf("\n|\\                          /|");
printf("\n| |->  ");
SetConsoleTextAttribute(hConsole, 7);
printf("CONFIRM ");
SetConsoleTextAttribute(hConsole, 10);
printf("PASSWORD");
SetConsoleTextAttribute(hConsole, 10);
printf("  <-| |");
printf("\n|/                          \\|");
SetConsoleTextAttribute(hConsole, 6);
printf("\n  \\                         /");
printf("\n   >-----------------------<");
printf("\n\n||");
SetConsoleTextAttribute(hConsole, 7);
}
void pass_edit_succ(){
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 6);
  printf("\n\n   >--------------------------------<");
printf("\n  /                                  \\");
SetConsoleTextAttribute(hConsole, 10);

printf("\n|\\                                   /|");

printf("\n| |->  ");
SetConsoleTextAttribute(hConsole, 7);
printf("PASSWORD EDITED ");
SetConsoleTextAttribute(hConsole, 10);
printf("SUCCEFULY");
printf("  <-| |");
printf("\n|/                                   \\|");
SetConsoleTextAttribute(hConsole, 6);
printf("\n  \\                                  /");
printf("\n   >--------------------------------<");
}

long long generateRandom14Digit() {
    // srand(time(NULL));
    long long num = 0;
    for (int i = 0; i < 14; i++) {
        int digit;
        if (i == 0) digit = 1 + rand() % 9;  // first digit can’t be 0
        else digit = rand() % 10;
        num = num * 10 + digit;
    }
    return num;
}
void code_box(long long number){
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(hConsole,14);
    printf("      ______________      \n");
     SetConsoleTextAttribute(hConsole,6);
printf(" ____");
SetConsoleTextAttribute(hConsole,14);
printf("/");
  SetConsoleTextAttribute(hConsole,6);
printf("______________");
SetConsoleTextAttribute(hConsole,14);
printf("\\");
  SetConsoleTextAttribute(hConsole,6);
printf("_____\n|");
    SetConsoleTextAttribute(hConsole,14);
    printf("/                       \\");
     SetConsoleTextAttribute(hConsole,6);
    printf("|\n|  ");
     SetConsoleTextAttribute(hConsole,10);
    printf("CODE :");
     SetConsoleTextAttribute(hConsole,7);
    printf(" %lld  ",number);
    SetConsoleTextAttribute(hConsole,6);
    printf("|\n|_________________________|\n");
    SetConsoleTextAttribute(hConsole,14);
    printf("    \\________________/   ");
    SetConsoleTextAttribute(hConsole,7);
}

void transfer_(client_data *p){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int choose;
  do{
   do{
         header();
         printf("\n-------------------| ACCOUNT SECTION / transfer  ");
         transfer_options();
         scanf("%d",&choose);
    }while(choose!=1 && choose!=2 && choose!=3);
    switch(choose){
case 1:send_(p);
break;

case 2: ticket_print(p,"C:\\Users\\user\\Desktop\\output\\result3.txt");
    break;

    }

  }while(choose!=3);


}
void transfer_options(){
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                                                       SetConsoleTextAttribute(hConsole, 6);
                                                   printf("\n  _________________________________");
printf("\n |                                 |");
printf("\n |");
SetConsoleTextAttribute(hConsole, 10);
printf("      \xB2 TRANSFER OPTIONS \xB2       "); // title changed here
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |_________________________________|");
printf("\n |                                 |");
printf("\n |  1 ");
SetConsoleTextAttribute(hConsole, 7);
printf("-> Sending                   ");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |  2 ");
SetConsoleTextAttribute(hConsole, 7);
printf("-> Receiving                 ");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |  3 ");
SetConsoleTextAttribute(hConsole, 7);
printf("-> Return to Account Section ");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |_________________________________|\n\n");
printf("|| ");
SetConsoleTextAttribute(hConsole, 7);}

void send_(client_data *p){
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   int id,id_last = last_id("C:\\Users\\user\\Desktop\\Professionnel\\clients_data_encrypted_bin.bin.txt");
   int k;
   do{

header();
printf("\n-------------------| ACCOUNT SECTION / transfer  ");
proverb();
id_receiver_box();
scanf("%d",&id);
if(id==0){
     printf("\n\n --< Transfer Operation Canceled >--");
        getchar();
        click();
        return;
}

else {
    if(id>id_last){

    header();
     printf("\n\n________________________________\n") ;
   printf(" Client Not Found ");
    k=try_again();
    if(k==0){
        printf("\n\n --< Transfer Operation Canceled >--");
        getchar();
        click();
         wait();
        return;
    }
    else continue;
}
else if(id==p->id){
     header();
     printf("\n\n________________________________\n") ;
   printf(" Invalid Input , %d it s your ID  ",p->id);
    k=try_again();
    if(k==0){
        printf("\n\n --< Transfer Operation Canceled >--");
        getchar();
        click();
         wait();
        return;
    }
     else continue;
}
else if(id<0)
{   printf("\n\n________________________________\n") ;
      printf("\n\n You have to type an  positive integer ");
    header();
    k=try_again();
    if(k==0){
        printf("\n\n --< Transfer Operation Canceled >--");
        getchar();
        click();
         wait();
        return;
    }
     else continue;
}
}
   }while(id<0 || id>id_last || id==p->id);
int amount;
   do{
        header();
   printf("\n-------------------| ACCOUNT SECTION / transfer  ");
    amount_transfer_box();
    scanf("%d",&amount);
    if(amount<=0){            // Cd
         header();
     printf("\n\n________________________________\n") ;
   printf(" Invalid Input (Positive None Nul) ");
    k=try_again();
    if(k==0){
        printf("\n\n --< Transfer Operation Canceled >--");
        getchar();
        click();
        wait();
        return;
    }
    }
    else if(amount>p->current_money){              // Cd
           header();
     printf("\n\n________________________________\n") ;
   printf(" You Can't Transfer More than %d $ ",p->current_money);
    k=try_again();
    if(k==0){
        printf("\n\n --< Transfer Operation Canceled >--");
        getchar();
        click();
         wait();
        return;
    }
    }
   }while(amount<=0 || amount>p->current_money);
   client_data *rec=extract_client_data("C:\\Users\\user\\Desktop\\Professionnel\\clients_data_encrypted_bin.bin.txt",id);
if(rec==NULL){
    printf("CLIENT NOT FOUND! ");
    free(rec);
}
   int choose;
   do{
    header();
    printf("\n-------------------| ACCOUNT SECTION / transfer \n ");
    confirmation_box(amount,rec->name);
    scanf("%d",&choose);
   }while(choose!=1 && choose!=0);
   if(choose==0){
     printf("\n\n --< Transfer Operation Canceled >--");
        getchar();
        click();
         wait();
        return;

   }

   do{
    header();
    printf("\n-------------------| ACCOUNT SECTION / transfer ");
    transfer_type_menu();
    scanf("%d",&choose);

   }while(choose!=1&& choose!=0 && choose!=2);
   if(choose==0){
    wait();
    return;

   }

   transfer *t=(transfer*)malloc(sizeof(transfer));
     t->amount=amount;
     t->code=0;
     t->id_receiver=rec->id;
     t->id_sender=p->id;
     t->code_=false;   // tmp


    switch(choose){

case 1: send_0(p,rec,t);
    break;
    // WITHOUT CODE


case 2:  send_1(p,rec,t);// WITH CODE
  break;

    }
getchar();
click();


}
void send_0(client_data *p,client_data *rec,transfer *t){
     char *filename_recepetion="C:\\Users\\user\\Desktop\\output\\result2.txt"; // TO GET RECEIPT
     char *filename_t_stoage="C:\\Users\\user\\Desktop\\output\\result3.txt";
     t->code_=false;
     t->statue=false; // SEND DIRECTLY
     write_transfer(t,filename_t_stoage);
     p->current_money-=t->amount;
     rec->current_money+=t->amount;
     write_edit(p,filename);
     write_edit(rec,filename);
    int choose;
    do{
     header();
     printf("\n-------------------| ACCOUNT SECTION / transfer / receipt ");
     receipt_menu();
     scanf("%d",&choose);
    }while(choose!=1 && choose!=2);
if(choose==2){
    printf("\n\n --< Transfer Operation Canceled >--");
        getchar();
        click();
         wait();
        return;
}
do {
    header();
     printf("\n-------------------| ACCOUNT SECTION / transfer / receipt ");
     print_file_box();
     scanf("%d",&choose);
}while(choose!=1 && choose!=0);
if(choose==0)print_transfer(p,rec,t,filename_recepetion);
else {
        char filepath[260];
    header();
     printf("\n-------------------| ACCOUNT SECTION / transfer / receipt ");
    path_box();
      if (scanf(" %[^\n]s",filepath)!=1) {
        perror("Error reading input");
        return ;
    }
     print_transfer(p,rec,t,filepath);
}

char senb[20];
 comment *tmpo=(comment*)malloc(sizeof(comment));
                             tmpo->id=p->id;
                               tmpo->type=1;  // WRITE FOR TRANSACTION   FOR THE SENDER

                               snprintf(senb,sizeof(senb),"SEND ID_%d",t->id_receiver);
                              snprintf(tmpo->com, sizeof(tmpo->com), "%-20s | %6d |  %s ",senb,t->amount,p->last_entrence);
                           write_comments(tmpo,"C:\\Users\\user\\Desktop\\Professionnel\\comments.bin.txt");
                              // WRITE FOR TRANSACTION   FOR THE RECEIVER
                              tmpo->id=rec->id;
                              tmpo->type=1;
                              snprintf(senb,sizeof(senb),"RECEIVE ID_%d",t->id_sender);
                                snprintf(tmpo->com, sizeof(tmpo->com), "%-20s | %6d |  %s ",senb,t->amount,p->last_entrence);
                                 write_comments(tmpo,"C:\\Users\\user\\Desktop\\Professionnel\\comments.bin.txt");
                            free(tmpo);

}
void send_1(client_data *p,client_data *rec,transfer *t){
 char *filename_recepetion="C:\\Users\\user\\Desktop\\output\\result2.txt";
 char *filename_t_stoage="C:\\Users\\user\\Desktop\\output\\result3.txt";
     t->code_=true;
     t->statue=true; // SEND DIRECTLY
     srand(time(NULL));
     t->code=generateRandom14Digit();
     write_transfer(t,filename_t_stoage);
     p->current_money-=t->amount;
     //rec->current_money+=t->amount;
     write_edit(p,filename);
     //write_edit(rec,filename);
    int choose;
    do{
     header();
     printf("\n-------------------| ACCOUNT SECTION / transfer / receipt ");
     receipt_menu();
     scanf("%d",&choose);
    }while(choose!=1 && choose!=2);
    //char filepath[260];
if(choose==2){
    printf("\n\n --< Transfer Succeded >--");
        getchar();
        click();
         wait();
        return;
}
do {
    header();
     printf("\n-------------------| ACCOUNT SECTION / transfer / receipt ");
     print_file_box();
     scanf("%d",&choose);
}while(choose!=1 && choose!=0);
if(choose==0){
    print_transfer(p,rec,t,filename_recepetion); // DO t->code
}
else {
        char filepath[260];
    header();
     printf("\n-------------------| ACCOUNT SECTION / transfer / receipt ");
    path_box();
      if (scanf(" %[^\n]s",filepath)!=1) {
        perror("Error reading input");
        return ;
    }
     print_transfer(p,rec,t,filepath);
}
 comment *tmpo=(comment*)malloc(sizeof(comment));
                             tmpo->id=p->id;
                               tmpo->type=1;
                               char senb[20];
                               snprintf(senb,sizeof(senb),"SEND ID_%d",t->id_receiver);
                              snprintf(tmpo->com, sizeof(tmpo->com), "%-20s | %6d |  %s ",senb,t->amount,p->last_entrence);
                           write_comments(tmpo,"C:\\Users\\user\\Desktop\\Professionnel\\comments.bin.txt");
                               free(tmpo);
}

void print_transfer(client_data *p,client_data *rec,transfer *t,char filepath[]){
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   FILE *fw=fopen(filepath,"w");
    if (!fw) {
        perror("Error opening file");
        return ;
    }
    char amount_str[50];
snprintf(amount_str, sizeof(amount_str), "%d $", t->amount);
  fprintf(fw,
"+==========================================================+\n"
"|                H T   B A N K   RECEIPT                   |\n"
"+==========================================================+\n"
"| File Type  : TEXT (.txt)                                 |\n"
"| Export Date: %-44.44s|\n"
"| Generated  : HT Bank Management System v1.0              |\n"
"+----------------------------------------------------------+\n"
"|  This document contains a record of all transactions.    |\n"
"|  All amounts are in USD ($) unless otherwise stated.     |\n"
"|  Please store this file securely.                        |\n"
"+----------------------------------------------------------+\n"
"| SENDER :                                                 |\n"
"| NAME    : %-46s |\n"
"| ID      : %-46d |\n"
"| ADDRESS : %-46s |\n"
"+----------------------------------------------------------+\n"
"| RECEIVER :                                               |\n"
"| NAME    : %-46s |\n"
"| ID      : %-46d |\n"
"| ADDRESS : %-46s |\n"
"+----------------------------------------------------------+\n"
"| TRANSFER DETAILS :                                       |\n"
"| AMOUNT  : %-46s |\n",
p->last_entrence, p->name, p->id, p->adress,
rec->name, rec->id, rec->adress, amount_str);
if (t->code_ == true) {
    fprintf(fw,"| CODE    : %-46lld |\n", t->code);
}

fprintf(fw,
"+==========================================================+\n"
"|                © 2025 HT BANK. All Rights Reserved.      |\n"
"+----------------------------------------------------------+\n"
"| This receipt is a confidential document issued by HT Bank|\n"
"| for the exclusive use of the account holder. By using    |\n"
"| our services, you agree to comply with HT Bank’s terms   |\n"
"| and policies. Unauthorized reproduction, distribution,   |\n"
"| or disclosure of this document, in whole or in part, is  |\n"
"| strictly prohibited.                                     |\n"
"|                                                          |\n"
"| For full details on our policies and customer rights,    |\n"
"| please visit your nearest HT Bank branch or refer to our |\n"
"| official website.                                        |\n"
"+==========================================================+\n");
fclose(fw);
wait();
header();
printf("\n-------------------| ACCOUNT SECTION / transfer ");
      SetConsoleTextAttribute(hConsole, 6);
   printf("\n\n ______________________________\n|                              |\n|  ");
   SetConsoleTextAttribute(hConsole, 7);
   printf("EXPORTING IN FILE ");
    SetConsoleTextAttribute(hConsole, 10);
   printf("SUCCEDED");
   SetConsoleTextAttribute(hConsole, 6);
   printf("  |\n|______________________________|\n");
   if(t->code_==true)code_box(t->code);
}
void receipt_menu() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);
    printf("\n\n  _________________________________");
    printf("\n |                                 |");
    printf("\n |       ");
    SetConsoleTextAttribute(hConsole, 10);
    printf(" \xB2 RECEIPT OPTIONS \xB2      ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n |_________________________________|");
    printf("\n |                                 |");
    printf("\n |  1 ");
    SetConsoleTextAttribute(hConsole, 7);
    printf("-> Print Receipt             ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n |  2 ");
    SetConsoleTextAttribute(hConsole, 7);
    printf("-> Return                    ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n |_________________________________|\n\n");
    printf("|| ");
    SetConsoleTextAttribute(hConsole, 7);
}

void confirmation_box(int amount, char name[]) {
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char buffer[256];
    snprintf(buffer, sizeof(buffer),
             "Are you sure that you want to send %d to Mr/Miss %s",
             amount, name);
    int len = strlen(buffer);
    char options[] = "Type 1 to Confirm | Type 0 to Deny";
    int opt_len = strlen(options);
    int box_width = (len > opt_len ? len : opt_len) + 4; // ensure both fit
    // Top border
    printf("\n  ");
     SetConsoleTextAttribute(hConsole, 6);
    for (int i = 0; i < box_width-2; i++) printf("_");
    // Empty padding line
    printf("\n |");
    for (int i = 0; i < box_width - 2; i++) printf(" ");
    printf("|");
    // Message line (centered)
    int left_padding = (box_width - 2 - len) / 2;
    int right_padding = box_width - 2 - len - left_padding;
    printf("\n |");
    for (int i = 0; i < left_padding; i++) printf(" ");
     SetConsoleTextAttribute(hConsole, 7);
    printf("%s", buffer);
     SetConsoleTextAttribute(hConsole, 6);
    for (int i = 0; i < right_padding; i++) printf(" ");
    printf("|");
     printf("\n |");
    for (int i = 0; i < box_width-2; i++) printf("_");
    printf("|");
    // Empty padding line
  //  printf("\n |");
     printf("\n |");
    for (int i = 0; i < box_width - 2; i++) printf(" ");
    printf("|");
    // Options line (centered)
    left_padding = (box_width - 2 - opt_len) / 2;
    right_padding = box_width - 2 - opt_len - left_padding;
    printf("\n |");
    for (int i = 0; i < left_padding; i++) printf(" ");
     SetConsoleTextAttribute(hConsole, 7);
    printf("%s", options);
     SetConsoleTextAttribute(hConsole, 6);
    for (int i = 0; i < right_padding; i++) printf(" ");
    printf("|");
    printf("\n |");
    for (int i = 0; i < box_width-2; i++) printf("_");
    printf("|");
    printf("\n\n||");
     SetConsoleTextAttribute(hConsole, 7);
}
void transfer_type_menu() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 6);
    printf("\n\n  _________________________________");
    printf("\n |                                 |");
    printf("\n |      ");
    SetConsoleTextAttribute(hConsole, 10);
    printf(" \xB2 TRANSFER OPTIONS \xB2      ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n |_________________________________|");

    printf("\n |                                 |");
    printf("\n |  1 ");
    SetConsoleTextAttribute(hConsole, 7);
    printf("-> Direct Transfer           ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n |  2 ");
    SetConsoleTextAttribute(hConsole, 7);
    printf("-> Transfer with Code        ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n |  0 ");
    SetConsoleTextAttribute(hConsole, 7);
    printf("-> Return                    ");
    SetConsoleTextAttribute(hConsole, 6);
    printf("|\n |_________________________________|");

    printf("\n\n|| ");
    SetConsoleTextAttribute(hConsole, 7);
}

void amount_transfer_box(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 6);
printf("\n\n  ________________________________________");
printf("\n |___                                 ____|");
printf("\n |   \\");
SetConsoleTextAttribute(hConsole, 14);
printf("-<");
SetConsoleTextAttribute(hConsole, 7);
printf(" Enter The ");
SetConsoleTextAttribute(hConsole, 10);
printf("Transfer");
SetConsoleTextAttribute(hConsole, 7);
printf(" Amount");
SetConsoleTextAttribute(hConsole, 14);
printf(" >-");
SetConsoleTextAttribute(hConsole, 6);
printf("/    |");
SetConsoleTextAttribute(hConsole, 14);
printf("\n |");
SetConsoleTextAttribute(hConsole, 6);
printf("\\   \\-----------------------------/    /");
SetConsoleTextAttribute(hConsole, 14);
printf("|");
printf("\n |_");
SetConsoleTextAttribute(hConsole, 6);
printf("\\____________________________________/");
SetConsoleTextAttribute(hConsole, 14);
printf("_|");
SetConsoleTextAttribute(hConsole, 6);
printf("\n\n||");
SetConsoleTextAttribute(hConsole, 7);
}

void proverb(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 6);
printf("\n\n________________________________________");
printf("\n                                        |");
printf("\n    ");
SetConsoleTextAttribute(hConsole, 4);
printf("\"");
SetConsoleTextAttribute(hConsole, 10);
printf("Fast ");
SetConsoleTextAttribute(hConsole, 7);
printf("as thought");
SetConsoleTextAttribute(hConsole, 4);
printf(", ");
SetConsoleTextAttribute(hConsole, 10);
printf("safe ");
SetConsoleTextAttribute(hConsole, 7);
printf("as trust");
SetConsoleTextAttribute(hConsole, 4);
printf("\"");
SetConsoleTextAttribute(hConsole, 6);
printf("    |\n________________________________________|\n\n");
SetConsoleTextAttribute(hConsole, 7);
}
void id_receiver_box(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 6);
printf("\n  ___________________________________\n |");
SetConsoleTextAttribute(hConsole, 10);
printf("___                            ____");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |   ");
SetConsoleTextAttribute(hConsole, 10);
printf("\\");
SetConsoleTextAttribute(hConsole, 6);
printf("-<");
SetConsoleTextAttribute(hConsole, 7);
printf(" Type the ");
SetConsoleTextAttribute(hConsole, 4);
printf("receiver");
SetConsoleTextAttribute(hConsole, 7);
printf(" ID ");
SetConsoleTextAttribute(hConsole, 6);
printf(">-");
SetConsoleTextAttribute(hConsole, 10);
printf("/");
SetConsoleTextAttribute(hConsole, 6);
printf("    |\n |\\   ");
SetConsoleTextAttribute(hConsole, 10);
printf("\\------------------------/    ");
SetConsoleTextAttribute(hConsole, 6);
printf("/|\n ");
SetConsoleTextAttribute(hConsole, 14);
printf("|_");
SetConsoleTextAttribute(hConsole, 6);
printf("\\_______________________________/");
SetConsoleTextAttribute(hConsole, 14);
printf("_|");
SetConsoleTextAttribute(hConsole, 14);
printf("\n |      ");
SetConsoleTextAttribute(hConsole, 6);
printf("\\                      /     ");
SetConsoleTextAttribute(hConsole, 14);
printf("|");
SetConsoleTextAttribute(hConsole, 14);
printf("\n |");
SetConsoleTextAttribute(hConsole, 14);
printf("------");
SetConsoleTextAttribute(hConsole, 6);
printf("|");
SetConsoleTextAttribute(hConsole, 4);
printf("(");
SetConsoleTextAttribute(hConsole, 7);
printf("or type ");
SetConsoleTextAttribute(hConsole, 4);
printf("0 ");
SetConsoleTextAttribute(hConsole, 7);
printf("to RETURN");
SetConsoleTextAttribute(hConsole, 4);
printf(")");
SetConsoleTextAttribute(hConsole, 6);
printf("|");
SetConsoleTextAttribute(hConsole, 14);
printf("------");
SetConsoleTextAttribute(hConsole, 14);
printf("|\n |______");
SetConsoleTextAttribute(hConsole, 6);
printf("\\____________________/");
SetConsoleTextAttribute(hConsole, 14);
printf("_______|\n\n");
SetConsoleTextAttribute(hConsole, 6);
printf("||");
SetConsoleTextAttribute(hConsole, 7);
/*
printf("\n  ___________________________________");
printf("\n |___                            ____|");
printf("\n |   \\-< Type the receiver ID >-/    |");
printf("\n |\\   \\ -----------------------/    /|");
printf("\n |_\\_______________________________/_|");
printf("\n |      \\                      /     |");
printf("\n |------|(or type 0 to return)|------|");
printf("\n |______\\____________________/_______|\n\n");

*/
}
void write_transfer(transfer *t,const char *filename_transfer) {

	FILE *fp = fopen(filename_transfer, "rb");
	if (!fp) {
		// File doesn't exist yet
		FILE *fw = fopen(filename_transfer, "wb");
		if (!fw) {
			perror("Opening File failed !");
			return;
		}
		fwrite(t, sizeof(transfer), 1, fw);
		fclose(fw);
		return;
	}
	FILE *fw = fopen("trans_tmp.bin", "wb");
	if (!fw) {
		perror("Error opening file");
		fclose(fp);
		return ;
	}
	transfer r;
	int inserted=0;
	// comment *p1_encrypted=encrypt_comment(p1);

	while (fread(&r, sizeof(transfer), 1, fp) == 1) {
		if (!inserted && r.id_receiver >= t->id_receiver) {
			fwrite(t, sizeof(transfer), 1, fw);
			inserted = 1;
		}
		fwrite(&r, sizeof(transfer), 1, fw);
	}
	if (!inserted) {
		fwrite(t, sizeof(transfer), 1, fw);
	}
	// p1= decrypt_comment(p1_encrypted);
	fclose(fp);
	fclose(fw);
	remove(filename_transfer);
	rename("trans_tmp.bin",filename_transfer);
	//free(p1_encrypted);
}
transfer *receive_code_id(client_data *p, long long code, const char *filename_transfer) {
    transfer *r = (transfer*)malloc(sizeof(transfer));
    if (!r) {
        perror("Memory allocation failed");
        return NULL;
    }
    r->amount = -1;  // default value
    FILE *fp = fopen(filename_transfer, "rb");
    if (!fp) {
        perror("Opening File Failed");
        return r;
    }
    transfer temp;
    while (fread(&temp, sizeof(transfer), 1, fp) == 1) {
        if (temp.id_receiver == p->id && temp.statue && temp.code_ && temp.code == code) {
            *r = temp;  // copy the matched record to r
            fclose(fp);
            return r;
        }
    }
    fclose(fp);
    r->amount = 0; // not found
    return r;
}

void type_receive_code(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hConsole, 6);
printf("\n\n  ___________________________________\n |");
SetConsoleTextAttribute(hConsole, 10);
printf("___                            ____");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |   ");
SetConsoleTextAttribute(hConsole, 10);
printf("\\");
SetConsoleTextAttribute(hConsole, 6);
printf("---<");
SetConsoleTextAttribute(hConsole, 7);
printf("   Type The ");
SetConsoleTextAttribute(hConsole, 4);
printf("CODE  ");
SetConsoleTextAttribute(hConsole, 7);
SetConsoleTextAttribute(hConsole, 6);
printf(">---");
SetConsoleTextAttribute(hConsole, 10);
printf("/");
SetConsoleTextAttribute(hConsole, 6);
printf("    |\n |\\   ");
SetConsoleTextAttribute(hConsole, 10);
printf("\\------------------------/    ");
SetConsoleTextAttribute(hConsole, 6);
printf("/|\n ");
SetConsoleTextAttribute(hConsole, 14);
printf("|_");
SetConsoleTextAttribute(hConsole, 6);
printf("\\_______________________________/");
SetConsoleTextAttribute(hConsole, 14);
printf("_|");
SetConsoleTextAttribute(hConsole, 14);
printf("\n |      ");
SetConsoleTextAttribute(hConsole, 6);
printf("\\                      /     ");
SetConsoleTextAttribute(hConsole, 14);
printf("|");
SetConsoleTextAttribute(hConsole, 14);
printf("\n |");
SetConsoleTextAttribute(hConsole, 14);
printf("------");
SetConsoleTextAttribute(hConsole, 6);
printf("|");
SetConsoleTextAttribute(hConsole, 4);
printf("(");
SetConsoleTextAttribute(hConsole, 7);
printf("or type ");
SetConsoleTextAttribute(hConsole, 4);
printf("0 ");
SetConsoleTextAttribute(hConsole, 7);
printf("to RETURN");
SetConsoleTextAttribute(hConsole, 4);
printf(")");
SetConsoleTextAttribute(hConsole, 6);
printf("|");
SetConsoleTextAttribute(hConsole, 14);
printf("------");
SetConsoleTextAttribute(hConsole, 14);
printf("|\n |______");
SetConsoleTextAttribute(hConsole, 6);
printf("\\____________________/");
SetConsoleTextAttribute(hConsole, 14);
printf("_______|\n\n");
SetConsoleTextAttribute(hConsole, 6);
printf("||");
SetConsoleTextAttribute(hConsole, 7);
}
int count_degit(long long number){
    if(number==0)return 1;
    int i=0;
    while(number>0){
        number/=10;
        i++;
    }
    return i;
}

void receive_(client_data *p){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 char *filename_recepetion="C:\\Users\\user\\Desktop\\output\\result2.txt";
 char *filename_t_stoage="C:\\Users\\user\\Desktop\\output\\result3.txt";
int count,choice;
long long code;
do{
     header();
      printf("\n-------------------| ACCOUNT SECTION / receive  ");
    type_receive_code();
    scanf("%lld",&code);
    if(code==0){
              SetConsoleTextAttribute(hConsole, 6);
        printf("\n\n --<");
          SetConsoleTextAttribute(hConsole, 7);
    printf(" Receiving Operation Canceled ");
      SetConsoleTextAttribute(hConsole, 6);
   printf(">--");
        getchar();
        click();
        wait();
        return;
    }
    count=count_degit(code);
    if(count!=14){
              SetConsoleTextAttribute(hConsole, 6);
           printf("\n________________________________\n") ;
      SetConsoleTextAttribute(hConsole, 7);
           printf("You Must Enter a number with ");
             SetConsoleTextAttribute(hConsole, 10);
           printf("14");
             SetConsoleTextAttribute(hConsole, 7);
           printf(" Degit ");
           int choice=try_again();
           if(choice==0){
            SetConsoleTextAttribute(hConsole, 6);
        printf("\n\n --<");
          SetConsoleTextAttribute(hConsole, 7);
    printf(" Receiving Operation Canceled ");
      SetConsoleTextAttribute(hConsole, 6);
   printf(">--");
        getchar();
        click();
        wait();
        return;
           }
      }
}while(count!=14);

transfer *r = receive_code_id(p, code, "C:\\Users\\user\\Desktop\\output\\result3.txt");
if(r->amount==-1){
    // invalid password
    perror("Opening File failed");
    free(r);
    return;
}
else if(r->amount==0) {
    invalid_code();
    getchar();
    click();
    free(r);
    return;
}
else{
   r->code_= false;
   header();
    printf("\n-------------------| ACCOUNT SECTION / receive  ");
    print_received_box(r->id_sender,r->amount);
    int choose=-1;
    do{
        if(choose!=-1){
            header();
               printf("\n-------------------| ACCOUNT SECTION / receive  ");
        }
        print_file_choose();
        scanf("%d",&choose);
    }while(choose!=1 && choose!=0);
    if(choose==0){
        wait();
        free(r);
        return ;
    }

do {
    header();
     printf("\n-------------------| ACCOUNT SECTION / transfer / receipt ");
     print_file_box();
     scanf("%d",&choose);
}while(choose!=1 && choose!=0);
 client_data *sender=extract_client_data("C:\\Users\\user\\Desktop\\Professionnel\\clients_data_encrypted_bin.bin.txt",r->id_sender);
if(sender==NULL){
    printf("CLIENT NOT FOUND! ");
    free(sender);
    return;
}
 r->code_= false; // to don t the code in the file , because print the code is useless

if(choose==0)print_transfer(sender,p,r,filename_recepetion);
else {
        char filepath[260];
    header();
     printf("\n-------------------| ACCOUNT SECTION / transfer / receipt ");
    path_box();
      if (scanf(" %[^\n]s",filepath)!=1) {
        perror("Error reading input");
        return ;
    }
     print_transfer(sender,p,r,filepath);
}
   getchar();
   click();
   comment *tmpo=(comment*)malloc(sizeof(comment));
                               tmpo->id=p->id;
                               tmpo->type=1;
                               char senb[20];
                               snprintf(senb,sizeof(senb),"RECEIVE ID_%d",r->id_receiver);
                               snprintf(tmpo->com, sizeof(tmpo->com), "%-20s | %6d |  %s ",senb,r->amount,p->last_entrence);
                               write_comments(tmpo,"C:\\Users\\user\\Desktop\\Professionnel\\comments.bin.txt");
                               free(tmpo);
    p->current_money+=r->amount;
   write_edit(p,filename);
    r->code_= true;
    edit_transfer(r);
   free(sender);
}
}

void edit_transfer(transfer *r){


const char *filename_transfer="C:\\Users\\user\\Desktop\\output\\result3.txt";
const char *filename_transfer_tmp="C:\\Users\\user\\Desktop\\output\\result_tmp.txt";
 FILE *fr = fopen(filename_transfer, "rb");
    if (!fr) {
        perror("Opening File Failed");
        return ;
    }


    FILE *fw=fopen(filename_transfer_tmp,"wb");
    if (!fw) {
        perror("Opening File Failed");
        return ;
    }


    transfer temp;
    while (fread(&temp, sizeof(transfer), 1, fr) == 1) {
        if (temp.id_receiver == r->id_receiver && temp.statue && temp.code_ && temp.code == r->code) {
            *r = temp;  // copy the matched record to r
            r->statue=false;
            fwrite(r,sizeof(transfer),1,fw);


        }
        else  fwrite(&temp,sizeof(transfer),1,fw);
    }
    free(r);
    fclose(fr);
    fclose(fw);
     if (remove(filename_transfer) != 0) {
        perror("Failed to remove original file");
        exit(1);
    }

    if (rename(filename_transfer_tmp, filename_transfer) != 0) {
        perror("Failed to rename temp file");
        exit(1);
    }

}
void invalid_code(){
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

SetConsoleTextAttribute(hConsole, 6);
printf("\n  _________________________________");
printf("\n |                                 |");
printf("\n |");
SetConsoleTextAttribute(hConsole, 12); // red
printf("           INVALID CODE          ");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |_________________________________|\n\n");
SetConsoleTextAttribute(hConsole, 7); // reset
}
void ticket_print(client_data *p, const char *filename_transfer) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     header();
     printf("\n-------------------| ACCOUNT SECTION / receive  ");
	FILE *fp = fopen(filename_transfer, "rb");
	if (!fp) {

	   // perror("Opening File Failed");
	    any_receives_box();
	   getchar();
	   click();
	   wait();


		return;
	}
	transfer r;
    int k=0;
	while (fread(&r, sizeof(transfer), 1, fp) == 1) {
	if(r.id_receiver==p->id){
	    if(r.statue==true){
	            if(r.code_==true){
	                               write_received_tickets(r);
	                               k=1;
	                              }
                             	}
	                         }
                     	}
	fclose(fp);
	if(k==0){
	   any_receives_box();
	   getchar();
	   click();
	   wait();

	   return;
	}
	else{
            getchar();
        click();
        header();
         printf("\n-------------------| ACCOUNT SECTION / receive  ");

        int choose;
        do{
            choose_receive_box();
            scanf("%d",&choose);
        }while(choose!=1 && choose!=0);
        // type 1 for receive 0 for return s
        if(choose==0){
              getchar();
	   click();
	   wait();
	   return;
        }
        receive_(p);
	}
}
void choose_receive_box(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

SetConsoleTextAttribute(hConsole, 6);
printf("\n  _________________________________");
printf("\n |                                 |");
printf("\n |");
SetConsoleTextAttribute(hConsole, 10);
printf("       \xB2 ACTION OPTIONS \xB2        "); // box title
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |_________________________________|");

printf("\n |                                 |");
printf("\n |  1 ");
SetConsoleTextAttribute(hConsole, 7);
printf("-> Receive                   ");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |  0 ");
SetConsoleTextAttribute(hConsole, 7);
printf("-> Return                    ");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |_________________________________|\n\n");

printf("|| ");
SetConsoleTextAttribute(hConsole, 7);
}
void any_receives_box(){
         HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
       //  header();
       // printf("\n-------------------| ACCOUNT SECTION / transfer / receipt ");
         SetConsoleTextAttribute(hConsole, 6);
         printf("\n\n  ___________________________________");
         printf("\n |___                             ___|\n |   ");
         SetConsoleTextAttribute(hConsole, 14);
         printf("\\-< ");
        SetConsoleTextAttribute(hConsole, 7);
         printf("You have any ");
         SetConsoleTextAttribute(hConsole, 4);
         printf("receipts ");
        SetConsoleTextAttribute(hConsole, 14);
         printf(">-/   ");
         SetConsoleTextAttribute(hConsole, 6);
         printf("|");
         SetConsoleTextAttribute(hConsole, 14);
         printf("\n |");
         printf("\\   \\ -----------------------/    /");
         SetConsoleTextAttribute(hConsole, 14);
         printf("|");
         printf("\n |_");
         SetConsoleTextAttribute(hConsole, 6);
         printf("\\_______________________________/");
         SetConsoleTextAttribute(hConsole, 14);
         printf("_|");
         }
void write_received_tickets(transfer r){
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     char content[256];
    snprintf(content, sizeof(content),
             "| FROM : %d | AMOUNT : %d | STATUS : ACTIVE |",
             r.id_sender, r.amount);

    int len = strlen(content)-2;

    // Print top border
    printf("\n\n ");
     SetConsoleTextAttribute(hConsole, 6);
    for (int i = 0; i < len; i++) printf("_");
    printf("\n");
    printf("|");
    for (int i = 0; i < len; i++) printf(" ");
    printf("|");

    //Print content
     printf("\n");

    // Print each character with conditional coloring
    for (int i = 0; i < len; i++) {
        if (content[i] == '|') {
           SetConsoleTextAttribute(hConsole, 6); // border color
            putchar('|');
            SetConsoleTextAttribute(hConsole, 7); // reset back to white
        } else {
            putchar(content[i]);
        }
    }
     SetConsoleTextAttribute(hConsole, 6);
    printf(" |\n");
   // printf("%s\n", content);


    // Print bottom border
    printf("|");
    for (int i = 0; i < len; i++) printf("_");  // or use '_' again
    printf("|\n");


}

static void print_hbar(HANDLE h, int width,int i) {
   if(i==0){ // top or buttom

        SetConsoleTextAttribute(h, 6); // border color
    putchar(' ');

    for (int i = 0; i < width; i++) putchar('_');
    putchar('\n');
   }
   else { // inside

        SetConsoleTextAttribute(h, 6); // border color
        printf("|");
    for (int i = 0; i < width; i++) putchar('_');
    printf("|\n");
   }



}
static void print_empty(HANDLE h, int width) {
    SetConsoleTextAttribute(h, 6); putchar('|');
    SetConsoleTextAttribute(h, 7); for (int i = 0; i < width; i++) putchar(' ');
    SetConsoleTextAttribute(h, 6); putchar('|'); putchar('\n');
}
static void print_centered(HANDLE h, const char *text, int width) {
    int n = (int)strlen(text);
    int left = (width > n) ? (width - n) / 2 : 0;
    int right = (width > n) ? width - n - left : 0;

    SetConsoleTextAttribute(h, 6); putchar('|');
    SetConsoleTextAttribute(h, 7); for (int i = 0; i < left; i++) putchar(' ');
    // title (no inner pipes here)
    fputs(text, stdout);
    for (int i = 0; i < right; i++) putchar(' ');
    SetConsoleTextAttribute(h, 6); putchar('|'); putchar('\n');
}
static void print_content_with_colored_pipes(HANDLE h, const char *content, int width) {
    int n = (int)strlen(content);

    SetConsoleTextAttribute(h, 6); putchar('|');

    // print content with colored '|' and red "INACTIVE"
    int i = 0;
    while (i < n && i < width) {
        if (content[i] == '|') {
            SetConsoleTextAttribute(h, 6);
            putchar('|');
            SetConsoleTextAttribute(h, 7);
            i++;
            continue;
        }
        // color the word INACTIVE in red
        if (i + 8 <= n && strncmp(&content[i], "INACTIVE", 8) == 0) {
            SetConsoleTextAttribute(h, 4);
            fwrite(&content[i], 1, 8, stdout);
            SetConsoleTextAttribute(h, 7);
            i += 8;
            continue;
        }
        putchar(content[i]);
        i++;
    }

    // pad remaining space
    SetConsoleTextAttribute(h, 7);
    for (; i < width; i++) putchar(' ');

    SetConsoleTextAttribute(h, 6); putchar('|'); putchar('\n');
}
void print_received_box(int id_sender, int amount) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    // Build the two dynamic lines
    const char *title = "RECEIVED OPERATION DONE SUCCESSFULLY";
    char line[256];
    snprintf(line, sizeof(line),
             " FROM : %d | AMOUNT : %d | STATUS : INACTIVE ",
             id_sender, amount);

    // Choose inner width that fits both lines
    int inner = (int)strlen(title);
    int nline = (int)strlen(line);
    if (nline > inner) inner = nline;

    // Top section
    printf("\n\n");
    print_hbar(h, inner,0);
    print_empty(h, inner);
    print_centered(h, title, inner);

    print_hbar(h, inner,1);


    // Spacer
    print_empty(h, inner);

    // Dynamic line with colored inner pipes and red INACTIVE
    print_content_with_colored_pipes(h, line, inner);

    // Bottom border
    print_hbar(h, inner,1);

    // Reset color
    SetConsoleTextAttribute(h, 7);
}

void end(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);;
wait();
system("cls");
entry();
SetConsoleTextAttribute(hConsole, 6);
printf("\n\n  ___________________________________\n |");
SetConsoleTextAttribute(hConsole, 10);
printf("___                            ____");
SetConsoleTextAttribute(hConsole, 6);
printf("|\n |   ");
SetConsoleTextAttribute(hConsole, 10);
printf("\\");
SetConsoleTextAttribute(hConsole, 6);
printf("---<");
SetConsoleTextAttribute(hConsole, 7);
printf("Its A Beatiful");
SetConsoleTextAttribute(hConsole, 14);
printf(" Day");
SetConsoleTextAttribute(hConsole, 6);
printf(">---");
SetConsoleTextAttribute(hConsole, 10);
printf("/");
SetConsoleTextAttribute(hConsole, 6);
printf("    |\n |\\   ");
SetConsoleTextAttribute(hConsole, 10);
printf("\\------------------------/    ");
SetConsoleTextAttribute(hConsole, 6);
printf("/|\n ");
SetConsoleTextAttribute(hConsole, 14);
printf("|_");
SetConsoleTextAttribute(hConsole, 6);
printf("\\_______________________________/");
SetConsoleTextAttribute(hConsole, 14);
printf("_|");
SetConsoleTextAttribute(hConsole, 14);
printf("\n |      ");
SetConsoleTextAttribute(hConsole, 6);
printf("\\                      /     ");
SetConsoleTextAttribute(hConsole, 14);
printf("|");
SetConsoleTextAttribute(hConsole, 14);
printf("\n |");
SetConsoleTextAttribute(hConsole, 14);
printf("------");
SetConsoleTextAttribute(hConsole, 6);
printf("|");
SetConsoleTextAttribute(hConsole, 4);
printf("(");
SetConsoleTextAttribute(hConsole, 7);
printf("Created By: ");
SetConsoleTextAttribute(hConsole, 3);
printf("HTALAL ");
SetConsoleTextAttribute(hConsole, 4);
printf(")");
SetConsoleTextAttribute(hConsole, 6);
printf("|");
SetConsoleTextAttribute(hConsole, 14);
printf("------");
SetConsoleTextAttribute(hConsole, 14);
printf("|\n |______");
SetConsoleTextAttribute(hConsole, 6);
printf("\\____________________/");
SetConsoleTextAttribute(hConsole, 14);
printf("_______|\n\n");
SetConsoleTextAttribute(hConsole, 6);
}

int main()
{
     int choose;
     entry();
    click();
    do{
     choose=choose_service();
    switch(choose){
case 1:client();
      break;
case 2: //admin();
    break;
case 3 : //special_orders();
    break;
    }
    }while(choose!=4);
    end();
    return 0;
}
