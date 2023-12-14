#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main()
{
    typedef map<string, int> mapType;
    mapType populationMap;

    populationMap.insert(pair<string, float>("Maharashtra", 125));
    populationMap.insert(pair<string, float>("Uttar Pradesh", 225));
    populationMap.insert(mapType::value_type("Bihar", 120));
    populationMap.insert(mapType::value_type("West Bengal", 100));
    populationMap.insert(make_pair("Madhya Pradesh", 90));
    populationMap.insert(make_pair("Tamil Nadu", 80));
    populationMap.insert(make_pair("Meghalaya", 4));
    populationMap.insert(make_pair("Sikkim", 1));
    populationMap.insert(make_pair("UT Dadra and Nagar Haveli and Daman and Diu", 1));
    populationMap.insert(make_pair("UT Andaman and Nicobar Islands", 1));
    populationMap.insert(make_pair("UT Lakshadweep", 0.0003));
    populationMap.insert(make_pair("UT Ladakh", 0.00006));

    mapType::iterator iter = --populationMap.end();
    populationMap.erase(iter);

    cout << "Total state and UT of India with Size of populationMap: " << populationMap.size() << '\n';

    for (iter = populationMap.begin(); iter != populationMap.end(); ++iter)
    {
        cout << iter->first << ":" << iter->second << " million\n";
    }

    char c;
    do
    {
        string state;
        cout << "\nEnter that state you want to know the population of: ";
        cin >> state;
        iter = populationMap.find(state);
        if (iter != populationMap.end())
            cout << state << "'s populations is "
                 << iter->second << " million\n";
        else
            cout << "State is not in populationMap" << '\n';

        cout << "Do you wish to continue?(y/n):";
        cin >> c;
    } while (c == 'y' || c == 'Y');

    populationMap.clear();

    return 0;
}

#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {

   map<string,int> statePopulations;

    statePopulations["California"] = 39512223;
    statePopulations["Texas"] = 28995881;
    statePopulations["Florida"] = 21477737;
    statePopulations["New York"] = 19453561;
    statePopulations["Pennsylvania"] = 12801989;

    string userInput;
    cout << "Enter the name of a state: ";
    getline(cin, userInput);

    auto it = statePopulations.find(userInput);
    if (it != statePopulations.end()) {

        cout << "Population of " << userInput << ": " << it->second <<endl;
    } else {

        cout << "State not found in the map." <<endl;
    }

    char c;
    do
    {
        string state;
        cout << "\nEnter that state you want to know the population of: ";
        cin >> state;
         auto it = statePopulations.find(state);
        if (it != statePopulations.end())
            cout << state << "'s populations is "
                 << it->second << " million\n";
        else
            cout << "State is not in populationMap" << '\n';

        cout << "Do you wish to continue?(y/n):";
        cin >> c;
    } while (c == 'y' || c == 'Y');

    return 0;
}

