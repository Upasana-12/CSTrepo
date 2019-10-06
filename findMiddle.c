/* struct Node
{
    int data;
    struct Node* next;
};

Above structure is used to define the linked list*/

int findMiddle(struct Node* head) 
{
	    if(head==NULL)
    return -1;
	struct Node* slow=head,*fast=head;
  while(fast!=NULL && fast->next!=NULL)
  {
    slow=slow->next;
    fast=fast->next->next;
  }
  return slow->data;
}