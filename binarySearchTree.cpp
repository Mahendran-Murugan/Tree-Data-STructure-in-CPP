#include<iostream>
using namespace std;

struct Node
{
    int key;
    struct Node *left, *right;
};

struct Node* newnode(int k){
    struct  Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->key= k;
    node->right=node->left = NULL;
    return node;
}



bool isFullBInaryTree(struct Node *root){
    if(root == NULL)
    return true;
    if((root->left) && (root->right) == NULL)
    return true;
    if((root->left) && (root->right))
    return isFullBInaryTree(root->left) && isFullBInaryTree(root->right);
    return false;
}

int main(){
    struct Node *root = NULL;
    root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->left->right->left = newnode(6);
    root->left->right->right = newnode(7);
    if(isFullBInaryTree(root)){
        cout << "It is Full Binary Tree" <<endl;
    }else{
        cout << "It is not Full Binary Tree" <<endl;
    }
    return 0;
}