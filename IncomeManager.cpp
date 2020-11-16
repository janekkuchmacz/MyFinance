#include "IncomeManager.h"

void IncomeManager:: addIncome()
{
    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = enterNewIncomeData();

    incomes.push_back(income);
    incomesFile.addIncomeToFile(income);

    int gotId=incomesFile.getLastIncomeId();
    incomesFile.setLastIncomeId(gotId+1);
    cout << endl << "Income added successfully" << endl << endl;
    system("pause");
}
string IncomeManager:: enterLine()
 {
    string input = "";
    getline(cin, input);
    return input;
 }
 Income IncomeManager::enterNewIncomeData()
 {
     Income income;
     char choice={0};
     string dateEntered="";
     string itemEntered="";
     string amountEntered="";

     income.setId(incomesFile.getLastIncomeId()+1);
     income.setUserId(SIGNED_USER_ID);
     do
     {
         cout<<"Enter income with current date? <y/n>: ";
         choice=AuxiliaryMethods::enterChar();
         if (choice=='y')
         {
            income.setDate(OperationsOnDates::convertDateToInt(OperationsOnDates::returnCurrentDate()));
         }
         else if (choice=='n')
         {
           do
           {
               cout<<"Enter the date as follows: yyyy-mm-dd (for example 2020-05-11): ";
               cin>>dateEntered;
               cin.ignore();
               if (OperationsOnDates::checkDateCorrectness(dateEntered)==1)
               {
                  income.setDate(OperationsOnDates::convertDateToInt(dateEntered));
                  break;
               }
               else
               {
                   cout<<"Entered date is incorrect."<<endl;
               }
           }
           while(1);
         }
     }
     while (choice!='y' && choice!='n');
     cout<<"What does this income relate to? :";
     getline (cin, itemEntered);
     income.setItem(itemEntered);
     cout<<"Enter the amount of income in PLN: ";
     getline(cin, amountEntered);
     income.setAmount(AuxiliaryMethods::replaceCommaWithDot(amountEntered));
     return income;
 }
 void IncomeManager::displayAllIncomesFromThisMonth ()
 {
     sort(incomes.begin(), incomes.end(), sortingVector());
     cout<<endl<<"INCOMES IN THIS MONTH"<<endl<<endl;
     for (int i=0; i<incomes.size(); i++)
     {
         if (OperationsOnDates::checkIfDateIsFromThisMonth(incomes[i].getDate())==1)
         {
         cout<<"Income id: "<<incomes[i].getId()<<endl;
         cout<<"Date of income: "<<incomes[i].getDate()<<endl;
         cout<<"Subject: "<<incomes[i].getItem()<<endl;
         cout<<"The amount of the income: "<<incomes[i].getAmount()<<endl;
         }
         cout<<endl;
     }
 }
 float IncomeManager::displaySumOfIncomesFromThisMonth()
 {
     float sumOfIncomes=0;
     for (int i=0; i<incomes.size(); i++)
     {
         if (OperationsOnDates::checkIfDateIsFromThisMonth(incomes[i].getDate())==1)
         {
             sumOfIncomes=sumOfIncomes+incomes[i].getAmount();
         }
     }
   return sumOfIncomes;
 }
 void IncomeManager::displayAllIncomesFromPreviousMonth ()
 {
     sort(incomes.begin(), incomes.end(), sortingVector());
     cout<<endl<<"INCOMES IN PREVIOUS MONTH"<<endl<<endl;
     for (int i=0; i<incomes.size(); i++)
     {
         if (OperationsOnDates::checkIfDateIsFromPreviousMonth(incomes[i].getDate())==1)
         {
         cout<<"Income id: "<<incomes[i].getId()<<endl;
         cout<<"Date of income: "<<incomes[i].getDate()<<endl;
         cout<<"Subject: "<<incomes[i].getItem()<<endl;
         cout<<"The amount of the income: "<<incomes[i].getAmount()<<endl;
         }
         cout<<endl;
     }
 }
 float IncomeManager::displaySumOfIncomesFromPreviousMonth()
 {
     float sumOfIncomes=0;
     for (int i=0; i<incomes.size(); i++)
     {
         if (OperationsOnDates::checkIfDateIsFromPreviousMonth(incomes[i].getDate())==1)
         {
             sumOfIncomes=sumOfIncomes+incomes[i].getAmount();
         }
     }
   return sumOfIncomes;
 }
 void IncomeManager::displayAllIncomesFromSelectedPeriodOfTime (int startDate, int finishDate)
 {
     sort(incomes.begin(), incomes.end(), sortingVector());
     cout<<endl<<"INCOMES IN SELECTED PERIOD OF TIME"<<endl<<endl;
     for (int i=0; i<incomes.size(); i++)
     {
         if (OperationsOnDates::checkIfDateIsFromSelectedPeriodOfTime(incomes[i].getDate(), startDate, finishDate)==1)
         {
         cout<<"Income id: "<<incomes[i].getId()<<endl;
         cout<<"Date of income: "<<incomes[i].getDate()<<endl;
         cout<<"Subject: "<<incomes[i].getItem()<<endl;
         cout<<"The amount of the income: "<<incomes[i].getAmount()<<endl;
         }

     }
 }
float IncomeManager::displaySumOfIncomesFromSelectedPeriodOfTime(int startDate, int finishDate)
 {
     float sumOfIncomes=0;
     for (int i=0; i<incomes.size(); i++)
     {
         if (OperationsOnDates::checkIfDateIsFromSelectedPeriodOfTime(incomes[i].getDate(), startDate, finishDate)==1)
         {
             sumOfIncomes=sumOfIncomes+incomes[i].getAmount();
         }
     }
   return sumOfIncomes;
 }

