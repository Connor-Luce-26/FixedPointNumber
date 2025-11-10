#include <cstdint>
#include <string>
#include <cmath>
#include <iostream>
#include <bitset>
#ifndef FIXEDPOINTNUMBER_HPP
#define FIXEDPOINTNUMBER_HPP
template<int numberOfIntegerBits, int numberOfFractionalBits>
class FixedPointNumber
{
private:
	std::bitset<numberOfIntegerBits + numberOfFractionalBits> bits;
	int numberOfDecimalPlaces;
public:
	FixedPointNumber(std::string valueString = "0");
	~FixedPointNumber();
	std::string toString() const;
	void print() const;
	void printLine() const;
	FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits> operator+(const FixedPointNumber<numberOfIntegerBits, numberOfFractionalBits>& other) const;
};

#endif

