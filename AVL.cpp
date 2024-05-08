#include <iostream>

using namespace std;
class Node
{

public:
    int data;
    Node *left;
    Node *right;
    int height;
};
int calculateHeight(Node *root)
{
    int lh = 0;
    int rh = 0;
    if (root->left != NULL)
    {
        lh = root->left->height;
    }
    if (root->right != NULL)
    {
        rh = root->right->height;
    }

    if (lh > rh)
    {
        return lh + 1;
    }
    else
    {
        return rh + 1;
    }
    // return 2 ;
}
int calculateBF(Node *root){
    int lh =0 ;
    int rh = 0; 

    if(root->left != NULL){
        lh = root->left->height;
    }
    if(root->right != NULL){
        lh = root->right->height;
    }

    return lh - rh; 

}
Node *addNode(Node *root, int num)
{
    if (root == NULL)
    {
        root = new Node();
        root->data = num;
        root->left = NULL;
        root->right = NULL;
        root->height = 1;
        return root;
    }
    else if (num > root->data)
    {
        root->right = addNode(root->right, num);
        // right insert
        int height = calculateHeight(root);
        root->height = height; 

        //bf = calculateBF(root);
    }
    else
    {
        root->left = addNode(root->left, num);
        // left insert
        int height = calculateHeight(root);
        root->height = height; 
   
    }

    return root;
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << " " << root->data<<"("<<root->height<<")";
        inOrder(root->right);
    }
}
int main()
{

    Node *root = NULL;

    root = addNode(root, 200);
    addNode(root,100);
    addNode(root,300);//1 
 

    inOrder(root);
    
    return 0;
}