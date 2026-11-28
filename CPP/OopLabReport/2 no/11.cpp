
#include <iostream>
using namespace std;

int main()
{
    try
    {
        cout << "Msg from try block" << endl;
        throw 1;
        cout << "This statement will not execute" << endl;
    }
    catch (int error)
    {
        cout << "Error value: " << error << endl;
    }

    cout << "The program is running from outside the try-catch block" << endl;

    return 0;
}
