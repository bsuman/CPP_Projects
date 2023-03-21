// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

class tmpClass {
public:
    tmpClass(int size) {
        char* p_mem = new char[size];

        delete []p_mem;
    }
};

void read_file_from_input(string filename) {
    fstream fs;

    fs.open(filename,ios::in | ios::ate);
    if (!fs.is_open())
        throw string("FILE_NOT_FOUND");
    else {
        auto size = fs.tellg();
        cout << size << '\n';
        string str(size, '\0'); 
        fs.seekg(0);
        if (fs.read(&str[0], size))
            cout << str << '\n';
        fs.close();
    }
}

int main()
{
    try {
        tmpClass C_tmp(10);
        tmpClass C_tmp1(10000000000000000000);
        read_file_from_input("C:\\Users\\Admin\\OneDrive\\Desktop\\test.txt");
        read_file_from_input("C:\\Users\\Admin\\OneDrive\\Desktop\\test1.txt");
    }
    catch (const string & msg) {
        cout << msg;

    }
    catch (const bad_alloc &e) {
        cout << "Out of memory! "<< e.what();
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
