#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <cstddef>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <utility>

using namespace std;

template <typename Comparable>
class node{
public:
	Comparable data;
	node<Comparable>* left;
	node<Comparable>* right;
	size_t height;

	size_t getHeight(){
		if (this == nullptr) {
			return 0;
		} else {
			return this->height;
		}
	}

	void heightBalance() {
		this->height = (max(this->left->getHeight(), this->right->getHeight()) + 1);
	}

	int balance() {
		if (this != nullptr) {
			return this->left->getHeight() - this->right->getHeight();
		}
		return 0;
	}

	size_t max(size_t lhs, size_t rhs) {
		if (lhs > rhs) {
			return lhs;
		} else {
			return rhs;
		}
	}

};


template <typename Comparable>
class AVLTree {
    // TODO(student): implement AVLTre
	node<Comparable>* root;

	void empty(node<Comparable>* tree) {
		if (tree != nullptr) {
			empty(tree->left);
			empty(tree->right);
			delete tree;
		}
	}

	node<Comparable>* copy(node<Comparable>* tree) {
		if(tree == nullptr) {
			return nullptr;
		}
		node<Comparable>* n = new node<Comparable>;
		n->data = tree->data;
		n->left = nullptr;
		n->right = nullptr;
		n->height = 1;
		n->left = copy(tree->left);
		n->right = copy(tree->right);
		return n;
	}



	node<Comparable>* insert_helper(node<Comparable>* tree, Comparable value) {
		if(tree == nullptr) {
			node<Comparable>* n = new node<Comparable>;
			n->data = value;
			n->left = nullptr;
			n->right = nullptr;
			n->height = 1;
			return n;
		}
		if (tree->data > value) {
			tree->left = insert_helper(tree->left, value);
		} else {
			tree->right = insert_helper(tree->right, value);
		}
		tree->heightBalance();
		int bal_num = tree->balance();
		if (bal_num > 1 && tree->left->data > value) {
			return leftRotate(tree);
		}
		if (bal_num > 1 && tree->left->data < value) {
			tree->left = rightRotate(tree->left);
			return leftRotate(tree);
		}
		if (bal_num < -1 && tree->right->data < value) {
			return rightRotate(tree);
		}
		if (bal_num < -1 && tree->right->data > value) {
			tree->right = leftRotate(tree->right);
			return rightRotate(tree);
		}
		return tree;
	}

	node<Comparable>* remove_helper(node<Comparable>* tree, Comparable value) {
		if (tree == nullptr) {
			return nullptr;
		}
		if (tree->data > value) {
			tree->left = remove_helper(tree->left, value);
		} else if (tree->data < value) {
			tree->right = remove_helper(tree->right, value);
		} else {
			if (tree->left == nullptr) {
				node<Comparable>* n = tree->right;
				delete tree;
				return n;
			} else if (tree->right == nullptr) {
				node<Comparable>* n = tree->left;
				delete tree;
				return n;
			}
			node<Comparable>* n = find_min_helper(tree->right);
			tree->data = n->data;
			tree->right = remove_helper(tree->right, n->data);
		}
		if (tree == nullptr) {
			return nullptr;
		}
		tree->heightBalance();
		int bal_num = tree->balance();
		if (bal_num > 1 && tree->left->balance() >= 0) {
			return leftRotate(tree);
		}
		if (bal_num > 1 && tree->left->balance() < 0) {
			tree->left = rightRotate(tree->left);
			return leftRotate(tree);
		}
		if (bal_num < -1 && tree->right->balance() <= 0) {
			return rightRotate(tree);
		}
		if (bal_num < -1 && tree->right->balance() > 0) {
			tree->right = leftRotate(tree->right);
			return rightRotate(tree);
		}
		return tree;
	}

	node<Comparable>* find_min_helper(node<Comparable>* subtree) {
		node<Comparable>* n = subtree;
		while (n != nullptr && n->left != nullptr) {
			n = n->left;
		}
		return n;
	}

	void print_helper(node<Comparable>* tree, int num, ostream& os) const {
		if (tree != nullptr) {
			num++;
			print_helper(tree->right, num, os);
			for (int i = 1; i < num; i++) {
				os << "  ";
			}
			os << tree->data << endl;
			print_helper(tree->left, num, os);
		} 
	}

	node<Comparable>* leftRotate(node<Comparable>* tree) {
		node<Comparable>* left = tree->left;
		node<Comparable>* left_r = left->right;
		left->right = tree;
		tree->left = left_r;
		tree->heightBalance();
		left->heightBalance();
		return left;

	}

	node<Comparable>* rightRotate(node<Comparable>* tree) {
		node<Comparable>* right = tree->right;
		node<Comparable>* right_l = right->left;
		right->left = tree;
		tree->right = right_l;
		tree->heightBalance();
		right->heightBalance();
		return right;

	}

public:

	AVLTree() : root(nullptr) {}
	AVLTree(const AVLTree& other) : root(nullptr) {
		this->root = copy(other.root);
	}
	~AVLTree() {
		empty(this->root);
	}
	AVLTree& operator=(const AVLTree& other) {
		if (this != &other) {
			empty(this->root);
			this->root = copy(other.root);
		}
		return *this;
	}
	bool contains(const Comparable& other) const {
		node<Comparable>* n = this->root;
		while (n != nullptr) {
			if (n->data == other) {
				return 1;
			} else if (n->data > other) {
				n = n->left;
			} else {
				n = n->right;
			}
		}
		return 0;
	}
	void insert(const Comparable& other) {
		if (contains(other) == 0) {
			this->root = insert_helper(this->root, other);
		}
	}
	void remove(const Comparable& other) {
		if(contains(other) == 1) {
			this->root = remove_helper(this->root, other);
		}
	}
	const Comparable& find_min() const {
		if (this->root == nullptr) {
			throw invalid_argument("Can't find min bc AVLtree is nullptr");
		}
		node<Comparable>* n = this->root;
		while(n->left != nullptr) {
			n = n->left;
		}
		return n->data;
	}
	const Comparable& find_max() const {
		if (this->root == nullptr) {
			throw invalid_argument("Can't find max bc AVLtree is nullptr");
		}
		node<Comparable>* n = this->root;
		while (n->right != nullptr) {
			n = n->right;
		}
		return n->data;
	}
	void print_tree(ostream& os = cout) const {
		if (this->root == nullptr) {
			os << "<empty>" << endl;
		} else {
			print_helper(this->root, 0 , os);
 		}
	}



};

#endif