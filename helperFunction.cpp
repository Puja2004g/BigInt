#include <iostream>
using namespace std;

#include "BigInt.h"

bool BigInt::null(BigInt &a) {
	if (a.digits.size() == 1 && a.digits[0] == 0) {
		return true;
	}
	return false;
}

int BigInt::length(BigInt& n) {
	return n.digits.size();
}

int BigInt::operator[](int& index) {
	if (digits.length() <= index || index < 0) {
		throw("Error!");
	}
	else {
		return digits[index];
	}
}