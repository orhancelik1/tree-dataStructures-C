#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int data;
    struct Node *right, *left;
    
}BST;  //BST = Binary Search Tree

BST *root = NULL; //implementing root-head node

//functions
BST *getNewNode(int);
BST* Insert(BST*,int);
BST* Search(BST*,int);

int main(int argc, char const *argv[])
{
    Insert(root,4);
    Insert(root,6);
    Insert(root,7);
    Insert(root,2);
    Insert(root,3);
    int num;
    printf("enter number to search:");
    scanf("%d",&num);
    if(Search(root,num)==num)
    printf("number is found %d",num);
    else printf("number is not found.");

    return 0;
}

BST *getNewNode(int data){
    BST *newNode = (BST*)malloc(sizeof(BST));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
//////insert
BST* Insert(BST *root, int data){
    if(root == NULL){
        root = getNewNode(data);
        
    }
    else if(data <= root->data){
        root->left = Insert(root->left, data);
    }
    else{
        root->right = Insert(root->right,data);
    }
    return root;
}

////////search
BST* Search(BST* root, int data){
    if(root==NULL) return NULL;
    else if(root->data == data) return root;
    else if(data <= root->data) return Search(root->left,data);
    else return Search(root->right, data);
}