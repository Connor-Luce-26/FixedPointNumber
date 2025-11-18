/**
 * @file FixedPointNumber.hpp
 * @author Robert Connor Luce
 * @brief Header file for FixedPointNumber class for fixed-point arithmetic.
 * @date November 17, 2025
 */
#include <cstdint>
#include <string>
#include <cmath>
#include <iostream>
#include <bitset>
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
	std::string toString() const;
	void print() const;
	void printLine() const;
	int getNumberOfDecimalPlaces() const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> absoluteValue() const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> operator+(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>& other) const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> operator-() const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> operator-(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>& other) const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> operator*(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>& other) const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> operator/(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>& other) const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> operator%(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>& other) const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> operator<<(int amountToShift) const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> operator>>(int amountToShift) const;
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
	void operator<<=(int amountToShift);
	void operator>>=(int amountToShift);
	void operator&=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other);
	void operator|=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other);
	void operator^=(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other);
	void operator++();
	void operator--();
	bool operator!() const;
	bool operator&&(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const;
	bool operator||(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> &other) const;
	
};
#endif