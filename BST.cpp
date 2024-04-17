#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

Node *addNode(int num, Node *root)//200,200
{ // 200 ,300
    if (root == NULL)
    {
        root = new Node();
        root->data = num;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else
    {   
        if(num == root->data){
            return root;
        }
        
        if (num > root->data) //100 > 150 
        {
            // right
            root->right = addNode(num, root->right); // 300,NULL
        }
        else
        {
            // left
            root->left = addNode(num, root->left);//100,NULL
        }

        return root;
    }
}

void inOrder(Node *root){//200  

    //left root right 
    if(root != NULL){ 
        inOrder(root->left);
        cout<<" "<<root->data;//50 100 
        inOrder(root->right);
    }
}

void preOrder(Node *root){
    if(root!=NULL){
         cout<<" "<<root->data;//200 
         preOrder(root->left);
         preOrder(root->right); 
    }
}

void postOrder(Node *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<<" "<<root->data; 
    }
}



int main()
{

    Node *first = NULL;

    first = addNode(200, first);
    addNode(300, first); // 300,200
    addNode(150, first);
    addNode(100,first);
    addNode(180,first); 
    addNode(500,first);

    //

//print(5) -> 5 4 3 2 1 
//print(5) -> 1 2 3 4 5 

    return 0;
}