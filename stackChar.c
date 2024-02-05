#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10 

char stack[SIZE]; 
int top = -1; //stack empty 

void push(char data);
char pop(); 
void display();
int isEmpty();

// int main(){
    
//    char str[10];
//     int i;

//    printf("\nEnter Name");
//    gets(str); //royal 

//     for(i=0;str[i] != '\0' ; i++){
//         push(str[i]);
//     }

//     display();

//     return 0;
// }

void push(char data){
    if(top == SIZE  - 1){
        printf("\nSTack OverFlow");
        return; 
    }else{
        top++;
        stack[top] = data; 
    }
}

void display(){
    int i;
    for(i=top ; i>= 0 ;i--){
        printf("%c",stack[i]);
    }
}

char pop(){
    if(top == -1){
        // printf("STACK UNDERFLOW");
        return -1;
    }else{
        return stack[top--];
    }
}

int isEmpty(){
    if(top == -1){
        return 1;//empty 
    }else{
        return 0;
    }
}


//1 top 
//3