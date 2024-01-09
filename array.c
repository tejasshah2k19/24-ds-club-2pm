#include<stdio.h>
#include<stdlib.h>

void getData(); //declaration 
void printData(); 

int a[5]; 
 
int main(){
    int choice; 

    for(;;){
        printf("\n0 For Exit\n1 For GetData\n2 For PrintData\nEnter your choice");
        scanf("%d",&choice); 
        
        switch (choice)
        {
        case 1:
            getData();
            break;
        case 2:
            printData();
            break;
        case 0:
            exit(0);
        default:
            printf("\nInvalid Choice PTA !!");
        }
    }
    return 0;
}

void getData(){ //define 
   printf("Enter Location");//2nd 
   printf("Enter Data"); //20 
   
}

void printData(){
    int i;
     for(i=0;i<5;i++){
        printf("\n%d",a[i]);
    }
}