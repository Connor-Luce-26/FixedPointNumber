#include "FixedPointNumber.hpp"
template <int numberOfIntegerBits, int numberOfFractionalBits>
std::bitset<numberOfIntegerBits + numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::twosComplement(std::bitset<numberOfIntegerBits + numberOfFractionalBits> bits)
{
	bits.flip();
	return addBitsets(bits, std::bitset<numberOfIntegerBits + numberOfFractionalBits>(), true);
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
std::bitset<numberOfIntegerBits + numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::addBitsets(const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bitSet1, const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bitSet2, const bool carryIn)
{
	std::bitset<numberOfIntegerBits + numberOfFractionalBits> sumBits;
	bool carry = carryIn;
	bool sum;
	for (int bitNumber = 0; bitNumber < numberOfIntegerBits + numberOfFractionalBits; bitNumber++)
	{
		sum = bitSet1[bitNumber] ^ bitSet2[bitNumber] ^ carry;
		carry = (bitSet1[bitNumber] && bitSet2[bitNumber]) || (bitSet1[bitNumber] && carry) || (bitSet2[bitNumber] && carry);
		sumBits[bitNumber] = sum;
	}
	return sumBits;
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
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::FixedPointNumber(int integerValue)
{
	*this = FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>(std::to_string(integerValue));
	this->numberOfDecimalPlaces = INT_MAX;
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
	result += std::to_string(static_cast<uint64_t>(std::round(fractionalPart * std::pow(10, this->numberOfDecimalPlaces == INT_MAX ? 0 : this->numberOfDecimalPlaces))));
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
	std::bitset<numberOfIntegerBits + numberOfFractionalBits> sumBits = addBitsets(this->bits, other.bits, false);
	return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>(sumBits, std::min(this->numberOfDecimalPlaces, other.numberOfDecimalPlaces));
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
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator*(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	std::bitset<numberOfIntegerBits + numberOfFractionalBits> productBits;
	for (int bitNumber = 0; bitNumber < numberOfFractionalBits; bitNumber++)
	{
		if (other.bits[bitNumber])
		{
			std::bitset<numberOfIntegerBits + numberOfFractionalBits> shiftedBits = this->bits >> (numberOfFractionalBits - bitNumber);
			productBits = addBitsets(productBits, shiftedBits, false);
		}
	}
	for (int bitNumber = numberOfFractionalBits; bitNumber < numberOfIntegerBits + numberOfFractionalBits; bitNumber++)
	{
		if (other.bits[bitNumber])
		{
			std::bitset<numberOfIntegerBits + numberOfFractionalBits> shiftedBits = this->bits << (bitNumber - numberOfFractionalBits);
			productBits = addBitsets(productBits, shiftedBits, false);
		}
	}
	return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>(productBits, std::min(this->numberOfDecimalPlaces, other.numberOfDecimalPlaces));
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator/(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	// TODO: Implement division operator
	return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>();
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator%(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	// TODO: Implement modulo operator
	return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>();
}