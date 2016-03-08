/*
 * main.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: Nick Gaulke
 */
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]) {
	// gets the double from the user
	cout << "Enter a double: ";
	double input;
	cin >> input;

	// convert it to long for use of bitwise operators
	unsigned long number;
	memcpy(&number, &input, sizeof(number));

	// get the sign
	short sign = number >> 63;
	if(sign == 0) cout << "Sign: +" << endl;
	else if(sign == 1) cout << "Sign: -" << endl;
	else cout << "Sign: Something went wrong!!" << endl;

	cout << "Base: 2 (always)" << endl;

	// get the exponent of the input
	unsigned long exp = number & 0x7ff0000000000000;
	exp >>= 52;
	exp -= 1023;
	cout << "Exponent: 0x" << hex << exp << endl;

	// get the mantissa of the input
	unsigned long mant = number & 0x000fffffffffffff;
	mant |= 0x0010000000000000;
	while((mant & 1) == 0)
		mant >>= 1;
	cout << "Exponent: 0x" << hex << mant << endl;

	return 0;
}
