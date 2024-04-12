#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

int main()
{

    // tree root -> 50
    Node *root = new Node();
    root->data = 50;
    root->left = NULL;
    root->right = NULL;
    
    // left -> 60
    Node *leftChild = new Node();
    leftChild->data = 60; 
    leftChild->left = NULL; 
    leftChild->right  = NULL;

    // right -> 70
    Node *rightChild = new Node();
    rightChild->data = 70; 
    rightChild->left = NULL; 
    rightChild->right  = NULL;

    root->left = leftChild;
    root->right = rightChild; 
    cout<< root->data <<" "<< root->right->data <<"  "<< root->left->data;
    return 0;
}