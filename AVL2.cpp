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


int calculateHeight(Node *root){
    int lh=0,rh=0; 

    if(root->left != NULL){
        lh = root->left->height; 
    }

    if(root->right != NULL){
        rh = root->right->height;
    }

    if(lh > rh){
        return lh+1;
    }else{
        return rh+1;
    }

}

int calculateBF(Node *root){
    int lh=0,rh=0; 

    if(root->left != NULL){
        lh = root->left->height; 
    }

    if(root->right != NULL){
        rh = root->right->height;
    }

    return lh - rh; 

}
Node *addNode(int num, Node *root) // 200,200
{                                  // 200 ,300
    if (root == NULL)
    {
        root = new Node();
        root->data = num;
        root->left = NULL;
        root->right = NULL;
        root->height= 1; // new node 
        return root;
    }
    else
    {
        if (num == root->data)
        {
            return root;
        }

        if (num > root->data) // 100 > 150
        {
            // right
            root->right = addNode(num, root->right); // 300,NULL
            //height 
            root->height = calculateHeight(root);
            int balanceFactor  = calculateBF(root);
            cout<<"\nRIGHT -> BF of "<<root->data<<" = "<<balanceFactor;


        }
        else
        {
            // left
            root->left = addNode(num, root->left); // 100,NULL
            root->height = calculateHeight(root);
            int balanceFactor  = calculateBF(root);
            cout<<"\nLEFT -> BF of "<<root->data<<" = "<<balanceFactor;

        }

        return root;
    }
}

void inOrder(Node *root)
{ // 200

    // left root right
    if (root != NULL)
    {
        inOrder(root->left);
        cout << " " << root->data<<"("<<root->height<<")"; // 50 100
        inOrder(root->right);
    }
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << " " << root->data; // 200
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << " " << root->data;
    }
}
 //bf => LH - RH 

  
 int main()
{

    Node *first = NULL;
    int count = 0;
    //LL 
    // cout<<endl<<"inserting 300";
    // first = addNode(300, first);
    // cout<<endl<<"inserting 200";
    // addNode(200, first); // 300,200
    // cout<<endl<<"inserting 100";
    // addNode(100, first); 
    // cout<<"\n*********\n";

    //RR 
    // cout<<endl<<"inserting 300";
    // first = addNode(300, first);
    // cout<<endl<<"inserting 400";
    // addNode(400, first); // 300,200
    // cout<<endl<<"inserting 500";
    // addNode(500, first); 
    // cout<<"\n*********\n";


    //LR 
    // cout<<endl<<"inserting 300";
    // first = addNode(300, first);
    // cout<<endl<<"inserting 200";
    // addNode(200, first); // 300,200
    // cout<<endl<<"inserting 250";
    // addNode(250, first); 
    // cout<<"\n*********\n";



    //RL
    cout<<endl<<"inserting 300";
    first = addNode(300, first);
    cout<<endl<<"inserting 500";
    addNode(500, first); // 300,200
    cout<<endl<<"inserting 400";
    addNode(400, first); 
    cout<<"\n*********\n";

    inOrder(first);
    return 0;
}