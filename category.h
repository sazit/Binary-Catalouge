/*
 * category.h
 *
 *  Created on: May 10, 2018
 *      Author: sajitgurubacharya
 */

#ifndef CATEGORY_H_
#define CATEGORY_H_
#include "base.h"
#include <fstream>

class Category: public Base {
public:
	Category();
	Category(const Category &obj);  // copy constructor
	Base* clone() const {
		return new Category(*this);
	}
	const Category & operator=(const Category & rhs); // Assignment a1 = a2
	void updateId_Name(int, const char*);
	void updateElse(const char*, double, double) {
		//do nothing, I know bad practice, but what to do
	}
	void display();
	void display(ofstream& fout);
	double getPrice() {
		return id;
	}
	double getDiscount() {
		return id;
	}
};

void Category::display() {
	cout << "\nCategory Information\nID: " << id << "\nName: " << name
			<< "\n\n";
}

void Category::display(ofstream& fout) {
	fout << "\nCategory Information\nID: " << id << "\nName: " << name
			<< "\n\n";
}
void Category::updateId_Name(int id, const char* name) {
	this->id = id;
	this->name = name;
}
Category::Category() :
		Base() {
	type = 1;

}
Category::Category(const Category &obj) {
	cout << "Copy constructor of Category\n." << endl;
	id = obj.id;
	name = obj.name;
	type = obj.type;

}

const Category & Category::operator=(const Category & rhs) {
	if (this != &rhs) {  // no self assignment
		// Copy elements
		id = rhs.id;
		name = rhs.name;
	}
	return *this;
}

#endif /* CATEGORY_H_ */
