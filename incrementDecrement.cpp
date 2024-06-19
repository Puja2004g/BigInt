#include <iostream>
using namespace std;

#include "BigInt.h"


//increment the digit and return the incremented digit
BigInt &BigInt::operator++() {
	int i, n = digits.length();
	for (i = 0; i < n && digits[i] == 9; i++) {
		digits[i] = 0;
	}

	if (i == n) {
		digits.push_back(1);
	}

	else {
		digits[i]++;
	}

	return *this;
}


//increment the digit but return the original digit
BigInt BigInt::operator++(int temp) {
	BigInt obj;
	obj = *this;
	++(*this);

	return obj;
}


//pre-decrement
BigInt &BigInt::operator--() {
	if (digits[0] == 0 && digits.length() == 1) {
		throw("Underflow");
	}
	int i, n = digits.length();

	for(i=0;i<n&&digits[i]==0;i++){
		digits[i] = 9;
	}
	if (n > 1 && digits[0] == 0) {
		digits.pop_back();
	}
	else {
		digits[i]--;
	}
	return *this;
}

//post-decrement
BigInt BigInt::operator--(int temp) {
	BigInt obj;
	obj = *this;
	--(*this);
	return obj;
}