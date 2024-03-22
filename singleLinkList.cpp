#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *head = NULL, *last = NULL;

void insertLast()
{
    // 10 20 30
    int num;
    cout << "\nEntern number";
    cin >> num;
    if (head == NULL)
    {

        head = new Node(); // struct *p *first = malloc()
        head->data = num;
        head->next = NULL;
        last = head;
    }
    else
    {
        Node *p = new Node();
        p->data = num;
        p->next = NULL;
        last->next = p;
        last = p;
    }
}

void insertBeg()
{
    // 30 20 10
    int num;
    cout << "\nEnter number";
    cin >> num; // 50

    Node *p = new Node();
    p->data = num;  // 50
    p->next = head; // head
    head = p;
}

void display()
{
    Node *p;
    cout << endl
         << "elements in the linked list" << endl;
    for (p = head; p != NULL; p = p->next)
    {
        cout << p->data << " "; // 50
    }
}

void insertAny()
{
    // destination,num
    int source, num;
    Node *q;
    cout << "Enter source and number";
    cin >> source >> num;
    // 20 2000

    for (q = head; q != NULL; q = q->next)
    {
        if (q->data == source)
        {
            break;
        }
    }

    if (q == NULL)
    {
        cout << "Invalid Source PTA";
    }
    else
    {
        Node *p = new Node();
        p->data = num;
        p->next = q->next;
        q->next = p;
    }
}

void delBeg()
{
    Node *p;
    p = head;
    head = head->next;
    delete p;
}

void delLast()
{
    Node *p;
    Node *q;

    q = head;
    // set q
    while (q->next != last)
    { // q!=NULL
        q = q->next;
    }

    p = last;
    q->next = NULL;
    last = q;
    delete p;
}

void delAny()
{

    Node *p,*q,*r;
    int src;
    cout << endl
         << "Enter num";
    cin >> src; // 300
    // 0

    if (head->data == src)
    {
        delBeg();
    }
    else if (last->data == src)
    {
        delLast();
    }
    else
    {

        p = head;
        while (p != NULL)
        {
            if (p->data == src)
            {
                // 1
                break;
            }
        }

        if (p == NULL)
        {
            cout << endl
                 << "Invalid Source";
        }
        else
        {
            // any
            r = p->next; 
            q=head;
            while(q->next != p){
                q=q->next; 
            }

            q->next =r;
            delete p; 
        }
    }
}

int main()
{

    insertLast(); // 10
    insertLast(); // 20
    insertLast(); // 30
    display();    // 10 20 30
    insertBeg();  // 50
    display();    // 50 10 20 30
    insertAny();  // 20 2000
    display();    // 50 10 20 2000 30

    return 0;
}
