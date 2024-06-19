#include <iostream>
#include <string>
using namespace std;

#include "BigInt.h"

BigInt::BigInt(unsigned long long n) {
	while (n) {
		int x = n % 10;
		digits.push_back(x);
		n /= 10;
	}
}

BigInt::BigInt(string& s) {
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

BigInt::BigInt(char* s) {
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

BigInt::BigInt(BigInt &a) {
	this->digits = a.digits;
}