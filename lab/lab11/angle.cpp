/*
 * angle.cpp
 *
 *  Created on: Apr 13, 2016
 *      Author: user
 */
#include <iostream>
#include "angle.h"

using namespace std;

Angle::Angle() {
	// TODO Auto-generated constructor stub
	degrees = 0;

}

Angle::Angle(double degrees) {
	// TODO constructor stub
	this->degrees = degrees;
}

Angle::~Angle() {
	// TODO Auto-generated destructor stub
}

bool operator<(Angle, Angle) {
	return true; // TODO
}

bool operator<=(Angle, Angle) {
	return true; // TODO
}

bool operator>(Angle, Angle) {
	return true; // TODO
}

bool operator>=(Angle, Angle) {
	return true; // TODO
}

bool operator==(Angle, Angle) {
	return true; // TODO
}

bool operator!=(Angle, Angle) {
	return true; // TODO
}

std::istream& operator>>(std::istream& in, Angle& a) {
	return in;
}

std::ostream& operator<<(std::ostream& in, Angle a) {
	return in;
}
