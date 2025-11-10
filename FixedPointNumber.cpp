#include "FixedPointNumber.hpp"
template <int numberOfIntegerBits, int numberOfFractionalBits>
inline FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::FixedPointNumber(std::string valueString)
{
	int decimalPointIndex = valueString.find('.');
	if (decimalPointIndex == std::string::npos)
	{
		this->numberOfDecimalPlaces = 0;
	}
	else
	{
		this->numberOfDecimalPlaces = valueString.length() - decimalPointIndex - 1;
	}
	double value = std::stod(valueString);
	bool isNegative = value < 0;
	float integerPart;
	float fractionalPart = std::modf(value, &integerPart);
	for (int bitNumber = numberOfIntegerBits - 1; bitNumber >= 0; bitNumber--)
	{
		if (integerPart >= std::pow(2, bitNumber))
		{
			this->bits.set(numberOfFractionalBits + bitNumber);
			integerPart -= std::pow(2, bitNumber);
		}
	}
	for (int bitNumber = 0; bitNumber < numberOfFractionalBits - 1; bitNumber++)
	{
		if (fractionalPart >= std::pow(2, -bitNumber - 1))
		{
			this->bits.set(numberOfFractionalBits - bitNumber - 1);
			fractionalPart -= std::pow(2.0, -bitNumber - 1);
		}
	}
	if (isNegative)
	{
		this->bits.flip();
		bool carry = true;
		for (int i = 0; i < numberOfIntegerBits + numberOfFractionalBits; i++)
		{	this->bits[i] = this->bits[i] ^ carry;
			carry = this->bits[i] && carry;
		}
	}
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::~FixedPointNumber()
{
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
std::string FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::toString() const
{
	std::string result = "";
	bool isNegative = this->bits[numberOfIntegerBits + numberOfFractionalBits - 1];
	std::bitset<numberOfIntegerBits + numberOfFractionalBits> absoluteValueBits = this->bits;
	if (isNegative)
	{
		absoluteValueBits.flip();
		bool carry = true;
		for (int i = 0; i < numberOfIntegerBits + numberOfFractionalBits; i++)
		{
			absoluteValueBits[i] = absoluteValueBits[i] ^ carry;
			carry = absoluteValueBits[i] && carry;
		}
		result += "-";
	}
	uint64_t integerPart = 0;
	for (int bitNumber = numberOfIntegerBits - 1; bitNumber >= 0; bitNumber--)
	{
		integerPart += absoluteValueBits[numberOfFractionalBits + bitNumber] * std::pow(2, bitNumber);
	}
	double fractionalPart = 0.0;
	int fractionalPartScalingFactor = 1;
	for (int bitNumber = 0; bitNumber < numberOfFractionalBits - 1; bitNumber++)
	{
		fractionalPart += absoluteValueBits[numberOfFractionalBits - bitNumber - 1] * std::pow(2, -bitNumber - 1);
	}
	result += std::to_string(integerPart);
	result += ".";
	result += std::to_string(static_cast<uint64_t>(fractionalPart * std::pow(10, this->numberOfDecimalPlaces)));
	return result;
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
void FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::print() const
{
	std::cout << this->toString();
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
void FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::printLine() const
{
	this->print();
	std::cout << std::endl;
}