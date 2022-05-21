#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
    char *name[100];
    char bloodgroup[100];
    char *address[100];
    int age, phone, reg, priority;
    struct node *next;
};
struct node *start= NULL;
struct node *insert(struct node *);
int main(){
int opt;

do{
printf("\n\t\t\tWELCOME TO CITY HOSPITAL SERIAL ADMIN PORTAL!\t\t\t ");
printf("\n\nDOCTOR'S APPOINTMENT DASHBOARD\n");
printf("\n1. ADD A PATIENT DETAILS FOR THE APPOINTMENT\t\t\t ");
printf("\n2. DISPLAY ALL APPOINTMENTS\t\t\t ");
printf("\n3. EXIT\t\t\t ");
printf("\n\nEnter your choice:\t");
scanf("%d",&opt);

switch(opt)
{
case 1:
start= insert(start);
getchar();
system("cls");
break;
case 2:
display(start);
getchar();
system("cls");
break;
case 3:
exit(0);
break;
}
}while(opt!=3);
}

struct node *insert(struct node *start)
{
    int value2,value4,value6,prio;
    char value1,value3,value5;
    struct node *ptr,*p;
    char* name[100];
    char* address[100];
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter Patient's Name:");
    scanf(" %s",ptr-> name);
    printf("Enter the Patient's age:");
    scanf("%d",&value2);
    printf("Enter Patient's Address:");
    scanf(" %s",ptr->address);
    printf("Enter Patient's Contact number:");
    scanf("%d",&value4);
    printf("Blood Group of the patient:");
    scanf(" %s",ptr->bloodgroup);
    printf("Set a Registration Number:");
    scanf("%d",&value6);
    printf("\nSelect Disease Category from the list below:");
    table();
    scanf("%d",&prio);

    ptr->age=value2;
    ptr->phone=value4;
    ptr->reg=value6;
    ptr->priority=prio;

if((start==NULL)||prio<start->priority)
{
ptr->next=start;
start=ptr;
}
else
{
p=start;
while(p->next!=NULL && p->next->priority <=prio)
p=p->next;
ptr->next=p->next;
p->next=ptr;
}
return start;
};
void display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    if(start==NULL)
        printf("\n\t\tNo patient data to Display!");
    else
    {
        printf("\nPriority wise appointments are listed below:\n");
        while(ptr!=NULL)
        {
        printf("\nName of Patient: %s\n",ptr->name);
        printf("Registration Number: %d\n",ptr->reg);
        printf("Age: %d\n",ptr->age);
        printf("Address: %s\n",ptr->address);
        printf("Phone Number: %d\n",ptr->phone);
        printf("Blood Group: %s\n",ptr->bloodgroup);
        printf("............................\n");
            ptr=ptr->next;
        }
    }
getchar();
}
void table()
{
printf("\n\n\t\tSelect a category. *Serial will be generated automated based on your selection.*\n");
printf("\n1. Heart Diseases [Attack or Failure]\n");
printf("2. Serious wound\n");
printf("3. Cancer\n");
printf("4. Fractures\n");
printf("5. Chest Pain\n");
printf("6. Diabetes Patient\n");
printf("7. Infection Related Disease\n");
printf("8. Normal Fever\n");
printf("9. Cold or Head Ache\n");
}
