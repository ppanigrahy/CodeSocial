nclude <iostream>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

void print (int i) {
  std::cout << ' ' << i;
}

struct Node{
	int Val;
	Node *left;
	Node *right;};

Node* CreateTree()
{
	Node *N1 = new Node(); N1->Val = 1;
	Node *N2 = new Node(); N2->Val = 2;
	Node *N3 = new Node(); N3->Val = 3;
	Node *N4 = new Node(); N4->Val = 4;
	Node *N5 = new Node(); N5->Val = 5;
	Node *N6 = new Node(); N6->Val = 6;
	Node *N7 = new Node(); N7->Val = 7;
	Node *N8 = new Node(); N8->Val = 8;
	Node *N9 = new Node(); N9->Val = 9;

	N1->left = N2; N1->right=N3;
	N2->left = N4; N2->right=N5;
	N3->left = N6; N3->right=N7;
	N7->left = N8; N7->right=N9;
	N4->left=N4->right=N5->left=N5->right=N6->left=N6->right=N8->left=N8->right=N9->left=N9->right=NULL;
	return N1;
}

//Space complexity O(2 pow logn), Time complexity O(n)
list<int> leftViewOfTree_iterative(Node *head)
{
	list<int> leftView;
	if (head == NULL) return leftView;
	Node *temp = head;
	queue<Node*> Q;
	Q.push(temp);
	Q.push(NULL);
	bool printNode(true);
	while(Q.size())
	{
		if(printNode) leftView.push_back(temp->Val);

		if(temp)
		{
			printNode = false;
			if(temp->left) 
				Q.push(temp->left);
			if(temp->right) 
				Q.push(temp->right);
		}
		else
		{
			printNode = true;
			Q.push(NULL);
		}
		temp = Q.front();
		Q.pop();
	}
	return leftView;
}

//Space complexity O(n) -Using system stack, Time complexity O(n)
void leftViewOfTree_recursive(Node *head, list<int>& leftView, int level=1, int *max_level=NULL)
{
	if (head == NULL) return;
	if(!max_level) max_level=new int(0);
	if (level>*max_level)
	{
		leftView.push_back(head->Val);
		*max_level = level;
	}
	leftViewOfTree_recursive(head->left, leftView, level+1, max_level);
	leftViewOfTree_recursive(head->right, leftView, level+1, max_level);
}

int main() 
{
	Node * root = CreateTree();
	list<int> leftView;
	leftView = leftViewOfTree_iterative(root);
	//leftViewOfTree_recursive(root, leftView);
	for_each(leftView.begin(), leftView.end(), print);
	return 0;
}
