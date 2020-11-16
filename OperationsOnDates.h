#ifndef OPERATIONSONDATES_H
#define OPERATIONSONDATES_H
#include <iostream>
#include <vector>
#include <windows.h>
#include<fstream>
#include<sstream>
#include <ctime>
#include <string>
#include <cstdlib>

#include "AuxiliaryMethods.h"


using namespace std;

class OperationsOnDates
{

public:
    static bool checkDateCorrectness(string date);
    static string returnCurrentDate();
    static int convertDateToInt (string dateWithDashes);
    static int returnMaxiumNumberofDaysInMonth(int month, int year);
    static string convertDateFromIntToString(int dateInt);
    static bool checkIfDateIsFromThisMonth (int date);
    static bool checkIfDateIsFromPreviousMonth (int date);
    static bool checkIfDateIsFromSelectedPeriodOfTime (int date, int startDate, int finishDate);

};
#endif
