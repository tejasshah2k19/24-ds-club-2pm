#include "stackChar.c"
#include<string.h>


int main(){

    char str[10]; 
    int i; 
    int flag=0;
    printf("Enter expression");
    scanf("%s",&str);//{{}}  {()} {]{}}   {}   {  [ ] }     
 

    for(i=0;str[i]!='\0';i++){
        if(str[i] == '{' || str[i] == '(' || str[i] == '['){
            push(str[i]); 
        }else if(str[i] == '}'){
            if('{' != pop()){
                flag=-1;//gadbad 
            }
        }else if(str[i] == ']'){
            if(pop() != '['){
                flag = -1;
            }
        }else if(str[i] == ')'){
            if(pop() != '('){
                flag = -1;
            }
        }
    }
// 
    if( isEmpty() == 1 && flag == 0){
        printf("\nValid");
    }else{
        printf("\nInValid");
    }




    return 0; 
}
// {}()  
// {[()]}
// {[)}