#include<stdio.h>

struct student{
    char name[30];
    int age; 

}a,b,c,d,r;

int main(){

    struct student s; //name age 
    struct student x; //name age 
    struct student *p; 

    printf("\nEnter name and age");
    scanf("%s%d",&s.name,&s.age); 

    printf("\nName : %s\nAge : %d",s.name,s.age); 

    p = &s; 
    printf("\nName : %s\nAge : %d",p->name,p->age); 

    return 0;
}