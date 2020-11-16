#include "ExpenseFile.h"

void ExpenseFile::addExpenseToFile (Expense expense)
{
    CMarkup xml;
    bool fileExists = xml.Load( EXPENSES_FILE_NAME );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");

    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", OperationsOnDates:: convertDateFromIntToString(expense. getDate()));
    xml.AddElem("Item",expense.getItem());
    xml.AddElem("Amount", AuxiliaryMethods:: floatToStringConversion(expense.getAmount()));

    xml.Save(EXPENSES_FILE_NAME);
}
int ExpenseFile::getLastExpenseId()
{
    return lastExpenseId;
}
 void ExpenseFile::setLastExpenseId(int LastExpenseId)
 {
     lastExpenseId=LastExpenseId;
 }
 vector <Expense> ExpenseFile::loadSignedUserExpensesFromFile(int signedUserId)
 {
        vector <Expense> expenses;
        Expense expense;
        CMarkup xml;
        bool fileExists = xml.Load( "expenses.xml" );
        int LastExpenseId=0;

        if (fileExists==1)
        {
            xml.ResetPos(); // top of document
            xml.FindElem(); // ORDER element is EXPENSES
            xml.IntoElem(); // inside EXPENSES

            while ( xml.FindElem("Expense"))
            {
                xml.IntoElem();
                xml.FindElem( "UserId" );
                if (signedUserId==AuxiliaryMethods::stringToIntConversion(xml.GetData()))
                {
                    xml.ResetMainPos();
                    xml.FindElem( "ExpenseId" );
                    expense.setId(AuxiliaryMethods::stringToIntConversion(xml.GetData()));
                    xml.FindElem( "UserId" );
                    expense.setUserId(AuxiliaryMethods::stringToIntConversion(xml.GetData()));
                    xml.FindElem( "Date");
                    expense.setDate(OperationsOnDates::convertDateToInt(xml.GetData()));
                    xml.FindElem( "Item");
                    expense.setItem(xml.GetData());
                    xml.FindElem( "Amount");
                    expense.setAmount(atof(xml.GetData().c_str()));

                    expenses.push_back(expense);
                }
                xml.OutOfElem();

            }

        }
        if (fileExists==1)
        {
            xml.ResetPos(); // top of document
            xml.FindElem(); // ORDER element is EXPENSES
            xml.IntoElem(); // inside EXPENSES

            while ( xml.FindElem("Expense"))
            {
                    xml.FindChildElem( "ExpenseId" );
                    LastExpenseId=AuxiliaryMethods::stringToIntConversion(xml.GetChildData());
            }
            lastExpenseId=LastExpenseId;

        }
        return expenses;
 }
