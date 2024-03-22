#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct royal
{
    char name[30];       // 30
    int maths, sci, eng; // 12
    struct royal *next;
} *first = NULL, *last = NULL;

void addStudent()
{

    struct royal *p; // 1 add student

    if (first == NULL)
    {
        first = malloc(sizeof(struct royal));

        printf("enter name and marks of three subjects");
        scanf("%s%d%d%d", &first->name, &first->maths, &first->sci, &first->eng);

        first->next = NULL;
        last = first;
    }
    else
    {
        p = malloc(sizeof(struct royal));

        printf("enter name and marks of three subjects");
        scanf("%s%d%d%d", &p->name, &p->maths, &p->sci, &p->eng);
        p->next = NULL;
        last->next = p;
        last = p;
    }
}

void display()
{
    struct royal *p;

    p = first;

    while (p != NULL)
    {
        printf("\n%s", p->name);
        p = p->next;
    }
}

void addStudentBeg()
{
    struct royal *p;

    p = malloc(sizeof(struct royal));

    printf("enter name and marks of three subjects");
    scanf("%s%d%d%d", &p->name, &p->maths, &p->sci, &p->eng);
    p->next  = first ; 
    first = p; 
}

void insertAny(){
    int search; 

    printf("\nEnter source number"); 
    scanf("%d",&search);//30
       


}


int main()
{

    int choice;
    while (1)
    {
        printf("\n1 For AddStudent\n2 For Display\n3 For Add Beg\nEnter choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            display();
            break;
        case 3:
            addStudentBeg();
            break;
        case 0:
            exit(0);
        }
    }
    return 0;
}