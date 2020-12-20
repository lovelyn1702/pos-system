#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"

//using struct to initialize the username
struct name
{
    char user[15];
};

//globally declaring the void transact
void transact();

int main()
{
    char pin[12];

    //calling the struct
    struct name *userPtr, user1;
    userPtr = &user1;

    //printing and scanning the stored name and pin
    printf("\t\t\t\t\tENTER YOUR NAME: ");
    scanf("%s", &userPtr->user);
    printf("\t\t\t\t\tENTER YOUR PIN: ");
    scanf("%s",&pin);

    //using if-else for the PIN and string compare funtion to check if the given PIN matches to the user's
        if(strcmp(pin,"1234")==0)
        {
            printf("\n\t\t\t\t\tLOGIN SUCCESSFUL!\n");

            //calling the function void transact
            transact();
        }
        else
        {
            printf("\n\t\t\t\t\tINVALID PIN!\n");
        }
    }

void transact()
{
    //creating a text file for the receipt
    FILE *fptr;
    fptr = fopen("Lovelyn.txt", "a");

	int choice;

    //printing the headline
    printf("\n\t\t\t\t\t======== WELCOME TO BURGERHEADS! ========");
    printf("\n");

    //using the do-while loop for transactions
	do {

        //using array to store multiple values to the variables
		char product[15][100] = {"NONE", "QUARTER POUNDER", "DOUBLE PATTY", "TRIPLE DECKER", "ORIGINAL FRIES", "FLAVORED FRIES", "OVERDRIVE", "F-LOADED HOTDOG", "MEATY HOTDOG", "CHEESY HOTDOG", "NACHO BEEF", "NACHO FINAL SET", "LEMONADE", "MINERAL WATER", "MOUNTAIN DEW"};
		float price[15] = {0, 65.00, 95.00, 155.00, 50.00, 60.00, 75.00, 75.00, 65.00, 50.00, 65.00, 75.00, 25.00, 20.00, 25.00}, cash, change, total;
		char addons[12][100] = {"NONE", "BACON", "EGG", "NACHO", "FRIES", "CHILI", "SPAM", "CHEESE", "VEGGIES", "ONION", "SAUCE"};
		float addprice [12] = {0.00, 25.00, 20.00, 25.00, 25.00, 25.00, 25.00, 15.00, 25.00, 10.00, 15.00};

        int code, prodadd, quant;

		printf("\n\t\t\t\t\tCODE\tPRODUCT NAME\t\tPRICE");

		//using the for loop to show the menu board
		for (int i = 1; i < 15; i++) {
			printf("\n\t\t\t\t\t%d\t%s\t\tP %.2f", i, product[i], price[i]);
		}

		//printing and scanning the stored code
        printf("\n\n\t\t\t\t\tENTER PRODUCT CODE: ");
		scanf("%d", &code);

		//printing and scanning the stored quantity
        printf("\n\t\t\t\t\tPRODUCT NAME: %s", product[code]);
		printf("\n\t\t\t\t\tPRODUCT PRICE: P %.2f\n", price[code]);
        printf("\n\t\t\t\t\tENTER QUANTITY: ");
		scanf("%d", &quant);

		//declaring values from the function.h
        float num1=quant, num2=price[code], subtotal;

        //expression to get the subtotal
        subtotal = sub (num1, num2);

        printf("\n\t\t\t\t\tCODE\tADD-ONS\t\t\tPRICE");

        //using the for loop to show the add-ons board
        for (int j = 1; j < 11; j++) {
            printf("\n\t\t\t\t\t%d\t%s\t\t\tP %.2f", j, addons[j], addprice[j]);
        }

        //printing and scanning the stored choice
        printf("\n\n\t\t\t\t\tENTER ADD-ON CODE: ");
        scanf("%d", &prodadd);

        //printing the name and price of the add-on
        printf("\n\t\t\t\t\tADD-ON NAME: %s", addons[prodadd]);
        printf("\n\t\t\t\t\tADD-ON PRICE: P %.2f\n", addprice[prodadd]);

        //expression to get the total
		total = subtotal + addprice[prodadd];

		do {

		printf("\n\t\t\t\t\tTOTAL AMOUNT: P %.2f\n", total);

		//printing and scanning stored cash
		printf("\n\t\t\t\t\tINPUT CASH: P ");
		scanf("%f", &cash);

			if (cash < total) {

				printf("\n\t\t\t\t\tINSUFFICIENT FUNDS!");

			}

		} while (cash < total);

                //expression to get change
				change = cash - total;

				//printing the change
				printf("\t\t\t\t\tCHANGE: P %.2f\n", change);

				//printing the pruchased items
				printf("\n\t\t\t\t\tYOU HAVE SUCCESSFULLY PURCHASED (%d) %s/s with %s ADD-ON!\n", quant, product[code], addons[prodadd]);

                //printing question for making another purchase
                printf("\n\t\t\t\t\tDO YOU WANT TO HAVE ANOTHER TRANSACTION? (1 = YES | 2 = NO): ");

                //scanning choice
                scanf("%d", &choice);

    //printing thw contents of the receipt
    fprintf(fptr, "=================== BURGERHEADS ===================\n");
    fprintf(fptr, "\n1 KESSING ST, COR E 6th St, Olongapo, 2200 Zambales\n");
    fprintf(fptr, "\n================= OFFICIAL RECEIPT ================\n");
    fprintf(fptr, "\tQTY\tPRODUCT\t\t\tPRICE\n");
    fprintf(fptr, "----------------------------------------------------\n");
    fprintf(fptr, "\t%d\t%s\t\tP %.2f\n\t\t\t\t\t----------\n", quant, product[code], subtotal);
    fprintf(fptr, "\t\t\t      SUBTOTAL: P %.2f\n\t\t\t\tADD-ON: P %.2f\n\t\t\t\t\t----------\n\t\t\t\t TOTAL: P %.2f\n\t\t\t\t  CASH: P %.2f\n\t\t\t\t\t----------\n\t\t\t\tCHANGE: P %.2f", subtotal, addprice[prodadd], total, cash, change);
    fprintf(fptr, "\n\n====================================================");
    fprintf(fptr, "\n  THIS INVOICE/RECEIPT SHALL BE VALID FOR FIVE (5) \n\tYEARS FROM THE DATE OF PERMIT TO USE");
    fprintf(fptr, "\n====================================================\n\n");

    //closing the receipt
    fclose(fptr);

	}

	while (choice != 2);

}

//function definition
float subtotal (int a, int b)
{
    int result;
    result = a * b;
    return result; //returning value
}
