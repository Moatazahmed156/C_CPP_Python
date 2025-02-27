#include <bits/stdc++.h>
using namespace std;

void displayMenu();
int gcd(int x, int y);

int main()
{
    int n;
    int num1, num2, result;
    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
            result = gcd(num1, num2);
            cout << "GCD of " << num1 << " and " << num2 << " is: " << result << endl;
            break;
        case 2:
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
            result = (num1 * num2) / gcd(num1, num2);
            cout << "LCM of " << num1 << " and " << num2 << " is: " << result << endl;
            break;
        case 0:
            cout << " --------------- " << endl;
            cout << "|   Thank you   |" << endl;
            cout << " --------------- " << endl;
            break;
        default:
            cout << " ----------------" << endl;
            cout << "| Invalid choice |" << endl;
            cout << " ----------------" << endl;
            break;
        }
    } while (n != 0);
    return 0;
}
void displayMenu()
{
    cout << endl;
    cout << " ---------" << endl;
    cout << "| 1. GCD  |" << endl;
    cout << "| 2. LCM  |" << endl;
    cout << "| 0. EXIT |" << endl;
    cout << " ---------" << endl;
    cout << endl;
}
int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}