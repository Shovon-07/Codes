#include <iostream>
using namespace std;

class Complex
{
    int real, imag;

public:
    Complex(int r, int i) { real = r, imag = i; }
    Complex operator+(Complex num)
    {
        Complex temp(0, 0);
        temp.real = real + num.real;
        temp.imag = imag + num.imag;
        return temp;
    }
    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    Complex n1(3, 4);
    Complex n2(2, 5);
    Complex n3 = n1 + n2;
    n3.display();

    return 0;
}
