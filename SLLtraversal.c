/* struct Node
{
    int data;
    struct Node* next;
};

Above structure is used to define the linked list */

void forwardPrint(struct Node* head)
{
  struct Node* n=head;
   if(head!=NULL)
   {
     while(n!=NULL)
     {
       printf("%d-",n->data);
       n=n->next;
     }
   }
}

void backwardPrint(struct Node* head)
{
   if(head!=NULL)
   {
     backwardPrint(head->next);
     printf("%d-",head->data);
   }
}
