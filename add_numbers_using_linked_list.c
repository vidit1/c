#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void add();
int length_1=0,length_2=0;
/*Definig the structure of each nod of the linked list*/
struct defining_node
{
    int data;
    struct defining_node *next;
    struct defining_node *pre;
}*head1=NULL,*tail1=NULL,*head2=NULL,*tail2=NULL;
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
//Insert 0 or a carry at the begining of list
node* insert_start(int x,node *head)
{
	node * temp,*t;
	//Allocating memory
	temp=(node*)malloc(sizeof(node));
	//Storing data
	temp->data=x;
	temp->pre=NULL;
	//repointing the head to new node and new node pointing to next node
	temp->next=head;
	t=head;
	t->pre=temp;
	head=temp;
	//returning new value of head
	return head;
}
void add()
{
    //x is used in for loop
    int difference,x,carry=0,y;
    //finds the difference in lengths of two linked list
    difference=length_1-length_2;
    //if difference is greater than zero means that second list is smaller than first
    if(difference>0)
    {
        //adds zero to the second list to increase the length of list and make it equal to first list
        for(x=0;x<difference;x++)
        {
            head2=insert_start(0,head2);
            length_2++;
        }
    }
    //if differeceis less than zero it means that first list is smaller
    else if(difference<0)
    {
        //adding zero in first list
        difference=difference*(-1);
        for(x=0;x<difference;x++)
        {
            head1=insert_start(0,head1);
            length_1++;
        }

    }
    //if both the list are of same length the addition can be done directly
    else if(difference==0)
        printf("\nboth numbers of same length");
    //starting from the end of each list, as addition is done in the same manner
    node *temp,*temp2;
    temp=tail1;
    temp2=tail2;
    //adding the nodes of two list one by one
   for(x=0;x<length_1;x++)
    {
        //Check if carry is generated than added to sum
        if(carry!=0)
        {
            temp->data=temp->data+temp2->data+carry;
        }
        //if no carry simply adding nodes
        else
        {
            temp->data=temp->data+temp2->data;
        }
        //finding carry
        y=temp->data;
        carry=y/10;
        temp->data=y%10;
        //checks if previous node is null or not
       if(temp->pre!=NULL||temp2->pre!=NULL)
        {
            temp=temp->pre;
            temp2=temp2->pre;
        }
        //if null that we reached the starting of the list
        else
        {
            //if there is a carry, it is added to starring to the list
            if(carry>0)
            {
                head1=insert_start(carry,head1);
                length_1++;
            }
            break;
        }
}


}
int main()
{
    printf("\n--------------ADDING TWO NUMBERS BY LINKED LIST-----------------\n");
    printf("the number is represented using linked list \nexample: number=2345 is represented by  2-->3-->4-->5-->NULL\n\n\n");
    int flag;
    char  input[3];
    //creating 3 node type variables new_node current and head
    node *new_node,*current;
    printf("\nEnter data to first linked list\n");
    //Dynamic initializtion
    new_node=(node *)malloc(sizeof(node));
    printf("\nEneter data to the node: ");
    //Storing some data
    scanf("%d",&new_node->data);
    //head pointing to the new node
    head1=new_node;
    new_node->next=NULL;
    new_node->pre=NULL;
    tail1=new_node;
    current=new_node;
    length_1++;
    printf("\nDo you want to enter new node(yes/no):");
    scanf("%s",input);
    flag=string_test(input);
    //Iterate itself until flag is 1 i. the string entered is yes
    while(flag==1)
    {
        length_1++;
        //calling create_node function to create new node and link it
        current=create_node(current);
        printf("\nDo you want to enter new node(yes/no):");
        scanf("%s",input);
        //calling string_test fuction to check whether the input is yes or no
        flag=string_test(input);
    }
    tail1=current;
    //Calling the display function and passing head as the value
    display(head1);
    //Second list
    printf("\nEnter data to Second linked list\n");
    //Dynamic initializtion
    new_node=(node *)malloc(sizeof(node));
    printf("\nEneter data to the node: ");
    //Storing some data
    scanf("%d",&new_node->data);
    //head pointing to the new node
    head2=new_node;
    new_node->next=NULL;
    new_node->pre=NULL;
    tail2=new_node;
    current=new_node;
    length_2++;
    printf("\nDo you want to enter new node(yes/no):");
    scanf("%s",input);
    flag=string_test(input);
    //Iterate itself until flag is 1 i. the string entered is yes
    while(flag==1)
    {
        length_2++;
        //calling create_node function to create new node and link it
        current=create_node(current);
        printf("\nDo you want to enter new node(yes/no):");
        scanf("%s",input);
        //calling string_test fuction to check whether the input is yes or no
        flag=string_test(input);
    }
    tail2=current;
    //Calling the display function and passing head as the value
    display(head2);

    add(tail1,tail2,head1,head2);
    printf("\nSecond list is added to first");
    display(head1);
    return 0;
}
