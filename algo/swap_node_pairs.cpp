// Program to swap the pair nodes. For example input is 1->2->3->4->5->6->NULL, output will be 2->1->4->3->6->5->NULL
//#include"stdafx.h"
#include"iostream"

struct Node
{
	int Val;
	Node *next;
};

Node* swap_alt_node(Node *Head)
{
	Node *curr_node = Head;
	Node *new_head = Head->next;

	Node *curr_tail(NULL);
	while(curr_node && curr_node->next)
	{
		Node *temp = curr_node->next;
		curr_node->next = curr_node->next->next;
		temp->next = curr_node;
		if(curr_tail)
			curr_tail->next = temp;
		curr_tail = curr_node;
		curr_node = curr_node->next;

	}
	return new_head;
}

void print_linked_list(Node *node)
{
	Node *tempNode = node;
	while(tempNode){
		std::cout<<tempNode->Val<<"  ";
		tempNode = tempNode->next;
	}
	std::cout<<std::endl;
}

int main()
{
	Node * n1 = new Node;
	Node * n2 = new Node;
	Node * n3 = new Node;
	Node * n4 = new Node;
	Node * n5 = new Node;
	Node * n6 = new Node;
	n1->Val = 1; n1->next = n2;
	n2->Val = 2; n2->next = n3;
	n3->Val = 3; n3->next = n4;
	n4->Val = 4; n4->next = n5;
	n5->Val = 5; n5->next = n6;
	n6->Val = 6; n6->next = NULL;

	print_linked_list(n1);
	Node *head = swap_alt_node(n1);
	print_linked_list(head);
	return 0;
}
