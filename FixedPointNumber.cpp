#include "FixedPointNumber.hpp"
template <int numberOfIntegerBits, int numberOfFractionalBits>
std::bitset<numberOfIntegerBits + numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::twosComplement(std::bitset<numberOfIntegerBits + numberOfFractionalBits> bits)
{
	bits.flip();
	bool carry = true;
	bool sum;
	for (int bitNumber = 0; bitNumber < numberOfIntegerBits + numberOfFractionalBits; bitNumber++)
	{
		sum = bits.test(bitNumber) ^ carry;
		carry = bits.test(bitNumber) && carry;
		bits[bitNumber] = sum;
	}
	return bits;
}
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
	double integerPart;
	double fractionalPart = std::modf(value, &integerPart);
	if (isNegative)
	{
		integerPart = -integerPart;
		fractionalPart = -fractionalPart;
	}
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
		this->bits = twosComplement(this->bits);
	}
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::FixedPointNumber(std::bitset<numberOfIntegerBits + numberOfFractionalBits> bits, int numberOfDecimalPlaces)
{
	this->bits = bits;
	this->numberOfDecimalPlaces = numberOfDecimalPlaces;
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::~FixedPointNumber()
{
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
std::string FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::toString() const
{
	std::string result = "";
	bool isNegative = this->bits.test(numberOfIntegerBits + numberOfFractionalBits - 1);
	std::bitset<numberOfIntegerBits + numberOfFractionalBits> absoluteValueBits = this->bits;
	if (isNegative)
	{
		absoluteValueBits = twosComplement(absoluteValueBits);
		result += "-";
	}
	uint64_t integerPart = 0;
	for (int bitNumber = numberOfIntegerBits - 1; bitNumber >= 0; bitNumber--)
	{
		integerPart += absoluteValueBits[numberOfFractionalBits + bitNumber] * std::pow(2, bitNumber);
	}
	double fractionalPart = 0.0;
	for (int bitNumber = 0; bitNumber < numberOfFractionalBits - 1; bitNumber++)
	{
		fractionalPart += absoluteValueBits[numberOfFractionalBits - bitNumber - 1] * std::pow(2, -bitNumber - 1);
	}
	result += std::to_string(integerPart);
	result += ".";
	result += std::to_string(static_cast<uint64_t>(std::round(fractionalPart * std::pow(10, this->numberOfDecimalPlaces))));
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
template <int numberOfIntegerBits, int numberOfFractionalBits>
int FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::getNumberOfDecimalPlaces() const
{
	return this->numberOfDecimalPlaces;
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator+(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	bool carry = false;
	std::bitset<numberOfIntegerBits + numberOfFractionalBits> resultBits;
	for (int bitNumber = 0; bitNumber < numberOfIntegerBits + numberOfFractionalBits; bitNumber++)
	{
		resultBits[bitNumber] = this->bits[bitNumber] ^ other.bits[bitNumber] ^ carry;
		carry = (this->bits[bitNumber] && other.bits[bitNumber]) || (this->bits[bitNumber] && carry) || (other.bits[bitNumber] && carry);
	}
	return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>(resultBits, std::min(this->numberOfDecimalPlaces, other.numberOfDecimalPlaces));
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator-() const
{
	return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>(twosComplement(this->bits), this->numberOfDecimalPlaces);
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator-(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	return *this + (-other);
}
