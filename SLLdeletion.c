#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node
{
  int data;
  struct Node *next;
};
struct Node* find(struct Node *head, int data)
{
  struct Node* temp=head;
  struct Node* tempp;
  if(head->data == data)
    return NULL;
  else
  {
    temp = head->next;
    tempp = head;
    while(temp != NULL)
    {
      if(temp->data == data)
        return tempp;
      tempp=temp;
      temp = temp->next;
    }
  }
  return NULL;
}
void deletenode(struct Node** head, struct Node* loc, struct Node* prev)
{
  if(prev ==NULL)     // loc is first node
    (*head) = (*head)->next;
  else
    prev->next = loc->next;
  free(loc);
}
void deleteitem(struct Node* head, int data)
{
  struct Node* prev;
  prev = find(head, data);
  if(prev ==NULL)     // loc is first node
    head = head->next;
  else
    prev->next = prev->next->next;
  //    free(prev->next);
}
// This function prints contents of linked list starting from head
void printList(struct Node *node)
{
  while (node != NULL)
  {
    printf("%d -> ", node->data);
    node = node->next;
  }
  printf("\n");
}
int main()
{
  struct Node* head = NULL;
  printf("Linked List = ");
  printList(head);
  insert(&head, 6);    // Insert an element
  insert(&head, 5);    // Insert an element
  insert(&head, 4);    // Insert an element
  insert(&head, 3);    // Insert an element
  insert(&head, 2);    // Insert an element
  insert(&head, 1);    // Insert an element
  insert(&head, 0);    // Insert an element
  printf("Linked List = ");
  printList(head);
  deletenode(&head, head->next, head);  //delete the 2nd element
  printf("Linked List after deleting 2nd element = ");
  printList(head);
  deleteitem(head, 5);
  printf("Linked List after deleting element 5 = ");
  printList(head);
  return 0;
}
