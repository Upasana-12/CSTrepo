#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node
{
  int data;
  struct Node *next;
};
// Insert in Beginning
void insertBeg(struct Node** head, int data)
{
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  node->data  = data;     //  Insert data in new node
  node->next = (*head);   // link new node at beginning of list
  (*head)    = node;  // Change the head to new node.
}

void insertAfter(struct Node* prev, int data)
{
  if (prev == NULL)
  {
    printf("the given previous node cannot be NULL");
    return;
  }
  struct Node* node =(struct Node*) malloc(sizeof(struct Node));
  node->data  = data;     //  Insert data in new node
  node->next = prev->next;   // link new node after prev node
  prev->next = node;  // Link the previous node to new node.
}

void insertEnd(struct Node** head, int data)
{
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  struct Node *last = *head;
  node->data  = data;     //  Insert data in new node
  node->next = NULL;   // link new node to NULL as it is last node
  if (*head == NULL)  // if list is empty add in beginning.
  {
    *head = node;
    return;
  }
  while (last->next != NULL)  // Find the last node
    last = last->next;
  last->next = node;  // Add the node after the last node of list
  return;
}

int main()
{
  struct Node* head = NULL;
  printf("Linked List = ");
  printList(head);
  insertBeg(&head, 6);    // At Beginning
  printf("Linked List = ");
  printList(head);
  insertBeg(&head, 2);    // At Beginning
  printf("Linked List = ");
  printList(head);
  insertAfter(head, 3);   // After Head node
  printf("Linked List = ");
  printList(head);
  insertEnd(&head, 8);    // At End
  printf("Linked List = ");
  printList(head);
  insertAfter(head->next, 4); // After 2nd Node
  printf("Linked List = ");
  printList(head);
  return 0;
}
