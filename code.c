#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct node
{
    struct node *prev;
    char name[MAX];
    char email_id[MAX];
    char number[MAX];
    struct node *next;
}node;
 
 node *addContact(node *head,char *name, char *number,char *email_id)
 {
    node* temp = malloc(sizeof(node));
    if(head == NULL)
    {
        temp->prev = NULL;
        temp->next = NULL;
        strcpy(temp->name,name);
        strcpy(temp->email_id,email_id);
        strcpy(temp->number,number);
        head = temp;
    }
    else{
        node *ptr = head;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        temp->prev = ptr;
        temp->next = NULL;
        ptr->next = temp;
        strcpy(temp->name,name);
        strcpy(temp->email_id,email_id);
        strcpy(temp->number,number);
    }
    return head;
 }
 void display(node *head)
 {
     node *ptr = head;
     while(ptr != NULL)
     {
         printf("\nName       : %s",ptr->name);
         printf("Mobile no. : %s",ptr->number);
         printf("Email id   : %s",ptr->email_id);
         ptr = ptr->next;
     }
 }
 void main()
 {
     node *head = NULL;
     char name[MAX];
     char number[MAX];
     char email_id[MAX];
     int choice;
     printf("---------MY PHONEBOOK---------");
     printf("\n\n MAIN MENU\n\n");
     do
    {
         printf("\n1. Add new contact      --enter 1");
         printf("\n2. Update contact       --enter 2");
         printf("\n3. Delete contact       --enter 3");
         printf("\n4. Display all contacts --enter 4");
         printf("\n5. Search               --enter 5");
         printf("\nExit applictaion       --enter 0");
         printf("\nEnter a choice : ");
         scanf("%d",&choice);
         getchar();
         switch(choice)
    {
        case 1 :
        {
            printf("Enter the name :");
            fgets(name,MAX,stdin);
            printf("Enter the mobile number : ");
            fgets(number,MAX,stdin);
            printf("Enter email id : ");
            fgets(email_id,MAX,stdin);
            head = addContact(head,name,number,email_id);
            break;
        }
        case 4:
        {
            display(head);
            break;
        }
    }
         
    }while(choice != 0);
}
     
