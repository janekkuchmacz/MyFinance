#include "ShowMenu.h"

char ShowMenu::  chooseOptionFromMainMenu()
 {
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Sign in" << endl;
    cout << "9. Quit" << endl;
    cout << "---------------------------" << endl;
    cout << "Enter your choice: ";
    choice = enterChar();

    return choice;
 }

 char ShowMenu:: chooseOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Display balance for this month" << endl;
    cout << "4. Display balance for the previous month" << endl;
    cout << "5. Display balance for selected period of time" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Sign out" << endl;
    cout << "---------------------------" << endl;
    cout << "Enter your choice: ";
    choice = enterChar();

    return choice;
}
char  ShowMenu::enterChar()
{
    string input = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            sign = input[0];
            break;
        }
        cout << "It is not one character. Enter your choice once again: " << endl;
    }
    return sign;
}
