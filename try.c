#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct Snodetype
{
    int info;
    struct Snodetype *next;
}SN;

SN* reverse(SN* head){
	if(head==NULL){
		printf("List is empty!\n");
		return 0;
	}
	SN* p1=NULL;
	SN* p2=head;
	SN* p3=NULL;
	while(p2!=NULL){
		p3=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p3;
	}
	head=p1;
	while(p1!=NULL){
		printf("%d ",p1->info);
		p1=p1->next;
	}
	printf("\n");
return head;
}
SN* removedup(SN* head)
{
    SN *p1, *p2, *p3;
    p1 = head;
    while (p1 != NULL && p1->next != NULL) {
        p2 = p1;
        while (p2->next != NULL) {
           if (p1->info == p2->next->info) {
                p3 = p2->next;
                p2->next = p2->next->next;
                free(p3);
            }
else 
                p2 = p2->next;
        }
        p1 = p1->next;
    }
    return head;
}

SN* deletefrombeg(SN *head)
{
    if(head==NULL)
    printf("Linked list is empty");
    else
    {
        printf("the deleted element is %d",head->info);
        SN *p1;
        p1=head;
        head=head->next;
        free(p1);
    }
    return head;
}
SN *deletefromlast(SN *head)
{
    if(head==NULL)
    printf("Linked list is empty");
    else
    {
        
        SN *p1,*p2;
        p1=head;
        while(p1->next!=NULL)
        {
            p2=p1;
        p1=p1->next;
        }
        printf("the deleted element is %d",p1->info);
        p2->next=NULL;
        free(p1);
    }
    return head;
}
SN* insertafteranode(SN *head)
{
    int item;
    SN *temp, *p1;
    temp=(SN*)malloc(sizeof(SN));
    if(temp==NULL)
    printf("Memory is not avilable");
    else
    {
        p1=head;
        printf("enter info");
        scanf("%d",&temp->info);
        printf("enter the value after which node to be inserted");
        scanf("%d",&item);
        while(p1->info!=item)
        p1=p1->next;
        temp->next=p1->next;
        p1->next=temp;
        
    }
return head;
}
SN* insertatbeg(SN *head)
{
    SN *temp;
    temp=(SN*)malloc(sizeof(SN));
    if(temp==NULL)
    printf("Memory is not avilable");
    else
    {
        printf("enter info");
        scanf("%d",&temp->info);
        temp->next=head;
        head=temp;
    }
return head;
}
SN* insertatlast(SN *head)
{
    SN *temp;
    temp=(SN*)malloc(sizeof(SN));
    if(temp==NULL)
    printf("Memory is not avilable");
    else if(head==NULL)
    {
        printf("enter info");
        scanf("%d",&temp->info);
        head=temp;
        temp->next=NULL;
    }
    else
    {
     SN *p1;
     p1=head; 
       while(p1->next!=NULL)
        p1=p1->next;
        printf("enter info");
        scanf("%d",&temp->info);
        temp->next=NULL;
        p1->next=temp;
    }
return head;
}

SN* display(SN *head)
{
    SN *p1;
    if(head==NULL)
    printf("Linked list is empty");
    else
    {
        p1=head;
        while(p1!=NULL)
        {
            printf("%d",p1->info);
            p1=p1->next;
        }
    }
return head;
}
int main()
{
SN *head=NULL;
    int choice;
    do
    {
        printf("Enter choice, 1 for insert at beg, 2 for insert at last, 3 for delete from beg , 4for delete from last, 5 for insert after a node 6 for display");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            head=insertatbeg(head);
            break;
            case 2:
            head=insertatlast(head);
            break;
            case 3:
            head=deletefrombeg(head);
            break;
            case 4:
            head=deletefromlast(head);
            break;
            case 5:
            head=insertafteranode(head);
            break;
            case 6:
            head=reverse(head); 
            break;     
            case 7:
            head=removedup(head);
            break;
            case 8:
            head=display(head);
            break;
            default:
            printf("wrong choice");
            exit(0);
        }
    }while(1);
}