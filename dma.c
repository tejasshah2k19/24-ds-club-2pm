#include<stdio.h>
#include<stdlib.h>


int main(){
    // int x;//x[]  
    // int *l;
    // float *f; 
    // l = (int*)malloc(sizeof(int));//4 2 
    // //malloc does not aware in which type of data type i have to assign memory 
    // //we need to cast using same datatype that we use for variable. 
    // //return type of malloc is generic pointer 
    // f = (float*)malloc(sizeof(float)); 

    // printf("\nEnter number");
    // scanf("%d",&x);

    // printf("\n%d ",x); 
    int *a;
    a = (int*)calloc(5,sizeof(int));
    a[0]=45;
    free(a);
    return 0;
}