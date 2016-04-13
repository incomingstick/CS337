/*
 * intVector.h
 *
 *  Created on: Apr 6, 2016
 *      Author: user
 */

#ifndef INTVECTOR_H_
#define INTVECTOR_H_

class intVector {
private:
	int count;
	int* vector;
	void set_size(int newSize);
public:
	intVector(int size = 0);
	intVector(const intVector &copy);
	virtual ~intVector();
	int size() const { return count; }
	void set(int index, int element);
	int get(int index) const;
	intVector& operator=(const intVector &copy);
};

#endif /* INTVECTOR_H_ */