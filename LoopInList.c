/* struct Node
{
    int data;
    struct Node* next;
};

Above structure is used to define the linked list.
Given a linked-list as input, check whether it contains a loop or not. If there is a loop return the number of nodes in the loop, otherwise return 0.
 */

int  loopInList(struct Node* head) 
{
	struct Node* s=head,*f=head;
  int flag=0;
  while(f && f->next)
  {
    s=s->next;
    f=f->next->next;
    if(s==f)
    {
      flag++;
      break;
    }
  }
  if(flag==0)
  return 0;
  struct Node* n=s->next;
  int c=1;
  while(n!=f)
  {
    c++;
    n=n->next;
  }
  return c;

}