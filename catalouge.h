/*
 * catalouge.h
 *
 *  Created on: May 27, 2018
 *      Author: sajitgurubacharya
 */

#ifndef CATALOUGE_H_
#define CATALOUGE_H_

#include <string>
#include <iostream>
#include <random>
#include <fstream>

using namespace std;

#include "binarytree.h"
#include "treebase.h"
#include "item.h"
#include "category.h"

class Catalouge {
	bSearchTreeType<Base*> tree;
	void addCategory(binaryTreeNode<Base*> *&);
	void addSubCategory(binaryTreeNode<Base*> *&);
	void moveToSubCategory(binaryTreeNode<Base*> *&);
	void addItemToCategory(binaryTreeNode<Base*> *&);
	void deleteNode(binaryTreeNode<Base*> *&, int);
	void buyItem(binaryTreeNode<Base*> *&);
	void resetToRoot(binaryTreeNode<Base*> *&);
	void searchById();
	void readFromFile();
	void writeToFile();
public:
	void start();
	int getRandom();
};

void Catalouge::writeToFile(){
	ofstream fout;
	cout << "Writing Tree to File.\n";
	fout.open("/Users/sajitgurubacharya/Desktop/catalouge.txt");
	if (fout.fail()) {
		cout << "Output file opening failed.\n";
		exit(1);
	}
	fout<<"Total items and categories count: "<< tree.treeNodeCount() <<"\n";
	fout<<"All elements in the tree\n";
	fout<<"-------------------------";
	tree.inorderTraversalFile(fout);
	fout.close();
	cout<<"Writing file finished!";
	fout.close();
	cout << "End of editing files for Bundle Generator.\n";
}

int Catalouge::getRandom() {
	uniform_int_distribution<> d(1, 9999);
	std::random_device rd;
	std::mt19937 gen(rd());
	return d(gen);
}

void Catalouge::start() {
	string f[5] = { "Laptop", "Desktop", "Mobile", "Keyboard", "Monitor" };
	binaryTreeNode<Base*> *current;
	for (int i = 0; i < 5; i++) {
		Category *test = new Category;
		test->updateId_Name(getRandom(), &f[i][0u]);
		tree.insertFirst(test);
	}
	int quit = 0;
	tree.printTree();
	current = tree.getRoot();
	int level;
	while (1) {
		current = tree.getRoot();
		cout
				<< "\nWelcome! Please input your level\n1: Seller\n2: Buyer\n3: The Manager\n";
		cin >> level;
		int option;

		quit = 0;
		switch (level) {
		case 1:
			while (quit == 0) {
				cout << "\n\nWelcome Mr.Seller!\nWhat would you like to do?\n";
				cout
						<< "1: Traverse\n2: Add item to category\n3: Add category\n4: Add sub category\n5: Reset to root\n6: Main Menu";
				cout << "\nCurrent Head: " << current->info->getId() << "\n";
				tree.printTree();
				tree.printList(current);
				cin >> option;
				switch (option) {
				case 1:
					cout << "\nCant Traverse YET!\n";
					break;
				case 2:
					addItemToCategory(current);
					break;
				case 3:
					addCategory(current);
					break;
				case 4:
					addSubCategory(current);
					break;
				case 5:
					resetToRoot(current);
					break;
				case 6:
					quit = 1;
					break;
				}
			}
			break;
		case 2:
			while (quit == 0) {
				cout << "\n\nWelcome Mr.Buyer!\nWhat would you like to do?\n";
				cout
						<< "1: Traverse\n2: Buy Item\n3: Move to sub category\n4: Reset to root\n5: Main Menu";
				cout << "\nCurrent Head: " << current->info->getId() << "\n";
				tree.printTree();
				tree.printList(current);
				cin >> option;
				switch (option) {
				case 1:
					cout << "\nCant Traverse YET!\n";
					break;
				case 2:
					buyItem(current);
					break;
				case 3:
					moveToSubCategory(current);
					break;
				case 4:
					resetToRoot(current);
					break;
				case 5:
					quit = 1;
					break;
				}
			}
			break;
		case 3:
			while (quit == 0) {
				cout << "\n\nWelcome Mr.Manager!\nWhat would you like to do?\n";
				cout
						<< "1: Traverse\n2: Add category\n3: Add sub category\n4: Move to sub category\n5: Search by ID\n6: Delete Category\n7: Delete Item\n8: Reset to root\n9: Main Menu\n10: Write to file";
				cout << "\nCurrent Head: " << current->info->getId() << "\n";
				tree.printTree();
				tree.printList(current);
				cin >> option;
				switch (option) {
				case 1:
					cout << "\nCant Traverse YET!\n";
					break;
				case 2:
					addCategory(current);
					break;
				case 3:
					addSubCategory(current);
					break;
				case 4:
					moveToSubCategory(current);
					break;
				case 5:
					searchById();
					break;
				case 6:
					deleteNode(current, 1);
					break;
				case 7:
					deleteNode(current, 2);
					break;
				case 8:
					resetToRoot(current);
					break;
				case 9:
					quit = 1;
					break;
				case 10:
					writeToFile();
					break;
				}
			}
			break;
		default:
			cout << "\nDidn't choose correctly! :(\n";
		}
	}
}

void Catalouge::addCategory(binaryTreeNode<Base*> *&current) {
	char *tempName;
	Category *test = new Category;

	cout << "Add category:";
	tempName = new char[20];
	cin >> tempName;
	test = new Category;
	test->updateId_Name(getRandom(), tempName);
	tree.insertSibling(current, test);
	tree.printList(current);
	cout << "\nCurrent ID: " << current->info->getId();
}

