#include<iostream>

class Node{
    private: 
        int data; //private 
        Node *next;
        Node *prev; 
    public: 
        void setData(int n){
            data =  n; 
        }
        void setNext(Node* n){
            next = n; 
        }
        void setPrev(Node *n){
            prev = n; 
        }
    
};



Node *head=NULL,*last=NULL;



void addNode(int num){//10{head} 20 30 40 

    if(head == NULL){
        head  = new Node(); 
        head->setData(num); 
        head->setPrev(NULL);
        head->setNext(NULL);
        last = head;  
    }else{
        Node *p = new Node();
        p->setData(num); 
        p->setNext(NULL);
        p->setPrev(last);
        last->setNext(p); 
        last = p ; 

    }

} 

int main(){
     
    addNode(10); 
    addNode(20); 
    addNode(30);

    return 0; 
}
















//linkedlist -> node


//node {data,next node address}

//node -> 2 part -> data | next 


//double linked '


//node 3 parth  prev | data | next


