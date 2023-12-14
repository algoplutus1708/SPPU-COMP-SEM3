
#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<string, int> populationMap;
	populationMap["1xyz"] = 321;
	populationMap["2xyz"] = 321;
	populationMap["3xyz"] = 321;
	populationMap["4xyz"] = 321;

	populationMap.insert(make_pair("Maharashtra", 125));
	populationMap.insert(make_pair("Uttar Pradesh", 225));
	populationMap.insert(make_pair("Bihar", 120));
	populationMap.insert(make_pair("West Bengal", 100));
	populationMap.insert(make_pair("Madhya Pradesh", 90));
	populationMap.insert(make_pair("Tamil Nadu", 80));
	populationMap.insert(make_pair("Rajasthan", 78));
	populationMap.insert(make_pair("Andhra Pradesh", 53));
	populationMap.insert(make_pair("Odisha", 47));
	populationMap.insert(make_pair("Kerala", 38));
	populationMap.insert(make_pair("Telangana", 37));
	populationMap.insert(make_pair("Assam", 35));
	populationMap.insert(make_pair("Jharkhand", 38));
	populationMap.insert(make_pair("Karnataka", 68));
	populationMap.insert(make_pair("Gujarat", 70));
	populationMap.insert(make_pair("Punjab", 31));
	populationMap.insert(make_pair("Chhattisgarh", 30));
	populationMap.insert(make_pair("Haryana", 29));
	populationMap.insert(make_pair("UT Delhi", 19));
	populationMap.insert(make_pair("UT Jammu and Kashmir", 14));
	populationMap.insert(make_pair("Uttarakhand", 12));
	populationMap.insert(make_pair("Himachal Pradesh", 8));
	populationMap.insert(make_pair("Tripura", 04));
	populationMap.insert(make_pair("Meghalaya", 4));
	populationMap.insert(make_pair("Manipur[", 3));
	populationMap.insert(make_pair("Nagaland", 2));
	populationMap.insert(make_pair("Goa", 2));
	populationMap.insert(make_pair("Arunachal Pradesh", 2));
	populationMap.insert(make_pair("UT Puducherry", 2));
	populationMap.insert(make_pair("Mizoram", 1));
	populationMap.insert(make_pair("UT Chandigarh", 1));
	populationMap.insert(make_pair("Sikkim", 1));
	populationMap.insert(make_pair("UT Dadra and Nagar Haveli and Daman and Diu", 1));
	populationMap.insert(make_pair("UT Andaman and Nicobar Islands", 1));
	populationMap.insert(make_pair("UT Lakshadweep", 0.0003));
	populationMap.insert(make_pair("UT Ladakh", 0.00006));

	map<string, int>::iterator it;

	cout << "Total state and UT of India with Size of populationMap: " << populationMap.size() << '\n';

	for (it = populationMap.begin(); it != populationMap.end(); ++it)
	{
		cout << it->first << ":" << it->second << " million\n";
	}

	char c;
	do
	{
		string state;
		cout << "\nEnter that state you want to know the population of: ";
		cin >> state;
	
		bool f = 0;
		for (it = populationMap.begin(); it != populationMap.end(); ++it)
		{
			if (it->first == state)
			{
				cout << state << "'s populations is "<< it->second << " million\n";
				f = 1;
				break;
			}
		}
		if(f==0)
		{
			cout << "State is not in data" << endl;
		}

		cout << "Do you wish to continue?(y/n):";
		cin >> c;
	} while (c == 'y' || c == 'Y');

	populationMap.clear();

	return 0;
}