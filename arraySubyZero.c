#include<stdio.h>

#define SIZE 5 

// int a[] = {1,5,0,3,5};

int a[] = {2,2,5,4,6};

//find out the min value from array which is not zero 
int getMin(){
    int i;
    int  min = a[0]; //3
    for(i=1;i<SIZE;i++){
        if(a[i]==0)
            continue;
        if(min ==0  || min > a[i])
        {
            min = a[i]; 
        }
    }
    return min;
}

//subtract min values from array 
void subtract(int min){
    int i;
    for(i=0;i<SIZE;i++){
        if(a[i] != 0){
            a[i] = a[i] - min; 
        }
    }
}

int isZero(){
     int  flag =1;
     int i;
    for(i=0;i<SIZE;i++){
        if(a[i] != 0){
            flag = 0; //we need to perform subtraction --->
            break;     
        }
    }
    return flag; //1 -> all zeros , 0-> 1 element is non zero 
}

int main(){

    int xMin; 
    int count = 0;

    while(isZero() == 0 ){
        count++;//3
        xMin = getMin();//
        subtract(xMin);//
    }

    printf("\nCount= %d",count);
    
    return 0; 
}























// int isZero(){
//     //if all are zero -> 1 
//     //if single element is not zero => 0 
//     int i; 
//     int flag = 1; // all zero 
//     for(i=0;i<SIZE;i++){ 
//         if(a[i] != 0 ){
//             flag = 0; //zero present 
//             break; 
//         }
//     }
//     return flag; //0
// }


// int getMin(){

// }


