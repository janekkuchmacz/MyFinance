#include "FinanceManager.h"

char FinanceManager :: chooseOptionFromMainMenu()
{
    showMenu.chooseOptionFromMainMenu();
}
char FinanceManager :: chooseOptionFromUserMenu()
{
    showMenu. chooseOptionFromUserMenu();
}
void FinanceManager:: userRegistration()
{
    userManager.userRegistration();
}
void FinanceManager::displayAllUsers()
{
    userManager.displayAllUsers();
}
void FinanceManager::userSignIn()
{
    userManager.userSignIn();
    if (userManager.userSignedIn()==true)
    {
        incomeManager=new IncomeManager (userManager.getSignedUserId());
        expenseManager=new ExpenseManager (userManager.getSignedUserId());
    }

}
int FinanceManager::getSignedUserId()
{
     userManager.getSignedUserId();
}
 void FinanceManager::setSignedUserId(int newUserId)
 {
     userManager. setSignedUserId(newUserId);
     delete incomeManager;
     incomeManager=NULL;
     delete expenseManager;
     expenseManager=NULL;
 }
 void FinanceManager::passwordChange()
 {
       userManager.passwordChange();
 }
 void FinanceManager::addIncome()
 {
    incomeManager->addIncome ();
 }
 void FinanceManager::displayAllIncomes ()
 {
     incomeManager->displayAllIncomesFromThisMonth();
 }
  void FinanceManager::addExpense()
 {
    expenseManager->addExpense ();
 }
 void FinanceManager::displayAllExpenses ()
 {
     expenseManager->displayAllExpensesFromThisMonth();
 }
 void FinanceManager::showMonthBalance()
 {
     float sumOfIncomes=0, sumOfExpenses=0, monthBalance=0;
     incomeManager -> displayAllIncomesFromThisMonth();
     expenseManager -> displayAllExpensesFromThisMonth();
     sumOfIncomes=incomeManager ->displaySumOfIncomesFromThisMonth();
     cout<<endl<<"SUM OF INCOMES IN THIS MONTH: "<<sumOfIncomes<<endl;
     sumOfExpenses=expenseManager->displaySumOfExpensesFromThisMonth();
     cout<<endl<<"SUM OF EXPENSES IN THIS MONTH: "<<sumOfExpenses<<endl;
     monthBalance=sumOfIncomes-sumOfExpenses;
     cout<<endl<<"YOUR MONTH BALANCE: "<<monthBalance<<endl<<endl;

     system("pause");
 }
  void FinanceManager::showPreviousMonthBalance()
 {
     float sumOfIncomes=0, sumOfExpenses=0, monthBalance=0;
     incomeManager -> displayAllIncomesFromPreviousMonth();
     expenseManager -> displayAllExpensesFromPreviousMonth();
     sumOfIncomes=incomeManager ->displaySumOfIncomesFromPreviousMonth();
     cout<<endl<<"SUM OF INCOMES IN PREVIOUS MONTH: "<<sumOfIncomes<<endl;
     sumOfExpenses=expenseManager->displaySumOfExpensesFromPreviousMonth();
     cout<<endl<<"SUM OF EXPENSES IN PREVIOUS MONTH: "<<sumOfExpenses<<endl;
     monthBalance=sumOfIncomes-sumOfExpenses;
     cout<<endl<<"BALANCE FOR PREVIOUS MONTH: "<<monthBalance<<endl<<endl;

     system("pause");
 }
 void FinanceManager::showBalanceForTheSelectedPeriodOfTime()
 {
     string startDateStr="";
     string finishDateStr="";
     int startDate=0;
     int finishDate=0;
     int counter1=0;
     int counter2=0;
     int counter3=0;
     do
     {
        if (counter3>0)
        {
            cout<<"Start date should be earlier than finish date!"<<endl;
            counter2=0; counter1=0;
        }
        do
            {
             if (counter1>0)
             {
                 cout<<"Date incorrect"<<endl;
             }
             cout<<"Enter start date as follows yyyy-mm-dd: ";
             cin>>startDateStr;
             counter1++;

            }
        while (OperationsOnDates::checkDateCorrectness(startDateStr)==false);
            do
            {
             if (counter2>0)
             {
                 cout<<"Date incorrect"<<endl;
             }
             cout<<"Enter finish date as follows yyyy-mm-dd: ";
             cin>>finishDateStr;
             counter2++;

            }
        while (OperationsOnDates::checkDateCorrectness(finishDateStr)==false);

        startDate=OperationsOnDates::convertDateToInt(startDateStr);
        finishDate=OperationsOnDates::convertDateToInt(finishDateStr);
        counter3++;

     }
     while(startDate>finishDate);


     float sumOfIncomes=0, sumOfExpenses=0, monthBalance=0;
     incomeManager -> displayAllIncomesFromSelectedPeriodOfTime(startDate, finishDate);
     expenseManager -> displayAllExpensesFromSelectedPeriodOfTime(startDate, finishDate);
     sumOfIncomes=incomeManager ->displaySumOfIncomesFromSelectedPeriodOfTime(startDate, finishDate);
     cout<<endl<<"SUM OF INCOMES IN SELECTED PERIOD OF TIME: "<<sumOfIncomes<<endl;
     sumOfExpenses=expenseManager->displaySumOfExpensesFromSelectedPeriodOfTime(startDate, finishDate);
     cout<<endl<<"SUM OF EXPENSES IN SELECTED PERIOD OF TIME: "<<sumOfExpenses<<endl;
     monthBalance=sumOfIncomes-sumOfExpenses;
     cout<<endl<<"BALANCE FOR SELECTED PERIOD OF TIME: "<<monthBalance<<endl<<endl;

     system("pause");
 }
