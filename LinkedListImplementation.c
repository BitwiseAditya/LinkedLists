#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
};
int main(){
       struct node *head=NULL;
       struct node *newNode, *temp;
       int choice=1, count=0;
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
            temp=head;  
            while(temp!=NULL){
                printf("%d ", temp->data);
                temp=temp->next;
                count++;
            }
            printf("\n");
            getch();
            printf("Total number of nodes: %d", count );
       return 0; 
             
}

