#include <bits/stdc++.h>
using namespace std;

class first
{
private:
	static int count;
	int rollNo;
	string name, phoneNo, DOB;

public:
	first()
	{
		rollNo = 0;
		count++;
	}

	first(string name, string phoneNo, string DOB)
	{
		this->name = name;
		this->DOB = DOB;
		this->phoneNo = phoneNo;
		this->rollNo = 0; // Set default value for rollNo
		count++;
	}

	first(first &t)
	{
		cout << "Copy constructor called" << endl;
		rollNo = t.rollNo;
		name = t.name;
		DOB = t.DOB;
		phoneNo = t.phoneNo;
		count++;
	}

	~first()
	{
		count--;
	}

	static int getCount()
	{
		return count;
	}

	friend class second;

	void output()
	{
		cout << "Name: " << name << endl;
		cout << "Roll No: " << rollNo << endl;
		cout << "DOB: " << DOB << endl;
		cout << "Phone number: " << phoneNo << endl;
	}
};

class second
{
public:
	void input(first &f)
	{
		cout << "Enter name:";
		cin >> f.name;
		cout << "Enter roll no.:";
		cin >> f.rollNo;
		cout << "Enter DOB:";
		cin >> f.DOB;
		cout << "Enter phone number:";
		cin >> f.phoneNo;
	}

	void output(first &f)
	{
		cout << "Name: " << f.name << endl;
		cout << "Roll No: " << f.rollNo << endl;
		cout << "DOB: " << f.DOB << endl;
		cout << "Phone number: " << f.phoneNo << endl;
	}

	
};

int first::count = 0; // Initialize static member variable

int main()
{
	int n;
	cout << "Enter the number of students: ";
	cin >> n;

	first temp("Returned", "987", "01012000");
	first copy_temp(temp);
	copy_temp.output();

	first *studentArray = new first[n];
	second obj2;

	for (int i = 0; i < n; ++i)
	{
		cout << "\nEnter details for student " << i + 1 << ":\n";
		obj2.input(studentArray[i]);
	}

	cout << "\nDetails of all students:\n";
	for (int i = 0; i < n; ++i)
	{
		obj2.output(studentArray[i]);
		cout << endl;
	}

	// Using static member function
	cout << "\nTotal objects created: " << first::getCount() << endl;

	// Cleanup dynamic memory
	delete[] studentArray;

	return 0;
}
