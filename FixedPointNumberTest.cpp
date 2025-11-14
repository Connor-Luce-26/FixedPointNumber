#include "FixedPointNumber.cpp"
#include <iostream>
void testDefaultConstructor()
{
	try
	{
		FixedPointNumber<8, 8> number;
		std::cout << "Default constructor: " << number.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testPositiveStringConstructor()
{
	try
	{
		FixedPointNumber<8, 8> number("12.34");
		std::cout << "Positive string constructor: " << number.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testNegativeStringConstructor()
{
	try
	{
		FixedPointNumber<8, 8> number("-12.34");
		std::cout << "Negative string constructor: " << number.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testIntegerConstructor()
{
	try
	{
		FixedPointNumber<8, 8> number(42);
		std::cout << "Integer constructor: " << number.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testAdditionOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("12.34");
		FixedPointNumber<8, 8> number2("23.45");
		FixedPointNumber<8, 8> sum = number1 + number2;
		std::cout << "Addition operator: " << number1.toString() << " + " << number2.toString() << " = " << sum.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testSubtractionOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("23.45");
		FixedPointNumber<8, 8> number2("12.34");
		FixedPointNumber<8, 8> difference = number1 - number2;
		std::cout << "Subtraction operator: " << number1.toString() << " - " << number2.toString() << " = " << difference.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testGetNumberOfDecimalPlaces()
{
	try
	{
		FixedPointNumber<8, 8> number("12.340");
		std::cout << "getNumberOfDecimalPlaces (\"12.340\"): " << number.getNumberOfDecimalPlaces() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testUnaryNegationAndZero()
{
	try
	{
		FixedPointNumber<8, 8> number("5.25");
		FixedPointNumber<8, 8> neg = -number;
		FixedPointNumber<8, 8> sum = number + neg;
		std::cout << "Unary negation: " << number.toString() << " + (" << neg.toString() << ") = " << sum.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testAdditionWithNegative()
{
	try
	{
		FixedPointNumber<8, 8> a("10.5");
		FixedPointNumber<8, 8> b("-3.25");
		FixedPointNumber<8, 8> sum = a + b;
		std::cout << "Addition with negative: " << a.toString() << " + " << b.toString() << " = " << sum.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testFractionalRounding()
{
	try
	{
		FixedPointNumber<8, 8> number("1.005");
		std::cout << "Fractional rounding (\"1.005\"): " << number.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testMultiplicationOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("3.5");
		FixedPointNumber<8, 8> number2("2.0");
		FixedPointNumber<8, 8> product = number1 * number2;
		std::cout << "Multiplication operator: " << number1.toString() << " * " << number2.toString() << " = " << product.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testNegativeMultiplication()
{
	try
	{
		FixedPointNumber<8, 8> number1("-4.0");
		FixedPointNumber<8, 8> number2("2.5");
		FixedPointNumber<8, 8> product = number1 * number2;
		std::cout << "Negative multiplication: " << number1.toString() << " * " << number2.toString() << " = " << product.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testModuloOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("10.5");
		FixedPointNumber<8, 8> number2("3.0");
		FixedPointNumber<8, 8> remainder = number1 % number2;
		std::cout << "Modulo operator: " << number1.toString() << " % " << number2.toString() << " = " << remainder.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testDivisionOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("7.0");
		FixedPointNumber<8, 8> number2("2.0");
		FixedPointNumber<8, 8> quotient = number1 / number2;
		std::cout << "Division operator: " << number1.toString() << " / " << number2.toString() << " = " << quotient.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testEqualityOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("5.0");
		FixedPointNumber<8, 8> number2("5.0");
		if (number1 == number2)
		{
			std::cout << "Equality operator: " << number1.toString() << " == " << number2.toString() << " is true." << std::endl;
		}
		else
		{
			std::cout << "Equality operator: " << number1.toString() << " == " << number2.toString() << " is false." << std::endl;
		}
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testInequalityOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("5.0");
		FixedPointNumber<8, 8> number2("6.0");
		if (number1 != number2)
		{
			std::cout << "Inequality operator: " << number1.toString() << " != " << number2.toString() << " is true." << std::endl;
		}
		else
		{
			std::cout << "Inequality operator: " << number1.toString() << " != " << number2.toString() << " is false." << std::endl;
		}
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testLessThanOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("5.0");
		FixedPointNumber<8, 8> number2("6.0");
		if (number1 < number2)
		{
			std::cout << "Less-than operator: " << number1.toString() << " < " << number2.toString() << " is true." << std::endl;
		}
		else
		{
			std::cout << "Less-than operator: " << number1.toString() << " < " << number2.toString() << " is false." << std::endl;
		}
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testLessThanOrEqualToOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("5.0");
		FixedPointNumber<8, 8> number2("5.0");
		if (number1 <= number2)
		{
			std::cout << "Less-than-or-equal-to operator: " << number1.toString() << " <= " << number2.toString() << " is true." << std::endl;
		}
		else
		{
			std::cout << "Less-than-or-equal-to operator: " << number1.toString() << " <= " << number2.toString() << " is false." << std::endl;
		}
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testGreaterThanOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("7.0");
		FixedPointNumber<8, 8> number2("6.0");
		if (number1 > number2)
		{
			std::cout << "Greater-than operator: " << number1.toString() << " > " << number2.toString() << " is true." << std::endl;
		}
		else
		{
			std::cout << "Greater-than operator: " << number1.toString() << " > " << number2.toString() << " is false." << std::endl;
		}
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testGreaterThanOrEqualToOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("7.0");
		FixedPointNumber<8, 8> number2("7.0");
		if (number1 >= number2)
		{
			std::cout << "Greater-than-or-equal-to operator: " << number1.toString() << " >= " << number2.toString() << " is true." << std::endl;
		}
		else
		{
			std::cout << "Greater-than-or-equal-to operator: " << number1.toString() << " >= " << number2.toString() << " is false." << std::endl;
		}
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testPlusEqualsOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("5.0");
		FixedPointNumber<8, 8> number2("3.0");
		std::cout << "Plus-equals operator: Before number1 += number2, number1 = " << number1.toString() << std::endl;
		number1 += number2;
		std::cout << "Plus-equals operator: After number1 += number2, number1 = " << number1.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testMinusEqualsOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("5.0");
		FixedPointNumber<8, 8> number2("3.0");
		std::cout << "Minus-equals operator: Before number1 -= number2, number1 = " << number1.toString() << std::endl;
		number1 -= number2;
		std::cout << "Minus-equals operator: After number1 -= number2, number1 = " << number1.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
int main()
{	
	testDefaultConstructor();
	testPositiveStringConstructor();
	testNegativeStringConstructor();
	testIntegerConstructor();
	testAdditionOperator();
	testSubtractionOperator();
	testGetNumberOfDecimalPlaces();
	testUnaryNegationAndZero();
	testAdditionWithNegative();
	testFractionalRounding();
	testMultiplicationOperator();
	testNegativeMultiplication();
	testDivisionOperator();
	testModuloOperator();
	testEqualityOperator();
	testInequalityOperator();
	testLessThanOperator();
	testLessThanOrEqualToOperator();
	testGreaterThanOperator();
	testGreaterThanOrEqualToOperator();
	testPlusEqualsOperator();
	testMinusEqualsOperator();
	return 0;
}
