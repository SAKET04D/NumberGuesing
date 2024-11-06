#include <iostream>

using namespace std;

int main()
{
    double Number1, Number2;
    char operation;

    cout << "MY CALCULATOR <3 "<<endl;
    cout << "Enter the 1st number: ";
    cin >> Number1;
    cout << "Choose an operator (+, -, *, /): ";
    cin >> operation;
    cout << "Enter the 2nd number: ";
    cin >> Number2;

    switch (operation)
    {
    case '+':
        cout << "Result: " << Number1 + Number2 << endl;
        break;
    case '-':
        cout << "Result: " << Number1 - Number2 << endl;
        break;
    case '*':
        cout << "Result: " << Number1 * Number2 << endl;
        break;
    case '/':
        if (Number2 != 0)
        {
            cout << "Result: " << Number1 / Number2 << endl;
        }
        else
        {
            cout << "!!! Error : Division by zero is not allowed !!!" << endl;
        }
        break;
    default:
        cout << "Invalid operator :( - Please use +, -, *, or /." << endl;
    }

    return 0;
}
