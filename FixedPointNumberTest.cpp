/**
 * @file FixedPointNumberTest.cpp
 * @author Robert Connor Luce
 * @brief Tests for FixedPointNumber class.
 */
#include "FixedPointNumber.hpp"
#include <iostream>
#include <fstream>
#ifndef TEST_OUTPUT_FILE
#define TEST_OUTPUT_FILE "FixedPointNumberTestOutput.txt"
#endif
std::ofstream file = std::ofstream(TEST_OUTPUT_FILE);
/**
 * @brief Tests the default constructor of FixedPointNumber.
 */
void testDefaultConstructor()
{
	try
	{
		FixedPointNumber<8, 8> number;
		std::cout << "Default constructor: " << number.toString() << std::endl;
		file << "Default constructor: " << number.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the positive string constructor of FixedPointNumber.
 */
void testPositiveStringConstructor()
{
	try
	{
		FixedPointNumber<8, 8> number("12.34");
		std::cout << "Positive string constructor: " << number.toString() << std::endl;
		file << "Positive string constructor: " << number.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the negative string constructor of FixedPointNumber.
 */
void testNegativeStringConstructor()
{
	try
	{
		FixedPointNumber<8, 8> number("-12.34");
		std::cout << "Negative string constructor: " << number.toString() << std::endl;
		file << "Negative string constructor: " << number.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the integer constructor of FixedPointNumber.
 */
void testIntegerConstructor()
{
	try
	{
		FixedPointNumber<8, 8> number(42);
		std::cout << "Integer constructor: " << number.toString() << std::endl;
		file << "Integer constructor: " << number.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the maximum static method of FixedPointNumber.
 */
void testMaximum()
{
	try
	{
		FixedPointNumber<8, 8> numbers[4] = {FixedPointNumber<8, 8>(0), FixedPointNumber<8, 8>(1), FixedPointNumber<8, 8>(2), FixedPointNumber<8, 8>(3)};
		FixedPointNumber<8, 8> maximumNumber = FixedPointNumber<8, 8>::maximum(numbers, 4);
		std::cout << "Maximum: The maximum of the array, " << numbers->toString() << ",  is " << maximumNumber.toString() << std::endl;
		file << "Maximum: The maximum of the array, " << numbers->toString() << ",  is " << maximumNumber.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
	
}
/**
 * @brief Tests the minimum static method of FixedPointNumber.
 */
void testMinimum()
{
	try
	{
		FixedPointNumber<8, 8> numbers[4] = {FixedPointNumber<8, 8>(0), FixedPointNumber<8, 8>(1), FixedPointNumber<8, 8>(2), FixedPointNumber<8, 8>(3)};
		FixedPointNumber<8, 8> minimumNumber = FixedPointNumber<8, 8>::minimum(numbers, 4);
		std::cout << "Minimum: The minimum of the array, " << numbers->toString() << ",  is " << minimumNumber.toString() << std::endl;
		file << "Minimum: The minimum of the array, " << numbers->toString() << ",  is " << minimumNumber.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
	
}
/**
 * @brief Tests the getNumberOfDecimalPlaces method of FixedPointNumber.
 */
void testGetNumberOfDecimalPlaces()
{
	try
	{
		FixedPointNumber<8, 8> number("12.340");
		std::cout << "getNumberOfDecimalPlaces: Number of Decimal Places of (\"12.340\") is " << number.getNumberOfDecimalPlaces() << std::endl;
		file << "getNumberOfDecimalPlaces: Number of Decimal Places of (\"12.340\") is " << number.getNumberOfDecimalPlaces() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the absoluteValue method of FixedPointNumber.
 */
void testAbsoluteValue()
{
	try
	{
		FixedPointNumber<8, 8> number("-15.75");
		FixedPointNumber<8, 8> absValue = number.absoluteValue();
		std::cout << "Absolute value: The absolute value of " << number.toString() << " is " << absValue.toString() << std::endl;
		file << "Absolute value: The absolute value of " << number.toString() << " is " << absValue.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the addition operator of FixedPointNumber.
 */
void testAdditionOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("12.34");
		FixedPointNumber<8, 8> number2("23.45");
		FixedPointNumber<8, 8> sum = number1 + number2;
		std::cout << "Addition operator: " << number1.toString() << " + " << number2.toString() << " = " << sum.toString() << std::endl;
		file << "Addition operator: " << number1.toString() << " + " << number2.toString() << " = " << sum.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the subtraction operator of FixedPointNumber.
 */
void testSubtractionOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("23.45");
		FixedPointNumber<8, 8> number2("12.34");
		FixedPointNumber<8, 8> difference = number1 - number2;
		std::cout << "Subtraction operator: " << number1.toString() << " - " << number2.toString() << " = " << difference.toString() << std::endl;
		file << "Subtraction operator: " << number1.toString() << " - " << number2.toString() << " = " << difference.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests unary negation and addition to zero.
 */
void testUnaryNegationAndZero()
{
	try
	{
		FixedPointNumber<8, 8> number("5.25");
		FixedPointNumber<8, 8> neg = -number;
		FixedPointNumber<8, 8> sum = number + neg;
		std::cout << "Unary negation: " << number.toString() << " + (" << neg.toString() << ") = " << sum.toString() << std::endl;
		file << "Unary negation: " << number.toString() << " + (" << neg.toString() << ") = " << sum.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests addition involving a negative fixed-point number.
 */
void testAdditionWithNegative()
{
	try
	{
		FixedPointNumber<8, 8> a("10.5");
		FixedPointNumber<8, 8> b("-3.25");
		FixedPointNumber<8, 8> sum = a + b;
		std::cout << "Addition with negative: " << a.toString() << " + " << b.toString() << " = " << sum.toString() << std::endl;
		file << "Addition with negative: " << a.toString() << " + " << b.toString() << " = " << sum.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the fractional rounding behavior of FixedPointNumber.
 */
void testFractionalRounding()
{
	try
	{
		FixedPointNumber<8, 8> number("1.005");
		std::cout << "Fractional rounding (\"1.005\"): " << number.toString() << std::endl;
		file << "Fractional rounding (\"1.005\"): " << number.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the multiplication operator of FixedPointNumber.
 */
void testMultiplicationOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("3.5");
		FixedPointNumber<8, 8> number2("2.0");
		FixedPointNumber<8, 8> product = number1 * number2;
		std::cout << "Multiplication operator: " << number1.toString() << " * " << number2.toString() << " = " << product.toString() << std::endl;
		file << "Multiplication operator: " << number1.toString() << " * " << number2.toString() << " = " << product.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests multiplication involving a negative fixed-point number.
 */
void testNegativeMultiplication()
{
	try
	{
		FixedPointNumber<8, 8> number1("-4.0");
		FixedPointNumber<8, 8> number2("2.5");
		FixedPointNumber<8, 8> product = number1 * number2;
		std::cout << "Negative multiplication: " << number1.toString() << " * " << number2.toString() << " = " << product.toString() << std::endl;
		file << "Negative multiplication: " << number1.toString() << " * " << number2.toString() << " = " << product.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the division operator of FixedPointNumber.
 */
void testDivisionOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("10.00");
		FixedPointNumber<8, 8> number2("3.0");
		FixedPointNumber<8, 8> quotient = number1 / number2;
		std::cout << "Division operator: " << number1.toString() << " / " << number2.toString() << " = " << quotient.toString() << std::endl;
		file << "Division operator: " << number1.toString() << " / " << number2.toString() << " = " << quotient.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the modulo operator of FixedPointNumber.
 */
void testModuloOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("10.5");
		FixedPointNumber<8, 8> number2("3.0");
		FixedPointNumber<8, 8> remainder = number1 % number2;
		std::cout << "Modulo operator: " << number1.toString() << " % " << number2.toString() << " = " << remainder.toString() << std::endl;
		file << "Modulo operator: " << number1.toString() << " % " << number2.toString() << " = " << remainder.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the bitwise left shift operator of FixedPointNumber.
 */
void testBitShiftLeftOperator()
{
	try
	{
		FixedPointNumber<8, 8> number("2.5");
		int shiftAmount = 2;
		FixedPointNumber<8, 8> shifted = number << shiftAmount;
		std::cout << "Left shift operator: " << number.bitsToString() << " << " << shiftAmount << " = " << shifted.bitsToString() << std::endl;
		file << "Left shift operator: " << number.bitsToString() << " << " << shiftAmount << " = " << shifted.bitsToString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the bitwise right shift operator of FixedPointNumber.
 */
void testBitShiftRightOperator()
{
	try
	{
		FixedPointNumber<8, 8> number("10.0");
		int shiftAmount = 1;
		FixedPointNumber<8, 8> shifted = number >> shiftAmount;
		std::cout << "Right shift operator: " << number.bitsToString() << " >> " << shiftAmount << " = " << shifted.bitsToString() << std::endl;
		file << "Right shift operator: " << number.bitsToString() << " >> " << shiftAmount << " = " << shifted.bitsToString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the bitwise NOT operator of FixedPointNumber.
 */
void testBitwiseNotOperator()
{
	try
	{
		FixedPointNumber<8, 8> number("5.0");
		FixedPointNumber<8, 8> notNumber = ~number;
		std::cout << "Bitwise NOT operator: ~" << number.bitsToString() << " = " << notNumber.bitsToString() << std::endl;
		file << "Bitwise NOT operator: ~" << number.bitsToString() << " = " << notNumber.bitsToString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the bitwise AND operator of FixedPointNumber.
 */
void testBitwiseAndOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("6.0");
		FixedPointNumber<8, 8> number2("3.0");
		FixedPointNumber<8, 8> andNumber = number1 & number2;
		std::cout << "Bitwise AND operator: " << number1.bitsToString() << " & " << number2.bitsToString() << " = " << andNumber.bitsToString() << std::endl;
		file << "Bitwise AND operator: " << number1.bitsToString() << " & " << number2.bitsToString() << " = " << andNumber.bitsToString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the bitwise OR operator of FixedPointNumber.
 */
void testBitwiseOrOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("6.0");
		FixedPointNumber<8, 8> number2("3.0");
		FixedPointNumber<8, 8> orNumber = number1 | number2;
		std::cout << "Bitwise OR operator: " << number1.bitsToString() << " | " << number2.bitsToString() << " = " << orNumber.bitsToString() << std::endl;
		file << "Bitwise OR operator: " << number1.bitsToString() << " | " << number2.bitsToString() << " = " << orNumber.bitsToString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the bitwise XOR operator of FixedPointNumber.
 */
void testBitwiseXorOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("6.0");
		FixedPointNumber<8, 8> number2("3.0");
		FixedPointNumber<8, 8> xorNumber = number1 ^ number2;
		std::cout << "Bitwise XOR operator: " << number1.bitsToString() << " ^ " << number2.bitsToString() << " = " << xorNumber.bitsToString() << std::endl;
		file << "Bitwise XOR operator: " << number1.bitsToString() << " ^ " << number2.bitsToString() << " = " << xorNumber.bitsToString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the equality operator of FixedPointNumber.
 */
void testEqualityOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("5.0");
		FixedPointNumber<8, 8> number2("5.0");
		if (number1 == number2)
		{
			std::cout << "Equality operator: " << number1.toString() << " == " << number2.toString() << " is true." << std::endl;
			file << "Equality operator: " << number1.toString() << " == " << number2.toString() << " is true." << std::endl;
		}
		else
		{
			std::cout << "Equality operator: " << number1.toString() << " == " << number2.toString() << " is false." << std::endl;
			file << "Equality operator: " << number1.toString() << " == " << number2.toString() << " is false." << std::endl;
		}
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the inequality operator of FixedPointNumber.
 */
void testInequalityOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("5.0");
		FixedPointNumber<8, 8> number2("6.0");
		if (number1 != number2)
		{
			std::cout << "Inequality operator: " << number1.toString() << " != " << number2.toString() << " is true." << std::endl;
			file << "Inequality operator: " << number1.toString() << " != " << number2.toString() << " is true." << std::endl;
		}
		else
		{
			std::cout << "Inequality operator: " << number1.toString() << " != " << number2.toString() << " is false." << std::endl;
			file << "Inequality operator: " << number1.toString() << " != " << number2.toString() << " is false." << std::endl;
		}
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the less-than operator of FixedPointNumber.
 */
void testLessThanOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("5.0");
		FixedPointNumber<8, 8> number2("6.0");
		if (number1 < number2)
		{
			std::cout << "Less-than operator: " << number1.toString() << " < " << number2.toString() << " is true." << std::endl;
			file << "Less-than operator: " << number1.toString() << " < " << number2.toString() << " is true." << std::endl;
		}
		else
		{
			std::cout << "Less-than operator: " << number1.toString() << " < " << number2.toString() << " is false." << std::endl;
			file << "Less-than operator: " << number1.toString() << " < " << number2.toString() << " is false." << std::endl;
		}
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the less-than-or-equal-to operator of FixedPointNumber.
 */
void testLessThanOrEqualToOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("5.0");
		FixedPointNumber<8, 8> number2("5.0");
		if (number1 <= number2)
		{
			std::cout << "Less-than-or-equal-to operator: " << number1.toString() << " <= " << number2.toString() << " is true." << std::endl;
			file << "Less-than-or-equal-to operator: " << number1.toString() << " <= " << number2.toString() << " is true." << std::endl;
		}
		else
		{
			std::cout << "Less-than-or-equal-to operator: " << number1.toString() << " <= " << number2.toString() << " is false." << std::endl;
			file << "Less-than-or-equal-to operator: " << number1.toString() << " <= " << number2.toString() << " is false." << std::endl;
		}
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the greater-than operator of FixedPointNumber.
 */
void testGreaterThanOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("7.0");
		FixedPointNumber<8, 8> number2("6.0");
		if (number1 > number2)
		{
			std::cout << "Greater-than operator: " << number1.toString() << " > " << number2.toString() << " is true." << std::endl;
			file << "Greater-than operator: " << number1.toString() << " > " << number2.toString() << " is true." << std::endl;
		}
		else
		{
			std::cout << "Greater-than operator: " << number1.toString() << " > " << number2.toString() << " is false." << std::endl;
			file << "Greater-than operator: " << number1.toString() << " > " << number2.toString() << " is false." << std::endl;
		}
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the greater-than-or-equal-to operator of FixedPointNumber.
 */
void testGreaterThanOrEqualToOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("7.0");
		FixedPointNumber<8, 8> number2("7.0");
		if (number1 >= number2)
		{
			std::cout << "Greater-than-or-equal-to operator: " << number1.toString() << " >= " << number2.toString() << " is true." << std::endl;
			file << "Greater-than-or-equal-to operator: " << number1.toString() << " >= " << number2.toString() << " is true." << std::endl;
		}
		else
		{
			std::cout << "Greater-than-or-equal-to operator: " << number1.toString() << " >= " << number2.toString() << " is false." << std::endl;
			file << "Greater-than-or-equal-to operator: " << number1.toString() << " >= " << number2.toString() << " is false." << std::endl;
		}
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the plus-equals operator of FixedPointNumber.
 */
void testPlusEqualsOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("5.0");
		FixedPointNumber<8, 8> number2("3.0");
		std::cout << "Plus-equals operator: " << number1.toString() << " += " << number2.toString();
		file << "Plus-equals operator: " << number1.toString() << " += " << number2.toString();
		number1 += number2;
		std::cout << " = " << number1.toString() << std::endl;
		file << " = " << number1.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the minus-equals operator of FixedPointNumber.
 */
void testMinusEqualsOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("5.0");
		FixedPointNumber<8, 8> number2("3.0");
		std::cout << "Minus-equals operator: " << number1.toString() << " -= " << number2.toString();
		file << "Minus-equals operator: " << number1.toString() << " -= " << number2.toString();
		number1 -= number2;
		std::cout << " = " << number1.toString() << std::endl;
		file << " = " << number1.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the multiplication-equals operator of FixedPointNumber.
 */
void testMultiplicationEqualsOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("5.0");
		FixedPointNumber<8, 8> number2("3.0");
		std::cout << "Multiplication-equals operator: " << number1.toString() << " *= " << number2.toString();
		file << "Multiplication-equals operator: " << number1.toString() << " *= " << number2.toString();
		number1 *= number2;
		std::cout << " = " << number1.toString() << std::endl;
		file << " = " << number1.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the division-equals operator of FixedPointNumber.
 */
void testDivisionEqualsOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("6.0");
		FixedPointNumber<8, 8> number2("3.0");
		std::cout << "Division-equals operator: " << number1.toString() << " /= " << number2.toString();
		file << "Division-equals operator: " << number1.toString() << " /= " << number2.toString();
		number1 /= number2;
		std::cout << " = " << number1.toString() << std::endl;
		file << " = " << number1.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the modulo-equals operator of FixedPointNumber.
 */
void testModuloEqualsOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("10.0");
		FixedPointNumber<8, 8> number2("3.0");
		std::cout << "Modulo-equals operator: " << number1.toString() << " %= " << number2.toString();
		file << "Modulo-equals operator: " << number1.toString() << " %= " << number2.toString();
		number1 %= number2;
		std::cout << " = " << number1.toString() << std::endl;
		file << " = " << number1.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the bitwise left-shift-equals operator of FixedPointNumber.
 */
void testBitShiftLeftEqualsOperator()
{
	try
	{
		FixedPointNumber<8, 8> number("3.25");
		int shiftAmount = 2;
		std::cout << "Left-shift-equals operator: " << number.toString() << " <<= " << shiftAmount;
		file << "Left-shift-equals operator: " << number.toString() << " <<= " << shiftAmount;
		number <<= shiftAmount;
		std::cout << " = " << number.toString() << std::endl;
		file << " = " << number.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the bitwise right-shift-equals operator of FixedPointNumber.
 */
void testBitShiftRightEqualsOperator()
{
	try
	{
		FixedPointNumber<8, 8> number("13.0");
		int shiftAmount = 2;
		std::cout << "Right-shift-equals operator: " << number.toString() << " >>= " << shiftAmount;
		file << "Right-shift-equals operator: " << number.toString() << " >>= " << shiftAmount;
		number >>= shiftAmount;
		std::cout << " = " << number.toString() << std::endl;
		file << " = " << number.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the bitwise AND-equals operator of FixedPointNumber.
 */
void testBitwiseAndEqualsOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("12.34");
		FixedPointNumber<8, 8> number2("5.67");
		std::cout << "Bitwise AND-equals operator: " << number1.toString() << " &= " << number2.toString();
		file << "Bitwise AND-equals operator: " << number1.toString() << " &= " << number2.toString();
		number1 &= number2;
		std::cout << " = " << number1.toString() << std::endl;
		file << " = " << number1.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the bitwise OR-equals operator of FixedPointNumber.
 */
void testBitwiseOrEqualsOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("12.34");
		FixedPointNumber<8, 8> number2("5.67");
		std::cout << "Bitwise OR-equals operator: " << number1.toString() << " |= " << number2.toString();
		file << "Bitwise OR-equals operator: " << number1.toString() << " |= " << number2.toString();
		number1 |= number2;
		std::cout << " = " << number1.toString() << std::endl;
		file << " = " << number1.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the bitwise XOR-equals operator of FixedPointNumber.
 */
void testBitwiseXorEqualsOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("12.34");
		FixedPointNumber<8, 8> number2("5.67");
		std::cout << "Bitwise XOR-equals operator: " << number1.toString() << " ^= " << number2.toString();
		file << "Bitwise XOR-equals operator: " << number1.toString() << " ^= " << number2.toString();
		number1 ^= number2;
		std::cout << " = " << number1.toString() << std::endl;
		file << " = " << number1.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the increment operator of FixedPointNumber.
 */
void testIncrementOperator()
{
	try
	{
		FixedPointNumber<8, 8> number("5.5");
		std::cout << "Increment operator: " << number.toString() << "++";
		file << "Increment operator: " << number.toString() << "++";
		number++;
		std::cout << " = " << number.toString() << std::endl;
		file << " = " << number.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the decrement operator of FixedPointNumber.
 */
void testDecrementOperator()
{
	try
	{
		FixedPointNumber<8, 8> number("5.5");
		std::cout << "Decrement operator: " << number.toString() << "--";
		file << "Decrement operator: " << number.toString() << "--";
		number--;
		std::cout << " = " << number.toString() << std::endl;
		file << " = " << number.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the logical NOT operator of FixedPointNumber.
 */
void testLogicalNotOperator()
{
	try
	{
		FixedPointNumber<8, 8> number("0.0");
		if (!number)
		{
			std::cout << "Logical NOT operator: !" << number.toString() << " is true." << std::endl;
			file << "Logical NOT operator: !" << number.toString() << " is true." << std::endl;
		}
		else
		{
			std::cout << "Logical NOT operator: !" << number.toString() << " is false." << std::endl;
			file << "Logical NOT operator: !" << number.toString() << " is false." << std::endl;
		}
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Tests the logical AND operator of FixedPointNumber.
 */
void testLogicalAndOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("5.0");
		FixedPointNumber<8, 8> number2("3.0");
		if (number1 && number2)
		{
			std::cout << "Logical AND operator: " << number1.toString() << " && " << number2.toString() << " is true." << std::endl;
			file << "Logical AND operator: " << number1.toString() << " && " << number2.toString() << " is true." << std::endl;
		}
		else
		{
			std::cout << "Logical AND operator: " << number1.toString() << " && " << number2.toString() << " is false." << std::endl;
			file << "Logical AND operator: " << number1.toString() << " && " << number2.toString() << " is false." << std::endl;
		}
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
} 
/**
 * @brief Tests the logical OR operator of FixedPointNumber.
 */
void testLogicalOrOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("0.0");
		FixedPointNumber<8, 8> number2("3.0");
		if (number1 || number2)
		{
			std::cout << "Logical OR operator: " << number1.toString() << " || " << number2.toString() << " is true." << std::endl;
			file << "Logical OR operator: " << number1.toString() << " || " << number2.toString() << " is true." << std::endl;
		}
		else
		{
			std::cout << "Logical OR operator: " << number1.toString() << " || " << number2.toString() << " is false." << std::endl;
			file << "Logical OR operator: " << number1.toString() << " || " << number2.toString() << " is false." << std::endl;
		}
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		file << exception.what() << std::endl;
	}
}
/**
 * @brief Main function to run all tests.
 */
int main()
{
	testDefaultConstructor();
	testPositiveStringConstructor();
	testNegativeStringConstructor();
	testIntegerConstructor();
	testMaximum();
	testMinimum();
	testGetNumberOfDecimalPlaces();
	testAbsoluteValue();
	testUnaryNegationAndZero();
	testAdditionOperator();
	testSubtractionOperator();
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
	testMultiplicationEqualsOperator();
	testDivisionEqualsOperator();
	testModuloEqualsOperator();
	testBitShiftLeftOperator();
	testBitShiftLeftEqualsOperator();
	testBitShiftRightOperator();
	testBitShiftRightEqualsOperator();
	testBitwiseNotOperator();
	testBitwiseAndOperator();
	testBitwiseOrOperator();
	testBitwiseOrEqualsOperator();
	testBitwiseXorOperator();
	testBitwiseXorEqualsOperator();
	testIncrementOperator();
	testDecrementOperator();
	testLogicalNotOperator();
	testLogicalAndOperator();
	testLogicalOrOperator();
	return 0;
}
