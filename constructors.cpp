#include <iostream>
#include <string>
using namespace std;

#include "BigInt.h"

inline BigInt::BigInt(unsigned long long n) {
	if (n == 0) {
		digits.push_back(0);
	}
	else {
		while (n) {
			int x = n % 10;
			digits.push_back(x);
			n /= 10;
		}
	}
}

inline BigInt::BigInt(string& s) {
	digits = "";
	for (int i = s.size() - 1; i >= 0; i--) {
		if (!isdigit(s[i])) {	//check if each char is a number
			throw("Error!");	
		}
		else {
			digits.push_back(s[i]-'0');	//convert each char into integer
		}
	}
}

inline BigInt::BigInt(char* s) {
	digits = "";
	for (int i = strlen(s) - 1; i >= 0; i--) {
		if (!isdigit(s[i])) {  
			throw("Error!");
		}
		else {
			digits.push_back(s[i] - '0');  
		}
	}
}

inline BigInt::BigInt(BigInt &a) {
	this->digits = a.digits;
}