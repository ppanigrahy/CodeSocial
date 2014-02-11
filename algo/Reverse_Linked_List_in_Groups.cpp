//Reverse the N length linklist in a group of K where K<N.

#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	node(int val)
	{
		data = val;
		next = NULL;
	}
};

void printList(node* root)
{
	if(root == NULL)
		return;
	while(root != NULL)
	{
		cout << root->data << " ";
		root = root->next;
	}
	cout << std::endl;
}

void createLinkedList(node** mylist)
{
	node* head = NULL;
	for(int i = 1; i <= 10; i++)
	{
		node* tempnode = new node(i);
		if(head == NULL)
		{
			head = tempnode;
			(*mylist) = head;
		}
		else
		{
			head->next = tempnode;
			head = head->next;
		}
	}
}

void reverse(node** root)
{
	node* curr = (*root);
	node* prev = NULL;
	node* tempnode = NULL;

	while(curr != NULL)
	{
		tempnode = curr->next;
		curr->next = prev;
		prev = curr;
		curr = tempnode;
	}
	(*root) = prev;
}

void reverseLinkedListInGroup(node** root, int groupval)
{
	if (*root == NULL)
		return;

	node* head = (*root);
	bool firsttime = true;

	node* start = NULL;
	node* prevend = NULL;

	int count;
	while(head != NULL && head->next != NULL)
	{
		start = head;
		count = 1;
		while( head->next != NULL && count < groupval)
		{
			head = head->next;
			count++;
		}

		if(groupval == count)
		{
			node* tempnode = head->next;
			head->next = NULL;
			node* prevstart = start;
			reverse(&start);
			if(firsttime)
			{
				firsttime = false;
				(*root) = start;
			}
			if(prevend)
				prevend->next = start;
				
			prevstart->next = tempnode;
			head = tempnode;
			prevend = prevstart;
		}
	}
}

int main()
{
	node* mylist;
	createLinkedList(&mylist);
	printList(mylist);
	reverseLinkedListInGroup(&mylist, 2);  
	printList(mylist);
}
