// C++ program to get merge point of two linked list

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

/* Takes head pointer of the linked list and
returns the count of nodes in the list */
int getCount(Node* head)
{
	Node* current = head;

	// Counter to store count of nodes
	int count = 0;

	// Iterate till NULL
	while (current != NULL) {

		// Increase the counter
		count++;

		// Move the Node ahead
		current = current->next;
	}

	return count;
}

/* function to get the merge point of two linked
lists list1 and list2 where list1 has d more nodes than
list2 */
int _getMergeNode(int d, Node* list1, Node* list2)
{
	// Stand at the starting of the bigger list
	Node* current1 = list1;
	Node* current2 = list2;

	// Move the pointer forward
	for (int i = 0; i < d; i++) {
		if (current1 == NULL) {
			return -1;
		}
		current1 = current1->next;
	}

	// Move both pointers of both list till the merge with each other
	while (current1 != NULL && current2 != NULL) {
		if (current1 == current2)
			return current1->data;

		// Move both the pointers forward
		current1 = current1->next;
		current2 = current2->next;
	}

	return -1;
}

/* function to get the merge point of two linked
lists list1 and list2 */
int getMergeNode(Node* list1, Node* list2)
{

	// Count the number of nodes in
	// both the linked list
	int n = getCount(list1);
	int m = getCount(list2);
	int d;

	// If first is greater
	if (n > m) {
		d = n - m;
		return _getMergeNode(d, list1, list2);
	}
	else {
		d = m - n;
		return _getMergeNode(d, list2, list1);
	}
}

// Driver Code
int main()
{
	/*
		Create two linked lists
	
		1st 3->6->9->15->30
		2nd 10->15->30
	
		15 is the merge point
	*/

	Node* newNode;

	// Addition of new nodes
	Node* list1 = new Node();
	list1->data = 10;

	Node* list2 = new Node();
	list2->data = 3;

	newNode = new Node();
	newNode->data = 6;
	list2->next = newNode;

	newNode = new Node();
	newNode->data = 9;
	list2->next->next = newNode;

	newNode = new Node();
	newNode->data = 15;
	list1->next = newNode;
	list2->next->next->next = newNode;

	newNode = new Node();
	newNode->data = 30;
	list1->next->next = newNode;

	list1->next->next->next = NULL;

	cout << "The node of merge is " << getMergeNode(list1, list2);
}