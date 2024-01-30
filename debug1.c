#include<stdio.h>

int main(){
    int i,j,k;


for(j=1;j<=3;j++){ //1 2 3 
    for(i=1;i<=5 - j + 1 ;i++){
        printf("%d ",i);
    }//1 2 3 4 5
    //1 2 3 4 
    //1 2 3  
    printf("\n");
}

    return 0;
}