# Catalogue Sale
A catalogue designed to be implemented in a binary tree structure.

Problem Description

A catalogue is a list of categories with either sub categories or items in each of them. There will be three types of users who have different functionalities, including adding, selling items, searching and traversing this list etc. Normally this would be implemented in a general tree, meaning a node would have 0 or more children. For this assignment, the number of children has been limited to two, thus using a binary tree. A tree, or the catalogue also must contain both item objects as well as category objects. Certain users will have different restriction on what they can and cannot do to the catalogue. Catalogue and Items have different contents but both have id and name as a common attribute. Item buying is restricted to the offer price not going below the lowest possible discount set by the seller.
A tree must be saved or read to a file as well.

Code Review

The program is written in C++. It contains six classes and one main. The catalogue itself is conceptualized in the catalogue class with a catalogue tree as it's only data. The catalogue tree itself is built up upon a generic binary tree structure. Only traversals, deletion, updating and some other functionalities have been written over the existing tree.

-	Binary Tree
The tree is made up of only one type of element type. Since the tree must contain both an Item and a Category, a new class, Base was created with elements in common, so it is the base class to the two different things in the tree. Also, a Base object cannot be directly stored in the tree to represent both Item and Category, thus a Base* (Base pointer) was used instead. This allows us to simply insert Item or Category object pointers to the tree of Base pointers. Working with a tree with pointer objects was a first.

-	Random Number Generation
Ids for keys are generated randomly, from 1 to 9999 currently. All possible outcomes have a uniform probability distribution using the uniform_int_distribution<> function. This means an id has approximately 1/10000 chance of recurring. 

-	Data types
All user input of words have been in char* and most numbers are represented as either int or double. Most functions are either of return type bool, node or simply just void. The main tree uses a generic data type of node<elemType>, which means the data is defined by the user. In this case, Base* was used.

![alt text](https://raw.githubusercontent.com/sazit/Binary-Catalouge/master/BinaryCatalougeDisplay.png)


Data Structures Analysis

The main data structure used for this assignment was a self-built binary tree. It is built upon treebase.h by D.S. Malik. I edited the binary search tree so that the tree inserts, traverses and deletes the item as it needed to. The restrictions of Items and Categories have also been properly dealt with. The main tree class has no specific restriction on this as the restrictions are applied through the catalogue class, where it makes sense to do so. The use of a general tree or AVL trees isn’t recommended as they would ass unnecessary extra management. A general tree is worse because of the search time it would educe. While not all that different than the current implementation, a binary tree ensures only two available directions available. A general tree could have an infinite amount. This means the tree would be wider than deeper generally, which means more nodes would have to be linked to each node, that too dynamically. In a binary tree, it goes deep than wide. This makes it computationally easy to traverse through ‘siblings’, as in items or categories of same level. This has a worst case time complexity of O(n) when starting from the level’s head pointer. A general tree would have to go back to its parent and then go the next child taking considerably more time.

Due to the use of pointer objects, no other data structures needed to be used. I was thinking of using a map to save item and category id’s but it seems unnecessary as they are stored in the node themselves. Char* has been used to store variables which makes it more efficient than strings. Pointers have been extensively used, that too sent with reference meaning minimal data and values are copied and original data is only worked on. The use of delete[] to free up memory have been used as well.


Algorithm Analysis

Algorithm analysis is required mainly in traversing and searching an object in the tree.
	Insertion – O(1) - as once you insert an item, it inserts to the end of the right link (its last sibling).

	Access – O(n) – To access an element, it must be in the same level as the current head. If one wants to access/display an item inside an existing category, he must access the current category first, traverse down(left) it, then access the element. 

	Search – O(n) – All nodes are visited exactly once until found. A simple traversal is done using recursion, starting from the root node. If the required node is found, it prints it out. For a graph, like this binary tree, the complexity is of a depth first traversal is O(n + m), where n is the number of nodes, and m is the number of connections. The number of lines that can come from a node is 2 or less. The maximum number of total lines in this tree is n-1, where n is the total number of nodes.  The complexity then becomes O(n + n-1), which is O(n).

	Deletion – O(1) – This follows the use of access or searching an item. Once the item is found, the program simply links the next node to the node that was previously linking to current node, the deletes the node.

Future Work

Recursion must be implemented greatly when developing this work in the future. The best way to traverse through a tree is recursion, performing certain actions inside the recursion loop. This way the algorithm would be much more efficient, but it is extremely hard to debug. I found it difficult to return a node pointer when recursively traversing through the tree because the node pointer would override itself. Saving the data of the items and catalogues into XML formatted files is also another area that has possibility to improve this implementation of a catalogue.


