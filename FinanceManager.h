#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H
#include <iostream>

#include "ShowMenu.h"
#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"

#include "OperationsOnDates.h"



using namespace std;

class FinanceManager
{
    ShowMenu showMenu;
    UserManager userManager;


    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;

public:
    FinanceManager ()
    {
      incomeManager=NULL;
      expenseManager=NULL;
    }
    ~FinanceManager ()
    {
      delete incomeManager;
      incomeManager=NULL;
      delete expenseManager;
      expenseManager=NULL;
    }
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    void userRegistration();
    void displayAllUsers();
    void userSignIn();
    int getSignedUserId();
    void setSignedUserId(int newUserId);
    void passwordChange();

    void addIncome();
    void displayAllIncomes ();

    void addExpense();
    void displayAllExpenses ();

    void showMonthBalance();
    void showPreviousMonthBalance();
    void showBalanceForTheSelectedPeriodOfTime();
};
#endif
