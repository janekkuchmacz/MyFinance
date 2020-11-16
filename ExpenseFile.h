#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Markup.h"

#include "expense.h"
#include "AuxiliaryMethods.h"
#include "OperationsOnDates.h"


using namespace std;

class ExpenseFile
{
    const string EXPENSES_FILE_NAME;
    int lastExpenseId;
public:
    ExpenseFile():EXPENSES_FILE_NAME("expenses.xml")
    {
        lastExpenseId=0;
    }
    void addExpenseToFile (Expense expense);
    int getLastExpenseId();
    void setLastExpenseId(int LastExpenseId);
    vector <Expense> loadSignedUserExpensesFromFile(int signedUserId);
};
#endif
