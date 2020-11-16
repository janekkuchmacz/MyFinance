#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H
#include <iostream>
#include<sstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

class AuxiliaryMethods
{
public:
  static int stringToIntConversion(string number);
  static string intToStringConversion (int number);
  static char enterChar();
  static float replaceCommaWithDot(string amount);
  static string floatToStringConversion (float number);

};
#endif
