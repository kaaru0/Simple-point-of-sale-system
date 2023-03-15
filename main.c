#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>


// DISPLAY MENU FUNCTION

//HEADER
void header() {
    printf("============================================================================================================\n");
    printf("    		    \t\t	 Welcome to CJ's Cafe\n");
    printf("============================================================================================================\n");
}

//MENU DISPLAY
void menu_actual () {
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("|						MENU						           |\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("ORDER CODE   SOUPS		     PRICE		ORDER CODE    HOT BEVERAGES	  M(12oz)  L(16oz) \n");
    printf("   001 	     Wild Mushroom Soup	     130\t\t   100 	      Americano		  100  	   120\n" );
    printf("   002       Clam Chowder	     150     \t\t   101        Cafe Mocha          110      130\n");
    printf("			               \t\t\t   102        Cappucino		  110      130\n");
    printf("	     SANDWICHES              PRICE	           103        Caramel Macchiato   140      160  \n");
    printf("   003       Chicken Ceasar Wrap     180    		   104        Espresso 		  100      120	\n");
    printf("   004       Buffalo Chicken Wrap    180		   105        Latte	           90      110\n");
    printf("   005       Four Cheese Panini      200		   106        Hot Milk 		   80      100\n");
    printf("   006       Tuna Melt Sandwich      150\n");
    printf("   007       Ham & Turkey Sandwich   150		 	      COLD BEVERAGES	  M(12oz)  L(16oz)\n");
    printf("                                                           107        Oreo Frappe         140      160\n");
    printf("	     PASTRIES	             PRICE                 108        Matcha Tea          150      170    \n");
    printf("   200       Crossiant               130                   109        Citrus Tea          150      170\n");
    printf("   201       Pecan Tart              150\n");
    printf("   202       Red Velvet Cupcake      170\n");
    printf("   203       Cranberry Whoopie Pie   190\n");
    printf("\n");

}

void displaymenu () {
    header();
    printf("\n");
    printf("Today's Menu\n");
    menu_actual();
    printf("Press Any Key for Options......");
    getch();
    system("cls");
    displayopt();
}

//DISPLAY OPTIONS
int displayopt () {
    int opt;
    header();
    printf("\n\n\n");
    printf("\t\t\t\t-----------------------------------------\n");
    printf("\t\t\t\t||\t\tMAIN MENU\t       ||\n");
    printf("\t\t\t\t-----------------------------------------\n");
    printf("\t\t\t\t||                                     ||\n");
    printf("\t\t\t\t||   Enter [1] to go back to the MENU  ||\n");
    printf("\t\t\t\t||   Enter [2] to take order           ||\n");
    printf("\t\t\t\t||   Enter [3] to change user          ||\n");
    printf("\t\t\t\t||                                     ||\n");
    printf("\t\t\t\t-----------------------------------------\n");
    printf("\n\n\t\t\t\t     What would you like to do?: ");
    scanf("%d", &opt);
    if(opt == 1) {
        system("cls");
        displaymenu();
    }
    else if (opt==2) {
        system("cls");
        char dm;
        printf("\n\n\n\n\n\n\n\t\t\tWould you like to display menu while taking order? [Y/N]: ");
        scanf("%s" , &dm);
        if(dm == 'Y'|| dm == 'y'){
            system("cls");
            header();
            menu_actual();
            printf("-----------------------------------------------------------------------------------------------------------\n");
            takeorder();
        }
        else if (dm == 'N' || dm == 'n'){
            system("cls");
            header();
            takeorder();
        }
    }
    else if (opt==3) {
        main();
        return 0;
    }
    else {
        printf("\t\t\t\t     Please Enter a valid input! ");
        printf("Press any key to continue....");
        getch();
        system("cls");
        displayopt();
    }

} //end of display options function

//TAKE MONEY FUNCTION START
take_money(float ttax){
    float pay, change, less;
    int exit;
    printf("\n\t\tPlease enter payment: ");
    scanf("%f" , &pay);
    change = pay - ttax;
    less = ttax - pay;
    if( pay>ttax) {
        printf("\n\t\tReceived %.2f\n" , pay );
        printf("\t\tChange = %.2f\n" , change);

    }
    else if (pay == ttax) {
        printf("\t\tReceived exact payment\n");
    }
    else if(ttax > pay){
        printf("\t\tYou are %.2f short, please try again:" , less);
        take_money(ttax);
    }

    printf("\n\t\tEnter [1] to confirm sale\n\t\t...or [2] to cancel order and go back to MENU: ");
    scanf("%d" , &exit);

    if(exit == 1) {
        printf("\n\t\t");
        printf("Transaction received!");
        printf("\n\t\tPress any key to continue...");
        getch();
        system("cls");
        displayopt();
    }
    else if(exit == 2){
        system("cls");
        displayopt();
    }
    else {
        printf("\t\tPlease input a valid option");
        take_money(ttax);

    }

} //end of take_money function

//DISCOUNTS FUNCTION START
discount(float total_tax) {
    int disc_opt, x,senior_id,pwd_id;
    char giftcode[10];
    /* gift card codes: 776-GMW-942 - 30% off
                        552-WND-255 - 50% off
    */
    printf("\n\n\n\t\tCheck for customer discounts:\n\t\t 0 - None\n\t\t 1 - Student");
    printf("\n\t\t 2 - Senior Citizen");
    printf("\n\t\t 3 - PWD");
    printf("\n\t\t 4 - CJ cafe gift card");
    printf("\n\t\t Enter [5] to cancel order\n");
    x = 1;
    do {
        printf("\t\t Enter discount option no. [Enter 0 if none]: ");
        scanf("%d" , &disc_opt);
        x = 1;
        if(disc_opt == 0) {
            printf("\t\t--------------------------------");
            printf("\n\t\t   Your total is %.2f php\n" , total_tax);
            printf("\t\t--------------------------------\n");
            take_money(total_tax);
            x = 0 ; //TO BREAK OUT OF DO WHILE LOOP
        }

        else if(disc_opt == 1) {
            total_tax = total_tax - total_tax*.05;
            printf("\t\t\tTotal = %.2f (5 precent off)" , total_tax);
            x = 1;
            printf("\n\t\t Other discounts\n");
        }

        else if(disc_opt == 2) {
            total_tax = total_tax - total_tax*.2;
            printf("\t\t\tTotal = %.2f (20 percent off)" , total_tax);
            x = 1;
            printf("\n\t\t Other discounts\n");
        }

        else if(disc_opt == 3) {
            total_tax = total_tax - total_tax*.2;
            printf("\t\t\tTotal = %.2f (20 percent off)" , total_tax);
            x = 1;
            printf("\n\t\t Other discounts\n");
        }
        else if(disc_opt == 4) {
            /* DISCOUNTS:
                        776-GMW-942 - 30% OFF
                        552-WND-255 - 50% OFF
            */
            printf("\t\t\tPlease enter gift card code:");
            scanf("%s" , &giftcode);
            if(strcmp(giftcode , "776-GMW-942") == 0){
                total_tax = total_tax - total_tax*.3;
                printf("\t\t\tCode has been redeemed!\n\t\t\t30 percent off on order\n\t\t\tTotal = %.2f" , total_tax);
                x = 1;
            }
            else if(strcmp(giftcode, "552-WND-255") == 0) {
                total_tax = total_tax - total_tax*.5;
                printf("\t\t\tCode has been redeemed!\n\t\t\t50 percent off on order\n\t\t\tTotal is %.2f" , total_tax);
                x = 1;
            }
            else {
                printf("\t\t\tInvalid code, please try again.");
                x = 1;
            }
            printf("\n\t\t Other discounts\n");
        }
        else if(disc_opt == 5) {
            system("cls");
            displayopt();
        }
    }//DO END
    while(x==1); // WILL CONTINUE TO ASK DISCOOUNT AS LONG AS X = 1
}
//DISCOUNT FUNCTION END

//TAKEORDER AND RECEIPT FUNCTION START
int takeorder() {
    int qty[21];
    int total;
    float stotal,stax;
    int i,j,k;
    int ord[21];
    char *dro[21];
    char *orders_item[21];
    int orders_price[21];
    char yn;
    ord[0] = 130;
    dro[0] = "Wild Mushroom Soup    ";
    ord[1] = 150;
    dro[1] = "Clam Chowder          ";
    ord[2] = 180;
    dro[2] = "Chicken Caesar Wrap   ";
    ord[3] = 180;
    dro[3] = "Buffalo Chicken Wrap  ";
    ord[4] = 200;
    dro[4] = "Four Cheese Panini    ";
    ord[5] = 150;
    dro[5] = "Tuna Melt Sandwhich   ";
    ord[6] = 150;
    dro[6] = "Ham & Turkey Sandwich ";
    ord[7] = 130;
    dro[7] = "Crossiant             ";
    ord[8] = 150;
    dro[8] = "Pecan Tart            ";
    ord[9] = 170;
    dro[9] = "Red Velvet Cupcake    ";
    ord[10] = 190;
    dro[10] = "Cranberry Whoopie Pie";
    ord[11] = 100;
    dro[11] = "Americano            ";
    ord[12] = 110;
    dro[12] = "Cafe Mocha           ";
    ord[13] = 110;
    dro[13] = "Cappucino            ";
    ord[14] = 140;
    dro[14] = "Caramel Macchiato    ";
    ord[15] = 100;
    dro[15] = "Espresso             ";
    ord[16] = 90;
    dro[16] = "Latte                ";
    ord[17] = 80;
    dro[17] = "Hot Milk             ";
    ord[18] = 140;
    dro[18] = "Oreo Frappe          ";
    ord[19] = 150;
    dro[19] = "Matcha Tea           ";
    ord[20] = 150;
    dro[20] = "Citrus Tea           ";
    total = 0;
    j = 1;
    printf("Enter [0] to go back to MAIN MENU\n");
    while(j==1){
        for(i=0;i<=21;i++) {
            printf("Enter Order code: ");
            scanf("%d",&ord[21]);
            if (ord[21]==001) {
                printf("QTY: ");
                scanf("%d",&qty[i]);
                total = total + ord[0]*qty[i];
                printf("(%d) %s" ,qty[i],dro[0]);
                printf("\nTotal = %d php\n",total);
                orders_item[i] = dro[0];
                orders_price[i+1] = ord[0];


            }
            else if (ord[21]==002){
                printf("QTY: ");
                scanf("%d",&qty[i]);
                total = total + ord[1]*qty[i];
                printf("(%d) %s" ,qty[i], dro[1]);
                printf("\nTotal = %d php\n",total);
                orders_item[i] = dro[1];
                orders_price[i+1] = ord[1];

            }
            else if (ord[21]==003) {
                printf("QTY: ");
                scanf("%d",&qty[i]);
                total = total + ord[2]*qty[i];
                printf("(%d) %s" ,qty[i], dro[2]);
                printf("\nTotal = %d php\n",total);
                orders_item[i] = dro[2];
                orders_price[i+1] = ord[2];

            }

            else if (ord[21]==004) {
                printf("QTY: ");
                scanf("%d",&qty[i]);
                total = total + ord[3]*qty[i];
                printf("(%d) %s" ,qty[i], dro[3]);
                printf("\nTotal = %d php\n",total);
                orders_item[i] = dro[3];
                orders_price[i+1] = ord[3];
            }
            else if (ord[21]==005) {
                printf("QTY: ");
                scanf("%d",&qty[i]);
                total = total + ord[4]*qty[i];
                printf("(%d) %s" ,qty[i], dro[4]);
                printf("\nTotal = %d php\n",total);
                orders_item[i] = dro[4];
                orders_price[i+1] = ord[4];
            }
            else if (ord[21]==006) {
                printf("QTY: ");
                scanf("%d",&qty[i]);
                total = total + ord[5]*qty[i];
                printf("(%d) %s" ,qty[i], dro[5]);
                printf("\nTotal = %d php\n",total);
                orders_item[i] = dro[5];
                orders_price[i+1] = ord[5];
            }
            else if (ord[21]==007) {
                printf("QTY: ");
                scanf("%d",&qty[i]);
                total = total + ord[6]*qty[i];
                printf("(%d) %s" ,qty[i], dro[6]);
                printf("\nTotal = %d php\n",total);
                orders_item[i] = dro[6];
                orders_price[i+1] = ord[6];
            }
            else if (ord[21]==200) {
                printf("QTY: ");
                scanf("%d",&qty[i]);
                total = total + ord[7]*qty[i];
                printf("(%d) %s" ,qty[i], dro[7]);
                printf("\nTotal = %d php\n",total);
                orders_item[i] = dro[7];
                orders_price[i+1] = ord[7];
            }
            else if (ord[21]==201) {
                printf("QTY: ");
                scanf("%d",&qty[i]);
                total = total + ord[8]*qty[i];
                printf("(%d) %s" ,qty[i], dro[8]);
                printf("\nTotal = %d php\n",total);
                orders_item[i] = dro[8];
                orders_price[i+1] = ord[8];
            }
            else if (ord[21]==202) {
                printf("QTY: ");
                scanf("%d",&qty[i]);
                total = total + ord[9]*qty[i];
                printf("(%d) %s" ,qty[i], dro[9]);
                printf("\nTotal = %d php\n",total);
                orders_item[i] = dro[9];
                orders_price[i+1] = ord[9];
            }
            else if (ord[21]==203) {
                printf("QTY: ");
                scanf("%d",&qty[i]);
                total = total + ord[10]*qty[i];
                printf("(%d) %s" ,qty[i], dro[10]);
                printf("\nTotal = %d php\n",total);
                orders_item[i] = dro[10];
                orders_price[i+1] = ord[10];
            }

            else if (ord[21]==100) {
                char size;
                printf("Size [L or M]: ");
                scanf("%s" , &size);
                if(size == 'M'||size == 'm'){
                    printf("QTY: ");
                    scanf("%d",&qty[i]);
                    total = total + ord[11]*qty[i];
                    printf("(%d) %s" ,qty[i], dro[11]);
                    printf("\nTotal = %d php\n",total);
                    orders_item[i] = dro[11];
                    orders_price[i+1] = ord[11];
                }
                else if(size == 'L' || size == 'l'){
                    printf("QTY: ");
                    scanf("%d",&qty[i]);
                    total = total + ord[11]*qty[i] + + 20*qty[i];
                    printf("(%d) %s" ,qty[i], dro[11]);
                    printf("\nTotal = %d php\n",total);
                    orders_item[i] = dro[11];
                    orders_price[i+1] = ord[11] + 20;
                }
                else{
                    printf("invalid input");
                }
            }
            else if (ord[21]==101) {
                char size;
                printf("Size [L or M]: ");
                scanf("%s" , &size);
                if(size == 'M'||size == 'm'){
                    printf("QTY: ");
                    scanf("%d",&qty[i]);
                    total = total + ord[12]*qty[i];
                    printf("(%d) %s" ,qty[i], dro[12]);
                    printf("\nTotal = %d php\n",total);
                    orders_item[i] = dro[12];
                    orders_price[i+1] = ord[12];
                }
                else if(size == 'L' || size == 'l'){
                    printf("QTY: ");
                    scanf("%d",&qty[i]);
                    total = total + ord[12]*qty[i] + 20*qty[i];
                    printf("(%d) %s" ,qty[i], dro[12]);
                    printf("\nTotal = %d php\n",total);
                    orders_item[i] = dro[12];
                    orders_price[i+1] = ord[12] + 20;
                }
                else{
                    printf("invalid input");
                }
            }
            else if (ord[21]==102) {
                char size;
                printf("Size [L or M]: ");
                scanf("%s" , &size);
                if(size == 'M'||size == 'm'){
                    printf("QTY: ");
                    scanf("%d",&qty[i]);
                    total = total + ord[13]*qty[i];
                    printf("(%d) %s" ,qty[i], dro[13]);
                    printf("\nTotal = %d php\n",total);
                    orders_item[i] = dro[13];
                    orders_price[i+1] = ord[13];
                }
                else if(size == 'L' || size == 'l'){
                    printf("QTY: ");
                    scanf("%d",&qty[i]);
                    total = total + (ord[13]+20)*qty[i];
                    printf("(%d) %s" ,qty[i], dro[13]);
                    printf("\nTotal = %d php\n",total);
                    orders_item[i] = dro[13];
                    orders_price[i+1] = ord[13] + 20;
                }
                else{
                    printf("invalid input");
                }
            }

            else if (ord[21]==103) {
                char size;
                printf("Size [L or M]: ");
                scanf("%s" , &size);
                if(size == 'M'||size == 'm'){
                    printf("QTY: ");
                    scanf("%d",&qty[i]);
                    total = total + ord[14]*qty[i];
                    printf("(%d) %s" ,qty[i], dro[14]);
                    printf("\nTotal = %d php\n",total);
                    orders_item[i] = dro[14];
                    orders_price[i+1] = ord[14];
                }
                else if(size == 'L' || size == 'l'){
                    printf("QTY: ");
                    scanf("%d",&qty[i]);
                    total = total + (ord[14]+20)*qty[i];
                    printf("(%d) %s" ,qty[i], dro[14]);
                    printf("\nTotal = %d php\n",total);
                    orders_item[i] = dro[14];
                    orders_price[i+1] = ord[14] + 20;
                }
                else{
                    printf("invalid input");
                }
            }

            else if (ord[21]==104) {
                char size;
                printf("Size [L or M]: ");
                scanf("%s" , &size);
                if(size == 'M'||size == 'm'){
                    printf("QTY: ");
                    scanf("%d",&qty[i]);
                    total = total + ord[15]*qty[i];
                    printf("(%d) %s" ,qty[i], dro[15]);
                    printf("\nTotal = %d php\n",total);
                    orders_item[i] = dro[15];
                    orders_price[i+1] = ord[15];
                }
                else if(size == 'L' || size == 'l'){
                    printf("QTY: ");
                    scanf("%d",&qty[i]);
                    total = total + (ord[15]+20)*qty[i];
                    printf("(%d) %s" ,qty[i], dro[15]);
                    printf("\nTotal = %d php\n",total);
                    orders_item[i] = dro[15];
                    orders_price[i+1] = ord[15] + 20;
                }
                else{
                    printf("invalid input");
                }
            }
            else if (ord[21]==105) {
                char size;
                printf("Size [L or M]: ");
                scanf("%s" , &size);
                if(size == 'M'||size == 'm'){
                    printf("QTY: ");
                    scanf("%d",&qty[i]);
                    total = total + ord[16]*qty[i];
                    printf("(%d) %s" ,qty[i], dro[16]);
                    printf("\nTotal = %d php\n",total);
                    orders_item[i] = dro[16];
                    orders_price[i+1] = ord[16];
                }
                else if(size == 'L' || size == 'l'){
                    printf("QTY: ");
                    scanf("%d",&qty[i]);
                    total = total + (ord[16]+20)*qty[i];
                    printf("(%d) %s" ,qty[i], dro[16]);
                    printf("\nTotal = %d php\n",total);
                    orders_item[i] = dro[16];
                    orders_price[i+1] = ord[16] + 20;
                }
                else{
                    printf("invalid input");
                }
            }
            else if (ord[21]==106) {
                char size;
                printf("Size [L or M]: ");
                scanf("%s" , &size);
                if(size == 'M'||size == 'm'){
                    printf("QTY: ");
                    scanf("%d",&qty[i]);
                    total = total + ord[17]*qty[i];
                    printf("(%d) %s" ,qty[i], dro[17]);
                    printf("\nTotal = %d php\n",total);
                    orders_item[i] = dro[17];
                    orders_price[i+1] = ord[17];
                }
                else if(size == 'L' || size == 'l'){
                    printf("QTY: ");
                    scanf("%d",&qty[i]);
                    total = total + (ord[17]+20)*qty[i];
                    printf("(%d) %s" ,qty[i], dro[17]);
                    printf("\nTotal = %d php\n",total);
                    orders_item[i] = dro[17];
                    orders_price[i+1] = ord[17] + 20;
                }
                else{
                    printf("invalid input");
                }
            }
            else if (ord[21]==107) {
                char size;
                printf("Size [L or M]: ");
                scanf("%s" , &size);
                if(size == 'M'||size == 'm'){
                    printf("QTY: ");
                    scanf("%d",&qty[i]);
                    total = total + ord[18]*qty[i];
                    printf("(%d) %s" ,qty[i], dro[18]);
                    printf("\nTotal = %d php\n",total);
                    orders_item[i] = dro[18];
                    orders_price[i+1] = ord[18];
                }
                else if(size == 'L' || size == 'l'){
                    printf("QTY: ");
                    scanf("%d",&qty[i]);
                    total = total + (ord[18]+20)*qty[i];
                    printf("(%d) %s" ,qty[i], dro[18]);
                    printf("\nTotal = %d php\n",total);
                    orders_item[i] = dro[18];
                    orders_price[i+1] = ord[18] + 20;
                }
                else{
                    printf("invalid input");
                }
            }
            else if (ord[21]==108) {
                char size;
                printf("Size [L or M]: ");
                scanf("%s" , &size);
                if(size == 'M'||size == 'm'){
                    printf("QTY: ");
                    scanf("%d",&qty[i]);
                    total = total + ord[19]*qty[i];
                    printf("(%d) %s" ,qty[i], dro[19]);
                    printf("\nTotal = %d php\n",total);
                    orders_item[i] = dro[19];
                    orders_price[i+1] = ord[19];
                }
                else if(size == 'L' || size == 'l'){
                    printf("QTY: ");
                    scanf("%d",&qty[i]);
                    total = total + (ord[19]+20)*qty[i];
                    printf("(%d) %s" ,qty[i], dro[19]);
                    printf("\nTotal = %d php\n",total);
                    orders_item[i] = dro[19];
                    orders_price[i+1] = ord[19] + 20;
                }
                else{
                    printf("invalid input");
                }
            }
            else if (ord[21]==109) {
                char size;
                printf("Size [L or M]: ");
                scanf("%s" , &size);
                if(size == 'M'||size == 'm'){
                    printf("QTY: ");
                    scanf("%d",&qty[i]);
                    total = total + ord[20]*qty[i];
                    printf("(%d) %s" ,qty[i], dro[20]);
                    printf("\nTotal = %d php\n",total);
                    orders_item[i] = dro[20];
                    orders_price[i+1] = ord[20];
                }
                else if(size == 'L' || size == 'l'){
                    printf("QTY: ");
                    scanf("%d",&qty[i]);
                    total = total + (ord[20]+20)*qty[i];
                    printf("(%d) %s" ,qty[i], dro[20]);
                    printf("\nTotal = %d php\n",total);
                    orders_item[i] = dro[20];
                    orders_price[i+1] = ord[20] + 20;
                }
                else{
                    printf("invalid input");
                }
            }
            else if(ord[21]==0) {
                system("cls");
                displayopt();
                /*menu_actual();
                printf("Press any key to order...");
                getch();*/
                i = i - 1;
            }

            else {
                printf("That is not a valid input! Please enter your order again.\n");
                printf("Press any key to continue...");
                getch();
                system("cls");
                header();
                menu_actual();
                takeorder();
            }

            printf("\nAdd another item? [Y/N]: ");
            scanf("%s",&yn);

            if(yn == 'Y' || yn == 'y') {
                j = 1;
            }
            else if (yn == 'N' || yn == 'n') {
                i = i + 22; //to break out of for loop
                j = 0; //to break out of while loop

            }
            else {
                printf("Please enter a valid input\n");
            }
        } // for end
    } // while end
    i = i - 22; // i now represents the number of items ordered (reverses the effect of inputting N in "Add another item? [Y/N]" to break out of loop)
    system("cls");
    header();
    printf("\n\n\n\t\t\t\tCONFIRM ORDER\n\t\t\t\t%d item/s:\n",i);
    for(k=0;k<i;k++) {
        printf("\t\t\t\t    %d. %dx %s\n", (k+1) , qty[k], orders_item[k]);
    }

    int opt2;
    printf("\n\n\t\t        ---------------------------------------------------------");
    printf("\n\t\t\t||  Press [1] to return to MENU                        ||");
    printf("\n\t\t\t||                                                     ||");
    printf("\n\t\t\t||  Press [2] to confirm order and display receipt     ||");
    printf("\n\t\t        ---------------------------------------------------------");
    printf("\n\n\n\n\t\t\t\t   What would you like to do? ");
    scanf("%d",&opt2);
    if (opt2==1) {
        system("cls");
        displayopt();
    }
    else if(opt2 == 2){
        system("cls");
        printf("============================================================================================================\n");
        printf("    		    \t\t	 Welcome to CJ's Cafe\n");
        printf("============================================================================================================\n");
        printf("\n\n\t\t\t\t\t\tYour Receipt\n");
        printf("\t\t==========================================================================\n");
        printf("\t\t\tQTY\t\tITEM/S\t\tITEM PRICE\tAMOUNT\n");
        printf("\t\t==========================================================================\n");
        for(k=0;k<i;k++) {
            printf("\t\t\t%d\t%s\t   %d\t\t %d\n", qty[k], orders_item[k], orders_price[k+1],orders_price[k+1]*qty[k]);
        }
        stax = 0.1 * total;
        stotal = total + stax;
        printf("\t\t--------------------------------------------------------------------------");
        printf("\n\t\t\t\t\t\t\t          total: %d.00",total);
        printf("\n\t\t\t\t\t\t\t  Sales Tax 10%%: %.2f",stax);
        getchar();
        printf("\n\t\t\t\t\t\t\t       subtotal: %.2f",stotal);

        discount(stotal);
    }

} // takeorder function end


//Login code inside main function
main () {
    char un[20] ;
    char ch, pass[20];
    int i ,invalid;
    char *users[4];
    char *pw[4];
    //two arrays for password and username with four elements inside for three sets of usernames and passwords
    users[0] = "carlh_ong";
    pw[0] = "1234";
    users[1] = "jerrick_kho";
    pw[1] = "5678";
    users[2] = "CJhouse";
    pw[2] = "ilovecoffee";
    users[3] = "user";
    pw[3] = "pass";
    system("cls");
    invalid = 1;
    // while the variable "invalid" is equal to 1 (username/password not valid) the program will keep asking for login credentials
    while(invalid == 1) {
        header();
        printf("\n\n\t\t\t\t          EMPLOYEE LOG-IN ");
        printf("\n\t\t\t\t     ENTER USERNAME: ");
        scanf("%s" , &un);
        printf("\t\t\t\t     ENTER PASSWORD: ");
        // PASSWORD MASKING START

        do
        {
            pass[i]=getch();
            ch = pass[i];
            if(ch!=13 && ch!='\b') //print "*" if input is not backspace or enter (13 is ASCII value of return key)
            {
                printf("*");
                i++;
            }
            else if(ch=='\b' && i==0) //so it can only backspace until the first character typed
            {
                printf("");
            }
            else if(ch=='\b') //to make backspace work
            {
                printf("\b \b");
                pass[i-1]='\0';
                i--;
            }

        } while(ch!=13); //end when enter key is pressed (13 is ASCII value of return key)

        pass[i]='\0';

        // PASSWORD MASKING END

        if (strcmp(un , users[0]) == 0 && strcmp(pass , pw[0]) == 0) {
            invalid = 0;
            system("cls");
            displaymenu();

        }
        else if (strcmp(un , users[1]) == 0 && strcmp(pass , pw[1]) == 0) {
            invalid = 0;
            system("cls");
            displaymenu();
        }
        else if (strcmp(un , users[2]) == 0 && strcmp(pass , pw[2]) == 0) {
            invalid = 0;
            system("cls");
            displaymenu();
        }
        else if (strcmp(un , users[3]) == 0 && strcmp(pass , pw[3]) == 0) {
            invalid = 0;
            system("cls");
            displaymenu();
        }
        else{

            printf("\n\n\t\t\t\t     Access Denied. Invalid username and/or password!");
            invalid = 1;
            printf("\n\t\t\t\t     Press Any key to try again...");
            getch();
            main();
            return 0;
        }
    }//while loop end
}




