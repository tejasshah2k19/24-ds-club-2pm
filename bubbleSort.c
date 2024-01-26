#include<stdio.h>

#define SIZE 7 

int a[] = {78,65,43,56,8,42,23};	 

void display(){
	int i;
	for(i=0;i<SIZE;i++){
		printf(" %d",a[i]); 
	}
}

void bubbleSort(){

	int i,j; 
	int tmp;
	for(j=1;j<SIZE;j++){
	    for(i=0; i <= SIZE - 2 ; i++ ){
	
		  if( a[i] > a[i+1] ){
		 	tmp = a[i];
			a[i] = a[i+1];
			a[i+1] = tmp; 	
		  } // if 
	    } // i 
      }//j  

}//bubbleSort 

int main(){
	
	printf("\nArray Before Sort\n");
	display();	
	
	bubbleSort();


	printf("\nArray After Sort\n");
	display();	
	
	return 0;

}
