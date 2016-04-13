/*
 * intVector.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: user
 */

#include <stdexcept>
#include "intVector.h"

intVector::intVector(int size)
	:count{ size }
{
	vector = new int[count];

	// init vector elements to 0
	for (int i = 0; i < count; i++)
	        vector[i] = 0;
}

intVector::intVector(const intVector &copy) {
	count = copy.size();
	vector = new int[count];
	for(int i = 0; i < count; i++)
		vector[i] = copy.get(i);
}

intVector::~intVector() {
	// TODO Auto-generated destructor stub
	delete[] vector;
}

intVector& intVector::operator=(const intVector &copy) {
	if(this == &copy)
		return *this;

	delete[] vector;

	count = copy.size();
	vector = new int[count];
	for(int i = 0; i < count; i++)
		vector[i] = copy.get(i);

	return *this;
}

void intVector::set_size(int newSize) {
	int* temp = new int[count];
	for(int i = 0; i < count; i++)
		temp[i] = vector[i];
	delete vector;
	vector = new int[newSize];

	// temp store old values
	for(int i = 0; i < count; i++)
		vector[i] = temp[i];

	// init new elements to 0
	for(int i = count; i < newSize; i++)
		vector[i] = 0;

	count = newSize;
}

void intVector::set(int index, int element) {
	if(index > count) {
		set_size((count * 2) + 1);
		set(index, element);
	}
	vector[index] = element;
}

int intVector::get(int index) const {
	if(index > count || index < 0) throw std::invalid_argument("Index out of bounds.");
	return vector[index];
}

