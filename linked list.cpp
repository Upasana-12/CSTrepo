#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};

struct node* create(int n)
{
    struct node* head=0;
	struct node* temp=0;
	struct node* p=0;
	int j,x;
	for(j=0;j<n;j++)
	{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	scanf("%d",&x);
	new_node->data=x;
	new_node->next=0;
	if(head==0)
	{
	head=new_node;
	
    }
	else
	{
	      p=head;
	      while(p->next!=0)
	      p=p->next;
	      p->next=new_node;
	}
	}
	return head;
}
int main()
{
	int i,num;
	struct node* h;
	scanf("%d",&num);
	h=create(num);

	struct node* n;
	for(n=h;n!=0;n=n->next)
	{
		printf("%d ",n->data);
	}
	return 0;
}

