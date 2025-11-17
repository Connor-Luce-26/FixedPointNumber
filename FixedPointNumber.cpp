#include "FixedPointNumber.hpp"
#include <sstream>
#include <iomanip>
template <int numberOfIntegerBits, int numberOfFractionalBits>
int FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::positionOfMostSignificantBit(std::bitset<numberOfIntegerBits + numberOfFractionalBits> bits)
{
	for (int bitNumber = numberOfIntegerBits + numberOfFractionalBits - 1; bitNumber >= 0; bitNumber--)
	{
		if (bits[bitNumber])
		{
			return bitNumber;
		}
	}
	return -1;
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
std::bitset<numberOfIntegerBits + numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::twosComplement(const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bits)
{
	std::bitset<numberOfIntegerBits + numberOfFractionalBits> copyBits = bits;
	copyBits.flip();
	return addBitsets(copyBits, std::bitset<numberOfIntegerBits + numberOfFractionalBits>(), true);
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
std::bitset<numberOfIntegerBits + numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::addBitsets(const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bitSet1, const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bitSet2, bool carryIn)
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
std::bitset<numberOfIntegerBits + numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::subtractBitsets(const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bitSet1, const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bitSet2)
{
	return addBitsets(bitSet1, twosComplement(bitSet2), false);
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
bool FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::isZero(const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bits)
{
	return bits.none();
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
bool FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::isNegative(const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bits)
{
	return bits[numberOfIntegerBits + numberOfFractionalBits - 1];
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
bool FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::isPositive(const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bits)
{
	return (!isNegative(bits) && !isZero(bits));
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
void FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::setNumberOfDecimalPlaces(int numberOfDecimalPlaces)
{
	this->numberOfDecimalPlaces = numberOfDecimalPlaces;
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::reciprocal() const
{
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> thisValue = *this;
	thisValue.setNumberOfDecimalPlaces(INT_MAX);
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> currentReciprocal = FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>(1);
	currentReciprocal.bits >>= positionOfMostSignificantBit(thisValue.bits) - numberOfFractionalBits;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> previousReciprocal;
	while (!(thisValue * currentReciprocal == 1) && previousReciprocal != currentReciprocal)
	{
		previousReciprocal = currentReciprocal;
		currentReciprocal = currentReciprocal * ((-thisValue * currentReciprocal) + 2);
	}
	return currentReciprocal;
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
	bool isNegative = *this < 0;
	std::bitset<numberOfIntegerBits + numberOfFractionalBits> absoluteValueBits = this->bits;
	if (isNegative)
	{
		absoluteValueBits = twosComplement(absoluteValueBits);
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
	// TODO: clean this up
	int N = (this->numberOfDecimalPlaces == INT_MAX ? 0 : this->numberOfDecimalPlaces);
	double scale = std::pow(10.0, N);
	uint64_t fracDigits = static_cast<uint64_t>(std::round(fractionalPart * scale));

	// Handle rounding carry into integer part (e.g., 1.999 -> 2.00)
	if (N > 0 && fracDigits >= static_cast<uint64_t>(scale))
	{
		integerPart += 1;
		fracDigits = 0;
	}

	std::ostringstream oss;
	if (isNegative)
	{
		oss << '-';
	}
	oss << integerPart;
	if (N > 0)
	{
		oss << '.' << std::setw(N) << std::setfill('0') << fracDigits;
	}
	else
	{
		oss << ".0";
	}
	return oss.str();
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
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::absoluteValue() const
{
	if (*this < 0)
	{
		return -(*this);
	}
	else
	{
		return *this;
	}
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
	std::bitset<numberOfIntegerBits + numberOfFractionalBits> thisBits = this->bits;
	std::bitset<numberOfIntegerBits + numberOfFractionalBits> otherBits = other.bits;
	bool productIsNegative = false;
	if (isNegative(thisBits) && isPositive(otherBits))
	{
		thisBits = twosComplement(thisBits);
		productIsNegative = true;
	}
	else if (isPositive(thisBits) && isNegative(otherBits))
	{
		otherBits = twosComplement(otherBits);
		productIsNegative = true;
	}
	else if (isNegative(thisBits) && isNegative(otherBits))
	{
		thisBits = twosComplement(thisBits);
		otherBits = twosComplement(otherBits);
	}
	for (int bitNumber = 0; bitNumber < numberOfFractionalBits; bitNumber++)
	{
		if (otherBits[bitNumber])
		{
			std::bitset<numberOfIntegerBits + numberOfFractionalBits> shiftedBits = thisBits >> (numberOfFractionalBits - bitNumber);
			productBits = addBitsets(productBits, shiftedBits, false);
		}
	}
	for (int bitNumber = numberOfFractionalBits; bitNumber < numberOfIntegerBits + numberOfFractionalBits; bitNumber++)
	{
		if (otherBits[bitNumber])
		{
			std::bitset<numberOfIntegerBits + numberOfFractionalBits> shiftedBits = thisBits << (bitNumber - numberOfFractionalBits);
			productBits = addBitsets(productBits, shiftedBits, false);
		}
	}
	if (productIsNegative)
	{
		productBits = twosComplement(productBits);
	}
	return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>(productBits, std::min(this->numberOfDecimalPlaces, other.numberOfDecimalPlaces));
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator/(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> dividend = *this;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> divisor = other;
	if (other == 0)
	{
		throw std::runtime_error("Division by zero");
	}
	bool isQuotientNegative = false;
	if (((dividend > 0) && (divisor < 0)) || ((dividend < 0) && (divisor > 0)))
	{
		isQuotientNegative = true;
	}
	else
	{
		isQuotientNegative = false;
	}
	dividend = dividend.absoluteValue();
	divisor = divisor.absoluteValue();
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> quotient = dividend * divisor.reciprocal();
	quotient.setNumberOfDecimalPlaces(std::min(dividend.getNumberOfDecimalPlaces(), divisor.getNumberOfDecimalPlaces()));
	if (isQuotientNegative)
	{
		quotient = -quotient;
	}
	return quotient;
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator%(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> remainder = *this;
	while (remainder >= other)
	{
		remainder -= other;
	}
	return remainder;
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
bool FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator==(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> difference = *this - other;
	return isZero(difference.bits);
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
bool FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator!=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	return !(*this == other);
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
bool FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator<(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> difference = *this - other;
	return isNegative(difference.bits);
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
bool FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator<=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	return (*this < other) || (*this == other);
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
bool FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator>(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	return !(*this <= other);
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
bool FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator>=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	return !(*this < other);
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
void FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator+=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other)
{
	*this = *this + other;
}
template <int numberOfIntegerBits, int numberOfFractionalBits>
void FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator-=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other)
{
	*this += -other;
}
