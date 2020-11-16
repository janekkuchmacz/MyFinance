#include "IncomesFile.h"

void IncomesFile::addIncomeToFile (Income income)
{
    CMarkup xml;
    bool fileExists = xml.Load( INCOMES_FILE_NAME );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");

    xml.IntoElem();
    xml.AddElem("IncomeId", income.getId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", OperationsOnDates:: convertDateFromIntToString(income. getDate()));
    xml.AddElem("Item",income.getItem());
    xml.AddElem("Amount", AuxiliaryMethods:: floatToStringConversion(income.getAmount()));

    xml.Save(INCOMES_FILE_NAME);
}
int IncomesFile::getLastIncomeId()
{
    return lastIncomeId;
}
 void IncomesFile::setLastIncomeId(int LastIncomeId)
 {
     lastIncomeId=LastIncomeId;
 }
 vector <Income> IncomesFile::loadSignedUserIncomesFromFile(int signedUserId)
 {
        vector <Income> incomes;
        Income income;
        CMarkup xml;
        bool fileExists = xml.Load( "incomes.xml" );
        int LastIncomeId=0;

        if (fileExists==1)
        {
            xml.ResetPos(); // top of document
            xml.FindElem(); // ORDER element is INCOMES
            xml.IntoElem(); // inside INCOMES

            while ( xml.FindElem("Income"))
            {
                xml.IntoElem();
                xml.FindElem( "UserId" );
                if (signedUserId==AuxiliaryMethods::stringToIntConversion(xml.GetData()))
                {
                    xml.ResetMainPos();
                    xml.FindElem( "IncomeId" );
                    income.setId(AuxiliaryMethods::stringToIntConversion(xml.GetData()));
                    xml.FindElem( "UserId" );
                    income.setUserId(AuxiliaryMethods::stringToIntConversion(xml.GetData()));
                    xml.FindElem( "Date");
                    income.setDate(OperationsOnDates::convertDateToInt(xml.GetData()));
                    xml.FindElem( "Item");
                    income.setItem(xml.GetData());
                    xml.FindElem( "Amount");
                    income.setAmount(atof(xml.GetData().c_str()));

                    incomes.push_back(income);
                }
                xml.OutOfElem();

            }

        }
        if (fileExists==1)
        {
            xml.ResetPos(); // top of document
            xml.FindElem(); // ORDER element is INCOMES
            xml.IntoElem(); // inside INCOMES

            while ( xml.FindElem("Income"))
            {
                    xml.FindChildElem( "IncomeId" );
                    LastIncomeId=AuxiliaryMethods::stringToIntConversion(xml.GetChildData());
            }
            lastIncomeId=LastIncomeId;

        }
        return incomes;
 }
