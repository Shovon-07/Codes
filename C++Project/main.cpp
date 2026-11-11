#include <iostream>
using namespace std;

class Number
{
    int value;

public:
    Number(int v) { value = v; }
    Number operator--()
    {
        return value -= 2;
    }
    Number operator+(Number num)
    {
        return value + num.value;
    }
    void display()
    {
        cout << value << endl;
    }
};

int main()
{
    Number n1(10);
    --n1;
    Number n2(20);
    Number n3 = n1 + n2;
    n3.display();

    return 0;
}
