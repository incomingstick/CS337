#include <iostream>
#include "intVector.h"

using namespace std;
 
int main() {
	int n;
	cout << "Enter the size of intVector a: "; cin >> n;

	// Create a new intVector with n elements, all zero
	intVector a(n);
	// Create a new intVector with 0 elements
	intVector b;
 
	// Print out some information about the size of this intVector:
	cout << "Vector a has " << a.size() << " elements." << endl;
	cout << "Vector b has " << b.size() << " elements." << endl;
 
	// Print out the contents of intVector a (should be all zeroes!):
	for(int r = 0; r < a.size(); r++) {
		cout << "a[" << r <<"] = " << a.get(r) << endl;
	}

	// Fill in a few values
	// if a.size < index, the intVector is resized with intervening elements = 0
	a.set(5, -5280); // 6th element is now -5280, elements 1-5 are 0
	a.set(0, 123); // 1st element is now 123
 
	// Create an identical copy of this intVector
	intVector c(a); //the copy constructor is called here
	// Assign intVector a to existing intVector b;

	b = a;
 
	// Change the original intVector some more
	a.set(2, 555);  // 3rd element is now 555
 
	// Examine some elements of each intVector
	cout << "a[0] = " << a.get(0) << " [should be 123]" << endl;
	cout << "b[0] = " << b.get(0) << " [should be 123]" << endl;
	cout << "c[0] = " << c.get(0) << " [should be 123]" << endl;

 
	cout << "a[2] = " << a.get(2) << " [should be 555]" << endl;
	cout << "b[2] = " << b.get(2) << " [should be 0, but will be 555 due to shallow copy]" << endl;
	cout << "c[2] = " << c.get(2) << " [should be 0]" << endl;
	return 0;
}
