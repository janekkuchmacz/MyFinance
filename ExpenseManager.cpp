#include "ExpenseManager.h"

void ExpenseManager:: addExpense()
{
    Expense expense;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    expense = enterNewExpenseData();

    expenses.push_back(expense);
    expensesFile.addExpenseToFile(expense);

    int gotId=expensesFile.getLastExpenseId();
    expensesFile.setLastExpenseId(gotId+1);
    cout << endl << "Expense added successfully" << endl << endl;
    system("pause");
}
string ExpenseManager:: enterLine()
 {
    string input = "";
    getline(cin, input);
    return input;
 }
 Expense ExpenseManager::enterNewExpenseData()
 {
     Expense expense;
     char choice={0};
     string dateEntered="";
     string itemEntered="";
     string amountEntered="";


     expense.setId(expensesFile.getLastExpenseId()+1);
     expense.setUserId(SIGNED_USER_ID);
     do
     {
         cout<<"Enter expense with current date? <y/n>: ";
         choice=AuxiliaryMethods::enterChar();
         if (choice=='y')
         {
            expense.setDate(OperationsOnDates::convertDateToInt(OperationsOnDates::returnCurrentDate()));
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
                  expense.setDate(OperationsOnDates::convertDateToInt(dateEntered));
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
     expense.setItem(itemEntered);
     cout<<"Enter the amount of income in PLN: ";
     getline(cin, amountEntered);
     expense.setAmount(AuxiliaryMethods::replaceCommaWithDot(amountEntered));
     return expense;
 }
void ExpenseManager::displayAllExpensesFromThisMonth ()
 {
     sort(expenses.begin(), expenses.end(), sortingVector());
     cout<<endl<<"EXPENSES IN THIS MONTH"<<endl<<endl;
     for (int i=0; i<expenses.size(); i++)
     {
         if (OperationsOnDates::checkIfDateIsFromThisMonth(expenses[i].getDate())==1)
         {
         cout<<"Expense id: "<<expenses[i].getId()<<endl;
         cout<<"Date of expense: "<<expenses[i].getDate()<<endl;
         cout<<"Subject: "<<expenses[i].getItem()<<endl;
         cout<<"The amount of the expense: "<<expenses[i].getAmount()<<endl;
         }
         cout<<endl;
     }
 }
 float ExpenseManager::displaySumOfExpensesFromThisMonth()
 {
     float sumOfExpenses=0;
     for (int i=0; i<expenses.size(); i++)
     {
         if (OperationsOnDates::checkIfDateIsFromThisMonth(expenses[i].getDate())==1)
         {
             sumOfExpenses=sumOfExpenses+expenses[i].getAmount();
         }
     }
   return sumOfExpenses;
 }
 void ExpenseManager::displayAllExpensesFromPreviousMonth ()
 {
     sort(expenses.begin(), expenses.end(), sortingVector());
     cout<<endl<<"EXPENSES IN PREVIOUS MONTH"<<endl<<endl;
     for (int i=0; i<expenses.size(); i++)
     {
         if (OperationsOnDates::checkIfDateIsFromPreviousMonth(expenses[i].getDate())==1)
         {
         cout<<"Expense id: "<<expenses[i].getId()<<endl;
         cout<<"Date of expense: "<<expenses[i].getDate()<<endl;
         cout<<"Subject: "<<expenses[i].getItem()<<endl;
         cout<<"The amount of the expense: "<<expenses[i].getAmount()<<endl;
         }
         cout<<endl;
     }
 }
 float ExpenseManager::displaySumOfExpensesFromPreviousMonth()
 {
     float sumOfExpenses=0;
     for (int i=0; i<expenses.size(); i++)
     {
         if (OperationsOnDates::checkIfDateIsFromPreviousMonth(expenses[i].getDate())==1)
         {
             sumOfExpenses=sumOfExpenses+expenses[i].getAmount();
         }
     }
   return sumOfExpenses;
 }
  void ExpenseManager::displayAllExpensesFromSelectedPeriodOfTime (int startDate, int finishDate)
 {
     sort(expenses.begin(), expenses.end(), sortingVector());
     cout<<endl<<"EXPENSES IN SELECTED PERIOD OF TIME"<<endl<<endl;
     for (int i=0; i<expenses.size(); i++)
     {
         if (OperationsOnDates::checkIfDateIsFromSelectedPeriodOfTime(expenses[i].getDate(), startDate, finishDate)==1)
         {
         cout<<"Expense id: "<<expenses[i].getId()<<endl;
         cout<<"Date of expense: "<<expenses[i].getDate()<<endl;
         cout<<"Subject: "<<expenses[i].getItem()<<endl;
         cout<<"The amount of the expense: "<<expenses[i].getAmount()<<endl;
         }
         cout<<endl;
     }
 }
 float ExpenseManager::displaySumOfExpensesFromSelectedPeriodOfTime(int startDate, int finishDate)
 {
     float sumOfExpenses=0;
     for (int i=0; i<expenses.size(); i++)
     {
         if (OperationsOnDates::checkIfDateIsFromSelectedPeriodOfTime(expenses[i].getDate(), startDate, finishDate)==1)
         {
             sumOfExpenses=sumOfExpenses+expenses[i].getAmount();
         }
     }
   return sumOfExpenses;
 }
