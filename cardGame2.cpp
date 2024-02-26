#include<iostream>
#include<vector>
#include<stdlib.h>  
#include<time.h>

#define SIZE 10 

using namespace std; 


vector<int> cards;//array -> store n element , remove -- 
//stl 
vector<int> playerA; 
vector<int> playerB; 

vector<int> battle; 


void generateCards(){
    //10 random number generate -> cards 
    
    int i;
    int num; 
    srand(time(NULL));
    for(i=0;i<SIZE;i++){
        num  = rand()%52+1; //2 3 4 5 6 7 8 9 10 11  
        cards.push_back(num);
    }
}


void distributeCards(){
    int i;
    for(i=0;i<SIZE;i++){
        if(i%2 == 0){
            playerA.push_back(cards[i]);
        }else{
            playerB.push_back(cards[i]);
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
    for(auto i:playerA){
        cout<<i<<endl; 
    }

    
    printf("\nPlayerB Cards\n");
    for(auto i:playerB){
        cout<<i<<endl;   
    }
}

void playBattle(int x,int y){
    if(x > y ){
        //playerA
        if(battle.size() != 0){
            for(auto i:battle){
                playerA.push_back(i);
            }
            battle.clear();
        }
        playerA.push_back(x);
        playerA.push_back(y); 
    }else if(x < y){
        //player B
        
        if(battle.size() != 0){
            for(auto i:battle){
                playerB.push_back(i);
            }
            battle.clear();
        }
        playerB.push_back(x);
        playerB.push_back(y); 
    }else if(x == y){
        //tie 
        printf("\n==TIE===");
        battle.push_back(x);
        battle.push_back(y); 

    }
} 


int main(){
    int x,y; 
    int i; 
    generateCards();
    distributeCards();
    printCards();


    for(i=1;i<=100;i++){ 
        
        if(playerA.size()==0){
            printf("\nPlayer  B IS WINNER");
            break; 
        }
        if(playerB.size() == 0){
            printf("\nPlayer A IS WINNER");
            break;
        }
        x = playerA.at(0);
        y = playerB.at(0);

        // playerA.clear(0); 
        playerA.erase(playerA.begin());
        playerB.erase(playerB.begin()); 

        playBattle(x,y); 
    }
    printf("\n==============\n");
    printCards();


    return 0; 
}