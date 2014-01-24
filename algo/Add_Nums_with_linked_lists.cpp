// Add two numbers in which the digits are nodes of two linked lists

//Test

#include<iostream>

static int carry=0;
struct Node{
    int Val;
  Node *next;
};

Node* Add(Node *H1, Node *H2, int diff)
{

	Node *prevNode(NULL);
	int temp_val=0;
	if(H1->next != NULL && H2->next != NULL){
		if(diff <= 0){
			prevNode = Add(H1->next, H2->next, --diff);
			temp_val = H1->Val + H2->Val + carry;}
		else{
			prevNode = Add(H1->next, H2, --diff);
			temp_val =  H1->Val + carry;}}

	if(diff < 0){
		temp_val = H1->Val + H2->Val + carry;}
	else{
		temp_val =  H1->Val + carry;}
	carry = 0;
	if(temp_val >=10) {carry = temp_val /10; temp_val =temp_val %10;}
	Node *newNode = new Node; newNode->Val=temp_val; newNode->next=prevNode;
	return newNode;
}

void AddLinkedLists(Node *H1, Node *H2)
{
	int L1=2, L2=4, diff=2;
	Node * final;
	int p=0;
	if(L1>L2)
		final = Add(H1, H2, diff);
	else
		final = Add(H2, H1, diff);
	Node * head(NULL);
	if(carry){
		head = new Node; head->Val=carry; head->next=final;
	}
	else
		head = final;
	while(head!=NULL){
		std::cout<<head->Val;
		head=head->next;
	}
}

int main()
{
	Node *N11 = new Node; Node *N12 = new Node;
	Node *Head1 = N11; N11->Val=1; N11->next=N12; N12->Val=7;N12->next=NULL;
	Node *N21 = new Node;Node *N22 = new Node;Node *N23 = new Node;Node *N24 = new Node;
	Node *Head2 = N21; N21->Val=8;N21->next=N22;N22->Val=9;N22->next=N23;N23->Val=6;N23->next=N24;N24->Val=0;N24->next=NULL;
	AddLinkedLists(Head1, Head2);
	getchar();
	return 0;
}
