#include<stdio.h>

#define SIZE 7 

// n*n 

int a[] = {78,65,43,56,8,42,23};	 

// int a[] = {1,2,3,4,5,6,7};	
		//


void display(){
	int i;
	for(i=0;i<SIZE;i++){
		printf(" %d",a[i]); 
	}
}

void selectionSort(){

	int i,j; 
	int tmp,sorted;
	int count=0,min;

    //78,65,43,56,8,42,23   
   //    min

    min=0;//a[min]
    for(i=1;i<SIZE;i++){
        if(a[min] > a[i]){
            min = i; 
        }
    }
    printf("\n%d ",a[min]); //8 8  



}//selectionSort 

int main(){
	
	printf("\nArray Before Sort\n");
	display();	
	
	selectionSort();


	printf("\nArray After Sort\n");
	display();	
	
	return 0;

}
