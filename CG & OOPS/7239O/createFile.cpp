#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Creating and writing to the output file
    ofstream outputFile("output.txt");
    if (!outputFile)
    {
        cout << "Error creating output file!" << endl;
        return 1;
    }

    outputFile << "Hello, this is some information written to the file." << endl;
    outputFile << "You can add more lines if needed." << endl;

    // Closing the output file
    outputFile.close();

    // Opening the file as input and reading information
    ifstream inputFile("output.txt");
    if (!inputFile)
    {
        cout << "Error opening input file!" << endl;
        return 1;
    }

    cout << "Reading from the file:" << endl;

    string line;
    while (getline(inputFile, line))
    {
        cout << line << endl;
    }

    // Closing the input file
    inputFile.close();

    return 0;
}
