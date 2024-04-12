#include <iostream>

class Node
{
private:
    int data; // private
    Node *next;
    Node *prev;

public:
    Node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int num)
    {
        data = num;
        next = NULL;
        prev = NULL;
    }
    Node(int num, Node *n, Node *p)
    {
        data = num;
        next = n;
        prev = p;
    }

    void setData(int n)
    {
        data = n;
    }
    void setNext(Node *n)
    {
        next = n;
    }
    void setPrev(Node *n)
    {
        prev = n;
    }
    Node *getNext()
    {
        return next;
    }
    int getData()
    {
        return data;
    }
    Node *getPrev()
    {
        return prev;
    }
};

Node *head = NULL, *last = NULL;

// insert at last
void addNode(int num)
{ // 10{head} 20 30 40

    if (head == NULL)
    {
        head = new Node(num);
        last = head;
    }
    else
    {
        Node *p = new Node(num, NULL, last);
        // data next prev
        last->setNext(p);
        last = p;
    }
}

void display()
{
    Node *p;
    for (p = head; p != NULL; p = p->getNext())
    {
        std::cout << " " << p->getData();
    }
}

void reverseDisplay()
{
    // 30 20 10
    Node *p;
    for (p = last; p != NULL; p = p->getPrev())
    {
        std::cout << " " << p->getData();
    }
}

void addBeg(int num)
{
    Node *p = new Node(num, head, NULL);
    head->setPrev(p);
    head = p;
}

// h.w -> addAny(100,1000) -> after 100 insert 1000

void removeLast()
{

    Node *p = last->getPrev();
    p->setNext(NULL);
    delete last;
    last = p;
}

void removeBeg()
{

    Node *p = head;
    head = head->getNext();
    head->setPrev(NULL);
    delete p;
}

// h.w -> removeAny(100) -> 100 will remove

void addAny(int newNum, int source)
{
    Node *p = head;

    while (p != NULL)
    {
        if (p->getData() == source)
        {
            break;
        }
        p = p->getNext();
    }

    if( p == NULL){
       std::cout<<"\nInvalid Source";
    }else{
        if(p == last){
            addNode(newNum);
        }else{
            Node *q = p->getNext();

            Node *tmp = new Node();
            tmp->setData(newNum);
            tmp->setNext(q);
            tmp->setPrev(p);

            p->setNext(tmp);
            q->setPrev(tmp); 
        }
    }
}

int main()
{

    addNode(10); // last
    addNode(20);
    addNode(30);

    display();
    reverseDisplay();

    addBeg(100);

    return 0;
}

// linkedlist -> node

// node {data,next node address}

// node -> 2 part -> data | next

// double linked '

// node 3 parth  prev | data | next
