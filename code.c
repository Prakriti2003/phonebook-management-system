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

typedef struct queue
{
	char name[MAX];
    char email_id[MAX];
    char number[MAX];
	struct queue* next;
}queue;
queue *f = NULL;
queue *r = NULL;

int dequeue() // Delete an element from Queue
{
	queue* t;
	t = f;
	if((f==NULL)&&(r==NULL))
		printf("\nQUEUE IS EMPTY");
	else if(f == r){
		f = r = NULL;
		free(t);
	}
	else{
		f = f->next;
		r->next = f;
		free(t);
	}
    return 0;
}

void enqueue(char *name, char *number,char *email_id) //Insert elements in Queue
{
    static int count = 0;
	queue* n;
	n = (queue*)malloc(sizeof(queue));
	strcpy(n->name,name);
    strcpy(n->email_id,email_id);
    strcpy(n->number,number);
	n->next = NULL;
	if((r==NULL)&&(f==NULL))
	{
		f = r = n;
		r->next = f;
        count++;
	}
	else
	{
        if(count >= 5)
        {
            dequeue();
            count--;
        }
		r->next = n;
		r = n;
		n->next = f;
        count++;
	}
} 

void print(){ // Print the elements of Queue for recently searched contacts
	queue* t;
	t = f;
	if((f==NULL)&&(r==NULL))
		printf("\nNO RECENT CONTACTS\n\n");
	else{
		do{
            printf("\n\n");
			printf("Name       : %s",t->name);
            printf("Mobile no. : %s",t->number);
            printf("Email id   : %s",t->email_id);
			t = t->next;
		}while(t != f);
	}
}

int validate(char *number)//To check if entered mobile no. is 10 digit
{
    int length =    strlen(number);
    if(length == 11)
    return 1;
    else 
    return 0;
}

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
    printf("\nCONTACT ADDED SUCCESSFULLY\n");
    return head;
}

node* sort(node* head)  //sorting contacts in alphabetical order
{
    node *i,*j;
    int temp;
    char name1[MAX];
    char number1[MAX];
    char email1[MAX];
    for(i=head;i->next!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            temp=strcmp(i->name,j->name);
            if(temp>0)
            {
                strcpy(name1,i->name);
                strcpy(number1,i->number);
                strcpy(email1,i->email_id);
                strcpy(i->name,j->name);
                strcpy(i->number,j->number);
                stpcpy(i->email_id,j->email_id);
                strcpy(j->name,name1);
                strcpy(j->number,number1);
                strcpy(j->email_id,email1);
            }
        }
    }
    return head;
}        

