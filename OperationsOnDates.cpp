#include "OperationsOnDates.h"

bool OperationsOnDates::checkDateCorrectness(string date)
{
    if (date.length()!=10)
    {
        return false;
    }
    string Year="", Month="", Day="";
    int year, month, day;
    int currentYear, currentMonth, currentDay;
    int year2000=2000, month01=1, day01=1;
    int dashCounter=0;

    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    currentYear=now->tm_year + 1900;
    currentMonth=now->tm_mon+1;
    currentDay=now->tm_mday;

   Year=date.substr(0,4);
   Month=date.substr(5,2);
   Day=date.substr(8,2);

    if(Day[0]+0<48 || Day[0]+0>57 ||Day[1]+0<48 || Day[1]+0>57 ||Year[0]+0<48 || Year[0]+0>57 ||Year[1]+0<48 || Year[1]+0>57 ||Year[2]+0<48 || Year[2]+0>57 || Year[3]+0<48 || Year[3]+0>57 || Month[0]+0<48 || Month[0]+0>57 || Month[1]+0<48 || Month[1]+0>57)
    {
        return false;
    }
    if (Month[0]=='0') {
        Month=Month.substr(1,1);
    }
    if (Day[0]=='0') {
        Day=Day.substr(1,1);
    }
    year=atoi(Year.c_str());
    month=atoi(Month.c_str());
    day=atoi(Day.c_str());

    if (year>=year2000 && year<=currentYear)
    {
        if (year==currentYear && month<=currentMonth && month>=1)
        {
            if (day>=1 && day<=returnMaxiumNumberofDaysInMonth(month, year) )
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (year!=currentYear && month>=1 && month<=12)
        {
            if (day>=1 && day<=returnMaxiumNumberofDaysInMonth(month, year))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
int OperationsOnDates:: returnMaxiumNumberofDaysInMonth(int month, int year)
{
    if ((month==1) || (month==3) || (month==5) || (month==7) || (month==8) || (month ==10) || (month==12) )
    {
        return 31;
    }
    else if ((month==4) || (month==6) || (month==9) || (month==11))
    {
        return 30;
    }
    else if (((year%4==0)&&(year%100!=0))||(year%400==0))
    {
        return 29;
    }
    else
    {
        return 28;
    }
}
string OperationsOnDates::returnCurrentDate()
{
        string year="", month="", day="", date="";

       time_t t = time(0);   // get time now
       struct tm * now = localtime( & t );

       year=AuxiliaryMethods::intToStringConversion(now->tm_year + 1900);

       if ((now->tm_mon+1)<10)
       {
          month="0"+ AuxiliaryMethods::intToStringConversion(now->tm_mon+1);
       }
       else
       {
          month=AuxiliaryMethods::intToStringConversion(now->tm_mon+1);
       }
       if ((now->tm_mday)<10)
       {
           day="0"+AuxiliaryMethods::intToStringConversion(now->tm_mday);
       }
       else
       {
           day=AuxiliaryMethods::intToStringConversion(now->tm_mday);
       }

       date=year+'-'+month+'-'+day;
       return date;
}
int OperationsOnDates::convertDateToInt (string dateWithDashes)
{
    string DateWithoutDashes="";
    for (int i=0; i<dateWithDashes.length(); i++)
    {
        if (dateWithDashes[i]!='-')
        {
            DateWithoutDashes=DateWithoutDashes+dateWithDashes[i];
        }
    }
    return AuxiliaryMethods::stringToIntConversion(DateWithoutDashes);
}
string OperationsOnDates::convertDateFromIntToString(int dateInt)
{
   string dateString=AuxiliaryMethods:: intToStringConversion(dateInt);
   string dateWithDashes="";
   for (int i=0; i<dateString.length(); i++)
   {
       dateWithDashes=dateWithDashes+dateString[i];
       if(i==3 || i==5)
       {
          dateWithDashes=dateWithDashes+'-';
       }
   }
   return dateWithDashes;
}
bool OperationsOnDates::checkIfDateIsFromThisMonth (int date)
{
    int currentYear=0, currentMonth=0, currentDay=0;
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    currentYear=now->tm_year + 1900;
    currentMonth=now->tm_mon+1;
    int year=0, month=0, day=0;
    year=date/10000;
    month=(date/100)%100;
    if (year==currentYear && month==currentMonth)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool OperationsOnDates::checkIfDateIsFromPreviousMonth (int date)
{
    int currentYear=0, currentMonth=0, currentDay=0;
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    currentYear=now->tm_year + 1900;
    currentMonth=now->tm_mon+1;
    int year=0, month=0, day=0;
    year=date/10000;
    month=(date/100)%100;
    if (year==currentYear && month==currentMonth-1 && currentMonth>1)
    {
        return true;
    }
    else if (currentMonth==1 && year==currentYear-1 && month==12)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool OperationsOnDates::checkIfDateIsFromSelectedPeriodOfTime (int date, int startDate, int finishDate)
{
    if (startDate<=date && date<=finishDate)
    {
        return true;
    }
    else
    {
        return false;
    }
}
