#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void display();
void display2();
struct node_type
{
	int data;
	struct node_type * next;
}*head=NULL,*new_head=NULL;
typedef struct node_type node;
int i=0,j=0;
void nodee()
{	char ch;
	do
	{
		node * new_node,*current;
		new_node=(node*)malloc(sizeof(node));
		printf("\nenter data to the element of the linked list: ");
		scanf("%d",&new_node->data);
		if(head==NULL)
		{
			head=new_node;
			current=new_node;
			i++;
		}
		else
		{
			current->next=new_node;
			current=new_node;
			i++;
		}
		printf("\ndo you want to enter new element(y/n): ");
		ch=getche();
		if(ch=='n')
		new_node->next=NULL;
	}while(ch!='n');
}
void nodee1()
{	char ch;
	do
	{
		node * new_node,*current;
		new_node=(node*)malloc(sizeof(node));
		printf("\nenter data to the element of the linked list: ");
		scanf("%d",&new_node->data);
		if(new_head==NULL)
		{
			new_head=new_node;
			current=new_node;
			j++;
		}
		else
		{
			current->next=new_node;
			current=new_node;
			j++;
		}
		printf("\ndo you want to enter new element(y/n): ");
		ch=getche();
		if(ch=='n')
		new_node->next=NULL;
	}while(ch!='n');
}
void merger()
{
    int flag;
    node *temp,*current,*a,*b;
    if(i>j)
    {
        current=head;
        a=new_head;
        flag=1;
    }else
    {
        current=new_head;
        a=head;
        flag=2;
    }
        do
        {
            temp=current->next;
            current->next=a;
            b=a->next;
            a->next=temp;
            current=temp;
            a=b;
        }while(a!=NULL||b!=NULL);
        if(flag==1)
        display();
        else if(flag==2)
        display2();

}
void display()
{
node *new_node;
 printf("\nThe Linked List Number 1: ");
 new_node=head;
 while(new_node!=NULL)
   {
   printf("%d--->",new_node->data);
   new_node=new_node->next;
   }
  printf("NULL");

}
void display2()
{
    node *new_node;
     printf("\nThe Linked List Number 2: ");
 new_node=new_head;
 while(new_node!=NULL)
   {
   printf("%d--->",new_node->data);
   new_node=new_node->next;
   }
  printf("NULL");
}
int main()
{
    printf("\nenter data to first linked list");
    nodee();
    display();
    printf("\nenter data to second linked list");
    nodee1();
    display2();
    merger();

    return 0;
}
