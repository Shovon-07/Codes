#include <iostream>
using namespace std;

int divide_numbers(int a, int b)
{
    if (b == 0)
    {
        throw 1;
    }

    return a / b;
}

int main()
{
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    try
    {
        int result = divide_numbers(a, b);
        cout << "Result: " << result << endl;
    }
    catch (int errorCode)
    {
        cout << "Error Code: " << errorCode << endl;
        cout << "Cannot divide by zero!" << endl;
    }

    return 0;
}
