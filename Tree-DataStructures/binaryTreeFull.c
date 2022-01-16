#include<stdio.h>
#include<stdlib.h>

typedef struct bTree{
    int data;
    struct bTree *right, *left;
}BST;

BST* root = NULL;

void insert(BST*,BST*);
void traverse(BST*);
BST* search(BST*, int);
int getRightMin(BST*);
BST *delete(BST*, int);
BST *readNode();
int countNodes(BST*,int);


int main()
{
    int choice=0,item, count = 0;
    BST *tempNode, *tempNode2;

    while (choice < 6)
    {
        printf("\n**************\n"
            "1. insert node\n"
            "2. delete node\n"
            "3. list node\n"
            "4. search node\n"
            "5. count nodes\n"
            "6. exit\n"
            "enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                tempNode = readNode();
                insert(root,tempNode);
                break;
            case 2:
                printf("enter item to delete: ");
                scanf("%d",&item);
                tempNode2 = delete(root,item);
                if(tempNode2 != NULL)
                    printf("Item deleted.\n");
                else
                    printf("Item not found.\n");
                break; 
            case 3:
                if(root != NULL)
                    traverse(root);
                else
                    printf("Tree is empty.\n");
                break;
            case 4:
                printf("enter item to search: ");
                scanf("%d",&item);
                tempNode2 = search(root,item);
                if(tempNode2 != NULL)
                printf("Item: %d, left child: %d, right child: %d",
                        tempNode2->data,tempNode2->left,tempNode2->right);
                else
                    printf("Item is not found.");
                break;
            case 5:
                count = countNodes(root, count);
                printf("Number of nodes: %d",count);
                break;
            default:
                break;
        }//switch

    }//while
    
}


///*****FUNCTION DEFINITONS******
BST *readNode(){
    BST *newNode = (BST*)malloc(sizeof(BST));

    printf("enter value of node: \n");
    scanf("%d",&newNode->data);
    newNode->right = newNode->left = NULL;
    return newNode;
}

int countNodes(BST* treeRoot, int sum){
    if(treeRoot == NULL){
        return sum;
    }
    sum++;
    sum = countNodes(treeRoot->left, sum);
    sum = countNodes(treeRoot->right, sum);
    return sum;
}

int getRightMin(BST* treeRoot){
    BST* temp = treeRoot;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

///*****PREORDER TRAVERSAL***
void traverse(BST* treeRoot){
    
    if(treeRoot != NULL){
        printf("Value: %d Node address: %d, ",treeRoot->data, treeRoot);  //root
        traverse(treeRoot->left);       //left 
        traverse(treeRoot->right);      //right
    }
}

BST* search(BST* treeRoot, int item){
    while(treeRoot != NULL && treeRoot->data != item)
    {
        if(item < treeRoot->data)
            treeRoot = treeRoot->left;
        else
            treeRoot = treeRoot->right;
    }
    return treeRoot;
}

void insert(BST* treeRoot,BST* newNode){
    if(treeRoot == NULL){
        root = newNode;
    }
    else{
        if(newNode->data < treeRoot->data){
            if(treeRoot->left == NULL)
                treeRoot->left = newNode;
            else
                insert(treeRoot->left, newNode);
        }
        else{
            if(treeRoot->right == NULL)
                treeRoot->right = newNode;
            else
                insert(treeRoot->right, newNode);
        
        }
    }
}

BST *delete(BST* treeRoot, int item){
    if(treeRoot == NULL)//check tree is empty or not.
    {
        
        return NULL;
    }
    if(treeRoot->data < item){
        treeRoot->right = delete(treeRoot->right, item);
    }
    else if(treeRoot->data > item)
    {
        treeRoot->left = delete(treeRoot->left, item); 
    }
    else //we find the item in the tree.
    {
        if(treeRoot->right == NULL && treeRoot->left == NULL){ //leaf node
            free(treeRoot);
            return NULL;
        }
        else if(treeRoot->right == NULL){ //node has only left child
            BST *temp = treeRoot->left;
            free(treeRoot);
            return temp;
        }
        else if(treeRoot->left == NULL){ //node has only right child
            BST *temp = treeRoot->right;
            free(treeRoot);
            return temp;
        }
        else{// have both right and left child
            int rightMin = getRightMin(treeRoot->right);
            treeRoot->data = rightMin;
            treeRoot->right = delete(treeRoot->right, rightMin);
        }
    }
    return treeRoot;
}