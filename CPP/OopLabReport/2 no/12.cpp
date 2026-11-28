#include <iostream>
using namespace std;

void Xhandler(int test)
{
    if (test == 0)
        throw 1;

    else if (test == 1)
        throw 'A';

    else if (test == 2)
        throw 1.5;
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        try
        {
            Xhandler(i);
        }
        catch (...)
        {
            cout << "Exception caught!" << endl;
        }
    }

    return 0;
}
