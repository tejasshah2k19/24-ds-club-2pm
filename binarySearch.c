#include<stdio.h>
#define SIZE 10 

int a[]={10,20,30,40,50,60,70,80,90,100};

void getData(){

}

void printArray(){
    int i;
    for(i=0;i<SIZE;i++){
        printf("\n%d",a[i]);
    }
}

void binarySearch(int search){//80 
    int min,max,mid; 

    min = 0;
    max = SIZE - 1; //9

    while(min<=max){
        mid = (min+max)/2;//0+9/2 -> 4   -> 

        if(a[mid] == search){
            printf("\n Found");
            break;
        }else if(search > a[mid]){
            //right 
            min = mid + 1; 
        }else {
            max = mid - 1;
        }
    }

}


int main(){
    int s; 
    getData();
    printArray();
    printf("\nEnter number that you want to search");
    scanf("%d",&s); 
    binarySearch(s);//80 
    return 0; 
}