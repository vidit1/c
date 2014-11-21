#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int length=0;
/*Definig the structure of each nod of the linked list*/
struct defining_node
{
    int data;
    struct defining_node *next;
    struct defining_node *pre;
}*head=NULL,*tail=NULL,*new_head=NULL,*new_tail=NULL;
typedef struct defining_node node;
/*create_node is function which creates new node in a linkes list,
 saves data in it and links the new node with previious node which
 passed on by the main function*/
node* create_node(node *current)
{
    //Initializingnew node
    node *new_node=(node*)malloc(sizeof(node));
    printf("\nEnter data to the node: ");
    //Saving data in the new node
    scanf("%d",&new_node->data);
    //Linking the previous node with the new node
    current->next=new_node;
    //New node is not further pointig to any node so NULL
    new_node->next=NULL;
    new_node->pre=current;
    //Returning the new node to the main fuction
    return new_node;
}
/*Display function takes the value of head from the main function
and displays the full linkes list*/
void display(node *current)
{
    printf("\nLinked list:");
    //Traversing all the nodes in the linked listone by one
    while(current!=NULL)
    {
        //Displaying the data of each node
        printf("%d-->",current->data);
        //Moving forward
        current=current->next;
    }
    //Printing NULL because the last node does not point to any node
    printf("NULL");

}
/*string_test function tests that the string passed is equal to "yes" or not
and return a value to main function based on value flag is 0 if string is yes, value passed is 1
 and  and 1 if not, value passed is 0*/
int string_test(char str1[])
{
    int i=0,flag=0;
    char str2[]="yes";
    //Two string are compared character by charater
    while(str1[i]!='\0' && str2[i]!='\0')
    {
        //if characters of both the string are not same flag is set to 1
        if(str1[i]!=str2[i])
        {
             flag=1;
             break;
        }
        i++;
    }
    //Depending flag value is returned to the main function
    if (flag==0 && str1[i]=='\0' && str2[i]=='\0')
         return 1;
    else
         return 0;

}
//New linke list is created by skiping 1 node
void alternate()
{
    node *temp;
    do
    {
        node *new_node,*current;
        new_node=(node*)malloc(sizeof(node));
        //new head is pointing to the 1st node of the old linked list
        if(new_head==NULL&&new_tail==NULL)
		{
		    //first node of new list is same as the node of old list
			new_head=head;
			new_tail=head;
			current=head;
			new_node->pre=NULL;
			new_node->next=NULL;
			temp=current;
		}
		//Skiping one node and adding to the new linked list
		else
		{
		    //checks whether the next node is null or not
		    if(current->next==NULL)
                break;
            //Adding node by skiping one
		    temp=current->next;
            temp=temp->next;
			new_node->pre=current;
			new_node->next=NULL;
			//if old list id even last element will no be added
			if(length%2==0)
            {
                new_tail=current;
                current->next=temp;
                current=temp;
            }
            //if odd last node will be added
			else
            {
                current->next=temp;
                current=temp;
                new_tail=current;
            }
        }
    }while(temp!=NULL);
}
//add reverse() reverse the nodes not added and then adds at the end of the new list
void add_reverse()
{
    node *temp,*current,*new_node;
    //if old list is even last element will be added first
    if(length%2==0)
    {
        temp=tail;
        current=new_tail;
        printf("\nold tail=%d\nnew tail=%d\n",temp->data,current->data);

    }
    //if old list is odd second last element will be added
    else
    {
        //second last node
        temp=tail->pre;
        current=new_tail;
        printf("\nold tail=%d\nnew tail=%d\n",temp->data,current->data);
     }
     //nodes are added from last till we have reached the starting of list
     do
     {
        current->next=temp;
        new_tail=current;
        current=temp;
        //Check if previous node is null or not
        if(temp->pre==NULL)
            break;
        //Skiping one node
        temp=temp->pre;
        temp=temp->pre;
     }while(temp!=NULL);
    current->next=NULL;

}

int main()
{
	int flag;
    char  input[3];
    //creating 3 node type variables new_node current and head
    node *new_node,*current;
    printf("\nEnter data to the linked list\n");
    //Dynamic initializtion
    new_node=(node *)malloc(sizeof(node));
    printf("\nEneter data to the node: ");
    //Storing some data
    scanf("%d",&new_node->data);
    //head pointing to the new node
    head=new_node;
    new_node->next=NULL;
    new_node->pre=NULL;
    tail=new_node;
    current=new_node;
    length++;
    printf("\nDo you want to enter new node(yes/no):");
    scanf("%s",input);
    flag=string_test(input);
    //Iterate itself until flag is 1 i. the string entered is yes
    while(flag==1)
    {
        length++;
        //calling create_node function to create new node and link it
        current=create_node(current);
        printf("\nDo you want to enter new node(yes/no):");
        scanf("%s",input);
        //calling string_test fuction to check whether the input is yes or no
        flag=string_test(input);
    }
    tail=current;
    //Calling the display function and passing head as the value
    display(head);
    //Alternate() is called to create new list containing alternate node
    alternate();
    //display new list
    display(new_head);
    //Add the rest of list
    add_reverse();
    //display newedited list
    display(new_head);
	return 0;
}
