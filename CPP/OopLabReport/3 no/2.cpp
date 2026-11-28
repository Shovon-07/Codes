
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream fout("number.txt");

    fout << "123456789";

    fout.close();

    ifstream fin("number.txt");

    fin.seekg(2, ios::beg);

    char ch;

    fin.get(ch);
    cout << "Character: " << ch << endl;
    cout << "Position: " << fin.tellg() << endl;

    fin.get(ch);
    cout << "Character: " << ch << endl;
    cout << "Position: " << fin.tellg() << endl;

    fin.get(ch);
    cout << "Character: " << ch << endl;
    cout << "Position: " << fin.tellg() << endl;

    fin.close();

    return 0;
}
