#include<stdio.h>
#define SIZE 5 

int q[SIZE]; 

int f=-1;
int r=-1; //queue is empty 

void insert(int data);
int remove();
void display();



int main(){

    insert(10);
    insert(20);
    insert(30);
    // insert(50); 

    // insert(60);
    display();//10 20 30
    remove();//
    display(); //20 30 

    insert(40);
    insert(50);
    insert(60);

    remove();//20
    remove();//30 
    remove();//40
    remove();//40
    remove();//50
     
    remove();//?? 


     
    return 0;
}



void insert(int data){ // 10  20 

    if(r == SIZE - 1){
        printf("\n Q is Full");
    }else{  
        r++; // 0 
        q[r] = data;  
        printf("\nInsertion done\n");
        if(f == -1){
            f++;
        }
    }
}

void display(){
    int i;
    for(i=f;i<=r;i++){
        printf(" %d",q[i]);
    }   
}

int remove(){
    int data;

    if(f == -1){
        printf("\nQ is Empty");
        return -1; 
    }else{ 

        data = q[f];//30
        if(f == r){
            f= -1;
            r=-1;
        }else{ 
            f++; 
        }
        return data;
    }
}