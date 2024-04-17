#include <iostream>
using namespace std;

void add()
{
    cout << "add()";
}

void sub()
{
    add();
    cout << "sub()";
}

void print(int n) // 5 4 3   2 1 
{ 
    if (n != 0)
    {

        print(n - 1); //
        cout << n;//1 
    }
}
int main()
{
 
    print(5);
    return 0;
}