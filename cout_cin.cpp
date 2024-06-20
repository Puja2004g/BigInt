#include <iostream>
#include <string>
using namespace std;

#include "BigInt.h"

inline ostream& operator<<(ostream& out, BigInt& a) {
	for (int i = a.digits.size() -1; i >= 0; i--) {
		cout << a.digits[i];
	}
	return cout;
}

inline istream& operator>>(istream& in, BigInt& a) {
	string s;
	in >> s;
	int n = s.size();

	for (int i = n - 1; i >= 0; i--) {
		if (!isdigit(s[i])) {
			throw("Invalid identifier");
		}
		a.digits[n - i - 1] = s[i];
	}
	return in;
}