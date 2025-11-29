/**
 * @file FixedPointNumber.hpp
 * @author Robert Connor Luce
 * @brief Header file for FixedPointNumber class for fixed-point arithmetic.
 */
#include <cstdint>
#include <string>
#include <cmath>
#include <iostream>
#include <bitset>
#include <sstream>
#include <iomanip>
#ifndef FIXEDPOINTNUMBER_HPP
#define FIXEDPOINTNUMBER_HPP
/**
 * @brief Class template for fixed-point numbers with specified integer and fractional bits.
 * @tparam numberOfIntegerBits Number of bits allocated for the integer part.
 * @tparam numberOfFractionalBits Number of bits allocated for the fractional part.
 */
template<int numberOfIntegerBits, int numberOfFractionalBits>
class FixedPointNumber
{
private:
	std::bitset<numberOfIntegerBits + numberOfFractionalBits> bits;
	int numberOfDecimalPlaces;
	static int positionOfMostSignificantBit(std::bitset<numberOfIntegerBits + numberOfFractionalBits> bits);
	static std::bitset<numberOfIntegerBits + numberOfFractionalBits> twosComplement(const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bits);
	static std::bitset<numberOfIntegerBits + numberOfFractionalBits> addBitsets(const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bitSet1, const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bitSet2, bool carryIn);
	static std::bitset<numberOfIntegerBits + numberOfFractionalBits> subtractBitsets(const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bitSet1, const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bitSet2);
	static bool isZero(const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bits);
	static bool isNegative(const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bits);
	static bool isPositive(const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bits);
	void setNumberOfDecimalPlaces(int numberOfDecimalPlaces);
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> reciprocal() const;
public:
	FixedPointNumber(std::string valueString = "0");
	FixedPointNumber(std::bitset<numberOfIntegerBits + numberOfFractionalBits> bits, int numberOfDecimalPlaces = INT_MAX);
	FixedPointNumber(int integerValue);
	~FixedPointNumber();
	static FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> maximum(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> fixedPointNumbers[], int fixedPointNumbersSize);
	static FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> minimum(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> fixedPointNumbers[], int fixedPointNumbersSize);
	std::string toString() const;
	std::string bitsToString() const;
	void print() const;
	void printLine() const;
	void printBits() const;
	void printBitsLine() const;
	int getNumberOfDecimalPlaces() const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> absoluteValue() const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> operator+(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>& other) const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> operator-() const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> operator-(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>& other) const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> operator*(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>& other) const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> operator/(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>& other) const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> operator%(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>& other) const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> operator<<(const int amountToShift) const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> operator>>(const int amountToShift) const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> operator~() const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> operator&(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> operator|(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> operator^(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const;
	bool operator==(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const;
	bool operator!=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const;
	bool operator<(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const;
	bool operator<=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const;
	bool operator>(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const;
	bool operator>=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const;
	void operator+=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other);
	void operator-=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other);
	void operator*=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other);
	void operator/=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other);
	void operator%=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other);
	void operator<<=(const int amountToShift);
	void operator>>=(const int amountToShift);
	void operator&=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other);
	void operator|=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other);
	void operator^=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other);
	void operator++();
	void operator--();
	bool operator!() const;
	bool operator&&(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const;
	bool operator||(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const;
	
};
/**
 * @brief Find the position of the most significant bit set to 1.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param bits 
 * @return int 
 */
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
/**
 * @brief Compute the two's complement of a bitset.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param bits 
 * @return std::bitset<numberOfIntegerBits + numberOfFractionalBits> 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
std::bitset<numberOfIntegerBits + numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::twosComplement(const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bits)
{
	std::bitset<numberOfIntegerBits + numberOfFractionalBits> copyBits = bits;
	copyBits.flip();
	return addBitsets(copyBits, std::bitset<numberOfIntegerBits + numberOfFractionalBits>(), true);
}
/**
 * @brief Add two bitsets with an optional carry-in.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param bitSet1 
 * @param bitSet2 
 * @param carryIn 
 * @return std::bitset<numberOfIntegerBits + numberOfFractionalBits> 
 */
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
/**
 * @brief Subtract two bitsets.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param bitSet1 
 * @param bitSet2 
 * @return std::bitset<numberOfIntegerBits + numberOfFractionalBits> 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
std::bitset<numberOfIntegerBits + numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::subtractBitsets(const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bitSet1, const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bitSet2)
{
	return addBitsets(bitSet1, twosComplement(bitSet2), false);
}
/**
 * @brief Check if the bitset represents zero.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param bits 
 * @return true 
 * @return false 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
bool FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::isZero(const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bits)
{
	return bits.none();
}
/**
 * @brief Check if the bitset represents a negative number.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param bits 
 * @return true 
 * @return false 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
bool FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::isNegative(const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bits)
{
	return bits[numberOfIntegerBits + numberOfFractionalBits - 1];
}
/**
 * @brief Check if the bitset represents a positive number.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param bits 
 * @return true 
 * @return false 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
bool FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::isPositive(const std::bitset<numberOfIntegerBits + numberOfFractionalBits> &bits)
{
	return (!isNegative(bits) && !isZero(bits));
}
/**
 * @brief Set the number of decimal places for the fixed-point number.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param numberOfDecimalPlaces 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
void FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::setNumberOfDecimalPlaces(int numberOfDecimalPlaces)
{
	this->numberOfDecimalPlaces = numberOfDecimalPlaces;
}
/**
 * @brief Compute the reciprocal of the fixed-point number using Newton-Raphson method.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> 
 */
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
/**
 * @brief Construct a new Fixed Point Number object from a string representation.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param valueString 
 */
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
/**
 * @brief Construct a new Fixed Point Number object from a bitset representation.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param bits 
 * @param numberOfDecimalPlaces 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::FixedPointNumber(std::bitset<numberOfIntegerBits + numberOfFractionalBits> bits, int numberOfDecimalPlaces)
{
	this->bits = bits;
	this->numberOfDecimalPlaces = numberOfDecimalPlaces;
}
/**
 * @brief Construct a new Fixed Point Number object from an integer value.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param integerValue 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::FixedPointNumber(int integerValue)
{
	*this = FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>(std::to_string(integerValue));
	this->numberOfDecimalPlaces = INT_MAX;
}
/**
 * @brief Destroy the Fixed Point Number object.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::~FixedPointNumber()
{
}
/**
 * @brief Find the maximum fixed-point number from an array.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param fixedPointNumbers
 * @param fixedPointNumbersSize
 * @return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
inline FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::maximum(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> fixedPointNumbers[], int fixedPointNumbersSize)
{
	if (fixedPointNumbersSize == 0)
	{
		throw std::runtime_error("Cannot determine maximum of an empty array.");
	}
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> largestNumber = fixedPointNumbers[0];
	for (int index = 1; index < fixedPointNumbersSize; index++)
	{
		if (fixedPointNumbers[index] > largestNumber)
		{
			largestNumber = fixedPointNumbers[index];
		}
	}
	return largestNumber;
}
/**
 * @brief Find the minimum fixed-point number from an array.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param fixedPointNumbers 
 * @param fixedPointNumbersSize
 * @return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
inline FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::minimum(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> fixedPointNumbers[], int fixedPointNumbersSize)
{
		if (fixedPointNumbersSize == 0)
	{
		throw std::runtime_error("Cannot determine minimum of an empty array.");
	}
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> smallestNumber = fixedPointNumbers[0];
	for (int index = 1; index < fixedPointNumbersSize; index++)
	{
		if (fixedPointNumbers[index] < smallestNumber)
		{
			smallestNumber = fixedPointNumbers[index];
		}
	}
	return smallestNumber;
}
/**
 * @brief Convert the fixed-point number to its string representation.
 * @tparam numberOfIntegerBits
 * @tparam numberOfFractionalBits
 * @return std::string
 */
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
	int numberOfDecimalPlaces = (this->numberOfDecimalPlaces == INT_MAX ? 0 : this->numberOfDecimalPlaces);
	double scale = std::pow(10.0, numberOfDecimalPlaces);
	uint64_t fractionalDigits = static_cast<uint64_t>(std::round(fractionalPart * scale));
	if (numberOfDecimalPlaces > 0 && fractionalDigits >= static_cast<uint64_t>(scale))
	{
		integerPart += 1;
		fractionalDigits = 0;
	}
	std::ostringstream outputStringStream;
	if (isNegative)
	{
		outputStringStream << '-';
	}
	outputStringStream << integerPart;
	if (numberOfDecimalPlaces > 0)
	{
		outputStringStream << '.' << std::setw(numberOfDecimalPlaces) << std::setfill('0') << fractionalDigits;
	}
	else
	{
		outputStringStream << ".0";
	}
	return outputStringStream.str();
}
/**
 * @brief Convert the fixed-point number's bits to a string representation.
 * @tparam numberOfIntegerBits
 * @tparam numberOfFractionalBits
 * @return std::string
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
inline std::string FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::bitsToString() const
{
	return this->bits.to_string();
}
/**
 * @brief Print the fixed-point number to standard output.
 * @tparam numberOfIntegerBits
 * @tparam numberOfFractionalBits
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
void FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::print() const
{
	std::cout << this->toString();
}
/**
 * @brief Print the fixed-point number followed by a newline to standard output.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
void FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::printLine() const
{
	this->print();
	std::cout << std::endl;
}
/**
 * @brief Print the bits of the fixed-point number to standard output.
 * @tparam numberOfIntegerBits
 * @tparam numberOfFractionalBits
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
inline void FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::printBits() const
{
	std::cout << this->bitsToString();
}
/**
 * @brief Print the bits of the fixed-point number followed by a newline to standard output.
 * @tparam numberOfIntegerBits
 * @tparam numberOfFractionalBits
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
inline void FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::printBitsLine() const
{
	std::cout << this->bitsToString() << std::endl;
}
/**
 * @brief Get the number of decimal places for the fixed-point number.
 * @tparam numberOfIntegerBits
 * @tparam numberOfFractionalBits
 * @return int
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
int FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::getNumberOfDecimalPlaces() const
{
	return this->numberOfDecimalPlaces;
}
/**
 * @brief Get the absolute value of the fixed-point number.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> 
 */
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
/**
 * @brief Add two fixed-point numbers.
 * @tparam numberOfIntegerBits
 * @tparam numberOfFractionalBits
 * @param other The other fixed-point number to add.
 * @return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> The sum of the two fixed-point numbers.
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator+(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	std::bitset<numberOfIntegerBits + numberOfFractionalBits> sumBits = addBitsets(this->bits, other.bits, false);
	return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>(sumBits, std::min(this->numberOfDecimalPlaces, other.numberOfDecimalPlaces));
}
/**
 * @brief Negate the fixed-point number.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> The negated fixed-point number.
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator-() const
{
	return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>(twosComplement(this->bits), this->numberOfDecimalPlaces);
}
/**
 * @brief Subtract another fixed-point number from this one.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param other The other fixed-point number to subtract.
 * @return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> The result of the subtraction.
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator-(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	return *this + (-other);
}
/**
 * @brief Multiply two fixed-point numbers.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param other 
 * @return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> 
 */
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
/**
 * @brief Divide this fixed-point number by another.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param other The divisor fixed-point number.
 * @return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> The result of the division.
 */
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
/**
 * @brief Calculate the remainder of division between two fixed-point numbers.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param other The divisor fixed-point number.
 * @return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> The remainder after division.
 */
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
/**
 * @brief Shift the fixed-point number to the right by a specified amount.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param amountToShift The number of bits to shift right.
 * @return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> The shifted fixed-point number.
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator<<(const int amountToShift) const
{
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> shiftedValue = *this;
	shiftedValue.bits <<= amountToShift;
	return shiftedValue;
}
/**
 * @brief Shift the fixed-point number to the left by a specified amount.
 * @tparam numberOfIntegerBits
 * @tparam numberOfFractionalBits
 * @param amountToShift The number of bits to shift left.
 * @return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> The shifted fixed-point number.
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator>>(const int amountToShift) const
{
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> shiftedValue = *this;
	shiftedValue.bits >>= amountToShift;
	return shiftedValue;
}
/**
 * @brief Bitwise NOT operation on the fixed-point number.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator~() const
{
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> result = *this;
	result.bits.flip();
	return result;
}
/**
 * @brief Bitwise AND operation on the fixed-point number.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param other 
 * @return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator&(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> result = *this;
	result.bits &= other.bits;
	return result;
}
/**
 * @brief Bitwise OR operation on the fixed-point number.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param other 
 * @return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator|(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> result = *this;
	result.bits |= other.bits;
	return result;
}
/**
 * @brief Bitwise XOR operation on the fixed-point number.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param other 
 * @return FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator^(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> result = *this;
	result.bits ^= other.bits;
	return result;
}
/**
 * @brief Check if two fixed-point numbers are equal.
 * @tparam numberOfIntegerBits
 * @tparam numberOfFractionalBits
 * @param other The other fixed-point number to compare.
 * @return true If the two numbers are equal.
 * @return false If the two numbers are not equal.
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
bool FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator==(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> difference = *this - other;
	return isZero(difference.bits);
}
/**
 * @brief Check if two fixed-point numbers are not equal.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param other The other fixed-point number to compare.
 * @return true If the two numbers are not equal.
 * @return false If the two numbers are equal.
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
bool FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator!=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	return !(*this == other);
}
/**
 * @brief Check if this fixed-point number is less than another.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param other The other fixed-point number to compare.
 * @return true If this number is less than the other.
 * @return false If this number is not less than the other.
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
bool FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator<(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> difference = *this - other;
	return isNegative(difference.bits);
}
/**
 * @brief Check if this fixed-point number is less than or equal to another.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param other The other fixed-point number to compare.
 * @return true If this number is less than or equal to the other.
 * @return false If this number is greater than the other.
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
bool FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator<=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	return (*this < other) || (*this == other);
}
/**
 * @brief Check if this fixed-point number is greater than another.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param other The other fixed-point number to compare.
 * @return true If this number is greater than the other.
 * @return false If this number is not greater than the other.
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
bool FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator>(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	return !(*this <= other);
}
/**
 * @brief Check if this fixed-point number is greater than or equal to another.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param other The other fixed-point number to compare.
 * @return true If this number is greater than or equal to the other.
 * @return false If this number is less than the other.
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
bool FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator>=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	return !(*this < other);
}
/**
 * @brief Add another fixed-point number to this one in place.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param other The other fixed-point number to add.
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
void FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator+=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other)
{
	*this = *this + other;
}
/**
 * @brief Subtract another fixed-point number from this one in place.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param other The other fixed-point number to subtract.
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
void FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator-=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other)
{
	*this += -other;
}
/**
 * @brief Multiply this fixed-point number by another in place.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param other The other fixed-point number to multiply by.
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
void FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator*=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other)
{
	*this = *this * other;
}
/**
 * @brief Divide this fixed-point number by another in place.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param other The other fixed-point number to divide by.
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
void FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator/=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other)
{
	*this = *this / other;
}
/**
 * @brief Calculate the remainder of division between this fixed-point number and another in place.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param other The other fixed-point number to divide by.
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
void FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator%=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other)
{
	*this = *this % other;
}
/**
 * @brief Shift this fixed-point number to the left by a specified amount in place.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param amountToShift 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
void FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator<<=(const int amountToShift)
{
	*this = *this << amountToShift;
}
/**
 * @brief Shift this fixed-point number to the right by a specified amount in place.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param amountToShift 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
void FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator>>=(const int amountToShift)
{
	*this = *this >> amountToShift;
}
/**
 * @brief Bitwise AND operation in place on this fixed-point number.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param other 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
void FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator&=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other)
{
	*this = *this & other;
}
/**
 * @brief Bitwise OR operation in place on this fixed-point number.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param other 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
void FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator|=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other)
{
	*this = *this | other;
}
/**
 * @brief Bitwise XOR operation in place on this fixed-point number.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param other 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
void FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator^=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other)
{
	*this = *this ^ other;
}
/**
 * @brief Increment the fixed-point number by one.
 * @tparam numberOfIntegerBits
 * @tparam numberOfFractionalBits
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
void FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator++()
{
	*this += FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>(1);
}
/**
 * @brief Decrement the fixed-point number by one.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
void FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator--()
{
	*this -= FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>(1);
}
/**
 * @brief Logical NOT operation on the fixed-point number.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @return true 
 * @return false 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
bool FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator!() const
{
	return (*this == 0);
}
/**
 * @brief Logical AND operation on the fixed-point number.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param other 
 * @return true 
 * @return false 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
bool FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator&&(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	return ((*this != 0) && (other != 0));
}
/**
 * @brief Logical OR operation on the fixed-point number.
 * @tparam numberOfIntegerBits 
 * @tparam numberOfFractionalBits 
 * @param other 
 * @return true 
 * @return false 
 */
template <int numberOfIntegerBits, int numberOfFractionalBits>
bool FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>::operator||(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const
{
	return ((*this != 0) || (other != 0));
}
#endif