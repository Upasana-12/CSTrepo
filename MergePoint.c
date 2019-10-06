/* struct Node
{
    int data;
    struct Node* next;
};

Above structure is used to define the linked list, You have to complete the below functions only */

// Using SLOW and FAST pointers ------------------
struct Node* findMergePoint(struct Node* head1, struct Node* head2) 
{
	if(head1==NULL || head2==NULL)
      return NULL;
  struct Node* a=head1,*b=head2;
  while(a!=b)
  {
    a=a==NULL?head2:a->next;
    b=b==NULL?head1:b->next;
  }
  return a;
}

// Using HASHING -------------------------
struct Node* findMergePoint(struct Node* head1, struct Node* head2) 
{
  if(head1==NULL || head2==NULL)
    return NULL;
    struct Node* hash[100];
  struct Node* n=head1,*head;
  int i=0,flag=0;
  
  while(n!=NULL)
  {
    hash[i++]=n;
    n=n->next;
  }
  hash[i]=NULL;
  n=head2;
  while(n!=NULL)
  {
    if(flag==0)
    {
    for(int j=0;j<i;j++)
    {
    if(n==hash[j])
    {
      head=hash[j];
      flag++;
      break;
    }
    }
    }
      n=n->next;
    }
  if(flag==0)
    return NULL;
  else
    return head;
  
}