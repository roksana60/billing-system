#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct items{
    char item[40];
    float price;
    int quantity;
};

struct orders{
    char customer[60];
    char date[50];
    int numOfItems;
    struct items itm[50];
};

void billHeader(char name [50], char date [40]){
    printf("\n\n");
        printf("\t      Mimi's Cuisine");
        printf("\n\t    ------------------");
        printf("\nDate:%s", date);
        printf("\nInvoice To: %s", name);
        printf("\n");
        printf("---------------------------------------------\n");
        printf("Items\t\t");
        printf("Quantity\t\t");
        printf("Total\t\t");
        printf("\n---------------------------------------------");
        printf("\n");
}
void billBody(char item[50], int quantity, float price){
    printf("%s\t\t", item);
        printf("%d\t\t", quantity);
        printf("%.2f\t\t", quantity*price);
        printf("\n\n");
}



void billFooter(float total){
   printf("\n\n");
   float dis = 0.1*total;
   float netTotal = total-dis;
   float cgst=0.09*netTotal, grandTotal=netTotal+2*cgst;
   printf("---------------------------------------\n");
   printf("Sub Total");
   printf("\nDiscount @10%s\t\t\t%.2f", "%", dis);
   printf("\n\t\t\t\t-------");
   printf("\nNet Total\t\t\t%.2f", netTotal);
   printf("\nCGST @9%s\t\t\t%.2f", "%", cgst);
   printf("\nSGST @9%s\t\t\t%.2f", "%", cgst);
   printf("\n---------------------------------------");
   printf("\nGrand Total\t\t\t%.2f", grandTotal);
   printf("\n---------------------------------------\n");
}
int main(){
    float total;
    int opt, n;
    struct orders ord;
    struct orders order;
    char saveBill = 'k';
    FILE *fp;

    printf("\t========Mimi's Cuisine========");
    printf("\n\nPlease Select One: ");
    printf("\n\n\n1. Make Invoice");
    printf("\n2. Show All Invoices");
    printf("\n3. Exit");
    

    printf("\nYour Choice: \t");
    scanf("%d", &opt);
    fgetc(stdin);
    switch (opt){
        case 1:
        system("clear");
        printf("\nEnter Customer Name:\t");
        fgets(ord.customer, 50, stdin);
        ord.customer[strlen(ord.customer)-1]=0;
        strcpy(ord.date,__DATE__);
        printf("\nEnter the number of the Items:\t");
        scanf("%d",&n);
        ord.numOfItems=n;
        for(int i=0;i<n; i++){
            fgetc(stdin);
            printf("\n\n");
            printf("\nPlease Enter the item %d:\t", i+1);
            fgets(ord.itm[i].item,40,stdin);
            ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
            printf("Enter the quantity:\t");
            scanf("%d",&ord.itm[i].quantity);
            printf("Please Enter the unit Price:\t");
            scanf("%f",&ord.itm[i].price);
            total += ord.itm[i].quantity * ord.itm[i].price;
        }

        billHeader(ord.customer, ord.date);
        for(int i=0; i<ord.numOfItems;i++){
           billBody(ord.itm[i].item, ord.itm[i].quantity, ord.itm[i].price); 
        }
        billFooter(total);

        printf("\nDo you want to save the invoice [y/n]:\t");
        scanf("%s", &saveBill);

        if(saveBill == 'k'){
            fp=fopen("rBill.dat", "a+");
            fwrite(&ord, sizeof(struct orders), 1, fp);
            if(fwrite!=0)
            printf("\nSaved Successfully!");
            else 
                printf("\nError Saving Bill!");
                fclose(fp);
        }
        break;

        case 2:
        system("clear");
        fp=fopen("rBill.dot", "r");
        printf("\n    *****Your Invoices*****\n");
        while(fread(&order, sizeof(struct orders),1,fp)){
            float tot=0;
         billHeader(order.customer,order.date);
         for(int i=0; i<order.numOfItems;i++){
           billBody(order.itm[i].item, order.itm[i].quantity, order.itm[i].price);
            tot=+order.itm[i].quantity * order.itm[i].price;
         } 
        billFooter(tot);
        }
        fclose(fp);
        break;

        case 3:
        printf("\n\t\t Bye Bye! System Closing.");
        exit(0);
        break;

        default:
        printf("Sorry, invalid option!");
        break;
    
    }
  
    printf("\n\n");

    return 0;
}