#include<stdio.h>
#include<stdlib.h>
#define SIZE 5 

void getData(); //declaration 
void printData(); 
void addData(int location,int data);

int a[5]; 
 
int main(){
    int choice; 
    int location,data; 
    int i;
    int count; 
    int found; 

    for(;;){
        printf("\n0 For Exit\n1 For GetData\n2 For PrintData\n3 For Delete\n4 For Update\n5 For Search\nEnter your choice");
        scanf("%d",&choice); 
        
        switch (choice)
        {
        case 1:
            printf("\nEnter location and data");
            scanf("%d%d",&location,&data);
            addData(location,data);
            break;
        case 2:
            printData();
            break;
        case 3:
            printf("\nEnter location");
            scanf("%d",&location);
            delete(location);
        case 4:
            printf("Enter location and new data");
            scanf("%d%d",&location,&data);

            a[location-1] = data; 
            break;
        case 5:
            printf("\nEnter Num that you want to search?");
            scanf("%d",&data);//20 

            found = 0; //not found
            count = 0;  
        //10 20 20 20 20 
        //20 
        //Found : 4 time  
            for(i=0;i<SIZE;i++){
                if(a[i] == data){
                    found = 1;//found 
                    count++;
                }    
            }

            if(found == 1 ){
                printf("\n%d FOUND %d time(s)",data,count);
            }else{
                printf("\n%d NOT FOUND",data);
            }


        case 0:
            exit(0);
        default:
            printf("\nInvalid Choice PTA !!");
        }
    }
    return 0;
}

void getData(){ //define 
    int i;
  for(i=0;i<SIZE;i++){
    printf("\nEnter Data");
    scanf("%d",&a[i]);
  }  
}

void addData(int location,int data){ //3:location ,100:data  
    int i;
    if(a[location-1] == 0 ){
        a[location-1] = data; 
    }else{             //i=4;i>2;i--  
        for(i=SIZE-1;i>location-1;i--){
            a[i] = a[i-1];
        }
        a[location-1]=data; 
    }
}

void printData(){
    int i;
     for(i=0;i<5;i++){
        printf("\n%d",a[i]);
    }
}

void delete(int location){ //2 

    int i;

    for(i=location-1;i != SIZE-1 ;i++){
        a[i] = a[i+1];
    }

    a[i] = 0; 



}