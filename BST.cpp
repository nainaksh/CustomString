#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BST
{
public:
	int data;
	BST* left;
	BST* right;
	vector<int> v;

	BST() :data(0)
	{
		left = nullptr;
		right = nullptr;
	}

	BST(int a) :data(a)
	{
		left = nullptr;
		right = nullptr;
	}

	BST* Insert(BST* root, int val)
	{
		if (root == nullptr)
		{
			root = new BST(data);
		}
		else if (val > root->data)
		{
			root->right = Insert(root->right, val);
		}

		else if (val < root->data)
		{
			root->left = Insert(root->left, val);
		}
	}

	void Inorder(BST* root)
	{
		Inorder(root->left);
		cout << root->data;
		Inorder(root->right);
	}

	void Preorder(BST* root)
	{
		cout << root->data;
		Inorder(root->left);
		Inorder(root->right);
	}

	void Postorder(BST* root)
	{
		Inorder(root->left);
		Inorder(root->right);
		cout << root->data;
	}

	void InorderTraverse(BST* root)
	{
		 Inorder(root->left);
		 v.push_back(root->data);
		 Inorder(root->right);
	}

	int kthSmallest(BST* root, int k) 
	{
		sort(v.begin(), v.end());
		return v[k-1];
	}
};