#include <iostream>
#include <vector>
using namespace std;

#include "BigInt.h"

inline BigInt& BigInt::operator=(BigInt& a) {
	if (*this != a) {
		this->digits = a.digits;
	}
	return *this;
}

inline BigInt& BigInt::operator+=(BigInt& a) {
	int t = 0, s, i;
	int n = length(a);
	int m = length(*this);

	if (m > n) {
		a.digits.append(m - n, 0);
	}

	for (i = 0; i < n; i++) {
		if (i < m) {
			s= a.digits[i] + this->digits[i] + t;
		}
		else {
			s = a.digits[i] + t;
		}
		t = s / 10;
		a.digits[i] = s % 10;
	}
	if (t != 0) {
		a.digits.push_back(t);
	}

	return a;
}

inline BigInt& BigInt::operator-=(BigInt& a) {
	int t = 0, s, i;

	int n = length(a);
	int m = length(*this);

	for (i = 0; i < n; i++) {
		if (i < m) {
			s = a.digits[i] - this->digits[i] + t;
		}
		else {
			s = a.digits[i] + t;
		}

		if (s < 0) {
			s += 10;
			t = -1;
		}
		else {
			t = 0;
		}

		a.digits[i] = s;
	}

	while (n > 1 && a.digits[n-1] == 0) {
		a.digits.pop_back();
		n--;
	}

	return a;
}

inline BigInt BigInt::operator+(BigInt &a) {
	BigInt temp;
	temp = a;
	temp += *this;

	return temp;
}

inline BigInt BigInt::operator-(BigInt& a) {
	BigInt temp;
	temp = a;
	temp -= *this;

	return temp;
}

inline BigInt& BigInt::operator*=(BigInt& a) {
	int s, t = 0;

	int n = length(a);
	int m = length(*this);

	if (null(a) || null(*this)) {
		BigInt a('0');
		return a;
	}

	vector<int> vec(n + m, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vec[i + j] += a.digits[i] * this->digits[j];
		}
	}

	n += m;
	a.digits.resize(vec.size());

	for (int i = 0; i < n; i++) {
		s = t + vec[i];
		vec[i] = s % 10;
		t = s / 10;
		a.digits[i] = vec[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		if (vec[i] == 0) {
			a.digits.pop_back();
		}
	}
}

inline BigInt BigInt::operator*(BigInt& a) {
	BigInt temp;
	temp = a;
	temp *= *this;

	return temp;
}

