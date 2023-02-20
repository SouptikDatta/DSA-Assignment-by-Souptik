//Find the modular node from the end

#include<iostream>
using namespace std;

//structure of the node
struct node
{
    int data;
    struct node *next;
};

//fuction to create a node
struct node *newNode(int data)
{   
    struct node *NODE = new struct node;
    NODE -> data = data;
    NODE -> next = NULL;
    
    return NODE;
}

//function to find the modular node from end
struct node *modul_node(struct node *head, int k)
{
    struct node *prev, *current;
    prev = current = head;
    int i = 1;

    //in this loop at first we moving current to kth node from first and then moving both current and prev n-k times
    while (current -> next != NULL)
    {
        current = current -> next;
        i++;
        if(i>k)
        {
            prev = prev -> next;
        }
    }

    return prev;
    
}


int main()
{
    // creating a linkedlist
    struct node *head = newNode(0);
    head -> next = newNode(1);
    head -> next -> next = newNode(2);
    head -> next -> next -> next = newNode(3);
    head -> next -> next -> next -> next = newNode(4);
    head -> next -> next -> next -> next -> next = newNode(5);
    head -> next -> next -> next -> next -> next -> next = newNode(6);
    head -> next -> next -> next -> next -> next -> next -> next = newNode(7);

    //let
    int k = 3;

    struct node *req_node = modul_node(head,k);

    cout<<"The value at modular node is "<<req_node -> data<<endl;

    return 0;
}