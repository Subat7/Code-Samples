#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <cstddef>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <utility>


using std::cout, std::endl, std::invalid_argument, std::ostream;

template <typename Comparable>
class RedBlackTree {
public:
	enum Color {RED, BLACK};

    struct Node {
		Comparable value;
		Node* right;
		Node* left;
		Node* parent;
		int color;

		//Node(Comparable data) : left(nullptr), right(nullptr), parent(nullptr), value(data), color(RED) {};
	};

private:

	Node* root;

	Node* copy(Node* other) {
		if (other == nullptr) {
			return nullptr;
		}
		Node* n = new Node;
		n->value = other->value;
		n->color = other->color;
		n->left = nullptr;
		n->right = nullptr;
		n->parent = nullptr;
		n->left = copy(other->left);
		if (n->left != nullptr) {
			n->left->parent = n;
		}
		n->right = copy(other->right);
		if (n->right != nullptr) {
			n->right->parent = n;
		}
		return n;
	}

	void empty(Node* other) {
		if(other != nullptr) {
			empty(other->left);
			empty(other->right);
			delete other;
		}
	}

	void print_helper(Node* tree, int num, ostream& os) const {
		if (tree != nullptr) {
			num++;
			print_helper(tree->right, num, os);
			for (int i = 1; i < num; i++) {
				os << "  ";
			}
			os << tree->value << " ";
			if (tree->color == 0) {
				os << "R" << endl;
			} else {
				os << "B" << endl;
			}
			print_helper(tree->left, num, os);
		} 
	}

	Node* sibling(Node* other) {
		if(other->value < other->parent->value) {
			return other->parent->right;
		} else {
			return other->parent->left;
		}
	}

	void recolor(Node* tree) {
		if (tree->color == 0) {
			tree->color = 1;
		} else {
			tree->color = 0;
		}
	}

	Node* insert_helper(Node* other, Comparable data) {

		if (other == nullptr) {
			Node* n = new Node;
			n->value = data;
			n->right = nullptr;
			n->left = nullptr;
			n->color = RED;
			return n;
		} 
		if (data < other->value) {
			other->left = insert_helper(other->left, data);
			other->left->parent = other;
		} else {
			other->right = insert_helper(other->right, data);
			other->right->parent = other;
		}
		return other;
	}

	Node* find_min_helper(Node* subtree) {
		Node* n = subtree;
		while (n != nullptr && n->left != nullptr) {
			n = n->left;
		}
		return n;
	}



	// Node* remove_helper(Node* tree, Comparable data) {
	// 	if(tree == nullptr) {
	// 		return nullptr;
	// 	}
		
	// }

	bool Node_color(Node* other, Comparable data) {
		while(other->value != data) {
    		if (data < other->value) {
    			other = other->left;
    		} else {
    			other = other->right;
    		}
    	}
    	if (other->color == RED) {
    		return 1;
    	} else {
    		return 0;
    	}

	}


	int rotationCheck(Node* other) {
		if((other->value > other->parent->value) && (other->parent->value < other->parent->parent->value)) {
			return 0;
		} else if ((other->value < other->parent->value) && (other->parent->value > other->parent->parent->value)) {
			return 1;
		} else if ((other->value < other->parent->value) && (other->parent->value < other->parent->parent->value)) {
			return 2;
		} else if ((other->value > other->parent->value) && (other->parent->value > other->parent->parent->value)) {
			return 3;
		}
		return 4;
	}

	void rotateLeft(Node* ptr) {
		Node *right_child = ptr->right;
		ptr->right = right_child->left;

		if (ptr->right != nullptr) {
			ptr->right->parent = ptr;
		}

		right_child->parent = ptr->parent;

		if (ptr->parent == nullptr) {
			root = right_child;
		}
		else if (ptr == ptr->parent->left) {
			ptr->parent->left = right_child;
		}
		else {
			ptr->parent->right = right_child;
		}

		right_child->left = ptr;
		ptr->parent = right_child;

	}

	void rotateRight(Node* ptr) {
		Node *left_child = ptr->left;
		ptr->left = left_child->right;

		if (ptr->left != nullptr) {
			ptr->left->parent = ptr;
		}

		left_child->parent = ptr->parent;

		if (ptr->parent == nullptr) {
			root = left_child;
		}
		else if (ptr == ptr->parent->left) {
			ptr->parent->left = left_child;
		}
		else {
			ptr->parent->right = left_child;
		}

		left_child->right = ptr;
		ptr->parent = left_child;
	}

