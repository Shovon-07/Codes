
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream fout;

    fout.open("data.txt", ios::app);

    fout << "Hello World" << endl;
    fout << "Welcome to C++" << endl;

    fout.close();

    ifstream fin("data.txt");

    string line;

    while (getline(fin, line))
    {
        cout << line << endl;
    }

    fin.close();

    return 0;
}
