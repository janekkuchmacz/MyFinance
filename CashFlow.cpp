#include "CashFlow.h"

void CashFlow::setId(int newId)
        {
            if (newId>0)
                id=newId;
        }
void CashFlow::setUserId(int newId)
        {
            if (newId>0)
                userId=newId;
        }
void CashFlow::setDate(int newDate)
{
    date=newDate;
}
void CashFlow::setItem(string newItemName)
{
    item=newItemName;
}
void CashFlow::setAmount(float newAmount)
{
    amount=newAmount;
}

int CashFlow::getId()
        {
            return id;
        }
int CashFlow::getUserId()
        {
            return userId;
        }
int CashFlow::getDate()
{
    return date;
}
string CashFlow::getItem()
{
    return item;
}
float CashFlow::getAmount()
 {
    return amount;
 }