	void rebalanceInsert(Node* other, Comparable data) {
    	while(other->value != data) {
    		if (data < other->value) {
    			other = other->left;
    		} else {
    			other = other->right;
    		}
    	}
		if (other->parent->color == BLACK) {
			
		} else {
			if ((sibling(other->parent) == nullptr) || (sibling(other->parent)->color == BLACK)) {
				//cout << "hello";
				if (rotationCheck(other) == 0) {
					rotateLeft(other->parent);
					rotateRight(other->parent);
					recolor(other);
					recolor(other->right);
				} else if (rotationCheck(other) == 1) {
					rotateRight(other->parent);
					rotateLeft(other->parent);
					recolor(other);
					recolor(other->left);
				} else if (rotationCheck(other) == 3) {
					rotateLeft(other->parent->parent);
					recolor(other->parent);
					recolor(other->parent->left);
				} else if (rotationCheck(other) == 2) {
					rotateRight(other->parent->parent);
					recolor(other->parent);
					recolor(other->parent->right);
				}
			} else {
				recolor(other->parent);
				recolor(sibling(other->parent));
				if (other->parent->parent != this->root) {
					recolor(other->parent->parent);
					rebalanceInsert(this->root, other->parent->parent->value);
				}
			}
		}
	}

	// void rebalanceDelete(Node* other, Comparable data) {
	// 	while(other->value != data) {
 //    		if (data < other->value) {
 //    			other = other->left;
 //    		} else if (data > other->value) {
 //    			other = other->right;
 //    		}
 //    	} 

 //    	if ((other->right->color == RED) || (other->left->color == RED)) {
 //    		if (other->left == nullptr) {
 //    			other->value = other->right->value;
 //    			other->right = remove_helper(other->right, other->right->value);
 //    		} else if (other->right == nullptr) {
 //    			other->value = other->left->value;
 //    			other->left = remove_helper(other->left, other->left->value);
 //    		} else {
 //    			other = remove_helper(other, other->value);
 //    		}
 //    	}

	// }


 public:

    RedBlackTree() : root(nullptr) {}

    RedBlackTree(const RedBlackTree& other) : root(nullptr) {
    	this->root = copy(other.root);
    }

    ~RedBlackTree() {
    	empty(this->root);
    }

    RedBlackTree& operator=(const RedBlackTree& other) {
    	if (this != &other) {
    		empty(this->root);
    		this->root = copy(other.root);
    	}
    	return *this;
    }

    bool contains(const Comparable& other) const {
    	Node* n = this->root;
    	while (n != nullptr) {
    		if (n->value == other) {
    			return 1;
    		} else if (n->value > other) {
    			n = n->left;
    		} else {
    			n = n->right;
    		}
    	}
    	return 0;
    }

    void print_tree(ostream& os = cout) const {
		if (this->root == nullptr) {
			os << "<empty>" << endl;
		} else {
			print_helper(this->root, 0 , os);
 		}
	}

    void insert(const Comparable& other) {
    	if (this->root == nullptr) {
    		Node* n = new Node;
			n->value = other;
			n->parent = nullptr;
			n->right = nullptr;
			n->left = nullptr;
			n->color = BLACK;
			this->root = n;
    	} else {
    		if (!contains(other)) {
    			this->root = insert_helper(this->root, other);
    			rebalanceInsert(this->root, other);
    		}
    	}
    }

    void remove(const Comparable& other) {
    	if (contains(other)) {
    		if (Node_color(this->root, other) == 1) {
    			//this->root = remove_helper(this->root, other);
    		} else {
    			//this->root = remove_helper(this->root, other);
    			//rebalanceDelete(this->root, other);
    		}
    	}
    }

    const Comparable& find_min() const {
		if (this->root == nullptr) {
			throw invalid_argument("Can't find min bc tree is nullptr");
		}
		Node* n = this->root;
		while(n->left != nullptr) {
			n = n->left;
		}
		return n->value;
	}

	const Comparable& find_max() const {
		if (this->root == nullptr) {
			throw invalid_argument("Can't find max bc tree is nullptr");
		}
		Node* n = this->root;
		while (n->right != nullptr) {
			n = n->right;
		}
		return n->value;
	}

	int color(const Node* other) const {
		if (other == nullptr) {
			return BLACK;
		} else {
			return other->color;
		}
	}

	const Node* get_root() const {
		return this->root;
	}


    
    // TODO(student): implement
};

#endif  // RED_BLACK_TREE_H