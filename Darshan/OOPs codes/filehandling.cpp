
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file; 

    file.open("someone.txt", ios::out);

    if (!file)
    {
        cout << "Error in creating file!!!" << endl;
        return 0;
    }

    cout << "File created successfully." << endl;
    // write text into file
    string str;
    cout << "enter what you want to enter in the file";
    getline(cin, str);
    file << str;
    file.close();

    file.open("someone.txt", ios::in);

    if (!file)
    {
        cout << "Error in opening file!!!" << endl;
        return 0;
    }

    
    char ch; 
    cout << "File content: ";

    while (!file.eof())
    {
        file >> ch; 
        cout << ch;
    }

    file.close(); // close file

    return 0;
}