
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream fout("data.txt");

    fout << "Snigdha";

    fout.seekp(1, ios::beg);

    fout << "zerin";

    fout.close();

    ifstream fin("data.txt");

    string line;

    getline(fin, line);

    cout << "File Content: " << line << endl;

    fin.close();

    return 0;
}
