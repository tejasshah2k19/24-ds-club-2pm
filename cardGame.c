#include<stdio.h>
#define SIZE 10
#include<stdlib.h>
#include<time.h> 

int cards[SIZE]; 
int playerA[SIZE]; //5 
int playerB[SIZE];//5 
int battle[SIZE]; 

   
void generateCards(){
    //10 random number generate -> cards 
    
    int i;
    int num; 
    srand(time(NULL));
    for(i=0;i<SIZE;i++){
        num  = rand()%52; //2 3 4 5 6 7 8 9 10 11  
        if(num == 0 ){
            i--; 
        }else{
            cards[i] = num; 
        }
    }
}

void printCards()
{
    int i;
    printf("\nAll Cards\n");
    for(i=0;i<SIZE;i++){
      printf("\n%d",cards[i]);  
    }

    printf("\nPlayerA Cards\n");
    for(i=0;i<SIZE/2;i++){
      printf("\n%d",playerA[i]);  
    }

    
    printf("\nPlayerB Cards\n");
    for(i=0;i<SIZE/2;i++){
      printf("\n%d",playerB[i]);  
    }
}

void distributeCards(){
    int i,j=0,k=0;
    for(i=0;i<SIZE;i++){
        if(i%2 == 0){
            playerA[j++] = cards[i];
        }else{
            playerB[k++] = cards[i];
        }
    }   
}

void playBattle(){
       
}

int main(){
    generateCards();
    distributeCards();
    printCards();

    return 0; 
}
