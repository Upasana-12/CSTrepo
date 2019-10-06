/* struct Node
{
    int data;
    struct Node* next;
};

Above structure is used to define the linked list*/

struct Node*  reverseList(struct Node* head) 
{
	struct Node* curr=head,*pre=NULL,*n;
  while(curr!=NULL)
  {
    n=curr->next;
    curr->next=pre;
    pre=curr;
    curr=n;
  }
  head=pre;
  return head;
}