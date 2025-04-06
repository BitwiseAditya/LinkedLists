#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
};
struct node* insertatbeg(struct node* head){
    struct node* newNode;
    newNode=(struct node*)malloc(sizeof(struct node));  
    if(newNode==NULL){
        printf("Memory not available.");
    }
    else{
    printf("Enter data you want to insert at beginning node of LL: ");
    scanf("%d", &newNode->data);
    newNode->next=head;
    head=newNode;
    }
    return head;    
}
struct node* insertatend(struct node* head){
    struct node* newNode, *temp;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory not available."); 
    }
    else if(head==NULL){
        printf("Enter info: ");
        scanf("%d", &newNode->data);
        head=newNode;
        newNode->next=NULL; 
    }
    else{
    printf("Enter data you want to insert at end node of LL: ");
    scanf("%d", &newNode->data);
    newNode->next=NULL;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    }
    return head;    
}   
struct node* insertafterspecific(struct node* head){
    struct node* newNode, *temp;
    int pos, i=1;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory not available."); 
    }
    else if(head==NULL){
        printf("Enter info: ");
        scanf("%d", &newNode->data);
        head=newNode;
        newNode->next=NULL; 
    }
    else{
    printf("Enter data you want to insert at end node of LL: ");
    scanf("%d", &newNode->data);
    newNode->next=NULL;
    printf("Enter position after which you want to insert: ");
    scanf("%d", &pos);
    temp=head;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    }
    return head;    
}  
struct node* deletefrombeg(struct node* head){
    struct node* temp;
    if(head==NULL){
        printf("Linked list is empty.");
    }
    else{
        printf("Deleted element is: %d", head->data);
        temp=head;
        head=head->next;
        free(temp);
    }
    return head;
}   
struct node* deletefromlast(struct node* head){
    struct node* temp, *prev;
    if(head==NULL){
        printf("Linked list is empty.");
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        printf("Deleted element is: %d", temp->data);
        prev->next=NULL;
        free(temp);
    }
    return head;
}   
struct node* deletefromspecific(struct node* head){
    struct node* temp, *prev;
    int pos, i=1;
    if(head==NULL){
        printf("Linked list is empty.");
    }
    else{
        printf("Enter position from where you want to delete: ");
        scanf("%d", &pos);
        temp=head;
        while(i<pos){
            prev=temp;
            temp=temp->next;
            i++;
        }
        printf("Deleted element is: %d", temp->data);
        prev->next=temp->next;
        free(temp);
    }
    return head;
}  
struct node* reverse(struct node* head){
    if (head== NULL){
        printf("Linked list is empty.");    
    }
    else{
    struct node* prevNode, *currNode, *nextNode;
    prevNode= NULL;
    currNode= nextNode= head;
    while(nextNode!=NULL){
        nextNode=nextNode->next;
        currNode->next=prevNode;
        prevNode=currNode;
        currNode=nextNode;
    }   
    head=prevNode;
    }
    return head;
}  
 struct node* removedup(struct node* head)
{
    struct node *p1, *p2, *p3;
    p1 = head;
    while (p1 != NULL && p1->next != NULL) {
        p2 = p1;
        while (p2->next != NULL) {
           if (p1->data == p2->next->data) {
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
struct node* display(struct node* head)
{
     struct node* temp;
     int count=0;
      printf("Linked list after operations:\n ");    
            temp=head;  
            while(temp!=NULL){
                printf("%d ", temp->data);
                temp=temp->next;
                count++;
            }
            printf("\n");
            getch();
            printf("Total number of nodes: %d", count );
}
int main(){
       struct node *head=NULL;
       struct node *newNode, *temp;
       int choice=1,choice2=1;
       while(choice){
        newNode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);    
        newNode->next=NULL;
        if (head==NULL)
        {
            head=newNode;
            temp=newNode;
        }
        else{
            temp->next=newNode;
            temp=newNode;
        }
       printf("Do you want to continue (0,1): ");   
         scanf("%d", &choice);
    }  
    while(choice2){
    printf("Enter one to insert a new node at beginning of above created LL, \ntwo to insert a new node at end of above created LL, \nthree to insert after a specified position, \nfour to delete a node from the beginning of LL, \nfive to delete from last, \nsix to delete from a specific position,\nSeven to reverse the LL,\nEight to remove duplicate elements from LL\n Nine to display the so formed LL : ");
    int choice1;
    scanf("%d", &choice1);
    switch(choice1){
        case 1:
            head=insertatbeg(head); 
            break;
        case 2:
            head=insertatend(head);
            break;
        case 3: 
            head=insertafterspecific(head);
            break;
        case 4:
            head=deletefrombeg(head);
            break;
        case 5:
            head=deletefromlast(head);
            break;
        case 6:
            head=deletefromspecific(head);
            break; 
        case 7:
            head=reverse(head);
            break;   
        case 8:
            head=removedup(head);
            break;  
        case 9:
            head=display(head);
            break;                      
        default: 
            printf("Invalid choice.");
    }
    printf("Do you want to continue to perform operations on LL?(0,1): ");   
         scanf("%d", &choice2);
    }   
       return 0;          
}