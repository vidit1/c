#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
/*Definig the structure of each nod of the linked list*/
struct defining_node
{
    int data;
    struct defining_node *next;
    struct defining_node *pre;
}*head=NULL,*tail=NULL;
typedef struct defining_node node;
int length=0;
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
//Pop() removes the element from the top and decreament the tail
void pop()
{
    //Temporary variables
	node * temp,*loc;
	temp=tail;
	//Repointing the tail
	loc=temp->pre;
	tail=loc;
	loc->next=NULL;
	//Dealocating memory
	free(temp);
	//Length is decreased
	length--;
	display(head);
}
//push() adds the new element at the top of list
void push()
{
	node * temp,* loc;
	//Dynamic allocation of memory
	temp=(node*)malloc(sizeof(node));
	printf("\nenter data to the new element: ");
	//Storing data in new node
	scanf("%d",&temp->data);
	loc=tail;
	//Pointing the tail to new node
	temp->pre=loc;
	loc->next=temp;
	temp->next=NULL;
	tail=temp;
	//Length is increamnted
	length++;
	display(head);

}
//delete_middla() deletes the middle element of the stack
void delete_middle()
{
    int m,x;
    m=length/2;
    node *temp,*pre,*next;
    temp=head;
    //Traversing stack till mid
    for(x=0;x<m;x++)
        temp=temp->next;
    //linking the previous node of middle element to the next element of mid element
    pre=temp->pre;
    next=temp->next;
    pre->next=next;
    next->pre=pre;
    printf("\nMiddle node %d deleted",temp->data);
    //Dealocating memory
    free(temp);
    display(head);
}
//find_middle() displays the middle element
void find_middle()
{
     int m,x;
    m=length/2;
    node *temp;
    temp=head;
    //Traversing stack till mid
    for(x=0;x<m;x++)
        temp=temp->next;
    printf("\nMiddle element is =%d",temp->data);
}

int main()
{
    printf("--------------------STACK--------------------\n\n");
    int flag,a;
    char  input[3],ch;
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
    //repeats the loops until n is pressed
    do
    {
        //List of operations that can be performed
        printf("\nOperation on stack:\n1.Push in stack\n2.Pop from stack\n3.Display middle element\n4.Delte middle element\nchoice=");
        scanf("%d",&a);
        //Switch case to decide the operation
        switch(a)
        {
            case 1:push();break;
            case 2:pop();break;
            case 3:find_middle();break;
            case 4:delete_middle();break;
            default: printf("\nWrong choice entered");
        }
        printf("\nDo you want to perform opration again....(y/n):");
        //Asking to perform opeeration again
        ch=getche();
    }while(ch!='n');
    return 0;
}
