//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : Davi
// Version     :
// Description : generic binary serach tree in C++, Ansi-style
//============================================================================
#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include <stddef.h>
#include "Queue.h"
#include "Stack.h"

template<typename T>
class BSTNode {
public:
	BSTNode() {
		left = right = NULL;
	}

	BSTNode(const T &e, BSTNode<T> *l = NULL, BSTNode<T> *r = NULL) {
		el = e;
		left = l;
		right = r;
	}

	T el;
	BSTNode<T> *left, *right;
};

template<typename T>
class BinarySearchTree {

public:
protected:
	BSTNode<T> * root;

	BinarySearchTree() {
		root = NULL;
	}

	bool isEmpty() const;

	void insert(const T&);

	int search(const T&) const;

	void breathFirst();

	//use recursion
	void preorder(BSTNode<T> *);
	void inorder(BSTNode<T> *);
	void postorder(BSTNode<T> *);

	//without recursion
	void iterativePreorder();
	void iterativeInorder();
	void iterativePostorder();

	void visit(BSTNode<T> *);

};

template<typename T>
bool BinarySearchTree<T>::isEmpty() const {
	return root == NULL;
}

template<typename T>
void BinarySearchTree<T>::insert(const T &el) {
	BSTNode<T> *node = new BSTNode(el);
	if (isEmpty()) {
		root = node;
	} else {
		BSTNode<T> *p = root->left;

		while (p != NULL) {
			if (p->left > el) {
				p = p->left;
			}
		}
		if (p == NULL) {
			p = node;
		} else {

		}
	}

}

template<typename T>
int BinarySearchTree<T>::search(const T& el) const {
	BSTNode<T> * p = root;
	while (p != NULL) {
		if (el == p->el) {
			return 1;
		} else if (el > p->el) {
			p = p->left;
		} else {
			p = p->right;
		}
	}

	return -1;
}

template<typename T>
void BinarySearchTree<T>::breathFirst() {
	Queue<BSTNode<T> *> treeQueue;
	BSTNode<T> *p = root;

	if (p != NULL) {
		treeQueue.equeue(p);

		while(!treeQueue.empty()) {

			BSTNode<T> *node = treeQueue.dequeue();
			visit(node);//print value

			if (node->left != NULL) {
				treeQueue.equeue(node->left);
			}
			if (node->right != NULL) {
				treeQueue.equeue(node->right);
			}
		}
	}
}

template<typename T>
void BinarySearchTree<T>::preorder(BSTNode<T> * p) {
	if (p != NULL) {
		visit(p);
		preorder(p->left);
		preorder(p->right);
	}
}

template<typename T>
void BinarySearchTree<T>::inorder(BSTNode<T> * p) {
	if (p != NULL) {
		preorder(p->left);
		visit(p);
		preorder(p->right);
	}
}

template<typename T>
void BinarySearchTree<T>::postorder(BSTNode<T> * p) {
	if (p != NULL) {
		preorder(p->left);
		preorder(p->right);
		visit(p);
	}
}

template<typename T>
void BinarySearchTree<T>::iterativePreorder() {
	BSTNode<T> * p = root;
	Stack<BSTNode<T> *> stack;
	if (p != NULL) {
		stack.push(p);

		while (!stack.empty()) {
			p = stack.pop();

			visit(p);

			if (p->right != NULL) {
				stack.push(p->right);
			}

			// left child pushed after right to be on the top of the stack
			if (p->left != NULL) {
				stack.push(p->left);
			}
		}
	}
}

template<typename T>
void BinarySearchTree<T>::iterativeInorder() {
	Stack<BSTNode<T> *> stack;
	BSTNode<T> * p = root;
	while (p != NULL) {
		while (p != NULL) { // stack the right child (if any)
			if (p ->right != NULL) {
				stack.push(p->right);
			}
			stack.push(p);
			p = p->left;
		}
		p = stack.pop();
		while (!stack.empty() && p->right == 0) {
			visit(p);
			p = stack.pop();
		}
		visit(p);
		if (!stack.empty()) {
			p = stack.pop();
		} else {
			p = NULL;
		}
	}
}

template<typename T>
void BinarySearchTree<T>::iterativePostorder() {
	Stack<BSTNode<T> *> stack;
	BSTNode<T> * p = root;
	BSTNode<T> * q = root;//help pointer

	while (p != NULL) {
		for (; p->left != NULL; p = p->left) {
			stack.push(p);
		}

		while (p->right == NULL || p->right == q) {
			visit(p);
			q = p;

			if (stack.empty()) {
				return;
			}
			p = stack.pop();
		}

		stack.push(p);
		p = p->right;
	}
}

template<typename T>
void BinarySearchTree<T>::visit(BSTNode<T> * p) {
	cout << p->el << ' ';
}

#endif
