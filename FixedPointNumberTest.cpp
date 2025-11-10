#include "FixedPointNumber.cpp"
#include <iostream>
int main()
{
	FixedPointNumber<64, 64> num1("123.4560");
	num1.printLine();
	return 0;
}
