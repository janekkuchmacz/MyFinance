#include "AuxiliaryMethods.h"


int AuxiliaryMethods:: stringToIntConversion(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}
string AuxiliaryMethods:: intToStringConversion (int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
char AuxiliaryMethods::enterChar()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "It is not one character. Enter your choice once again: " << endl;
    }
    return character;
}
float AuxiliaryMethods::replaceCommaWithDot (string amount)
{
  string amountWithDot="";
  float amountWithDotFloat=0;
  int counter=0;
  for (int i=0; i<amount.length(); i++)
      {
          if(amount[i]+0>=48 && amount[0]+0<=57)
          {
              amountWithDot = amountWithDot + amount [i];
          }
          else if (amount[i]+0==44)
          {
              amountWithDot = amountWithDot + ".";
          }
      }

  amountWithDotFloat=atof(amountWithDot.c_str());
  amountWithDotFloat=amountWithDotFloat*100;
  amountWithDotFloat=floor(amountWithDotFloat);
  amountWithDotFloat=amountWithDotFloat/100;
  return amountWithDotFloat;
}
string AuxiliaryMethods:: floatToStringConversion (float number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}


