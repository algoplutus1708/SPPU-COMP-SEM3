#include <bits/stdc++.h>
using namespace std;
class student
{
private:
    int roll_no;
    string name, Class, division, DOB, blood_group, address, mobile_number, driving_license_number;

public:

    // Default constructor
    student()
    {
        roll_no = 7239;
    }
 
    // parameter constructor
    student(string Name)
    {
       name = Name;
    }

    // copy constructor
    student(student &X)
    {
        name = X.name;
        roll_no = 39;
    }

    // destructor
    ~student()
    {
        name = -1;
    }

    void Input();
    void Output();
};

void student::Input()
{
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter roll no.: ";
    cin >> roll_no;
    cout << "Enter the class: ";
    cin >> Class;
    cout << "Enter division: ";
    cin >> division;
    cout << "Enter date of birth: ";
    cin >> DOB;
    cout << "Enter blood group: ";
    cin >> blood_group;
    cout << "Enter mobile number: ";
    cin >> mobile_number;
    cout << "Enter driving license number: ";
    cin >> driving_license_number;
    cout << "Enter address: ";
    cin.ignore();
    getline(cin, address);
}

void student::Output()
{
    cout << "Name: ";
    cout << name << endl;
    cout << "Roll Number.: ";
    cout << roll_no << endl;
    cout << "Class: ";
    cout << Class << endl;
    cout << "Division: ";
    cout << division << endl;
    cout << "Date of birth: ";
    cout << DOB << endl;
    cout << "Blood group: ";
    cout << blood_group << endl;
    cout << "Mobile number: ";
    cout << mobile_number << endl;
    cout << "Driving license number: ";
    cout << driving_license_number << endl;
    cout << "Address: ";
    cout << address << endl;
}

int main()
{
    int n;
    cout << "Enter Number of students: ";
    cin >> n;

    student s[n];

    for (int i = 0; i < n; i++)
    {
        cout << "ENTER DATA OF STUDENT\n";
        s[i].Input();
    }

    cout << "-------------STUDENT DATA-------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "STUDENT DATA\n";
        s[i].Output();
    }

    student A("Piyush");
    A.Output();
    student B(A);
    B.Output();
}

