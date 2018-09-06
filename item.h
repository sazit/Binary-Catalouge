/*
 * item.h
 *
 *  Created on: May 10, 2018
 *      Author: sajitgurubacharya
 */

#ifndef ITEM_H_
#define ITEM_H_
#include "base.h"
#include <fstream>

class Item: public Base {
private:
	const char* itemDescription;
	double itemPrice;
	double maxDiscount;
public:
	Item();
	void updateId_Name(int, const char*);
	void updateElse(const char*, double, double);
	double getPrice();
	double getDiscount();
	void display();
	void display(ofstream& fout);
	Base* clone() const {
		return new Item(*this);
	}
	const Item & operator=(const Item & rhs); // Assignment a1 = a2

};

double Item::getPrice(){
	return itemPrice;
}

double Item::getDiscount(){
	return maxDiscount;
}
void Item::display() {
	cout << "\nItem Information\nID: " << id << "\nName: " << name
			<< "\nPrice: $" << itemPrice << "\nDescription: " << itemDescription
			<< "\n\n";
}

void Item::display(ofstream& fout) {
	fout << "\nItem Information\nID: " << id << "\nName: " << name
			<< "\nPrice: $" << itemPrice << "\nDescription: " << itemDescription
			<< "\n\n";
}

Item::Item() :
		Base() {
	itemDescription = "No description";
	itemPrice = 0.00;
	maxDiscount = 0.00;
	type = 2;
}

void Item::updateElse(const char* itemDescription, double itemPrice,
		double maxDiscount) {
	this->itemDescription = itemDescription;
	this->itemPrice = itemPrice;
	this->maxDiscount = maxDiscount;
}

void Item::updateId_Name(int id, const char* name) {
	this->id = id;
	this->name = name;

}

const Item & Item::operator=(const Item & rhs) {
	if (this != &rhs) {  // no self assignment
		// Copy elements
		id = rhs.id;
		name = rhs.name;

	}
	return *this;
}

#endif /* ITEM_H_ */
