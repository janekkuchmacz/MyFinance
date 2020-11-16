#include <iostream>
#include "FinanceManager.h"

using namespace std;

int main()
{
    FinanceManager financeManager;
    char choice;
    while (true)
    {
        if (financeManager.getSignedUserId() == 0)
        {
            choice = financeManager.chooseOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                financeManager. userRegistration();
                break;
            case '2':
                  financeManager. userSignIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Choose correct option, please" << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {

       choice = financeManager.chooseOptionFromUserMenu();


            switch (choice)
            {
            case '1':
                financeManager.addIncome();

                break;
            case '2':
                financeManager.addExpense ();
                break;
            case '3':
                financeManager.showMonthBalance();
                break;
            case '4':
                financeManager.showPreviousMonthBalance();
                break;
            case '5':
                financeManager.showBalanceForTheSelectedPeriodOfTime();
                break;
            case '6':
                financeManager.passwordChange();
                break;
            case '7':
                financeManager.setSignedUserId(0);
                break;
            }
        }
    }

    return 0;
}

