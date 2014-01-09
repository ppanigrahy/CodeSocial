/**Merge Linked List 
Input List 1 : 1 2 3 
Input List 2 : 4 5 6 7 
Result List 1 : 1 4 2 5 3 6 
Result List 1 : 7 
Note that in the process of merging, no new node should be created and the complexity should be 0(n)
*/
#include <iostream>
using namespace std;

struct Node{
	int Val;
	Node* next;
};

void printList(Node *Head)
{
	Node *tmp = Head;
	while(tmp)
	{
		cout<< tmp->Val<< " ";
		tmp = tmp->next;
	}
	cout<<endl;
}

void Merge(Node **H1, Node **H2)
{
	Node *tmp1 = *H1; Node *tmp2 = *H2;
	while(tmp1 && tmp2)
	{
		Node *tmpNxt1= tmp1->next;
		Node *tmpNxt2= tmp2->next;
		tmp1->next = tmp2;
		tmp1 = tmpNxt1;
		tmp2->next = tmp1;
		tmp2 = tmpNxt2;
	}
	if(tmp1) *H2 = tmp1; else *H2 = tmp2;
}

int main() {
	Node *N11 = new Node; N11->Val = 1; 
	Node *N12 = new Node; N12->Val = 2;
	Node *N13 = new Node; N13->Val = 3;
	N11->next=N12; N12->next=N13; N13->next=NULL; 
	printList(N11);
	
	Node *N21 = new Node; N21->Val = 4; 
	Node *N22 = new Node; N22->Val = 5;
	Node *N23 = new Node; N23->Val = 6;
	Node *N24 = new Node; N24->Val = 7;
	N21->next=N22; N22->next=N23; N23->next=N24; N24->next=NULL;
	printList(N21);
	
	Node *H1= N11;  Node *H2 = N21;
	Merge(&H1, &H2);
	printList(H1);
	printList(H2);
	return 0;
}