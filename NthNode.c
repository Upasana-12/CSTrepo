/* struct Node
{
    int data;
    struct Node* next;
};

Above structure is used to define the linked list*/
int findNLast(struct Node* head, int n)
{
	int i;
  if(head==NULL)
    return -1;
	struct Node* curr=head;
  int l=1;
  while(curr->next!=NULL)
  {
    l++;
    curr=curr->next;
  }
  if(n>l)
    return curr->data;
  int r=l-n;
  curr=head;
  while(r>0)
  {
    curr=curr->next;
    r--;
  }
  return curr->data;
  
}
