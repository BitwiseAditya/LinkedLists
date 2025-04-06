#include<stdio.h>
#include<stdlib.h>
                    //ADT for Circular linked list
typedef struct CLList
{
  int data;
  struct CLList *next;
}node;

void insert(node **top)
{
    int ch=0;
    node *curr =NULL;
    while(1)
     {
        node *p = (node*)malloc(sizeof(node));
      printf("enter data");
       scanf("%d",&p->data);
       //adding nodes before first node/towards left side
      if(*top == NULL)
        {
          *top = p;
          (*top)->next = *top;
        }
      else
      {
          curr = *top;
      while (curr->next != *top)
          curr = curr->next;

        curr->next = p;
        p->next = *top;
        *top = p;
      }
      printf("enter 1 to continue/0 to exit insert function");
        scanf("%d",&ch);
       if(ch==0)
          break;
    }
}

void deleteBegin(node **top)
{

  node *temp = *top;

  // if there are no nodes in Linked List display msg
  if(*top == NULL)
    {
      printf ("Linked List Empty...........");
      return;
    }
     // if there is only 1 node exist in CLL
  if(temp->next == *top)
    {
      *top = NULL;
      return;
    }
  node *curr = *top;

  // traverse till last node in CLL
  while(curr->next != *top)
       curr = curr->next;

  // assign last node's next to 2nd node in CLL
  curr->next = (*top)->next;

  // move top to next node
     *top = (*top)->next;
  free(temp);
}

void deleteEnd (node **top)
{
   node *temp = *top;
  node *prev;

  // if there are no nodes in Linked List can't delete display msg. empty
  if(*top == NULL)
    {
      printf("Linked List Empty............");
      return;
    }
  // if there is only 1 node in Linked list
  if(temp->next == *top)
    {
      *top = NULL;
      return;
    }

  // else traverse to the last node
  while(temp->next != *top)
    {
      // store prev link node as we need to change its next val
      prev = temp;
      temp = temp->next;
    }
  // Curr assign 2nd last node's next to top
  prev->next = *top;
  // delete the last node
  free(temp);
  // after deleting last node 2nd last node becomes the last node
}
int Legnth(node *top)
{
  int len = 0;
  node *temp = top;

  if(temp == NULL)
    return len;
  do
    {
      len++;
      temp = temp->next;
    }while(temp != top);

return len;
}

void deletePos(node **top)
{
    int pos=0,i=0;
        if(*top==NULL)
        {
            printf("Linked List Empty............");
        return;
        }
  int size = Legnth(*top);
   printf("\nenter position to dalete");
        scanf("%d",&pos);

  if(pos < 1 || size < pos)
    {
      printf("Can't delete,invalid position\n", pos);
      return;
    }
  else if(pos == 1)
    deleteBegin(top);
  else if(pos == size)
    deleteEnd(top);
  else
    {
        i=1;
      node *temp = *top;
      node *prev;
      // traverse to the desired position of deletion
      while(i!=pos)
        {
          // store prev link of node as we need to change its next value
          prev = temp;
          temp = temp->next;
          i++;
        }
      // change prev node's next node to nth node's next node
      prev->next = temp->next;
      // delete this nth node
      free(temp);
    }
}

void display(node *top)
{
   node *temp = top;
  if(top == NULL)
    {
       printf("List is empty.....");
      return;
    }

  printf ("\nList data: ");
  do
    {
      printf("%d ", temp->data);
      temp = temp->next;
    }while(temp != top);
}

int main()
{
   int c=0,pos=0;
    node *top = NULL;

    while(1)
    {
        printf("\n1.Insert\n2.Display\n3.DeleteAtBeg\n4.DeleteAtEnd");
        printf("\n5.Delete From Desired position\n6.Exit");
        scanf("%d",&c);
        switch(c)
        {
          case 1:
              insert(&top);
            break;
          case 2:
              display(top);
            break;
            case 3:
              deleteBegin(&top);
            break;
          case 4:
              deleteEnd(&top);
            break;
            case 5:
                deletePos(&top);
            break;
          case 6:
              exit(0);
        }
    }
return 0;
}
