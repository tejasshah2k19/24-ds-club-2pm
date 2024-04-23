#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

Node *addNode(int num, Node *root) // 200,200
{                                  // 200 ,300
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
        if (num == root->data)
        {
            return root;
        }

        if (num > root->data) // 100 > 150
        {
            // right
            root->right = addNode(num, root->right); // 300,NULL
        }
        else
        {
            // left
            root->left = addNode(num, root->left); // 100,NULL
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
        cout << " " << root->data; // 50 100
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

int search(int key, Node *root)
{ // 500

    if (root == NULL)
    {
        return -1;
    }
    else if (root->data == key)
    { // 500  == 500
        return 1;
    }
    else if (root->data < key)
    {
        return search(key, root->right); // 500 , 500
    }
    else if (root->data > key)
    {
        return search(key, root->left);
    }
    return 0;
}

int minCount(Node *root, int key, int count) // null,150,0
{

    if (root != NULL)
    {
        if (root->data <= key)
        {
            count++;
        }
        return count + minCount(root->left, key, 0) + minCount(root->right, key, 0);
    }
    return 0;
}

int fact(int num)
{

    if (num == 1)
        return 1;
    else
        return num * fact(num - 1);
} // fact(5) -> f(5) 5*f(4)
  // 4 *f(3) 3*f(2) 2*f(1) 1

void deleteNode(int key, Node *root)
{
    if (root == NULL)
    {
        cout << "\nInvalid Source";
    }
    else if (root->data == key)
    { // 500  == 500
        cout<<"\nFound";
        //delete 

        // 0 child 
        if(root->left == NULL && root->right == NULL){
            cout<<" 0 Child";
        }else if(root->left != NULL && root->right != NULL){
            cout<<" 2 Child";
        }else{
            cout<<" 1 Child" ;  
        }
        // 1 child 

        // 2 child 
    }
    else if (root->data < key)
    {
        deleteNode(key, root->right); // 500 , 500
    }
    else if (root->data > key)
    {
        deleteNode(key, root->left);
    }
}
int main()
{

    Node *first = NULL;
    int count = 0;
    first = addNode(200, first);
    addNode(300, first); // 300,200
    addNode(150, first);
    addNode(100, first);
    addNode(180, first);
    addNode(500, first);

    cout << "\nSearch" << search(500, first);
    cout << "\nSearch" << search(180, first);
    cout << "\nSearch" << search(100, first);
    cout << "\nSearch" << search(150, first);
    cout << "\nSearch" << search(-500, first);
    cout << "\nSearch" << search(5000, first);
    cout << "\nSearch" << search(1500, first);

    //

    cout << "\ncount = " << minCount(first, 150, count);

    // print(5) -> 5 4 3 2 1
    // print(5) -> 1 2 3 4 5

    deleteNode(200, first);

    return 0;
}