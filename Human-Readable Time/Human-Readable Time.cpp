#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

template<typename T>
T GetInput(string inputMessage);

int main()
{
    int seconds = GetInput<int>("input time in seconds");
    int minutes = seconds / 60;
    int leftOverSeconds = seconds % 60;
    int hours = minutes / 60;
    int leftOverMinutes = minutes % 60;
    if (hours > 99)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << leftOverMinutes << ":" << setw(2) << setfill('0') << leftOverSeconds;
    }
}

template<typename T>
T GetInput(string inputMessage)
{
    T userInput;
    while (true)
    {
        cout << inputMessage << endl << endl;
        string rawInput;
        getline(cin, rawInput);
        try
        {
            istringstream iss(rawInput);
            iss >> userInput;
            if (iss.fail() && iss.peek() != EOF)
            {
                throw logic_error("This is the wrong data type");
            }
            else if (userInput < 0)
            {
                throw out_of_range("This is below zero");
            }
            break;
        }
        catch (const exception& e)
        {
            cerr << e.what() << endl << endl;
        }
    }
    return userInput;
}