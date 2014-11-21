#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/*Definig the structure of each nod of the linked list*/
struct node_type
{
	int data;
	struct node_type * next;
}*head=NULL;
int length=0;
typedef struct node_type node;
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
    //Returning the new node to the main fuction
    return new_node;
}
//swaping function swapes the node at given postion from end and starting
void swaping(int k,int flag)
{
    int x,m;
    node *pre_s,*current_s,*next_s,*pre_l,*current_l,*next_l;
    current_s=head;
    pre_s=current_s;
    //finding the kth node from starting and assigning pointers
    for(x=0;x<k;x++)
    {
        pre_s=current_s;
        current_s=current_s->next;
    }
    next_s=current_s->next;
    printf("\nfrom beginig node to be swaped=%d",current_s->data);
    m=length-k;
    current_l=head;
    pre_l=current_l;
    //finding the kth node from end and assigning pointers
    for(x=0;x<m-1;x++)
    {
        pre_l=current_l;
        current_l=current_l->next;

    }
    next_l=current_l->next;
    printf("\nfrom end node to be swaped=%d",current_l->data);
    //if in consecutive nodes pair first node chosen
    if(flag==1)
    {
        pre_s->next=current_l;
    	current_l->next=current_s;
    	current_s->next=next_l;
    	display();
    }
    //if in consecutive node pair second node is chosen
    else if(flag==2)
    {
        pre_l->next=current_s;
        current_s->next=current_l;
        current_l->next=next_s;
        display();
    }
    //rest for all positions
    else
    {
        pre_s->next=current_l;
        current_l->next=next_s;
    	pre_l->next=current_s;
        current_s->next=next_l;
    	display();
	}
}
//swaping_start() function swaps the first and last nodes of the list
void swaping_start()
{
	int x=0;
	node *temp,*current,*pre_l,*next_s;
	temp=head;
	next_s=temp->next;
	current=head;
	//traversing till end
	for(x=0;x<length-1;x++)
	{
		pre_l=current;
		if(current->next!=NULL)
        {
			    current=current->next;
        }
		else
        {
			    break;
        }
	}
	//swaping nodes
	head=current;
	pre_l->next=temp;
	current->next=next_s;
	temp->next=NULL;
	display();
}
/*Display function takes the value of head from the main function
and displays the full linkes list*/
void display()
{
    printf("\nLinked list:");
    node *current=head;
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
    printf("\nLength of list = %d",length);

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
int main()
{
    int m,k,j,flag,consecutive_flag=0,x;
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
    //Calling the display function and passing head as the value
    display();
    printf("\nEnter the position of the node to swap from end and begining: ");
    //input the position
	scanf("%d",&m);
    //postion should be less than the length of the linked list
	if(m<length)
    {
        j=length%2;
        //if lenght is odd
       if(j!=0)
       {
	       	 j=length/2;
	       	 j++;
	       	 consecutive_flag=0;
	       	 //if middle element and postion is same, no change
	       	 if(j==m)
	       	 {
	       	 	printf("\nPostion entered id middle position s o no changes..");
	       	 	display(head);
	         }
	         //if position es enteres is start or the end of list
	       	 else if(m==1||m==length)
	       	 {
	       			printf("\ncalling swap");
	       			swaping_start();
	       	}
	       	//Swaping for any other positions
             else
                     swaping(m-1,consecutive_flag);
       }
       //if lengthis ever
       else
       {
            x=length/2;
            //if postion is half the length i.e to swap to nodes
            if(m==x)
            {
                consecutive_flag=1;
                swaping(m-1,consecutive_flag);
            }
            //if postion is half the length i.e to swap to nodes
            else if(m==(x+1))
            {
                consecutive_flag=2;
                swaping(m-1,consecutive_flag);
            }
            //if position es enteres is start or the end of list
            else if(m==1||m==length)
            {
                swaping_start();
            }
            //for rest all postions
            else
                swaping(m-1,consecutive_flag);
       }
    }
    else
    printf("\nThe position entered is greater than the length of the linked list");
    return 0;
}
