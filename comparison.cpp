#include <iostream>
using namespace std;

#include "BigInt.h"

inline bool BigInt::operator==(BigInt& a) {
	return this->digits == a.digits;
}

inline bool BigInt::operator!=(BigInt& a) {
	return !(this->digits == a.digits);
}

inline bool BigInt::operator>(BigInt& a) {
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

inline bool BigInt::operator<(BigInt& a) {
	return !(a < *this);
}

inline bool BigInt::operator>=(BigInt& a) {
	return !(a < *this);
}

inline bool BigInt::operator<=(BigInt& a) {
	return !(a > *this);
}