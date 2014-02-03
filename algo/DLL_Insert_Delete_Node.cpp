n doubly linked list. This function should cover all the scenarios.
Similarly, to delete a node from  a given location.
*/
//#include "stdafx.h"
#include <iostream>
using namespace std;

struct node
{
	int data;
	node* previous;
	node* next;
};

void DLLInsert(node** head, int data, int position)
{
	if(position<1) return;
	int k = 1;
	node* temp, *current;
	temp = new node;
	if (!temp)
	{
		cout<<"memory error";
		return;
	}
	temp->data = data;

	/* Insert at the beginning*/
	if(position == 1)
	{
		temp->next = *head;
		temp->previous = NULL;
		if(*head)
			(*head)->previous = temp;
		*head = temp;
		return;
	}


	current = *head;

	while((k < position-1) && (current->next != NULL))
	{
		current = current->next;
		k++;
	}

	if(position > ++k)
	{
		cout<<endl<<"desired position does not exist";
		return;
	}    

	temp->next = current->next;  
	temp->previous = current;
	if(current->next)
		current->next->previous = temp;
	current->next = temp;
	return;
}

void DLLDelete(node** head, int position)
{
	if(!(*head) || position<1) return;
	node *temp = *head;
	for(int i=1; i<position; i++)
	{
		if(temp) {
			temp = temp->next;
		}
		else{
			cout<<"Position out of range"<<endl;
			return;
		}
	}
	if(temp){
		if(temp->previous)
		{
			temp->previous->next = temp->next;
		}
		else
			*head = temp->next;
		if(temp->next)
			temp->next->previous = temp->previous;
		delete temp;
		temp=NULL;
	}
	else{
		cout<<"Position out of range"<<endl;
	}

}
void print(node* dlist)
{

	if(dlist == NULL)
		return;

	while(dlist != NULL)
	{
		cout << dlist->data << " ";
		dlist = dlist->next;
	}
}

int main()
{
	node* mydlist(NULL);
	DLLInsert(&mydlist, 10, 1);
	DLLInsert(&mydlist, 20, 2);
	DLLInsert(&mydlist, 30, 3);
	DLLInsert(&mydlist, 40, 4);
	DLLInsert(&mydlist, 50, 5);
	DLLInsert(&mydlist, 60, 6);
	DLLInsert(&mydlist, 70, 7);
	DLLInsert(&mydlist, 100, 5);
	DLLDelete(&mydlist, 20);

	print(mydlist);
	return 0;
}
