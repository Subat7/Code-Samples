#include "red_black_tree.h"
#include <cstddef>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <utility>


using std::cout, std::endl, std::invalid_argument;

int main() {  
    // TODO(student): write at least 1000 lines of test
	RedBlackTree<int> tree1;
	// tree1.insert(1);
	// tree1.insert(2);
	// tree1.insert(3);
	// tree1.insert(0);
	// tree1.insert(-1);
	// tree1.insert(5);
	// tree1.print_tree();
	// cout << "-----------------------------" << endl;

	// RedBlackTree<int> tree2(tree1);
	// tree2.print_tree();
	// cout << "-----------------------------" << endl;

	// tree1.insert(4);
	// if (tree1.contains(4) == tree2.contains(4)) {
	// 	cout << "lol" << endl;
	// }
	// tree1.print_tree();
	// cout << "-----------------------------" << endl;
	// tree2.print_tree();
	// cout << "-----------------------------" << endl;

	// tree1.remove(2);
	// tree1.print_tree();
	// cout << "-----------------------------" << endl;
	// tree2.print_tree();
	// cout << "-----------------------------" << endl;


	// tree1.insert(1);
	// tree1.print_tree();
	// cout << "----------------------------------" << endl;
	tree1.insert(20);
	tree1.print_tree();
	cout << "----------------------------------" << endl;
	tree1.insert(16);
	tree1.print_tree();
	cout << "----------------------------------" << endl;
	// tree1.insert(0);
	// tree1.print_tree();
	// cout << "----------------------------------" << endl;cout << "----------------------------------" << endl;
	// tree1.insert(-1);
	// tree1.print_tree();
	// cout << "----------------------------------" << endl;
	tree1.insert(18);
	tree1.print_tree();
	cout << "----------------------------------" << endl;
	tree1.insert(15);
	tree1.insert(17);
	tree1.insert(19);
	tree1.insert(21);
	tree1.print_tree();
	cout << "----------------------------------" << endl;
	//tree1.rotateLeft(16);
	tree1.print_tree();
	cout << "----------------------------------" << endl;
	//tree1.rotateRight(20);
	tree1.print_tree();
	cout << "----------------------------------" << endl;
	cout << "----------------------------------" << endl;
	cout << "----------------------------------" << endl;

	RedBlackTree<int> tree2;
	tree2.insert(10);
	tree2.print_tree();
	cout << "----------------------------------" << endl;
	tree2.insert(18);
	tree2.print_tree();
	cout << "----------------------------------" << endl;
	tree2.insert(7);
	tree2.print_tree();
	cout << "----------------------------------" << endl;
	tree2.insert(15);
	tree2.print_tree();
	cout << "----------------------------------" << endl;
	tree2.insert(16);
	tree2.print_tree();
	cout << "----------------------------------" << endl;
	tree2.insert(30);
	tree2.print_tree();
	cout << "----------------------------------" << endl;
	tree2.insert(25);
	tree2.print_tree();
	cout << "----------------------------------" << endl;
	tree2.insert(40);
	tree2.print_tree();
	cout << "----------------------------------" << endl;
	tree2.insert(60);
	tree2.print_tree();
	cout << "----------------------------------" << endl;
	tree2.insert(2);
	tree2.print_tree();
	cout << "----------------------------------" << endl;
	tree2.insert(1);
	tree2.print_tree();
	cout << "----------------------------------" << endl;
	tree2.insert(70);
	tree2.print_tree();
	cout << "----------------------------------" << endl;
	cout << tree2.find_min() << endl;
	cout << tree2.find_max() << endl;

	RedBlackTree<int> tree3;
	for (int n = 0; n < 21; n++) {
		tree3.insert(n);
	}
	tree3.print_tree();
	cout << "----------------------------------" << endl;

	RedBlackTree<int> tree4;
	tree4 = tree2;
	tree4.print_tree();
	cout << tree4.find_min() << endl;
	cout << tree4.find_max() << endl;
	cout << "----------------------------------" << endl;

	// // cout << tree4.contains(70);
	// // tree4.remove(70);
	// // tree4.print_tree();
	// // cout << tree4.contains(70);
	// // cout << "----------------------------------" << endl;
	// // tree4.remove(40);
	// // tree4.print_tree();
	// // cout << "----------------------------------" << endl;

	// // RedBlackTree<int> tree5(tree4);
	// // tree5.print_tree();
	// // cout << "----------------------------------" << endl;
	// // cout << "Tree 5" << endl;
	// // tree5.remove(60);
	// // tree5.print_tree();


	RedBlackTree<int> tree6;
	tree6.insert(20);
	tree6.insert(12);
	tree6.insert(10);
	tree6.insert(17);
	tree6.insert(40);
	tree6.insert(33);
	tree6.insert(56);
	tree6.insert(34);
	tree6.insert(77);
	// tree6.insert(4);
	// tree6.insert(10);
	// tree6.insert(5);
	// tree6.insert(17);
	// tree6.insert(43);
	// tree6.insert(49);
	// tree6.insert(31);
	tree6.print_tree();
	cout << "----------------------------------" << endl;

	tree6.remove(40);
	tree6.print_tree();
	cout << "----------------------------------" << endl;

	tree6.remove(12);
	tree6.print_tree();
	cout << "+++++++++++++++++++++++++++++++++" << endl;

	RedBlackTree<int> tree7;
	tree7.insert(10);
	tree7.insert(7);
	tree7.insert(20);
	tree7.insert(30);
	tree7.print_tree();
	cout << "----------------------------------" << endl;
	tree7.remove(20);
	tree7.print_tree();
	cout << "+++++++++++++++++++++++++++++++++" << endl;

	RedBlackTree<int> tree8;
	tree8.insert(10);
	tree8.insert(5);
	tree8.insert(2);
	tree8.insert(9);
	tree8.insert(30);
	tree8.insert(25);
	tree8.insert(38);
	tree8.insert(35);
	tree8.insert(36);
	tree8.insert(50);
	tree8.print_tree();
	cout << "----------------------------------" << endl;
	tree8.remove(30);
	tree8.print_tree();
	cout << "------------------------------------" << endl;


	// tree6.insert(18);
	// tree6.insert(25);
	// tree6.insert(27);
	// tree6.print_tree();
	// cout << "----------------------------------" << endl;

	// tree6.remove(20);
	// tree6.print_tree();
	// cout << "----------------------------------" << endl;

	// tree6.remove(27);
	// tree6.print_tree();
	// cout << "----------------------------------" << endl;


	//int n = tree1.contains(1);

	//cout << n;
    
    return 0;
}