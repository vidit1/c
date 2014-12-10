#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//definig the structre of each node in a tree
typedef struct node_type
{
    struct node_type *left;
    int data;
    struct node_type *right;
}node;
//initializing root node
node *root=NULL;
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
//direction adds a new node to the tree dependingon the direction provided by the user
void directions(node *temp,char dir)
{
    //switch case for left and right movement
    switch(dir)
    {
    //if l is pressed it meanes we move to left of the parent node
    case 'l':
        //if left of the parent node is null then new node is added
        if(temp->left==NULL)
        {
            //initialization
            node *new_node=NULL;
            //allocating memory to the new node
            new_node=(node*)malloc(sizeof(node));
            //scanning data
            printf("\nEnter the data:");
            scanf("%d",&new_node->data);
            //linking it with tree
            temp->left=new_node;
            new_node->left=NULL;
            new_node->right=NULL;
        }
        //else than move to left of parent node and ask for fyrther directions
        else
        {
            temp=temp->left;
            printf("\nMoved to %d further direction(l/r)?",temp->data);
            dir=getche();
            directions(temp,dir);
        }
        break;
    //if r is pressed it meanes we move to right of the parent node
    case 'r':
        //if right of the parent node is null then new node is added
        if(temp->right==NULL)
        {
            //initialization
            node *new_node=NULL;
            //allocating memory to the new node
            new_node=(node*)malloc(sizeof(node));
            //scanning data
            printf("\nEnter the data:");
            scanf("%d",&new_node->data);
            //linking it with tree
            temp->right=new_node;
            new_node->left=NULL;
            new_node->right=NULL;

        }
        //else than move to right of parent node and ask for fyrther directions
        else
        {
            temp=temp->right;
            printf("\nMoved to %d. further direction(l/r)?",temp->data);
            dir=getche();
            directions(temp,dir);
        }
        break;
    //if wrong key is pressed
    default:
        printf("\nwrong directin entered press 'l' tom move left and press 'r' to move right");
        dir=getche();
        directions(temp,dir);
    }
}
//prints the tree in in_order form
void print_inorder(node *center)
{
    if (center!=NULL)
    {
        print_inorder(center->left);
        printf("%d\n",center->data);
        print_inorder(center->right);
    }
}
//convert function starts working from the bottom of the tree and start checking from the bottom whether it satisfies the property
//it calculates the difference between the sum of left and right node and parent node. if the diff is negative than increament the
//children node, if the differnce is positive the parent node is increamented
void convert(node *temp)
{
    //intializing the variables
    int left=0,right=0,diff=0;
    //if node is leaf node or the node is null than return
    if(temp==NULL||(temp->left==NULL&&temp->right==NULL))
        return;
    //by recursively calling the convert the functon move to the bottom of tree
    //find the difference
    else
    {
        //recursive calling
         convert(temp->left);
         convert(temp->right);
         //assigning the value to variables
         if(temp->left!=NULL)
            left=temp->left->data;
         if(temp->right!=NULL)
            right=temp->right->data;
        //calculate the differnce between the parent data and children data
        diff=left+right-temp->data;
        //if difference is negative increament is done in children
        if(diff<0)
        {
            //converting to positive integer
            diff=(-diff)
            //callind add function to add difference in the childrens
            add(temp,diff);
        }
        //difference is positive than add in parent data
        else if(diff>0)
        {
            //adding in parent data
            temp->data=temp->data+diff;
        }
    }
}
//add function adds the difference calculated from above function
//and adds the value to one of the children
void add(node* temp,int diff)
{
    //if left child is present than add it to it
    if(temp->left!=NULL)
    {
        temp->left->data=temp->left->data+diff;
        //add the differnce to further children of the node in which the value is added
        add(temp->left,diff);
    }
    //if right child is present than add diff to it
    else if(temp->right!=NULL)
    {
        temp->right->data=temp->right->data+diff;
        //add the differnce to further children of the node in which the value is added
        add(temp->right,diff);
    }
}
int main()
{   //intializing different variables accordingly
    char input[3],dir;
    int flag,data=0;
    //scan data fo root
    printf("enter the data to the root");
    root=(node*)malloc(sizeof(node));
    scanf("%d",&root->data);
    root->right=NULL;
    root->left=NULL;
    //asking for new node to added or not
     printf("\nDo you want to enter new node(yes/no):");
    scanf("%s",input);
    //chacking the input if yes than return 1 and enters into while loop
    flag=string_test(input);
    while(flag==1)
    {
        //asking to direction to traverse tree from root for adding new node
        printf("\nStartinf from root enter direction(l/r)?");
        dir=getche();
        //calling direction function
        directions(root,dir);
        printf("\nDo you want to enter new node(yes/no):");
        scanf("%s",input);
        //calling string_test fuction to check whether the input is yes or no
        flag=string_test(input);
    }
    printf("\nInorder traversal:");
    //printing the tree
    print_inorder(root);
    //calling convert function to convert the tree such that the new tree can satify the children sum property
    convert(root);
    printf("\nChanging the tree so that the new tree can satisfies the children sum property");
    printf("\nInorder traversal:");
    //travering the new tree in inorder
    print_inorder(root);
    return 0;
}
