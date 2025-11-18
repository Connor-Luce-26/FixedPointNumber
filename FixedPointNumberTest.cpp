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
void testDivisionOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("10.00");
		FixedPointNumber<8, 8> number2("3.0");
		FixedPointNumber<8, 8> quotient = number1 / number2;
		std::cout << "Division operator: " << number1.toString() << " / " << number2.toString() << " = " << quotient.toString() << std::endl;
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
void testBitShiftLeftOperator()
{
	try
	{
		FixedPointNumber<8, 8> number("2.5");
		FixedPointNumber<8, 8> shifted = number << 2;
		std::cout << "Bitwise left shift operator: " << number.toString() << " << 2 = " << shifted.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testBitShiftRightOperator()
{
	try
	{
		FixedPointNumber<8, 8> number("10.0");
		FixedPointNumber<8, 8> shifted = number >> 1;
		std::cout << "Bitwise right shift operator: " << number.toString() << " >> 1 = " << shifted.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testBitwiseNotOperator()
{
	try
	{
		FixedPointNumber<8, 8> number("5.0");
		FixedPointNumber<8, 8> notNumber = ~number;
		std::cout << "Bitwise NOT operator: ~" << number.toString() << " = " << notNumber.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testBitwiseAndOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("6.0");
		FixedPointNumber<8, 8> number2("3.0");
		FixedPointNumber<8, 8> andNumber = number1 & number2;
		std::cout << "Bitwise AND operator: " << number1.toString() << " & " << number2.toString() << " = " << andNumber.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testBitwiseOrOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("6.0");
		FixedPointNumber<8, 8> number2("3.0");
		FixedPointNumber<8, 8> orNumber = number1 | number2;
		std::cout << "Bitwise OR operator: " << number1.toString() << " | " << number2.toString() << " = " << orNumber.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testBitwiseXorOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("6.0");
		FixedPointNumber<8, 8> number2("3.0");
		FixedPointNumber<8, 8> xorNumber = number1 ^ number2;
		std::cout << "Bitwise XOR operator: " << number1.toString() << " ^ " << number2.toString() << " = " << xorNumber.toString() << std::endl;
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
void testMultiplicationEqualsOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("5.0");
		FixedPointNumber<8, 8> number2("3.0");
		std::cout << "Multiplication-equals operator: Before number1 *= number2, number1 = " << number1.toString() << std::endl;
		number1 *= number2;
		std::cout << "Multiplication-equals operator: After number1 *= number2, number1 = " << number1.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testDivisionEqualsOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("6.0");
		FixedPointNumber<8, 8> number2("3.0");
		std::cout << "Division-equals operator: Before number1 /= number2, number1 = " << number1.toString() << std::endl;
		number1 /= number2;
		std::cout << "Division-equals operator: After number1 /= number2, number1 = " << number1.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testModuloEqualsOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("10.0");
		FixedPointNumber<8, 8> number2("3.0");
		std::cout << "Modulo-equals operator: Before number1 %= number2, number1 = " << number1.toString() << std::endl;
		number1 %= number2;
		std::cout << "Modulo-equals operator: After number1 %= number2, number1 = " << number1.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testBitShiftLeftEqualsOperator()
{
	try
	{
		FixedPointNumber<8, 8> number("3.25");
		std::cout << "Bitwise left-shift-equals operator: Before number <<= 2, number = " << number.toString() << std::endl;
		number <<= 2;
		std::cout << "Bitwise left-shift-equals operator: After number <<= 2, number = " << number.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testBitShiftRightEqualsOperator()
{
	try
	{
		FixedPointNumber<8, 8> number("13.0");
		std::cout << "Bitwise right-shift-equals operator: Before number >>= 2, number = " << number.toString() << std::endl;
		number >>= 2;
		std::cout << "Bitwise right-shift-equals operator: After number >>= 2, number = " << number.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testBitwiseAndEqualsOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("12.34");
		FixedPointNumber<8, 8> number2("5.67");
		std::cout << "Bitwise AND-equals operator: Before number1 &= number2, number1 = " << number1.toString() << std::endl;
		number1 &= number2;
		std::cout << "Bitwise AND-equals operator: After number1 &= number2, number1 = " << number1.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testBitwiseOrEqualsOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("12.34");
		FixedPointNumber<8, 8> number2("5.67");
		std::cout << "Bitwise OR-equals operator: Before number1 |= number2, number1 = " << number1.toString() << std::endl;
		number1 |= number2;
		std::cout << "Bitwise OR-equals operator: After number1 |= number2, number1 = " << number1.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testBitwiseXorEqualsOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("12.34");
		FixedPointNumber<8, 8> number2("5.67");
		std::cout << "Bitwise XOR-equals operator: Before number1 ^= number2, number1 = " << number1.toString() << std::endl;
		number1 ^= number2;
		std::cout << "Bitwise XOR-equals operator: After number1 ^= number2, number1 = " << number1.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testIncrementOperator()
{
	try
	{
		FixedPointNumber<8, 8> number("5.5");
		std::cout << "Increment operator: Before ++number, number = " << number.toString() << std::endl;
		++number;
		std::cout << "Increment operator: After ++number, number = " << number.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testDecrementOperator()
{
	try
	{
		FixedPointNumber<8, 8> number("5.5");
		std::cout << "Decrement operator: Before --number, number = " << number.toString() << std::endl;
		--number;
		std::cout << "Decrement operator: After --number, number = " << number.toString() << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testLogicalNotOperator()
{
	try
	{
		FixedPointNumber<8, 8> number("0.0");
		if (!number)
		{
			std::cout << "Logical NOT operator: !" << number.toString() << " is true." << std::endl;
		}
		else
		{
			std::cout << "Logical NOT operator: !" << number.toString() << " is false." << std::endl;
		}
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
void testLogicalAndOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("5.0");
		FixedPointNumber<8, 8> number2("3.0");
		if (number1 && number2)
		{
			std::cout << "Logical AND operator: " << number1.toString() << " && " << number2.toString() << " is true." << std::endl;
		}
		else
		{
			std::cout << "Logical AND operator: " << number1.toString() << " && " << number2.toString() << " is false." << std::endl;
		}
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
} 
void testLogicalOrOperator()
{
	try
	{
		FixedPointNumber<8, 8> number1("0.0");
		FixedPointNumber<8, 8> number2("3.0");
		if (number1 || number2)
		{
			std::cout << "Logical OR operator: " << number1.toString() << " || " << number2.toString() << " is true." << std::endl;
		}
		else
		{
			std::cout << "Logical OR operator: " << number1.toString() << " || " << number2.toString() << " is false." << std::endl;
		}
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
