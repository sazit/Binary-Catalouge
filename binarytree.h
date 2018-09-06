//Header File Binary Search Tree

#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <iostream>
#include <cassert>
#include <string>
#include "treebase.h"

//*************************************************************
// Author: S.G Gurubacharya
//
// This class specifies the basic operations to implement a
// Catalog search tree. It is a general tree condensed into
// a binary tree.
//*************************************************************

using namespace std;

template<class elemType>
class bSearchTreeType: public binaryTreeType<elemType> {
public:
	void printList(binaryTreeNode<elemType>* currentHead);
	void insertFirst(const elemType& insertItem);
	void insertSibling(binaryTreeNode<elemType> *currentHead,
			const elemType& insertItem);
	bool goToChild(binaryTreeNode<elemType> *&currentHead, int itemNo);
	void insertNewChild(binaryTreeNode<elemType> *currentHead,
			const elemType& insertItem);
	void updateCurrent(binaryTreeNode<elemType> *&currentHead, int itemNo);
	void updateCurrentToBuy(binaryTreeNode<elemType> *&currentHead, int itemNo);
	void resetToRoot(binaryTreeNode<elemType> *&currentHead);
	void deleteNode(binaryTreeNode<elemType> *&currentHead, int itemNo,
			int& type);
	void search(int id);
private:
	void _search(int id, binaryTreeNode<elemType> *p);
};

template<class elemType>
void bSearchTreeType<elemType>::printList(
		binaryTreeNode<elemType>* currentHead) {
	binaryTreeNode<elemType> *current;
	binaryTreeNode<elemType> *beforeCurrent;
	current = currentHead;
	int i = 1;
	while (current != NULL) {
		printf("[%d] %s id: %d\n", i, current->info->getName(),
				current->info->getId());
		if (current->llink != NULL) {
			beforeCurrent = current;
			current = current->llink;
			int j = 1;
			while (current != NULL) {
				printf("	  %d. %s id: %d\n", j, current->info->getName(),
						current->info->getId());
				current = current->rlink;
				j++;
			}
			current = beforeCurrent;
		}
		current = current->rlink;
		i++;
	}
}

template<class elemType>
void bSearchTreeType<elemType>::insertSibling(
		binaryTreeNode<elemType>* currentHead, const elemType& insertItem) {
	binaryTreeNode<elemType> *current;  //pointer to traverse the tree
	current = currentHead;
	binaryTreeNode<elemType> *trailCurrent; //pointer behind current
	binaryTreeNode<elemType> *newNode;  //pointer to create the node

	newNode = new binaryTreeNode<elemType>;
	assert(newNode != NULL);
	newNode->info = insertItem;
	newNode->llink = NULL;
	newNode->rlink = NULL;
	while (current != NULL) {
		trailCurrent = current;
		current = current->rlink;
	}
	trailCurrent->rlink = newNode;
}

template<class elemType>
void bSearchTreeType<elemType>::insertFirst(const elemType& insertItem) {
	binaryTreeNode<elemType> *current;  //pointer to traverse the tree
	binaryTreeNode<elemType> *trailCurrent; //pointer behind current
	binaryTreeNode<elemType> *newNode;  //pointer to create the node

	newNode = new binaryTreeNode<elemType>;
	assert(newNode != NULL);
	newNode->info = insertItem;
	newNode->llink = NULL;
	newNode->rlink = NULL;

	if (binaryTreeType<elemType>::root == NULL)
		binaryTreeType<elemType>::root = newNode;
	else {
		current = binaryTreeType<elemType>::root;
		while (current != NULL) {
			trailCurrent = current;
			current = current->rlink;
		}
		trailCurrent->rlink = newNode;
	}
}

template<class elemType>
bool bSearchTreeType<elemType>::goToChild(
		binaryTreeNode<elemType>*& currentHead, int itemNo) {
	binaryTreeNode<elemType> *current;  //pointer to traverse the tree
	current = currentHead;
	for (int i = 0; i < itemNo; i++) {
		if (current->rlink == NULL) {
			printf("\nThat item does not exist!\n");
		} else {
			current = current->rlink;
		}
	}
	if (current->llink == NULL) {
		currentHead = current;
		return false;
	} else {
		current = current->llink;
		currentHead = current;
		return true;
	}
}

