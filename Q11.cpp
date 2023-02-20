// Q. Check whether the given linked list is either NULL-terminated or ends in cycle(cyclic).


#include<iostream>
using namespace std;

//structure of a node

struct node
{
    int data;
    struct node *next;
};

//function to create a node

struct node *newNode(int data)
{
    struct node *Node = new struct node;
    Node -> data = data;
    Node -> next = NULL;

    return Node;
}


/*This function takes head pointer as a input and return type is boolean.
  It returns true if the linkedlist is cyclic otherwise false */

bool checkCyclic(struct node *head)
{
    struct node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main()
{
    //for null linkedlist
    struct node *head = NULL;

    //for NULL terminated linkedlist
    head = newNode(5);
    head -> next = newNode(8);
    head -> next ->next = newNode(6);
    head -> next ->next -> next = newNode(14);

    //for circular linkedlist
    head -> next ->next -> next = head;

    bool check = checkCyclic(head);

    if(check)
        cout<<"This is a cyclic linkedlist."<<endl;
    
    else
        cout<<"The linkedlist is NULL terminated."<<endl;

    return 0;
}