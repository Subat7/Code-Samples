#include <cstddef>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <utility>

#include "binary_search_tree.h"

using std::cout, std::endl;

int main() {
    // TODO(student): write tests
    BinarySearchTree<int> tree1;
    try {
    	tree1.find_min();
    } catch (const invalid_argument& ) {
    	cout << "caught" << endl;
    }

    try {
    	tree1.find_max();
    } catch (const invalid_argument& ) {
    	cout << "caught" << endl;
    }
    
    tree1.print_tree();
    tree1.insert(1);
    tree1.print_tree();
    if (tree1.contains(1)) {
    	cout << "Tree 1 contains 1" << endl;
    } else {
    	cout << "Tree 1 doesn't contain 1" << endl;
    }
    BinarySearchTree<int> tree2(tree1);
    tree2.print_tree();
    if (tree2.contains(1)) {
    	cout << "Tree 2 contains 1" << endl;
    } else {
    	cout << "Tree 2 doesn't contain 1" << endl;
    }
    tree2.insert(2);
    tree2.insert(3);
    tree2.print_tree();
    tree2.remove(2);
    tree2.print_tree();
    BinarySearchTree<int> tree3;
    tree3 = tree2;
    tree3.print_tree();
    cout << tree3.find_max() << endl;
    cout << tree3.find_min() << endl;
    tree3 = tree3;
    cout << tree3.contains(5) << endl;
    tree2.remove(1);
    BinarySearchTree<int> tree4;
    tree4.contains(3);
    tree4.insert(1);
    tree4.insert(1);
    tree4.remove(2);
    tree4.remove(2);
    tree4.remove(1);
    tree4.remove(1);
    tree4 = tree3;
    BinarySearchTree<int> tree;

// insert 5 values into the tree
    tree.insert(6);
    tree.insert(4);
    tree.insert(2);
    tree.insert(8);
    tree.insert(10);

// search the tree
    std::cout << "contains 4? " << std::boolalpha << tree.contains(4) << std::endl;
    std::cout << "contains 7? " << std::boolalpha << tree.contains(7) << std::endl;

// remove the root
    tree.remove(6);

// find the minimum element
    std::cout << "min: " << tree.find_min() << std::endl;

// find the maximum element
    std::cout << "max: " << tree.find_max() << std::endl;

// print the tree
    std::cout << "tree: " << std::endl;
    tree.print_tree();

    BinarySearchTree<int> tree5;
    tree5 = tree1;
    tree5.insert(700);
    tree5.insert(333);
    tree5.insert(1000);
    tree5.find_max();
    tree5.find_min();
    tree5.insert(1100);
    tree5.insert(111);
    tree5.insert(72000);
    tree5.remove(700);
    tree5.remove(1000);
    tree5.remove(1);
    tree5.find_max();
    tree5.find_min();

    cout << "----------------------------------" << endl;

    // BinarySearchTree<int> tree6;
    // tree6.insert(2);
    // tree6.contains(3);
    // tree6.remove(2);
    // try {
    // 	tree6.find_min();
    // } catch (const invalid_argument& ) {
    // 	cout << "caught" << endl;
    // }

    BinarySearchTree<int> tree6;
	tree6.insert(11);
	tree6.insert(6);
	tree6.insert(8);
	tree6.insert(19);
	tree6.insert(4);
	tree6.insert(10);
	tree6.insert(5);
	tree6.insert(17);
	tree6.insert(43);
	tree6.insert(49);
	tree6.insert(31);
	tree6.print_tree();
	cout << "----------------------------------" << endl;

	tree6.remove(11);
	tree6.print_tree();
	cout << "----------------------------------" << endl;






}
