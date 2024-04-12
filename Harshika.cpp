#include<iostream>

using namespace std; 
class Student{
    int age;
    int pocketMoney; 

    public: 
        Student(){
            age = -1;
            pocketMoney = -1;
        }
        Student(int a,int p){
            age = a;
            pocketMoney = p; 
        }
        void display(){
            cout<<"PM :"<<pocketMoney<<" Age :"<<age;
        }

}; 

int main(){

    Student *s = new Student();//age pocketMoney 
    s->display(); //-1 -1 

    Student *s2 = new Student(18,18000);//age pocketMoney 
    s2->display();

    return 0; 
}