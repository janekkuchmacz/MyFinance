#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include<fstream>
#include<sstream>

#include "expense.h"
#include "OperationsOnDates.h"

#include "ExpenseFile.h"


using namespace std;

class ExpenseManager
{
    const int SIGNED_USER_ID;

    vector <Expense> expenses;
    string enterLine();
    Expense enterNewExpenseData();

    ExpenseFile expensesFile;

    struct sortingVector
    {
    inline bool operator() (Expense& struct1, Expense& struct2)
    {
        return (struct1.getDate() < struct2.getDate());
    }
    };

public:
    ExpenseManager (int signedUserId): SIGNED_USER_ID (signedUserId)
    {
        expenses=expensesFile.loadSignedUserExpensesFromFile(signedUserId);
    }
    void addExpense();
    void displayAllExpensesFromThisMonth();
    float displaySumOfExpensesFromThisMonth();
    void displayAllExpensesFromPreviousMonth();
    float displaySumOfExpensesFromPreviousMonth();
    void displayAllExpensesFromSelectedPeriodOfTime (int startDate, int finishDate);
    float displaySumOfExpensesFromSelectedPeriodOfTime(int startDate, int finishDate);

};
#endif
