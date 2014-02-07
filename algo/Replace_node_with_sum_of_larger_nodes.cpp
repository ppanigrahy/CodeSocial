/** 
Given a BST, replace each node with the sum of the values of all the nodes that are greater than that node. It needs to be done with O(n) complexity.

Question and solution by Seshadri...
*/

#include <iostream>
using namespace std;

struct node
{
	int val;
	node* left;
	node* right;

	node(int x)
	{
		val = x;
		left = NULL;
		right = NULL;
	}
};



void createBinSearchTree(node** root)
{
	node* head = new node(10);
	head->left = new node(7);
	head->left->left = new node(6);
	head->left->right = new node(8);
	head->right = new node(18);
	head->right->left = new node(16);
	head->right->left->left = new node(15);
	head->right->left->right = new node(17);
	head->right->right = new node(20);
	head->right->right->left = new node(19);
	head->right->right->right = new node(21);

	(*root) = head;
}



int replaceWithSumOfNodes(node* root, int sum)
{
	if (root == NULL)
		return 0;
	int tempsum1 = replaceWithSumOfNodes(root->right, sum);
	int tempsum2 = replaceWithSumOfNodes(root->left, root->val + tempsum1);
	//cout << "root->val " << root->val << " sum = " << sum << "tempsum1 = " << tempsum1 << "tempsum2 = " << tempsum2 << std::endl;    

	if(root->left == NULL && root->right == NULL)
	{
		root->val = root->val + sum + tempsum1;
		return root->val;
	}
	else
	{
		root->val =  root->val + tempsum1;
		return tempsum2;
	}
}

void inOrderTraversal(node* mytree)
{
	if(mytree == NULL)
		return;        

	inOrderTraversal(mytree->left);
	cout << " " << mytree->val;
	inOrderTraversal(mytree->right);
}

void modified_inOrderTraversal(node* mytree, int *sum=NULL)
{
	if(mytree == NULL)
		return;
	if(sum == NULL) 
		sum = new int(0);
	modified_inOrderTraversal(mytree->right, sum);
	*sum = *sum + (mytree->val);
	mytree->val = *sum;
	modified_inOrderTraversal(mytree->left, sum);
}

int main()
{
	node* mytree;
	int sum = 0;
	createBinSearchTree(&mytree);
	inOrderTraversal(mytree);
	cout<<endl;
	//replaceWithSumOfNodes(mytree, sum);
	inOrderTraversal(mytree);
	cout<<endl;
	modified_inOrderTraversal(mytree);
	inOrderTraversal(mytree);
}

