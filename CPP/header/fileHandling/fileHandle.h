#ifndef FILEhANDLE_H
#define FILEhANDLE_H
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

class fileHandle
{
    string txt1, txt2, txt3;

public:
    void file1()
    {
        ofstream w1("/home/shovon/Documents/Codes/CPP/header/fileHandling/data.txt");
        w1 << "This is file handling lab class\n";
        w1.close();
        ifstream r1("/home/shovon/Documents/Codes/CPP/header/fileHandling/data.txt");
        getline(r1, txt1);
        cout << "File 1 : " << txt1 << endl;
        r1.close();
    }

    void file2()
    {
        ofstream w2("/home/shovon/Documents/Codes/CPP/header/fileHandling/data2.txt");
        w2 << "This is second file\n";
        w2.close();
        ifstream r2("/home/shovon/Documents/Codes/CPP/header/fileHandling/data2.txt");
        getline(r2, txt2);
        cout << "File 2 : " << txt2 << endl;
        r2.close();
    }

    void file3()
    {
        ofstream w3("/home/shovon/Documents/Codes/CPP/header/fileHandling/backup.txt", ios::app);
        w3 << txt1 << endl
           << txt2 << endl;
        w3.close();
        ifstream r3("/home/shovon/Documents/Codes/CPP/header/fileHandling/backup.txt");
        cout << endl;
        while (getline(r3, txt3))
        {
            cout << "File 3 : " << txt3 << endl;
        }
        r3.close();
    }

    void deleteFile(string fileName)
    {
        fs::remove("/home/shovon/Documents/Codes/CPP/header/fileHandling/" + fileName);
    }

    void deleteAllFile()
    {
        fs::remove("/home/shovon/Documents/Codes/CPP/header/fileHandling/data.txt");
        fs::remove("/home/shovon/Documents/Codes/CPP/header/fileHandling/data2.txt");
        fs::remove("/home/shovon/Documents/Codes/CPP/header/fileHandling/backup.txt");
    }

    /*
    Use these in main.cpp
    fileHandle fwr;
    fwr.file1();
    fwr.file2();
    fwr.file3();
    // fwr.deleteFile("data.txt");
    // fwr.deleteAllFile();
    */
};
#endif