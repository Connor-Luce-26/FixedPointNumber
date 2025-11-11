#include "FixedPointNumber.cpp"
#include <iostream>
int main()
{
	FixedPointNumber<64, 64> num1("123.5560");
	num1.printLine();
	FixedPointNumber<64, 64> num2("-1.0");
	num2.printLine();
	FixedPointNumber<64, 64> num3 = num1 + num2;
	num3.printLine();
	FixedPointNumber<64, 64> num4 = num3 - num1;
	num4.printLine();
	FixedPointNumber<64, 64> num5 = -num4;
	num5.printLine();
	return 0;
}