void Catalouge::addSubCategory(binaryTreeNode<Base*> *&current) {
	char *tempName;
	Category *test = new Category;
	int no;
	binaryTreeNode<Base*> *beforeCurrent;
	cout << "Add sub category to which category: ";
	cin >> no;
	cout << "Add category:";
	tempName = new char[20];
	cin >> tempName;
	test = new Category;
	test->updateId_Name(getRandom(), tempName);
	beforeCurrent = current;
	if (!tree.goToChild(current, no - 1)) {
		printf("ID %d has no child currently\n", current->info->getId());
		tree.insertNewChild(current, test);
	} else {
		tree.insertSibling(current, test);
	}
	cout << "\nCurrent ID: " << current->info->getId();
	if (current->llink != NULL) {
		cout << "\nCurrent llink ID: " << current->llink->info->getId();
	}
	if (current->rlink != NULL) {
		cout << "\nCurrent rlink ID: " << current->rlink->info->getId();
	}
	cout << "\nbefore Current ID: " << beforeCurrent->info->getId();
	current = beforeCurrent;
}

void Catalouge::moveToSubCategory(binaryTreeNode<Base*> *&current) {
	int no;
	cout << "Move into which category: ";
	cin >> no;
	cout << "\nCurrent ID: " << current->info->getId();
	tree.updateCurrent(current, no - 1);
	cout << "\nnew Current ID: " << current->info->getId();
}

void Catalouge::addItemToCategory(binaryTreeNode<Base*> *&current) {
	char *tempName;
	char *tempDesc;
	double tempPrice, tempMaxDiscount;
	Item *test2 = new Item;
	int no;
	binaryTreeNode<Base*> *beforeCurrent;
	tempName = new char[20];
	tempDesc = new char[50];
	cout << "Add item into which category: ";
	cin >> no;
	cout << "Add item:";
	cin >> tempName;
	cout << "\nItem Description:";
	cin >> tempDesc;
	cout << "\nItem Price:";
	cin >> tempPrice;
	cout << "\nItem Max Discount:";
	cin >> tempMaxDiscount;
	test2->updateId_Name(getRandom(), tempName);
	test2->updateElse(tempDesc, tempPrice, tempMaxDiscount);
	beforeCurrent = current;
	if (!tree.goToChild(current, no - 1)) {
		printf("ID %d has no child currently\n", current->info->getId());
		tree.insertNewChild(current, test2);
	} else {
		tree.insertSibling(current, test2);
	}
	cout << "\nCurrent ID: " << current->info->getId();
	if (current->llink != NULL) {
		cout << "\nCurrent llink ID: " << current->llink->info->getId();
	}
	if (current->rlink != NULL) {
		cout << "\nCurrent rlink ID: " << current->rlink->info->getId();
	}
	cout << "\nbefore Current ID: " << beforeCurrent->info->getId();
	current = beforeCurrent;
}

void Catalouge::deleteNode(binaryTreeNode<Base*> *&current,
		int itemOrCategory) {
	binaryTreeNode<Base*> *beforeCurrent;
	beforeCurrent = current;
	int no;
	int type = itemOrCategory;
	cout << "\nBefore Current ID: " << beforeCurrent->info->getId();
	cout << "\nWhich number do you want to delete?";
	cout << "\nAre you sure you want to delete ";
	cin >> no;
	tree.deleteNode(current, no - 1, type);
	cout << "\nNext Current ID: " << current->info->getId();
	if (current != tree.getRoot()) {
		current = beforeCurrent;
	}
	cout << "\nBefore Current ID: " << current->info->getId() << "\n";
}

void Catalouge::buyItem(binaryTreeNode<Base*> *&current) {
	binaryTreeNode<Base*> *beforeCurrent;
	beforeCurrent = current; // head
	int no;
	int type = 2;
	double lowestItemPrice, customerOfferPrice;
	cout << "\nBefore Current ID: " << beforeCurrent->info->getId();
	cout << "\nWhich number do you want to buy?";
	cin >> no;
	tree.updateCurrentToBuy(current, no - 1);
	if (current->info->getType() != 2) {
		cout << "\nSorry! That's not an item!";
		current = beforeCurrent;
	} else {
		cout << "\n\n";
		current->info->display();
		cout << "\nYour offer: $";
		cin >> customerOfferPrice;
		cout<<"PRICE: "<<current->info->getPrice();
//		cout<<"\nDISCOUNT: "<< current->info->getDiscount();
		lowestItemPrice = current->info->getPrice() * (1 - current->info->getDiscount()/100);
		cout<<"\nLowestItemPrice: "<< lowestItemPrice;
		cout<<"\nBuyerPrice: "<< customerOfferPrice;
		if (customerOfferPrice >= lowestItemPrice) {
			current = beforeCurrent;
			tree.deleteNode(current, no - 1, type);
			if (current != tree.getRoot()) {
				current = beforeCurrent;
			}
		} else {
			cout << "\nSorry, you're too cheap!";
		}
	}
}

void Catalouge::resetToRoot(binaryTreeNode<Base*> *&current) {
	tree.resetToRoot(current);
}

void Catalouge::searchById() {
	int no;
	cout << "Looking for which ID: ";
	cin >> no;
	tree.search(no);
}
#endif /* CATALOUGE_H_ */
