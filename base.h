/*
 * base.h
 *
 *  Created on: May 11, 2018
 *      Author: sajitgurubacharya
 */

#ifndef BASE_H_
#define BASE_H_

#include "item.h"
#include <fstream>

class Base {
protected:
	int id;
	const char* name;
	int type;
public:
	Base();
	Base(const Base &obj);  // copy constructor
	virtual ~Base()=0;
	virtual Base* clone() const=0;
	virtual void updateId_Name(int, const char*)=0;
	virtual void updateElse(const char*, double, double)=0;
	virtual void display()=0;
	virtual void display(ofstream& fout)=0;
	const Base & operator=(const Base & rhs); // Assignment a1 = a2
	int getId();
	int getType();
	virtual double getPrice()=0;
	virtual double getDiscount() =0;
	const char* getName();
	bool operator>(const Base& base) {
		return (this->id > base.id);
	}
	bool operator==(const Base& base) {
		return (this->id == base.id);
	}
	bool operator!=(const Base& base) {
		return !(this->id == base.id);
	}

};
Base::Base() {
	id = 999;
	name = "No name";
	type = 0;
}
Base::Base(const Base &obj) {
	cout << "Copy constructor of Base\n." << endl;
	id = obj.id;
	name = obj.name;
	type = obj.type;
}
Base::~Base() {
}

const Base & Base::operator=(const Base & rhs) {
	if (this != &rhs) {  // no self assignment
		// Copy elements
		id = rhs.id;
		name = rhs.name;
	}
	return *this;
}

int Base::getId() {
	return id;
}
int Base::getType() {
	return type;
}

const char* Base::getName() {
	return &*name;
}

#endif /* BASE_H_ */
