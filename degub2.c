#include<stdio.h>

#define SIZE 5 

int main(){
    int i,j,k;

    int a[] = {11,33,22,5,4};

    
    for(i=0;i<SIZE;i++){//4 
        for(j=0;j<i;j++){//0 1  
            k = a[j];
            a[j] = a[j+1];
            a[j+1] = k ;
        }
    }


    for(i=0;i<SIZE;i++){
        printf(" %d",a[i]);
    }


    return 0;
}