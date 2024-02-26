#include<stdio.h>

int main(){

    int a; 
    int *p; 
    int **q; 

    p = &a; //address of a is store into pointer p 
    a = 1000;
    q = &p;  
    //how to print a's memory address ? 
    printf("\n%u",p); 
    printf("\n%u",&a); 

    //print a's value 
    printf("\n%d",a); 
    //how to access a's value using pointer 
    printf("\n%d",*p); // dereference 

    //how to store address of p ? 

    printf("\n%u",q); //address of p 
    printf("\n%u",*q); //addres of a 
    printf("\n%u",**q); // value of a 
     
    

    return 0;
}