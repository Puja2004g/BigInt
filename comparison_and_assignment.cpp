#include <iostream>
using namespace std;

#include "BigInt.h"

BigInt BigInt::operator=(BigInt &a) {
	this->digits = a.digits;
	return *this;
}

bool BigInt::operator==(BigInt& a) {
	return this->digits == a.digits;
}

bool BigInt::operator!=(BigInt& a) {
	return !(this->digits == a.digits);
}

bool BigInt::operator>(BigInt& a) {
	int n = length(a);
	int m = length(*this);

	if (n != m) {
		return n<m;
	}

	while (n--)
	{
		if (a.digits[n] != this->digits[n]) {
			return a.digits < this->digits;
		}
	}
	return false;
}

bool BigInt::operator<(BigInt& a) {
	return !(a < *this);
}

bool BigInt::operator>=(BigInt& a) {
	return !(a < *this);
}

bool BigInt::operator>=(BigInt& a) {
	return !(a > *this);
}