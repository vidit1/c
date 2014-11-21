#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int i=0;
/*Definig the structure of each nod of the linked list*/
struct defining_node
{
    int data;
    struct defining_node *next;
}*head=NULL;
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
    new_node->next=head;
    //Returning the new node to the main fuction
    return new_node;
}
/*Display function takes the value of head from the main function
and displays the full linkes list*/
void display(node *current)
{
    printf("\nLinked list:");
    //Traversing all the nodes in the linked listone by one
    do
   	{
   		printf("%d--->",current->data);
   		if(current->next!=NULL)
   		current=current->next;
   	}while(current!=head);
    //Printing NULL because the last node does not point to any node
    printf("points to head");

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
//Rotate linked list rotates the list anti clockwise k times
void rotate_linked_list(int k)
{
    int x;
   node *current,*next,*temp;
   current=head;
   //traversing to the end of list
   do
   	{
   		current=current->next;
   	}while(current!=head);
    //Moving head forward and re-pointing the last node
    for(x=0;x<k;x++)
    {
   	    temp=head;
   	    //Head shifted to next node
        head=temp->next;
        //last node pointing to head
        current->next=head;
        //last node increamenteed
        current=current->next;
    }
   	 display(head);
}
int main()
{
    int r;
    int flag;
    char  input[3];
    //creating 3 node type variables new_node current and head
    node *new_node,*current;
    //Dynamic initializtion
    new_node=(node *)malloc(sizeof(node));
    printf("\nEneter data to the node: ");
    //Storing some data
    scanf("%d",&new_node->data);
    //head pointing to the new node
    head=new_node;
    new_node->next=NULL;
    current=new_node;
    printf("\nDo you want to enter new node(yes/no):");
    scanf("%s",input);
    flag=string_test(input);
    //Iterate itself until flag is 1 i. the string entered is yes
    while(flag==1)
    {
        //calling create_node function to create new node and link it
        current=create_node(current);
        printf("\nDo you want to enter new node(yes/no):");
        scanf("%s",input);
        //calling string_test fuction to check whether the input is yes or no
        flag=string_test(input);
    }

    //Calling the display function and passing head as the value
    display(head);
    printf("\nEnter the number of times you want to rotate the list");
    scanf("%d",&r);
    //calling the rotate linkedd list function
    rotate_linked_list(r);
    return 0;
}
