
// #include <bits/stdc++.h>
// using namespace std;

// struct PersonalRecord
// {
// 	string name, DOB, phoneNo;
// };

// inline void displayRecord(PersonalRecord &record)
// {
// 	cout << "Name:" << record.name << endl;
// 	cout << "DOB:" << record.DOB << endl;
// 	cout << "PHone number:" << record.phoneNo << endl;
// 	cout << endl;
// }

// int main()
// {
// 	vector<PersonalRecord> record = {{"pbc", "321", "987654321"}, {"aoi", "987", "654321987"}, {"lkj", "456", "123569876"}};

// 	int n = record.size();

// 	cout << "before sorting\n";
// 	for (int i = 0; i < n; i++)
// 	{
// 		displayRecord(record[i]);
// 	}

// 	for (int i = 0; i < n; i++)
// 	{
// 		for (int j = 0; j < n - 1; j++)
// 		{
// 			if (record[j].name > record[j + 1].name)
// 			{
// 				swap(record[j].name, record[j + 1].name);
// 			}
// 		}
// 	}

// 	cout << "After sorting\n";
// 	for (int i = 0; i < n; i++)
// 	{
// 		displayRecord(record[i]);
// 	}

// 	string s;
// 	cout << "Enter name for searching: ";
// 	cin >> s;
// 	bool f = 0;
// 	for (int i = 0; i < n; i++)
// 	{
// 		if (record[i].name == s)
// 		{
// 			cout << "Found:" << endl;
// 			f = 1;
// 			displayRecord(record[i]);
// 			break;
// 		}
// 	}
// 	if (f == 0)
// 	{
// 		cout << "not found\n";
// 	}
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct PersonalRecord
{
	string name, DOB, phoneNo;
};

inline void displayRecord(const PersonalRecord &record)
{
	cout << "Name: " << record.name << endl;
	cout << "DOB: " << record.DOB << endl;
	cout << "Phone number: " << record.phoneNo << endl;
	cout << endl;
}

int main()
{
	vector<PersonalRecord> record = {{"pbc", "321", "987654321"}, {"aoi", "987", "654321987"}, {"lkj", "456", "123569876"}};

	int n = record.size();

	cout << "Before sorting\n";
	for (const auto &rec : record)
	{
		displayRecord(rec);
	}

	// Using STL sort to sort based on the 'name' field
	sort(record.begin(), record.end(), [](const PersonalRecord &a, const PersonalRecord &b)
		 { return a.name < b.name; });

	cout << "After sorting\n";
	for (const auto &rec : record)
	{
		displayRecord(rec);
	}

	string s;
	cout << "Enter name for searching: ";
	cin >> s;

	// Using STL binary_search to check if 's' exists in 'record'
	auto it = find_if(record.begin(), record.end(), [&s](const PersonalRecord &rec)
					  { return rec.name == s; });

	if (it != record.end())
	{
		cout << "Found:" << endl;
		displayRecord(*it);
	}
	else
	{
		cout << "Not found\n";
	}

	return 0;
}
