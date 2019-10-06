#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

void deletenode(struct Node** head, struct Node* loc)
{
  if(loc->prev ==NULL) {    // loc is first node
    (*head) = (*head)->next;
    (*head)->next->prev=NULL;
  }
  else
    loc->prev->next = loc->next;
  loc->next->prev = loc->prev;
  free(loc);
}
void deleteitem(struct Node* head, int data)
{
  struct Node* loc;
  loc = find(head, data);
  deletenode(&head, loc);
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
  deletenode(&head, head->next);  //delete the 2nd element
  printf("Linked List after deleting 2nd element = ");
  printList(head);
  deleteitem(head, 5);
  printf("Linked List after deleting element 5 = ");
  printList(head);
  return 0;
}
