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

void inorder(struct Node *root){
    if(root != NULL){
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
    return;
}

bool isFullBInaryTree(struct Node *root){
    if(root == NULL)
    return true;
    if((root->left == NULL) && (root->right == NULL))
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
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    if(isFullBInaryTree(root)){
        cout << "It is Full Binary Tree" <<endl;
    }else{
        cout << "It is not Full Binary Tree" <<endl;
    }
    inorder(root);
    cout << endl;
    return 0;
}