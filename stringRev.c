#include "stackChar.c"
#include<string.h>

int main(){
    
   char str[10];
    int i;

   printf("\nEnter Name");
   gets(str); //royal 

    for(i=0;str[i] != '\0' ; i++){
        push(str[i]);
    }

    display();

    return 0;
}


//royal -> layor 

// {}()  
// {[()]}
// {[)}

