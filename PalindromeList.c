/* struct Node
{
    int data;
    struct Node* next;
};

Above structure is used to define the linked list */
int chpal(struct Node* slow, struct Node* fast)
{
  static struct Node* c=NULL;
  if(fast==NULL)
  {
    c=slow;
    return 1;
  }
  else if(fast->next==NULL)
  {
    c=slow->next;
    return 1;
  }
  else
  {
    if(chpal(slow->next,fast->next->next))
    {
      if(c->data==slow->data)
      {
        c=c->next;
        return 1;
      }
      else
        return 0;
    }
    else
      return 0;
  }
}
int  checkPalindrome(struct Node* head) 
{
	if(head==NULL)
      return 0;
  if(head->next==NULL)
    return 1;
  return chpal(head,head);
}