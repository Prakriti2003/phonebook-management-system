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

node* delete1(node *head,char *entered_name){
    node* ptr = head;
    node* temp = NULL;
    if(strcmp(head->name, entered_name) == 0){
        head = head->next;
        free(ptr);
        ptr = NULL;
        return head;
    }
    while(strcmp(ptr->name , entered_name) != 0){
        ptr = ptr -> next;
    }
    if(ptr -> next == NULL){
        ptr->prev->next = NULL;
        free(ptr);
        ptr = NULL;
    }
    else{
        temp = ptr->prev;
        temp->next = ptr->next;
        ptr->next->prev = temp;
        free(ptr);
        ptr = NULL;
    }
    return head;
};

node* delete2(node *head,char *entered_number){
    node* ptr = head;
    node* temp = NULL;
    if(strcmp(ptr -> number, entered_number)== 0){
        head = head->next;
        free(ptr);
        ptr = NULL;
        return head;
    }
    while(strcmp(ptr->number , entered_number) != 0){
        ptr = ptr -> next;
    }
    if(ptr -> next == NULL){
        ptr->prev->next = NULL;
        free(ptr);
        ptr = NULL;
    }
    else{
        temp = ptr->prev;
        temp->next = ptr->next;
        ptr->next->prev = temp;
        free(ptr);
        ptr = NULL;
    }
    return head;
};

node* delete3(node *head, char *entered_email_id){
    node* ptr = head;
    node* temp = NULL;
    if(strcmp(ptr -> email_id, entered_email_id) == 0){
        head = head->next;
        free(ptr);
        ptr = NULL;
        return head;
    }
    while(strcmp(ptr->email_id , entered_email_id) != 0){
        ptr = ptr -> next;
    }
    if(ptr -> next == NULL){
        ptr->prev->next = NULL;
        free(ptr);
        ptr = NULL;
    }
    else{
        temp = ptr->prev;
        temp->next = ptr->next;
        ptr->next->prev = temp;
        free(ptr);
        ptr = NULL;
    }
    return head;
};



void main(){
    node *head = NULL;
    char name[MAX];
    char number[MAX];
    char email_id[MAX];
    int choice;
    printf("---------MY PHONEBOOK---------");
    printf("\n\n MAIN MENU\n\n");
    do{
        printf("\n1. Add new contact      --enter 1");
        printf("\n2. Update contact       --enter 2");
        printf("\n3. Delete contact       --enter 3");
        printf("\n4. Display all contacts --enter 4");
        printf("\n5. Search               --enter 5");
        printf("\nExit applictaion       --enter 0");
        printf("\nEnter a choice : ");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1 :
                printf("Enter the name :");
                fgets(name,MAX,stdin);
                printf("Enter the mobile number : ");
                fgets(number,MAX,stdin);
                printf("Enter email id : ");
                fgets(email_id,MAX,stdin);
                head = addContact(head,name,number,email_id);
                break;
            case 4:
                display(head);
                break;
            case 3:
                printf("\n1. Delete contact by name      --enter 1");
                printf("\n2. Delete contact by mobile number     --enter 2");
                printf("\n3. Delete contact by email id      --enter 3");
                printf("\n");
                int choose;
                scanf("%d", &choose);
                getchar();
                switch(choose){
                    case 1:
                        printf("Enter the name : ");
                        fgets(name,MAX,stdin);
                        head = delete1(head, name);
                        printf("\nContact Deleted\n");
                        break;
                    case 2:
                        printf("Enter the mobile number : ");
                        fgets(number,MAX,stdin);
                        head = delete2(head, number);
                        printf("\nContact Deleted\n");
                        break;
                    case 3:
                        printf("Enter email id : ");
                        fgets(email_id,MAX,stdin);
                        head = delete3(head, email_id);
                        printf("\nContact Deleted\n");
                        break;
                }
        }
    }while(choice != 0);

}