template<class elemType>
void bSearchTreeType<elemType>::insertNewChild(
		binaryTreeNode<elemType>* currentHead, const elemType& insertItem) {
	binaryTreeNode<elemType> *current;  //pointer to traverse the tree
	current = currentHead;
	binaryTreeNode<elemType> *newNode;  //pointer to create the node

	newNode = new binaryTreeNode<elemType>;
	assert(newNode != NULL);
	newNode->info = insertItem;
	newNode->llink = NULL;
	newNode->rlink = NULL;
	currentHead->llink = newNode;
}

template<class elemType>
void bSearchTreeType<elemType>::updateCurrent(
		binaryTreeNode<elemType>*& currentHead, int itemNo) {
	binaryTreeNode<elemType> *current;  //pointer to traverse the tree
	current = currentHead;
	for (int i = 0; i < itemNo; i++) {
		if (current->rlink == NULL) {
			printf("\nThat item does not exist!\n");
		} else {
			current = current->rlink;
		}
	}
	if (current->llink == NULL) {
		printf("\nNo child in that one!!\n");
	} else {
		current = current->llink;
		currentHead = current;
	}
}

template<class elemType>
void bSearchTreeType<elemType>::updateCurrentToBuy(
		binaryTreeNode<elemType>*& currentHead, int itemNo) {
	binaryTreeNode<elemType> *current;  //pointer to traverse the tree
	current = currentHead;
	for (int i = 0; i < itemNo; i++) {
		if (current->rlink == NULL) {
			printf("\nThat item does not exist!\n");
		} else {
			current = current->rlink;
		}
	}
	currentHead=current;
}

template<class elemType>
void bSearchTreeType<elemType>::resetToRoot(
		binaryTreeNode<elemType>*& currentHead) {
	binaryTreeNode<elemType> *current;  //pointer to traverse the tree
	current = currentHead;
	current = binaryTreeType<elemType>::root;
	currentHead = current;
}

template<class elemType>
void bSearchTreeType<elemType>::deleteNode(
		binaryTreeNode<elemType>*& currentHead, int itemNo, int& type) {
	binaryTreeNode<elemType> *current;  //pointer to traverse the tree
	binaryTreeNode<elemType> *trialCurrent;
	binaryTreeNode<elemType> *firstCurrent;
	current = currentHead;
	trialCurrent = current;
	firstCurrent = current;
	for (int i = 0; i < itemNo; i++) {
		trialCurrent = current;
		if (current->rlink == NULL) {
			printf("\nThat item does not exist!\n");
		} else {
			current = current->rlink;
		}
	}
	if (current->info->getType() != type) {
		type = current->info->getType();
		cout << "\nYou can't delete this here..\n";
		current = firstCurrent;
		currentHead = current;
	} else {
		if (current == binaryTreeType<elemType>::root) {
			binaryTreeType<elemType>::root = current->rlink;
			currentHead = binaryTreeType<elemType>::root;
			delete current;
		} else if (itemNo == 0 && trialCurrent->rlink != NULL) {
			trialCurrent->info = trialCurrent->rlink->info;
			trialCurrent->rlink = trialCurrent->rlink->rlink;
			current = trialCurrent->rlink;

			currentHead = current;
			delete current;
		} else if (current->rlink == NULL) {
			trialCurrent->llink = NULL;
			trialCurrent->rlink = NULL;
			currentHead = trialCurrent;
			delete current;
		} else {
			trialCurrent->rlink = current->rlink;
			currentHead = trialCurrent;
			delete current;
		}
	}
}

template<class elemType>
void bSearchTreeType<elemType>::search(int id) {
	if (binaryTreeType<elemType>::root == NULL) {
		cerr << "Cannot search the empty tree." << endl;
	} else {
		_search(id, this->root);
	}
}

template<class elemType>
void bSearchTreeType<elemType>::_search(int id, binaryTreeNode<elemType> *p) {
	if (p->info->getId() == id) {
		p->info->display();
	} else if (p != NULL) {
		if (p->llink != NULL) {
			_search(id, p->llink);
		}
		if (p->rlink != NULL) {
			_search(id, p->rlink);
		}

	}
}

#endif

