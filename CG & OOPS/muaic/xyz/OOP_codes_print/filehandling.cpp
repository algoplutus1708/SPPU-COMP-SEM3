#include<bits/stdc++.h>
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
    string str;
    cout << "enter what you want to enter in the file";
    cin.ignore();
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
        file >> str; 
        cout << str;
    }
    file.close();
    return 0;
}

// fstream file;
// f.open("name.txt",ios::out);
// if(!file)
// cout<<"Error in creating file !!!"
// cout<<"file created successfully";
