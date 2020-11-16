#ifndef CASHFLOW_H
#define CASHFLOW_H
#include <iostream>


using namespace std;

class CashFlow
{
   int id, userId, date;
   string item;
   float amount;
public:
    void setId(int newId);
    void setUserId(int newId);
    void setDate(int newDate);
    void setItem(string newItemName);
    void setAmount(float newAmount);
    int getId();
    int getUserId();
    int getDate();
    string getItem();
    float getAmount();

};
#endif
