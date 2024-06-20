#pragma once
#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
using namespace std;

class BigInt {
private:
	string digits;

public:
	//constructors
	BigInt() : digits(1, 0) {}

	BigInt(unsigned long long n);

	//constructor for strings
	BigInt(string& s);

	//constructor for character arrays
	BigInt(char *s);

	//copy constructor
	BigInt(BigInt &a);


	//helper function

	//check if a bigint is null
	bool null(BigInt& a);

	//size of bigint
	int length(BigInt& n);

	//access the index
	int operator[](int& index);

	//operator overloading

	//post-increment operator
	BigInt &operator++();

	//pre increment operator - dummy parameter is used to differentiate pre and post
	BigInt operator++(int temp);

	//pre-decrement operator
	BigInt &operator--();
	 
	//post-decrement operator
	BigInt operator--(int temp);

	//comparison operator
	bool operator==(BigInt &a);
	bool operator!=(BigInt &a);

	bool operator<(BigInt& a);
	bool operator>(BigInt& a);
	bool operator>=(BigInt& a);
	bool operator<=(BigInt& a);

	//assignment operators
	
	//direct assignment operator
	BigInt &operator=(BigInt& a);

	BigInt &operator+=(BigInt& a);
	BigInt &operator-=(BigInt& a);

	BigInt &operator*=(BigInt& a);
	//BigInt &operator/=(BigInt& a);
	//BigInt &operator%=(BigInt& a);

	//arithmetic operators
	BigInt operator+(BigInt& a);
	BigInt operator-(BigInt& a);

	BigInt operator*(BigInt& a);
	//BigInt operator/(BigInt& a);
	//BigInt operator%(BigInt& a);

	friend ostream &operator<<(ostream &out, BigInt& a);
	friend istream &operator>>(istream &in, BigInt& a);
};


#endif 