#include <stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

/*new node*/

struct node *newnode(int value)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->key=value;
    temp->left=temp->right=NULL;
    return temp;
};

//search for specific key

struct node *search(struct node *root,int target)
{
    if (root==NULL||root->key==target)
    return root;
    if (root->key >target)
    return search(root->right,target);
    return search(root->left,target);
};

//insert node with value

struct node *valnode(struct node *node,int value)
{
    if (node==NULL)
    return newnode(value);
    if(value<node->key)
    node->left=valnode(node->left,value);
    else
    node->right=valnode(node->right,value);
    return node;
}

//post order traversal

void postorder(struct node *root)
{
    if (root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->key);
    }
}

//inorder traversal

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d",root->key);
        inorder(root->right);
    }
}

// pre order trevarsal

void preorder(struct node *root)
{
    if (root!=NULL)
    {
        printf("%d", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

// find min

struct node *min(struct node *root)
{
    if (root==NULL)
    return root;
    else if (root->left!=NULL)
    return min(root->left);
    return root;
}