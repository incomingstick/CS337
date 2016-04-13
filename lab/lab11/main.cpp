/*
 * main.cpp
 *
 *  Created on: Apr 13, 2016
 *      Author: user
 */
#include <iostream>
#include "angle.h"

using namespace std;

int main(int argc, char* argv[]) {
	Angle a;
	Angle b;
	Angle right(90);
	double temp;

	cout << "Enter the first angle (in degrees): ";
	cin >> temp;
	a.setD(temp);
	cout << "Enter the second angle (in degrees): ";
	cin >> b;

	cout << "The first angle is " << a << " degrees" << endl;
	cout << "The second angle is " << b.getD() << " degrees" << endl;

	if (a == b)
	cout << "The two angles are equal." << endl;
	else if (a != b)
	cout << "The two angles are not equal." << endl;

	if (a > b)
	cout << "First angle is greater than second angle." << endl;
	if (a >= b)
	cout << "First angle is greater than or equal to second angle." << endl;
	if (a < b)
	cout << "First angle is less than second angle." << endl;
	if (a <= b)
	cout << "First angle is less than or equal to second angle." << endl;

	cout << "End of test." << endl;
	return 0;
}
