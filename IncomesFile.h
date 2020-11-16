#ifndef INCOMESFILE_H
#define INCOMESFILE_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Markup.h"

#include "income.h"
#include "AuxiliaryMethods.h"
#include "OperationsOnDates.h"


using namespace std;

class IncomesFile
{
    const string INCOMES_FILE_NAME;
    int lastIncomeId;
public:
    IncomesFile():INCOMES_FILE_NAME("incomes.xml")
    {

    }
    void addIncomeToFile (Income income);
    int getLastIncomeId();
    void setLastIncomeId(int LastIncomeId);
    vector <Income> loadSignedUserIncomesFromFile(int signedUserId);
};
#endif
