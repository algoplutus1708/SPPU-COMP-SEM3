
#include <iostream>
using namespace std;


class ClubMember
{
public:
    int PRN;
    string name;
    ClubMember *next;
};


class PinnacleClub
{
public:
    ClubMember *president; 
    ClubMember *secretary; 

public:
    PinnacleClub()
    {
        president = nullptr;
        secretary = nullptr;

        // OR

        // president = NULL;
        // secretary = NULL;
    }

    // Function to add a new member
    void addMember(int prn, string name)
    {
        // Create a new member
        ClubMember *newMember = new ClubMember;
        newMember->PRN = prn;
        newMember->name = name;
        newMember->next = nullptr;

        // Add the new member to the end of the list
        if (president == nullptr)
        {
            president = newMember;
            secretary = newMember;
        }
        else
        {
            secretary->next = newMember;
            secretary = newMember;
        }
    }

    // Function to delete a member
    void deleteMember(int prn)
    {
        ClubMember *current = president;
        ClubMember *previous = nullptr;

        while (current != nullptr && current->PRN != prn)
        {
            previous = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Member not found." << endl;
            return;
        }

        if (current == president)
        {
            president = president->next;
        }
        else
        {
            previous->next = current->next;
        }

        delete current;
    }

    // Function to compute the total number of members
    int totalMembers()
    {
        int count = 0;
        ClubMember *current = president;

        while (current != nullptr)
        {
            count++;
            current = current->next;
        }

        return count;
    }

    // Function to display members
    void displayMembers()
    {
        ClubMember *current = president;

        while (current != nullptr)
        {
            cout << "PRN: " << current->PRN << " Name: " << current->name << endl;
            current = current->next;
        }
    }

    // Function to display the list in reverse order using recursion
    void displayReverse(ClubMember *current)
    {
        if (current == nullptr)
        {
            return;
        }
        displayReverse(current->next);
        cout << "PRN: " << current->PRN << " Name: " << current->name << endl;
    }

    // Function to concatenate two lists
    void concatenateLists(PinnacleClub &other)
    {
        if (president == nullptr)
        {
            president = other.president;
        }
        else
        {
            ClubMember *current = president;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = other.president;
        }
    }
};

int main()
{
    // Create two instances of PinnacleClub for two divisions
    PinnacleClub division1;
    PinnacleClub division2;
    int prn;
    string name;
    // Add members to division1
    for (int i = 0; i < 3; i++)
    {
        cin >> prn;
        cin >> name;
        division1.addMember(prn, name);
    }

    
    // division1.addMember(1, "Alice");
    // division1.addMember(2, "Bob");
    // division1.addMember(3, "Charlie");

    // Add members to division2

    for (int i = 0; i < 3; i++)
    {
        cin >> prn;
        cin >> name;
        division2.addMember(prn, name);
    }
    // division2.addMember(4, "David");
    // division2.addMember(5, "Eve");
    // division2.addMember(6, "Frank");

    // Display members of division1
    cout << "Division 1 members:" << endl;
    division1.displayMembers();

    // Display members of division2
    cout << "Division 2 members:" << endl;
    division2.displayMembers();

    // Concatenate division2 into division1
    division1.concatenateLists(division2);

    // Display concatenated list
    cout << "Concatenated list:" << endl;
    division1.displayMembers();

    // Display the list in reverse order using recursion
    cout << "List in reverse order:" << endl;
    division1.displayReverse(division1.president);

    return 0;
}
