#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <cstddef>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <utility>

using namespace std;


template <typename Comparable>
struct Node {
	Comparable data;
	Node* left;
	Node* right;
};

template <typename Comparable>
class BinarySearchTree {
    // TODO(student): implement BinarySearchTree
	Node<Comparable>* root;

	void empty(Node<Comparable>* tree) {
		if(tree != nullptr) {
			empty(tree->left);
			empty(tree->right);
			delete tree;
		}
	}

	Node<Comparable>* copy(Node<Comparable>* tree) {
		if(tree == nullptr) {
			return nullptr;
		}
		Node<Comparable>* n = new Node<Comparable>;
		n->data = tree->data;
		n->left = nullptr;
		n->right = nullptr;
		n->left = copy(tree->left);
		n->right = copy(tree->right);
		return n;
	}

	Node<Comparable>* insert_helper(Node<Comparable>* tree, Comparable value) {
		if (tree == nullptr) {
			Node<Comparable>* n = new Node<Comparable>;
			n->data = value;
			n->right = nullptr;
			n->left = nullptr;
			return n;
		} 
		if (tree->data > value) {
			tree->left = insert_helper(tree->left, value);
		} else {
			tree->right = insert_helper(tree->right, value);
		}
		return tree;
	}

	// Node<Comparable>* remove_helper(Node<Comparable>* tree, Comparable value) {
	// 	if(tree == nullptr) {
	// 		return nullptr;
	// 	}
	// 	if (tree->data > value) {
	// 		tree->left = remove_helper(tree->left, value);
	// 	} else if (tree->data < value) {
	// 		tree->right = remove_helper(tree->right, value);
	// 	} else {
	// 		if (tree->right == nullptr && tree->left == nullptr) {
	// 			delete tree;
	// 			return nullptr;
	// 		} else if (tree->right != nullptr || tree->left != nullptr) {
	// 			if (tree->left == nullptr) {
	// 				Node<Comparable>* n = tree->right;
	// 				delete tree;
	// 				return n;
	// 			} else {
	// 				Node<Comparable>* n = tree->left;
	// 				delete tree;
	// 				return n;
	// 			}
	// 		} else {
	// 			Node<Comparable>* n = find_min_helper(tree->right);
	// 			tree->data = n->data;
	// 			tree->right = remove_helper(tree->right, n->data);
	// 		}
	// 	}
	// 	return tree;
	// }

	Node<Comparable>* remove_helper(Node<Comparable>* tree, Comparable value) {
		if(tree == nullptr) {
			return nullptr;
		}
		if (tree->data > value) {
			tree->left = remove_helper(tree->left, value);
		} else if (tree->data < value) {
			tree->right = remove_helper(tree->right, value);
		} else {
			if (tree->right == nullptr) {
				Node<Comparable>* n = tree->left;
				delete tree;
				return n;
			} 
			if (tree->left == nullptr) {
				Node<Comparable>* n = tree->right;
				delete	tree;
				return n;
			}

			Node<Comparable>* n = find_min_helper(tree->right);
			tree->data = n->data;
			tree->right = remove_helper(tree->right, n->data);
		}
		return tree;
	}

	Node<Comparable>* find_min_helper(Node<Comparable>* subtree) {
		Node<Comparable>* n = subtree;
		while (n != nullptr && n->left != nullptr) {
			n = n->left;
		}
		return n;
	}

	void print_helper(Node<Comparable>* tree, int num, ostream& os) const {
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



public:
	BinarySearchTree() : root(nullptr) {}

	BinarySearchTree(const BinarySearchTree& other) : root(nullptr) {
		this->root = copy(other.root);
	}

	~BinarySearchTree() {
		empty(this->root);
	}

	BinarySearchTree& operator=(const BinarySearchTree& other) {
		if (this != &other) {
			empty(this->root);
			this->root = copy(other.root);
		}
		return *this;
	}

	bool contains(const Comparable& other) const {
		Node<Comparable>* n = this->root;
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
			throw invalid_argument("Can't find min bc tree is nullptr");
		}
		Node<Comparable>* n = this->root;
		while(n->left != nullptr) {
			n = n->left;
		}
		return n->data;
	}

	const Comparable& find_max() const {
		if (this->root == nullptr) {
			throw invalid_argument("Can't find max bc tree is nullptr");
		}
		Node<Comparable>* n = this->root;
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