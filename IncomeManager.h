#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include<fstream>
#include<sstream>

#include "income.h"
#include "OperationsOnDates.h"
#include "IncomesFile.h"


using namespace std;

class IncomeManager
{
    const int SIGNED_USER_ID;

    vector <Income> incomes;
    string enterLine();
    Income enterNewIncomeData();

    IncomesFile incomesFile;

    struct sortingVector
    {
    inline bool operator() (Income& struct1, Income& struct2)
    {
        return (struct1.getDate() < struct2.getDate());
    }
    };
public:
    IncomeManager (int signedUserId): SIGNED_USER_ID (signedUserId)
    {
        incomes=incomesFile.loadSignedUserIncomesFromFile(signedUserId);
    }
    void addIncome();
    void displayAllIncomesFromThisMonth();
    float displaySumOfIncomesFromThisMonth();
    void displayAllIncomesFromPreviousMonth();
    float displaySumOfIncomesFromPreviousMonth();
    void displayAllIncomesFromSelectedPeriodOfTime (int startDate, int finishDate);
    float displaySumOfIncomesFromSelectedPeriodOfTime(int startDate, int finishDate);


};
#endif
