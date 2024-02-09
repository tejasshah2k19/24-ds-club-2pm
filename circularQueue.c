#include<stdio.h>
#define SIZE 5 

int q[SIZE];

int f=-1,r=-1;

void insert(int data);
int remove1(); 
void display();


int main(){

    insert(10); //1 
    return 0; 
}

void insert(int data){
    if(r == SIZE - 1 && f == 0 ){ // 
        printf("\nQueue is Full");
    }else if( r == f-1){ // 
      printf("\nQueue is Full");
    }else{
        //insert 
        if(r==SIZE-1){
            //cycle 
            r = 0 ; 
            q[r] = data; 
        }else{
            r++; 
            q[r]  = data; 
        }
        if(f == -1 ){
            f  = 0;
        }
    }
}

int remove1(){
    int num;

    if(f == -1 ){
        printf("\nQueue is Empty");
        num=-1; 
    } else if(f< r){
        num = q[f]; 
        f++; 
    }else if(f == SIZE - 1 ){
        num = q[f]; 
        f=0;
    }else if(f ==r){
        num = q[f]; 
        f=-1;
        r=-1;
    }
    return num; 
}

void display(){
    int i;

    if(r >= f){ 
        for(i=f;i<=r;i++){
             printf(" %d",q[i]);
        }
    }else{

        for(i=f;i<SIZE;i++){
            printf(" %d",q[i]);
        }
        for(i=0;i<=r;i++){
            printf(" %d",q[i]);
        }
    }

}
