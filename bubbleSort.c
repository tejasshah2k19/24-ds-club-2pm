#include<stdio.h>

#define SIZE 7 

// n*n 

// int a[] = {78,65,43,56,8,42,23};	 

int a[] = {1,2,3,4,5,6,7};	
		//


void display(){
	int i;
	for(i=0;i<SIZE;i++){
		printf(" %d",a[i]); 
	}
}

void bubbleSort(){

	int i,j; 
	int tmp,sorted;
	int count=0;
	for(j=1;j<SIZE;j++){ // 6 times   1 2 3 4 5 6 
	   
	//1st time 2nd time 
		sorted = 0; 
	    for(i=0; i <= SIZE - 2 - j + 1   ; i++ ){
		//0 1 2 3 4 5 
		count++;
		  if( a[i] > a[i+1] ){
			sorted = 1;
		 	tmp = a[i];
			a[i] = a[i+1];
			a[i+1] = tmp; 	
		  } // if 
	    } // i 
		
		if(sorted==0)
			break; 
		
		printf("\nPass %d =>\n",j);
		display();
      }//j  

      printf("\n%d times executed",count);	 
}//bubbleSort 

int main(){
	
	printf("\nArray Before Sort\n");
	display();	
	
	bubbleSort();


	printf("\nArray After Sort\n");
	display();	
	
	return 0;

}
