
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream fout("Hello.txt");

    fout << "Hello";

    cout << "Position after Hello: "
         << fout.tellp() << endl;

    fout << " World";

    cout << "Position after World: "
         << fout.tellp() << endl;

    fout.close();

    return 0;
}