void display(node *head)
{
    node *ptr = head;
    head = sort(head);
    while(ptr != NULL)
    {
        printf("Name       : %s",ptr->name);
        printf("Mobile no. : %s",ptr->number);
        printf("Email id   : %s",ptr->email_id);
        printf("\n\n");
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
    printf("\nCONTACT DELETED SUCCESSFULLY\n");
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
    printf("\nCONTACT DELETED SUCCESSFULLY\n");
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
    printf("\nCONTACT DELETED SUCCESSFULLY\n");
    return head;
};

void search_name(node* head, char* entered_name)
{
    node *ptr = head;
    while(ptr != NULL)
    {
        if(strcmp(entered_name,ptr->name)==0)
        {
            printf("\nName       : %s",ptr->name);
            printf("Mobile no. : %s",ptr->number);
            printf("Email id   : %s",ptr->email_id);
            enqueue(ptr->name,ptr->number,ptr->email_id);
            break;
        }
        ptr = ptr->next;
    }
    if(ptr == NULL){
    printf("\nEntered name is NOT present in contacts\n");
    printf("Try again.\n");
    }
}

void search_number(node* head, char* entered_number)
{
    node *ptr = head;
    while(ptr != NULL)
    {
        if(strcmp(entered_number,ptr->number)==0)
        {
            printf("\nName       : %s",ptr->name);
            printf("Mobile no. : %s",ptr->number);
            printf("Email id   : %s",ptr->email_id);
            enqueue(ptr->name,ptr->number,ptr->email_id);
            break;
        }
        ptr = ptr->next;
    }
    if(ptr == NULL){
    printf("\nEntered number is NOT present in contacts\n");
    printf("Try again.\n");
    }
}

void search_email(node* head, char* entered_email)
{
    node *ptr = head;
    while(ptr != NULL)
    {
        if(strcmp(entered_email,ptr->email_id)==0)
        {
            printf("\nName       : %s",ptr->name);
            printf("Mobile no. : %s",ptr->number);
            printf("Email id   : %s",ptr->email_id);
            enqueue(ptr->name,ptr->number,ptr->email_id);
            break;
        }
        ptr = ptr->next;
    }
    if(ptr == NULL){
    printf("\nEntered email_id is NOT present in contacts\n");
    printf("Try again\n");
    }
}

node* update_name(node* head, char* entered_name)
{
    node *ptr = head;
    while(ptr != NULL)
    {
        if(strcmp(entered_name,ptr->name)==0)
        {
            printf("Enter new name : ");
            fgets(ptr->name,MAX,stdin);
            printf("\nCONTACT UPDATED SUCCESSFULLY\n");
            break;
        }
        ptr = ptr->next;
    }
    if(ptr == NULL)
    {
        printf("\nEntered name is NOT present in contacts\n");
        printf("Try again.\n");
    }
    return head;
}

node* update_number(node* head, char* entered_number)
{
    node *ptr = head;
    while(ptr != NULL)
    {
        if(strcmp(entered_number,ptr->number)==0)
        {
            printf("Enter new number : ");
            fgets(ptr->number,MAX,stdin);
           while(validate(ptr->number) == 0)
           {
               printf("Enter a valid new number : ");
               fgets(ptr->number,MAX,stdin);
           }
            printf("\nCONTACT UPDATED SUCCESSFULLY\n");
            break;
        }
        ptr = ptr->next;
    }
    if(ptr == NULL)
    {
        printf("\nEntered number is NOT present in contacts\n");
        printf("Try again.\n");
    }
    return head;
}

node* update_email(node* head, char* entered_email)
{
    node *ptr = head;
    while(ptr != NULL)
    {
        if(strcmp(entered_email,ptr->email_id)==0)
        {
            printf("Enter new email id : ");
            fgets(ptr->email_id,MAX,stdin);
            printf("\nCONTACT UPDATED SUCCESSFULLY\n");
            break;
        }
        ptr = ptr->next;
    }
    if(ptr == NULL)
    {
        printf("\nEntered email id is NOT present in contacts\n");
        printf("Try again.\n");
    }
    return head;
}

void main(){
    node *head = NULL;
    char name[MAX];
    char number[MAX];
    char email_id[MAX];
    int choice;
    printf("\n*******WELCOME TO PHONEBOOK MANAGEMENT SYSTEM*******\n");
    printf("\nYou can easily ADD, UPDATE, DELETE, DISPLAY, SEARCH, and find your RECENTLY SEARCHED CONTACTS in only a few simple steps\n");
    printf("\n---------MY PHONEBOOK---------");
    printf("\n\n MAIN MENU\n\n");
    do{
        printf("\n1. Add new contact      --enter 1");
        printf("\n2. Update contact       --enter 2");
        printf("\n3. Delete contact       --enter 3");
        printf("\n4. Display all contacts --enter 4");
        printf("\n5. Search               --enter 5");
        printf("\n6. Recently searched    --enter 6");
        printf("\nExit applictaion       --enter 0");
        printf("\n\nEnter a choice : ");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1 :
                printf("Enter the name : ");
                fgets(name,MAX,stdin);
                printf("Enter the mobile number : ");
                fgets(number,MAX,stdin);
                while(validate(number) == 0)
                {
                    printf("Enter a valid mobile number : ");
                    fgets(number,MAX,stdin);
                }
                printf("Enter email id : ");
                fgets(email_id,MAX,stdin);
                head = addContact(head,name,number,email_id);
                break;
            case 2 :
            {
                printf("\n1. Update  name      --enter 1");
                printf("\n2. Update mobile number     --enter 2");
                printf("\n3. Update email id      --enter 3");
                printf("\n");
                int choose;
                printf("\nEnter a choice : ");
                scanf("%d", &choose);
                getchar();
                switch(choose){
                    case 1:
                        printf("Enter the name : ");
                        fgets(name,MAX,stdin);
                        head = update_name(head, name);
                        break;
                    case 2:
                        printf("Enter the mobile number : ");
                        fgets(number,MAX,stdin);
                        head = update_number(head, number);
                        break;
                    case 3:
                        printf("Enter email id : ");
                        fgets(email_id,MAX,stdin);
                        head = update_email(head, email_id);
                        break;
                }
                    break;
            }    
            case 4:
                printf("\n\n");
                display(head);
                break;
            case 3:
                printf("\n1. Delete contact by name      --enter 1");
                printf("\n2. Delete contact by mobile number     --enter 2");
                printf("\n3. Delete contact by email id      --enter 3");
                printf("\n");
                int choose;
                printf("\nEnter a choice : ");
                scanf("%d", &choose);
                getchar();
                switch(choose){
                    case 1:
                        printf("Enter the name : ");
                        fgets(name,MAX,stdin);
                        head = delete1(head, name);
                        //printf("\nContact Deleted\n");
                        break;
                    case 2:
                        printf("Enter the mobile number : ");
                        fgets(number,MAX,stdin);
                        head = delete2(head, number);
                        //printf("\nContact Deleted\n");
                        break;
                    case 3:
                        printf("Enter email id : ");
                        fgets(email_id,MAX,stdin);
                        head = delete3(head, email_id);
                        //printf("\nContact Deleted\n");
                        break;
                }
            case 5 :
            {   if(head == NULL){
                    printf("\nNO CONTACTS ENTERED YET\n");
                    break;
                }
                printf("\n1. Search contact by name      --enter 1");
                printf("\n2. Search contact by mobile number     --enter 2");
                printf("\n3. Search contact by email id      --enter 3");
                printf("\n");
                int choose;
                printf("\nEnter a choice : ");
                scanf("%d", &choose);
                getchar();
                switch(choose){
                    case 1:
                        printf("Enter the name : ");
                        fgets(name,MAX,stdin);
                        search_name(head, name);
                        break;
                    case 2:
                        printf("Enter the mobile number : ");
                        fgets(number,MAX,stdin);
                        search_number(head, number);
                        break;
                    case 3:
                        printf("Enter email id : ");
                        fgets(email_id,MAX,stdin);
                        search_email(head, email_id);
                        break;    
                }
                    break;
            }
            case 6 :
            {
                print();
                break;
            }
        }
    }while(choice != 0);

}
