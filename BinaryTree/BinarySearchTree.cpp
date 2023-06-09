#include "BinarySearchTree.h"

void BinarySearchTree::insertNode(int key, string data)
{
	Node *x = root;
	Node *y = nullptr;
	Node *z = new Node();
	z->key = key;
	z->data = data;

	while (x)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	z->parent = y;

	if (y == NULL)
		root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
}

BinarySearchTree::Node *BinarySearchTree::searchNode(Node *x, int key, string data)
{
	while (x && key != x->key)
	{
		if (key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	return x->data.compare(data) ? nullptr : x;
}

void BinarySearchTree::preorderTraversal(Node *x)
{
	if (x)
	{
		cout << " " << x->key << "\t" << x->data << endl;
		if (x->left)
			preorderTraversal(x->left);
		if (x->right)
			preorderTraversal(x->right);
	}
}

void BinarySearchTree::inorderTraversal(Node *x)
{
	if (x)
	{
		if (x->left)
			inorderTraversal(x->left);
		cout << " " << x->key << "\t" << x->data << endl;
		if (x->right)
			inorderTraversal(x->right);
	}
}

void BinarySearchTree::postorderTraversal(Node *x)
{
	if (x)
	{
		if (x->left)
			postorderTraversal(x->left);
		if (x->right)
			postorderTraversal(x->right);
		cout << " " << x->key << "\t" << x->data << endl;
	}
}

BinarySearchTree::Node *BinarySearchTree::findMax(Node *x)
{
	while (x->right)
		x = x->right;
	return x;
}

void BinarySearchTree::removeMax(Node *x)
{
	if (x->right)
	{
		while (x->right->right)
			x = x->right;
		delete x->right;
		x->right = nullptr;
	}
	else
	{
		delete x;
		root = nullptr;
	}
}

BinarySearchTree::Node *BinarySearchTree::successor(Node *x)
{
	if (x->right)
	{
		x = x->right;
		while (x->left)
			x = x->left;
		return x;
	}
	else
	{
		Node *y = x->parent;
		while (y && x == y->right)
		{
			x = y;
			y = y->parent;
		}
		return y;
	}
}

void BinarySearchTree::deleteNode(Node *z)
{
	Node *x = nullptr;
	Node *y = nullptr;

	if (!z->left || !z->right)
		y = z;
	else
		y = successor(z);

	if (y->left)
		x = y->left;
	else
		x = y->right;

	if (x)
		x->parent = y->parent;

	if (!y->parent)
		root = x;
	else
	{
		if (y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;
	}

	if (y != z)
		z->key = y->key;
}

void BST()
{
	BinarySearchTree bst;
	int choice, key;
	while (true)
	{
		cout << endl;
		cout << endl;
		cout << " Binary Search Tree Example " << endl;
		cout << " ----------------------------- " << endl;
		cout << " 1. Insert a Node " << endl;
		cout << " 2. Delete a Node " << endl;
		cout << " 3. Pre-Order Traversal " << endl;
		cout << " 4. In-Order Traversal " << endl;
		cout << " 5. Post-Order Traversal " << endl;
		cout << " 6. Find Max " << endl;
		cout << " 7. Remove Max " << endl;
		cout << " 8. Successor " << endl;
		cout << " 9. Return to Main Menu " << endl;
		cout << " Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << endl;
			cout << " Enter key (int value) to be inserted : ";
			cin >> key;
			bst.insertNode(key, "");
			break;

		case 2:
			cout << endl;
			if (!bst.isEmpty())
			{
				cout << " Enter key (int value) to be deleted : ";
				cin >> key;
				if (bst.searchNode(bst.root, key, ""))
					bst.deleteNode(bst.searchNode(bst.root, key, ""));
				else
					cout << " E: No Such Node ";
			}
			else
				cout << " E: BST is Empty ";
			break;

		case 3:
			cout << endl;
			cout << " Pre-Order Traversal " << endl;
			cout << " -------------------" << endl;
			bst.preorderTraversal(bst.root);
			break;

		case 4:
			cout << endl;
			cout << " In-Order Traversal " << endl;
			cout << " -------------------" << endl;
			bst.inorderTraversal(bst.root);
			break;

		case 5:
			cout << endl;
			cout << " Post-Order Traversal " << endl;
			cout << " -------------------" << endl;
			bst.postorderTraversal(bst.root);
			break;

		case 6:
			cout << endl;
			cout << " Find Max " << endl;
			cout << " -------------------" << endl;
			if (bst.root)
				cout << " " << bst.findMax(bst.root)->key << " ";
			break;

		case 7:
			cout << endl;
			if (!bst.isEmpty())
			{
				cout << " Remove Max ";
				bst.removeMax(bst.root);
			}
			else
				cout << " E: BST is Empty ";
			break;

		case 8:
			cout << endl;
			if (!bst.isEmpty())
			{
				cout << " Enter key (int value) to find successor : ";
				cin >> key;
				if (bst.searchNode(bst.root, key, ""))
				{
					if (bst.successor(bst.searchNode(bst.root, key, "")))
						cout << bst.successor(bst.searchNode(bst.root, key, ""))->key << endl;
					else
						cout << " E: No Successor ";
				}
				else
					cout << " E: No Such Node ";
			}
			else
				cout << " E: BST is Empty ";
			break;

		case 9:
			return;

		default:
			cout << " E: Invalid Choice ";
		}
	}
}