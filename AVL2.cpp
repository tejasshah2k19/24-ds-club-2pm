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
    int lh = 0, rh = 0;

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
}
int calculateBF(Node *root)
{
    int lh, rh;

    if (root->left == NULL)
    {
        lh = 0;
    }
    else
    {
        lh = root->left->height;
    }

    if (root->right == NULL)
    {
        rh = 0;
    }
    else
    {
        rh = root->right->height;
    }

    int bf = lh - rh;
    return bf;
}

Node *lefRotate(Node *root)
{
    Node *newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    root->right = NULL;

    return newRoot;
}
Node *rightRotate(Node *root)
{
    Node *newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    root->left = NULL;
    return newRoot;
}

Node *addNode(int num, Node *root) // 200,200
{                                  // 200 ,300
    if (root == NULL)
    {
        root = new Node();
        root->data = num;
        root->left = NULL;
        root->right = NULL;
        root->height = 1; // new node
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
            // height
            root->height = calculateHeight(root);
            int bf = calculateBF(root);
            cout << endl
                 << root->data << " " << bf;
            if (bf < -1 && num > root->right->data)
            {
                cout << "\nRight:Right Imbalance Found";
                // 10
                return lefRotate(root);
                // 20
            }
            else if (bf < -1 && num < root->right->data)
            {
                cout << "\nRight:Left Imbalance Found";
                root->right = rightRotate(root->right);
                return lefRotate(root);
            }
        }
        else
        {
            // left
            root->left = addNode(num, root->left); // 100,NULL
            root->height = calculateHeight(root);
            int bf = calculateBF(root);
            cout << endl
                 << root->data << " " << bf;
            if (bf > 1 && num < root->left->data)
            { // left
                cout << "\nLeft:Left Imbalance Found";
                return rightRotate(root);
            }
            else if (bf > 1 && num > root->left->data)
            {
                cout << "\nLeft:Right Imbalance Found";
                root->left = lefRotate(root->left);
                return rightRotate(root);
            }
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
        cout << " " << root->data << "(" << root->height << ")"; // 50 100
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
// bf => LH - RH

int main()
{

    Node *first = NULL;
    int count = 0;
    // LL
    // cout << endl
    //      << "inserting 300";
    // first = addNode(300, first);
    // cout << endl
    //      << "inserting 200";
    // first = addNode(200, first); // 300,200
    // cout << endl
    //      << "inserting 100";
    // first = addNode(100, first);
    // cout << "\n*********\n";

    // RR
    cout << endl
         << "inserting 10";
    first = addNode(10, first);
    cout << endl
         << "inserting 20";
    first = addNode(20, first); // 300,200
    cout << endl
         << "inserting 30";
    first = addNode(30, first);

    cout << endl
         << "inserting 40";
    first = addNode(40, first);
    cout << endl
         << "inserting 50";
    first = addNode(50, first);
    cout << endl
         << "inserting 60";
    first = addNode(60, first);
    cout << endl
         << "inserting 70";
    first = addNode(70, first);

    cout << "\n*********\n";

    // LR
    //  cout<<endl<<"inserting 300";
    //  first = addNode(300, first);
    //  cout<<endl<<"inserting 200";
    //  first = addNode(200, first); // 300,200
    //  cout<<endl<<"inserting 250";
    //  first = addNode(250, first);
    //  cout<<"\n*********\n";

    // RL
    //  cout<<endl<<"inserting 300";
    //  first = addNode(300, first);
    //  cout<<endl<<"inserting 500";
    //  addNode(500, first); // 300,200
    //  cout<<endl<<"inserting 400";
    //  addNode(400, first);
    //  cout<<"\n*********\n";

    inOrder(first);
    return 0;
}