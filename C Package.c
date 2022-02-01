#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

#define CO 15
#define CA 4

//STRUCTURE DECLACRATION
struct customer
{
    int id;
    char name[20];
    float expenditure;
}cust[10];

struct product
{
    char name[20];
    int id;
    float quantity;
    float rate;
}pd[10];

struct bill
{
    int id;
    float price[100];
    float total;
    int prod_id[100];
    float quantity[100];
    int cust_id;
}bl[10];

/*struct employee
{
   int id;
   char name[20];
   char password[20];
   char role[20];
}emp[10];void store_home();*/
void login();
//PRODUCT MENUS
void product_home();
void addproduct();
void viewproduct();
void editproduct();
void deleteproduct();

//BILL MENU
void bill_home();
void display_bill(int bill_id);
void deletebill();
 void viewbill();

//CUSTOMER MENU
void customer_home();
void addcustomer();
void viewcustomer();
void deletecustomer();
//REVENUE MENU
void revenue_home();
void store_revenue();

//Declaration
int locate_product(struct product pd[]);
int locate_customer(struct customer cust[]);
int locate_bill(struct bill bl[]);
//int locate_employee(struct employee emp[]);
int index,product_count,bill_count,customer_count;
float income;
int resp;
static int i=0;

void main()
{
     home();
}
//Coordinates and structure
COORD coord={0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


struct password
{
char pasw[10];
}pass[10];

//SIGNING
void login()
{
    FILE *fp1;
    int us;
    char pwrd[10],c;
    fp1=fopen("file.txt","r");
    gotoxy (30,19);printf("Enter the password:");
    //scanf("%s",pwrd);
    while( (c=getch())!='\r')
        {
            pwrd[i] = c;
            printf("*");
            i++;
        }pwrd[i]='\0';


    while(fread(&pass,sizeof(pass),1,fp1)==1)
    {
        //printf("%s",pass[0].pasw);
         if(strcmp(pwrd,pass[0].pasw)==0)
         {
             gotoxy (30,20);printf("Access Granted");
             mainmenu();
             // fseek(fp,sizeof(struct accounts)*records,SEEK_SET);
              //fwrite(&s,sizeof(s),1,fp);
         }
    }
fclose(fp1);

}

void home()
{
    int i;
    char ch;
    const char *menu[]={" LOGIN"," SIGNUP"," EXIT"};
    system("cls");
    window(3,90,9,36);
    for (i=0;i<=2;i++){
    gotoxy(30,15+i+1);printf("%s\n\n",menu[i]);}
    curser(3);
    /*gotoxy (30,16);printf("1.Login");
    gotoxy (30,17);printf("2.Signup");
    gotoxy (30,18);printf("----->");
    scanf("%d",&resp);
    switch(resp)
   {
       case 1:login();
              //system("cls");
              break;
       case 2:signup();
              system("cls");
              home();
              break;
   }*/
}
void signup()
{
    FILE *fp;
    fp=fopen("file.txt","w");
   gotoxy (30,19);printf("Enter your password:");
   scanf("%s",pass[0].pasw);
   fwrite(&pass,sizeof(pass),1,fp);
   fclose(fp);
   gotoxy (30,20);printf("Signup successful");
   home();
}
//MAIN MENU
void mainmenu()
{
 int i;
 char ch;
 const char *menu[]={"PRODUCTS","BILLING","CUSTOMER","REVENUE","EXIT"};
 system("cls");

window(3,90,9,36);//left,ri8,top,bottom

 gotoxy(33,14);printf("MAIN MENU");



 for (i=0;i<=4;i++){
  gotoxy(30,15+i+1);printf("%s\n\n\n\n\n",menu[i]);}
  curser(5);

}
//cursor movement BILL AND REVENUE
void curser(int no)
{
    int count=1;
    char ch='0';
    gotoxy(30,16);
 while(1){
  switch(ch){
   case 80:
    count++;
    if (count==no+1) count=1;
    break;
   case 72:
    count--;
    if(count==0) count=no;
    break;
  }
  highlighter(no,count);
  ch=getch();
  if(ch=='\r')
  {
      if (no==3)
      {
          if (count==1)login();
          else if (count==2)signup();
          else exit(0);
      }

      if(no==5){
        if (count==1)product_home();
        else if (count==2)bill_home();
        else if(count==3)customer_home();
        else if(count==4)revenue_home();
        else exit(0);
      }
      //product menu
    if(no==6){
    if (count==2) addproduct();
    else if(count==3)viewproduct();
    else if(count==4)editproduct();
    else if(count==5)deleteproduct();
    else if(count==6) mainmenu();
    }
    //customer menu
    if(no==7){
            if (count==2) addcustomer();
            else if(count==3) viewcustomer();
            else if(count==4) editcustomer();
            else if(count==5) deletecustomer();
            else if (count==6) mainmenu();

    }
    //BILL MENU
    /*if(no==8){
            if (count==6) mainmenu();

    }*/
    }

 }
}

//HIGHLIGHTER
void highlighter(int no,int count)
{
    if(no==3)
    {
        gotoxy (30,16);printf("   LOGIN ");
        gotoxy (30,17);printf("   SIGNUP      ");
        gotoxy (30,18);printf("   EXIT      ");
    switch(count)
    {
   case 1:
    gotoxy (30,16);
    printf(" - LOGIN");
    break;
   case 2:
    gotoxy (30,17);
    printf(" - SIGNUP");
    break;
   case 3:
    gotoxy(30,18);
    printf(" - EXIT");
    break;
    }
    }

   if(no==5){
  gotoxy (30,16);printf("1. PRODUCTS ");
  gotoxy (30,17);printf("2. BILLING      ");
  gotoxy (30,18);printf("3. CUSTOMER     ");
  gotoxy (30,19);printf("4. REVENUE    ");
  gotoxy (30,20);printf("5. EXIT   ");


  switch(count){
   case 1:
    gotoxy (30,16);
    printf(" - PRODUCTS ");
    break;
   case 2:
    gotoxy (30,17);
    printf(" - BILLING     ");
    break;
   case 3:
    gotoxy (30,18);
    printf(" - CUSTOMER     ");
    break;
   case 4:
    gotoxy (30,19);
    printf(" - REVENUE   ");
    break;
   case 5:
       gotoxy (30,20);
       printf("- EXIT  ");
       break;
       }
 }
//PRODUCT

  if (no==6){
  gotoxy(30,16);printf("   OPTIONS:          ");
  gotoxy(30,17);printf("   ADD NEW PRODUCT   ");
  gotoxy(30,18);printf("   VIEW PRODUCTS     ");
  gotoxy(30,19);printf("   UPDATE PRODUCT    ");
  gotoxy(30,20);printf("   DELETE PRODUCT    ");
  gotoxy(30,21);printf("   BACK              ");
  gotoxy(30,22);printf("  SELECT AN OPTION   ");
  switch(count)
  {
   case 1:
    gotoxy(30,16);
    printf(" - OPTIONS:");
    break;
   case 2:
    gotoxy(30,17);
    printf(" - ADD NEW PRODUCT");
    break;
   case 3:
    gotoxy(30,18);
    printf(" - VIEW PRODUCTS");
    break;
   case 4:
    gotoxy(30,19);
    printf(" - UPDATE PRODUCT");
    break;
   case 5:
    gotoxy(30,20);
    printf(" - DELETE PRODUCT");
    break;
   case 6:
    gotoxy(30,21);
    printf(" - BACK");
  }

}
//CUSTOMER
if (no==7){
  gotoxy(30,16);printf("   OPTIONS:          ");
  gotoxy(30,17);printf("   ADD NEW CUSTOMER   ");
  gotoxy(30,18);printf("   VIEW CUSTOMERS     ");
  gotoxy(30,19);printf("   UPDATE CUSTOMER    ");
  gotoxy(30,20);printf("   DELETE CUSTOMER    ");
  gotoxy(30,21);printf("   BACK               ");
  gotoxy(30,22);printf("  SELECT AN OPTION   ");
  //gotoxy(30,22);printf("   USE UP ARROW       ");
  switch(count)
  {
   case 1:
    gotoxy(30,16);
    printf(" - OPTIONS:");
    break;
   case 2:
    gotoxy(30,17);
    printf(" - ADD NEW CUSTOMER");
    break;
   case 3:
    gotoxy(30,18);
    printf(" - VIEW CUSTOMERS");
    break;
   case 4:
    gotoxy(30,19);
    printf(" - UPDATE CUSTOMER");
    break;
   case 5:
    gotoxy(30,20);
    printf(" - DELETE CUSTOMER");
    break;
   case 6:
    gotoxy(30,21);
    printf(" - BACK");
    break;
   case 7:
    gotoxy(30,22);
    printf("  SELECT AN OPTION");
}
}

//REVENUE
if (no==4){
  gotoxy(30,16);printf("   OPTIONS:          ");
  gotoxy(30,17);printf("   STORE REVENUE   ");
  gotoxy(30,18);printf("   CUSTOMER EXPENDITURE         ");
  gotoxy(30,19);printf("   BACK       ");
  gotoxy(30,20);printf("   SELECT AN OPTION       ");
  //gotoxy(30,22);printf("   USE UP ARROW       ");
  switch(count)
  {
   case 1:
    gotoxy(30,16);
    printf(" - OPTIONS:");
    break;
   case 2:
    gotoxy(30,17);
    printf(" - STORE REVENUE");
    break;
   case 3:
    gotoxy(30,18);
    printf(" - CUSTOMER EXPENDITURE");
    break;
   case 4:
    gotoxy(30,19);
    printf(" - BACK");
    break;
   case 5:
    gotoxy(30,20);
    printf(" - SELECT AN OPTION");
    break;
}
}
}
//cursor movement
void cursor(int on)
{
    int count=1;
    char ch='0';
    gotoxy(30,16);
 while(1){
  switch(ch){
   case 80:
    count++;
    if (count==on+1) count=1;
    break;
   case 72:
    count--;
    if(count==0) count=on;
    break;
  }
  highlighters(on,count);
  ch=getch();
  if(ch=='\r')
  {

    //BILL MENU
    if(on==5){
             if (count==2) addbill();
             else if (count==3) viewbill();
             else if (count==4) deletebill();
            else if (count==5) mainmenu();

    }
    if(on==4)
    {
        if(count==2) store_revenue();
        else if (count==3) mainmenu();

    }


 }
}
}
//HIGHLIGHTERs
void highlighters(int on,int count)
{
//BILLING
if (on==5){
  gotoxy(30,16);printf("   OPTIONS:          ");
  gotoxy(30,17);printf("   CREATE NEW BILL   ");
  gotoxy(30,18);printf("   VIEW BILLLING HISTORY         ");
  gotoxy(30,19);printf("   DELETE BILL       ");
  gotoxy(30,20);printf("   BACK              ");
  gotoxy(30,21);printf("  SELECT AN OPTION   ");
  //gotoxy(30,22);printf("   USE UP ARROW       ");
  switch(count)
  {
   case 1:
    gotoxy(30,16);
    printf(" - OPTIONS:");
    break;
   case 2:
    gotoxy(30,17);
    printf(" - CREATE NEW BILL");
    break;
   case 3:
    gotoxy(30,18);
    printf(" - VIEW BILLLING HISTORY");
    break;
   case 4:
    gotoxy(30,19);
    printf(" - DELETE BILL");
    break;
   case 5:
    gotoxy(30,20);
    printf(" - BACK");
    break;
   case 6:
    gotoxy(30,21);
    printf("  SELECT AN OPTION");
}
}
if (on==4){
  gotoxy(30,16);printf("   OPTIONS:          ");
  gotoxy(30,17);printf("   STORE REVENUE   ");
  gotoxy(30,18);printf("   BACK         ");
  switch(count)
  {
   case 1:
    gotoxy(30,16);
    printf(" - OPTIONS:");
    break;
   case 2:
    gotoxy(30,17);
    printf(" - STORE REVENUE");
    break;
   case 3:
    gotoxy(30,18);
    printf(" - BACK");
    break;
  }

}
}

//WINDOW
void window(int a,int b,int c,int d)
{
 int i;
 system("cls");
 gotoxy(20,10);

 for (i=1;i<=6;i++)
 printf(":):)");
 printf(":)");
 for (i=1;i<=5;i++)
        printf(":)");
 printf(":)");
 system("COLOR 71");

 gotoxy(56,33);printf("USE UP AND DOWN ARROW TO NAVIGATE");
 gotoxy(30,12);printf("C PAKAGE STORES");
 gotoxy(27,35);printf("THANKYOU FOR VISITING:)");
 gotoxy(85,35);printf("DAVG");

 for (i=a;i<=b;i++){
        gotoxy(i,13);printf("\xcd");
        gotoxy(i,15);printf("\xcd");
        gotoxy(i,c);printf("\xcd");
        gotoxy(i,d);printf("\xcd");
        }


 gotoxy(a,17);printf("\xc9");
 gotoxy(a,18);printf("\xba");
 gotoxy(a,19);printf("\xc8");
 gotoxy(b,17);printf("\xbb");
 gotoxy(b,18);printf("\xba");
 gotoxy(b,19);printf("\xbc");

 for(i=c;i<=d;i++){
  gotoxy(a,i);printf("\xba");
  gotoxy(b,i);printf("\xba");
 }
 gotoxy(a,c);printf("\xc9");
 gotoxy(a,d);printf("\xc8");
 gotoxy(b,c);printf("\xbb");
 gotoxy(b,d);printf("\xbc");

}

//HOME OF ALL MENUS

//PRODUCT MENU
void product_home()
{
 char ch;
 int i;

    const char *menu[]={"   OPTIONS:","   ADD NEW PRODUCT","   VIEW PRODUCTS","   UPDATE PRODUCT","   DELETE PRODUCT","   BACK"};
 system("cls");
 window(3,90,9,36);
 gotoxy(27,14);printf(" ** PRODUCT MENU **");
 for (i=0;i<=5;i++){
 gotoxy(30,15+i+1);printf("%s\n\n\n\n\n",menu[i]);}
 curser(6);

}
void viewproduct()
{
    system("cls");
    window(3,90,9,36);
    int i = 0,count = 0;
    gotoxy(25,16);printf("PRODUCT ID \t PRODUCT NAME \t RATE(RS) \t QUANTITY ");
    gotoxy(20,18);printf("-------------------------------------------------- \n");
    int n=20;
    while(count!=product_count)
    {

        if(pd[i].id != 0)
        {
           gotoxy(25,n);
           printf("%d \t ",pd[i].id);
           printf("\t %s",pd[i].name);
           printf("\t\t %.2f",pd[i].rate);
           printf("\t\t%.2f",pd[i].quantity);
           count++;
        }
        n++;
        i++;

    }
    gotoxy(6,16);printf("PRODUCT COUNT: %d",product_count);
    getch();
    product_home();
}

void addproduct()
{
    system("cls");
    window(3,90,9,36);
    int pos = locate_product(pd);
    pd[pos].id = 101+pos;
    gotoxy(67,16);printf("PRODUCT ID: %d \n",101+pos);
    gotoxy(20,16);printf("ENTER DETAILS OF THE PRODUCT TO BE ADDED \n \n");
    gotoxy(20,18);printf("ENTER THE NAME OF THE PRODUCT: ");
    scanf(" %[^\n]",pd[pos].name);



    //GETTNG PRODUCT QUANTITY(NON NEGATIVE)
    while(1)
    {
        gotoxy(20,20);printf("ENTER THE QUANTITY:");
        scanf("%f",&pd[pos].quantity);



        if(pd[pos].quantity < 1)
        {
            system("cls");
            window(3,90,9,36);
            gotoxy(67,16);printf("PRODUCT ID: %d \n",101+pos);
             gotoxy(20,18);printf("ENTER THE NAME OF THE PRODUCT:%s ",pd[pos].name);
            gotoxy(20,22);printf("ENTER A POSITIVE QUANTITY!");

        }
        else
        {
            break;
        }
    }

     //GETTNG PRODUCT RATE(NON NEGATIVE)
    while(1)
    {
        gotoxy(20,24);printf("ENTER THE RATE(PER UNIT QUANTITY) IN RS. :");
        scanf("%f",&pd[pos].rate);


        if(pd[pos].rate < 1)
        {
            system("cls");
            window(3,90,9,36);
            gotoxy(67,16);printf("PRODUCT ID: %d \n",101+pos);
            gotoxy(20,18);printf("ENTER THE NAME OF THE PRODUCT:%s ",pd[pos].name);
            gotoxy(20,20);printf("ENTER THE QUANTITY:%.2f ",pd[pos].quantity);
             gotoxy(20,26);printf("ENTER A POSITIVE RATE!");

        }
        else
        {
            break;
        }
    }
    product_count++;
    product_home();
}
void editproduct()
{
    system("cls");
    window(3,90,9,36);
    int id,ch,proceed=0;
    gotoxy(20,18);printf("ENTER THE ID OF THE (3-DIGIT) PRODUCT TO BE UPDATED: ");
    scanf("%d",&id);
    if(pd[id-101].id == 0)
    {
        system("cls");
        window(3,90,9,36);
        gotoxy(20,18);printf("ENTER THE ID OF THE PRODUCT TO BE UPDATED: ");
        gotoxy(20,19);printf("PRODUCT WITH GIVEN ID %d DOES NOT EXIST!  PRESS ANY KEY TO RETRY\n",id);
        editproduct();
    }

    while(proceed != 1)
    {   gotoxy(20,20);printf("CURRENT PRODUCT DETAILS: \n");
        gotoxy(20,21);printf("PRODUCT ID: %d \n",pd[id-101].id);
        gotoxy(20,22);printf("PRODUCT NAME: %s \n",pd[id-101].name);
        gotoxy(20,23);printf("PRODUCT RATE : %.2f \n \n",pd[id-101].rate);
        gotoxy(20,24);printf("PRODUCT QUANTITY: %.2f \n \n",pd[id-101].quantity);
        gotoxy(20,25);printf("WHAT WOULD YOU LIKE TO EDIT? : ");
        gotoxy(20,26);printf("0.BACK TO PRODUCT HOME : ");
        gotoxy(20,27);printf("1.NAME : ");
        gotoxy(20,28);printf("2.RATE : ");
        gotoxy(20,29);printf("3.QUANTITY: ");
        gotoxy(20,30);printf("ENTER CHOICE(1/2/3): ");
        scanf("%d",&ch);
        switch(ch)
        {   case 0: product_home();
                    proceed = 1;
                    break;
            case 1: gotoxy(20,31);printf("CURRENT PRODUCT NAME: %s",pd[id-101].name);
                    gotoxy(20,32);printf("ENTER NEW NAME: ",pd[id-101].name);
                    scanf(" %[^\n]",pd[id-101].name);
                    gotoxy(20,33);printf("PRODUCT NAME CHANGED TO '%s' \n",pd[id-101].name);
                    getch();
                    system("cls");
                    window(3,90,9,36);
                    break;
            case 2: gotoxy(20,31);printf("CURRENT RATE: %.2f : ",pd[id-101].rate);
                    gotoxy(20,32);printf("ENTER NEW RATE: ");
                    scanf("%f",&pd[id-101].rate);
                    gotoxy(20,33);printf("PRODUCT RATE CHANGED TO %.2f RUPEES",pd[id-101].rate);
                    getch();
                    system("cls");
                    window(3,90,9,36);
                    break;
            case 3: gotoxy(20,31);printf("CURRENT QUANTITY: %.2f",pd[id-101].quantity);
                    gotoxy(20,32);printf("ENTER NEW QUANTITY: ");
                    scanf("%f",&pd[id-101].quantity);
                    gotoxy(20,33);printf("PRODUCT QUANTITY CHANGED TO %.2f NOS.",pd[id-101].quantity);
                    getch();
                    system("cls");
                    window(3,90,9,36);
                    break;
            default:system("cls");
                    window(3,90,9,36);
                    gotoxy(20,33);printf("ENTER A VALID CHOICE!");
        }
    }
}
void deleteproduct()
{
    system("cls");
    window(3,90,9,36);
    int id;
    gotoxy(20,18);printf("ENTER THE ID OF THE PRODUCT TO BE DELETED: ");
    scanf("%d",&id);
    if(pd[id-101].id == 0)
    {
        system("cls");
        window(3,90,9,36);
        gotoxy(20,20);printf("PRODUCT WITH GIVEN ID %d NOT EXIST! \n",id);
        deleteproduct();
    }
    gotoxy(20,22);printf("PRODUCT NAMED '%s' DELETED!",pd[id-101].name);
    pd[id-101].id = 0;
    product_count--;
    getch();
    product_home();
}

//BILL MENU
void bill_home()
{
 char ch;
 int i;
    const char *menu[]={"   OPTIONS","   CREATE NEW BILL","   VIEW BILLING HISTORY ","   DELETE BILL"};
 system("cls");
 window(3,90,9,36);
 gotoxy(27,14);printf("***BILL MENU***");
 for (i=0;i<=3;i++){
 gotoxy(30,15+i+1);printf("%s\n\n\n",menu[i]);}
 cursor(5);
}
void addbill()
{
    system("cls");
    window(3,90,9,36);
    int pos;
    pos = locate_bill(bl);
    bl[pos].id = 10001 + pos;
    gotoxy(67,16);printf("BILL ID: %d \n", bl[pos].id);

//    To get the customer id
    while(1)
    {
         gotoxy(20,20);printf("ENTER THE CUSTOMER ID: ");
        scanf("%d",&bl[pos].cust_id);

        if(cust[bl[pos].cust_id - 1001].id == 0)
        {
            //system("clear");
            system("cls");
            window(3,90,9,36);
            gotoxy(67,16);printf("CUSTOMER NOT FOUND! \n");
        }
        else
        {
            break;
        }
    }

    int i = 0;
    char ch;
    while(1)
    {
        //Getting Product ID and validating
        while(1)
        {
            //system("clear");
            system("cls");
            window(3,90,9,36);
            display_bill(bl[pos].id);
            gotoxy(20,22);printf("ENTER PRODUCT ID: ");
            scanf("%d",&bl[pos].prod_id[i]);
            if(pd[bl[pos].prod_id[i] - 101].id == 0)
            {
                gotoxy(20,18);printf("PRODUCT DOES NOT EXIST! \n PLEASE ENTER A VALID ENTRY! \n");
            }
            else
            {
                break;
            }
        }

        //Getting required Quantity and validating with available stock
        while(1)
        {
            system("cls");
            window(3,90,9,36);
            gotoxy(20,20);printf("ENTER QUANTITY: ");
            scanf("%f",&bl[pos].quantity[i]);
            if(pd[bl[pos].prod_id[i] - 101].quantity < bl[pos].quantity[i])
            {
                gotoxy(20,22);printf("PRODUCT STOCK INSUFFICIENT! \nSTOCK AVAILABLE: %.2f \n",pd[bl[pos].prod_id[i] - 101].quantity);
            }
            else
            {
                break;
            }
        }
        i++;

        //Asking user if they want to continue
        gotoxy(20,23);printf("ADD ANOTHER ENTRY? (ENTER 'Y' TO CONTINUE) : ");
        scanf(" %c",&ch);
        if(ch == 'Y' || ch == 'y')
        {
            continue;
        }
        else
        {
            //system("clear");
            system("cls");
            window(3,90,9,36);
            display_bill(bl[pos].id);
             cust[bl[pos].cust_id - 1001].expenditure = cust[bl[pos].cust_id - 1001].expenditure + bl[pos].total;
            income = income + bl[pos].total;
            bill_count++;
            gotoxy(20,25);printf("PRESS ANY KEY TO CONTINUE...\n\n");
            getch();
            bill_home();
             break;
        }
    }


}
void display_bill(int bill_id)
{
    system("cls");
    window(3,90,9,36);
    int i = 0;
    bl[bill_id - 10001].total = 0;
    gotoxy(8,14);printf("BILL ID: %d",bill_id);
    gotoxy(27,14);printf("CUSTOMER NAME: %s ",cust[bl[bill_id - 10001].cust_id - 1001].name);
    gotoxy(15,16);printf("PRODUCT ID \t PRODUCT NAME \t RATE(RS) \t QUANTITY \t PRICE");

    int n=18;
    while(bl[bill_id -10001].prod_id[i] != 0)
    {
        if(pd[bl[bill_id - 10001].prod_id[i] - 101].id != 0)
        {
            gotoxy(15,n);
           printf("%d \t",bl[bill_id - 10001].prod_id[i]);
           printf("\t %s",pd[bl[bill_id - 10001].prod_id[i] - 101].name);
           printf("\t\t %.2f",pd[bl[bill_id - 10001].prod_id[i] - 101].rate);
           printf("\t\t%.2f",bl[bill_id - 10001].quantity[i]);
           printf("\t\t%.2f",bl[bill_id - 10001].price[i] =(bl[bill_id - 10001].quantity[i] * pd[bl[bill_id - 10001].prod_id[i] - 101].rate));
            bl[bill_id - 10001].total = bl[bill_id - 10001].total + bl[bill_id - 10001].quantity[i] * pd[bl[bill_id - 10001].prod_id[i] - 101].rate;
        }
        n++;
        i++;

    }



    gotoxy(20,26);printf("-------------------------------------------------------\n\n\n");
    gotoxy(20,28);printf("BILL TOTAL:%.2f \n",bl[bill_id - 10001].total);
    gotoxy(20,30);printf("NUMBER OF ENTRIES: %d \n",i);
    gotoxy(20,32);printf("--------------------------------------------------------\n");

}
 void deletebill()
 {
     system("cls");
     window(3,90,9,36);
     int id;
     gotoxy(20,18);printf("ENTER THE ID OF THE BILL TO BE DELETED: ");
     scanf("%d",&id);
     if(bl[id-10001].id == 0)
     {
         //system("clear");
         system("cls");
         window(3,90,9,36);
         gotoxy(20,20);printf("PRODUCT WITH GIVEN ID %d NOT EXIST! \n",id);
         deletebill();
     }
     gotoxy(20,22);printf("BILL OF CUSTOMER NAMED '%s' DELETED!",cust[bl[id-10001].cust_id - 1001].name);
     bl[id-10001].id = 0;
     bill_count--;
     getch();
     //system("read -n1 -p ' ' key");
     bill_home();
 }
 void viewbill()
 {
     system("cls");
     window(3,90,9,36);
     int i = 0,count = 0;
     gotoxy(25,16);printf("BILLING DATABASE");
     gotoxy(6,18);printf("BILL ID \t CUSTOMER NAME \t CUSTOMER ID \t BILL TOTAL ");
    gotoxy(6,19);printf("-------------------------------------------------- \n");
     int n=20;
     while(count!=bill_count)
     {
         if(pd[i].id != 0)
         {
             gotoxy(6,n);
             printf("%d ",bl[i].id);
             printf("\t %s",cust[bl[i].cust_id - 1001].name);
             printf("\t\t %d",bl[i].cust_id);
             printf("\t\t %.2f",bl[i].total);
             count++;
         }
         n++;
        i++;

     }
     gotoxy(6,16);printf("BILL COUNT: %d \n",bill_count);
     gotoxy(6,33);printf("PRESS ANY KEY TO CONTINUE..");
     getch();
     //system("read -n1 -p ' ' key");
     bill_home();
 }

//CUSTOMER MENU
void customer_home()
{
    char ch;
    int i;

        const char *menu[]={"   OPTIONS:","   ADD NEW CUSTOMER","   VIEW CUSTOMERS","   UPDATE CUSTOMER","   DELETE CUSTOMER","   BACK"};


        system("cls");
 window(3,90,9,36);
 gotoxy(27,14);printf("***CUSTOMER MENU***");
 for (i=0;i<=5;i++){
 gotoxy(30,15+i+1);printf("%s\n\n\n\n\n",menu[i]);}
 curser(7);
}
void addcustomer()
{
    system("cls");
    window(3,90,9,36);
    int pos = locate_customer(cust);
    cust[pos].id = 1001+pos;
    while (1){
    gotoxy(67,16);printf("CUSTOMER ID: %d \n",1001+pos);
    gotoxy(20,16);printf("ENTER DETAILS OF THE CUSTOMER TO BE ADDED: \n \n");
    gotoxy(20,18);printf("ENTER THE NAME OF THE CUSTOMER: ");
    scanf(" %[^\n]",cust[pos].name);
    if (!(isalpha(cust[pos].name[0])))
    {   system("cls");
        window(3,90,9,36);
        gotoxy(20,16);printf("ENTER DETAILS OF THE CUSTOMER TO BE ADDED: \n \n");
        gotoxy(20,18);printf("ENTER THE NAME OF THE CUSTOMER: ");
        gotoxy(20,22);printf("CUSTOMER NAME CAN NOT BEGIN WITH NUMERIC OF SPECIAL CHARACTER :/ \n");
    }
    else
        break;
    }
    customer_count++;
    customer_home();
}
void viewcustomer()
{
    system("cls");
    window(3,90,9,36);

    int i = 0,count = 0;
    gotoxy(25,16);printf("CUSTOMER ID \t    CUSTOMER NAME \t    CUSTOMER EXPENDITURE");
    gotoxy(20,18);printf("----------------------------------------- \n");
    int n=20;
    while(count!=customer_count)
    {
        if(cust[i].id != 0)
        {
            gotoxy(25,n);
            printf("%d \t ",cust[i].id);
            printf("\t \t%s \t",cust[i].name);
            printf("\t \t%.2f",cust[i].expenditure);
            count++;
        }
        i++;
        n++;
    }
    gotoxy(6,16);printf("CUSTOMER COUNT: %d",customer_count);
    getch();
    customer_home();
}
void editcustomer()
{
    system("cls");
    window(3,90,9,36);
    int id;
    gotoxy(20,18);printf("ENTER THE (4-DIGIT) ID OF THE CUSTOMER TO BE EDITED: ");
    scanf("%d",&id);
    if(cust[id-1001].id == 0)
    {
        system("cls");
        window(3,90,9,36);
        gotoxy(20,19);printf("CUSTOMER WITH GIVEN ID %d NOT EXIST! PRESS ANY KEY TO RETRY\n",id);
        editcustomer();
    }
    gotoxy(20,20);printf("CURRENT CUSTOMER NAME: %s",cust[id-1001].name);
    gotoxy(20,21);printf(" ENTER NEW NAME: ",cust[id-1001].name);
    scanf(" %[^\n]",cust[id-1001].name);
    gotoxy(20,23);printf("CUSTOMER NAME CHANGED TO '%s' \n",cust[id-1001].name);
    getch();
    customer_home();
}
void deletecustomer()
{
    system("cls");
    window(3,90,9,36);
    int id;
    gotoxy(20,18);printf("ENTER THE ID OF THE CUSTOMER TO BE DELETED: ");
    scanf("%d",&id);
    if(cust[id-1001].id == 0)
    {
        system("cls");
        window(3,90,9,36);
        gotoxy(20,20);printf("CUSTOMER WITH GIVEN ID %d NOT EXIST! \n",id);
        deletecustomer();
    }
    gotoxy(20,22);printf("CUSTOMER NAMED %s DELETED!",cust[id-1001].name);
    cust[id-1001].id = 0;
    customer_count--;
    getch();
    customer_home();
}

//REVENUE MENU
void revenue_home()
{   char ch;
    int i;

     const char *menu[]={"   OPTIONS:","   STORE REVENUE","    BACK"};


        system("cls");
 window(3,90,9,36);
 gotoxy(27,14);printf("***REVENUE MENU***");
 for (i=0;i<=2;i++){
 gotoxy(30,15+i+1);printf("%s\n\n\n",menu[i]);}
 cursor(4);
}
void store_revenue()
 {   system("cls");
    window(3,90,9,36);
     int proceed = 0;
     while(proceed !=1)
     {
                     system("cls");
                     window(3,90,9,36);
                     proceed = 1;
                     gotoxy(6,18);printf("TOTAL NUMBER OF PRODUCTS: %d \n",product_count);
                     gotoxy(6,20);printf("TOTAL NUMBER OF CUSTOMERS: %d \n",customer_count);
                     gotoxy(6,22);printf("TOTAL NUMBER OF BILLS: %d \n",bill_count);
                     gotoxy(6,24);printf("TOTAL INCOME: %.2f \n",income);
                     gotoxy(6,26);printf("PRESS ANY KEY TO CONTINUE...");
                     getch();
                     revenue_home();
                     break;

         }
     }


//LOCATERS
int locate_product(struct product pd[])
{
    int i = 0;
    while(1)
    {
        if(pd[i].id == 0)
        {
            return i;
        }
        i++;
    }
}

int locate_customer(struct customer cust[])
{
    int i = 0;
    while(1)
    {
        if(cust[i].id == 0)
        {
            return i;
        }
        i++;
    }
}

int locate_bill(struct bill bl[])
{
    int i = 0;
    while(1)
    {
        if(bl[i].id == 0)
        {
            return i;
        }
        i++;
    }
}

/*int locate_employee(struct employee emp[])
{
    int i = 0;
    while(1)
    {
        if(emp[i].id == 0)
        {
            return i;
        }
        i++;
    }
}*/
