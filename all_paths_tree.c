#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/*Defining structure of a single node of a binary tree*/
typedef struct node_type
{
    struct node_type *left;
    int data;
    struct node_type *right;
}node;
//initializing root node
node *root=NULL;
void paths(node *,int[],int);
void print(int[],int);
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
//definig all the paths possible int a tree
void paths(node *node,int path[],int len)
{
    //if node is NULL tha return
    if(node==NULL)
    {
        return;
    }
    //else store the value of the node in the array
    else
    {
        path[len]=node->data;
        len++;
    }
    //if node is the leaf than call the printing function to print the path
    if(node->left==NULL&&node->right==NULL)
    {
        printf("\nnew path:");
        print(path,len);
    }
    //else move traverse to the left and right child node of the root
    else
    {
        paths(node->left,path,len);
        paths(node->right,path,len);
    }
}
//printing the path
void print(int path[],int len)
{
    int i=0;
    for(i=0;i<len;i++)
    {
        printf("%d  ",path[i]);
    }
}

int main()
{
    char input[3];
    //array to store paths
    int path[1000];
    int flag,data=0;
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
    //calling path function and apssing its attributes
    paths(root,path,0);
    return 0;
}
