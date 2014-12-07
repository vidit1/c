#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define infinity 999;
/*Defining structure of a single node of a binary tree*/
typedef struct node_type
{
    struct node_type *left;
    int data;
    struct node_type *right;
}node;
int current_level;
int height(node*);
void level(node *,int);
//initializing root node
node *root=NULL;
//create node function traverse the treee according to the data and places the new node
void create_node(node *center,int data)
{
    node *new_node=NULL;
    //check if data is smaller the root node
        if(data<center->data)
        {
            //check if left of the root is empty
            if(center->left==NULL)
            {
                //dynamic allocation
                new_node=(node*)malloc(sizeof(node));
                new_node->data=data;
                new_node->left=NULL;
                new_node->right=NULL;
                //place the new node to the left of root node
                center->left=new_node;
            }
            else
            {
                //if left is not empty, move to the left node and call the function and now the new root is the left node
               create_node(center->left,data);
            }
        }
        //check if the node is greater than the root node
        else if(data>center->data)
        {
            //check if right of the root is empty
             if(center->right==NULL)
            {
                //dynamic allocation
                new_node=(node*)malloc(sizeof(node));
                new_node->data=data;
                new_node->left=NULL;
                new_node->right=NULL;
                //place the new node to the right of root node
                center->right=new_node;
            }
            else
            {
                //if right is not empty, move to the right node and call the function and now the new root is the left node
                create_node(center->right,data);
            }
        }
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
int height(node* temp)
{
    int left,right;
    if(temp==NULL)
    {
        return 0;
    }
    left=height(temp->left);
    right=height(temp->right);
    if(left>right)
    {
        return (left+1);
    }
    else
    {
        return (right+1);
    }
}
void level(node *node,int l)
{
   if(node==NULL)
    return;
  if(l== 1)
    printf("%d\t",node->data);
  else if (l>1)
  {
    level(node->left,l-1);
    level(node->right,l-1);
  }
}

int main()
{
    char input[3];
    int flag,data=0,h,i;
    //dynamic allocatio of the root
    root=(node*)malloc(sizeof(node));
    printf("\nEnter the data to the node");
    //assign data
    scanf("%d",&root->data);
    root->left=NULL;
    root->right=NULL;
    //for new node
    printf("\nDo you want to enter new node(yes/no):");
    scanf("%s",input);
    flag=string_test(input);
    //Iterate itself until flag is 1 i. the string entered is yes
    while(flag==1)
    {
        //for new node
        printf("\nEnter the data to the new node");
        //scan data
        scanf("%d",&data);
        //calling the create node function to create new node
        create_node(root,data);
        printf("\nDo you want to enter new node(yes/no):");
        scanf("%s",input);
        //calling string_test fuction to check whether the input is yes or no
        flag=string_test(input);
    }
    h=height(root);
    printf("\nlevel order traversal:\n");
    printf("%d",root->data);
    for(i=1;i<=h;i++)
    {
       level(root,i);
    }
    return 0;
}
