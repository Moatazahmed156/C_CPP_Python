#include <bits/stdc++.h>
using namespace std;
void menu()
{
    cout << "------------------------" << endl;
    cout << "| ATM |" << endl;
    cout << "------------------------" << endl;
    cout << "| 1 | Login |" << endl;
    cout << "| 2 | Report (Admin) |" << endl;
    cout << "| 0 | Exit |" << endl;
    cout << "------------------------" << endl;
}
void Menu2(int i, string cus[])
{
    cout << "HELLO Mr/Ms : " << cus[i] << " !\n";
    cout << "--------------------" << endl;
    cout << "| ATM |" << endl;
    cout << "--------------------" << endl;
    cout << "| 1 | Balance |" << endl;
    cout << "| 2 | Withdraw |" << endl;
    cout << "| 3 | Deposit |" << endl;
    cout << "| 4 | Transfer($) |" << endl;
    cout << "| 0 | Exit |" << endl;
    cout << "--------------------" << endl;
}
void Report(string cus[], string crd[], string pass[], double bal[])
{
    cout << "------------------------------------------" << endl;
    cout << "| ID \t Name \t Card \t Pass \t Balance |" << endl;
    cout << "------------------------------------------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "| " << i + 1 << " \t " << cus[i] << "\t " << crd[i] << " \t " << pass[i] << " \t " << bal[i] << " \t |" << endl;
    }
    cout << "------------------------------------------" << endl;
}
void Admin(string cus[], string crd[], string pass[], double bal[])
{
    string key;
    cout << "Enter Admin Key :\t";
    cin >> key;
    if (key == "admin156")
    {
        Report(cus, crd, pass, bal);
    }
    else
    {
        cout << "Wrong Key !" << endl;
    }
}
int login(string cards[], string pass[])
{
    string card, pas;
    cout << "Enter Card Number : \t";
    cin >> card;
    for (int i = 0; i < 5; i++)
    {
        if (cards[i] == card)
        {
            cout << "Enter Password : \t";
            cin >> pas;
            if (pas == pass[i])
            {
                return i;
            }
            else
            {
                return -2;
            }
        }
    }
    return -1;
}
void withdraw(int id, double balances[])
{
    double money;
    cout << "Enter Withdraw Money :\t";
    cin >> money;
    if (money <= balances[id])
    {
        balances[id] -= money;
    }
    else
    {
        cout << "Not Enough Money !" << endl;
    }
}
void deposit(int id, double balances[])
{
    double money;
    cout << "Enter Deposit Money \t";
    cin >> money;
    balances[id] += money;
}
int main()
{
    string customers[5] = {"ali", "ahmed", "moataz", "amr", "mazen"};
    string cards[5] = {"1111", "2222", "3333", "4444", "5555"};
    string pass[5] = {"1111", "2222", "3333", "4444", "5555"};
    double balances[5] = {5000, 7000, 20000, 1500, 13700};
    menu();
    int choice;
    cout << "Enter Your Choice :\t";
    cin >> choice;
    if (choice == 1)
    {
        int id = login(cards, pass);
        if (id == -1)
        {
            cout << "WRONG CARD NUMBER !" << endl;
        }
        else if (id == -2)
        {
            cout << "WRONG Password !" << endl;
        }
        else
        {
            while (true)
            {
                Menu2(id, customers);
                int ch;
                cout << "Enter Your Choice :\t";
                cin >> ch;
                switch (ch)
                {
                case 1:
                    cout << "Your Balance \t" << balances[id] << endl;
                    break;
                case 2:
                    withdraw(id, balances);
                    break;
                case 3:
                    deposit(id, balances);
                    break;
                case 4:
                    cout << balances[id] / 48.43 << " $" << endl;
                    break;
                case 0:
                    cout << "Thanks !" << endl;
                default:
                    cout << "Enter a Correct Choice !" << endl;
                    break;
                }
            }
        }
    }
    else if (choice == 2)
    {
        Admin(customers, cards, pass, balances);
    }
    else if (choice == 0)
    {
        cout << "Thanks !" << endl;
        return 0;
    }
    else
    {
        cout << "Invalid choice ! ,Enter correct choice" << endl;
    }
}