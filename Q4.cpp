#include <bits/stdc++.h>
using namespace std;

//Definition of a singly linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Function to find the value of root(n)th element
int rootNthElement(ListNode* head) {

    // return an appropriate value for an empty list
    if (head == NULL) {
        return -1;
    }
    int count = 0;
    ListNode* current = head;

    // Traverse the list and count the number of elements
    while (current != NULL) {
        count++;
        current = current->next;
    }

    // Calculate root(n)
    int root = sqrt(count);

    // Traverse the list again, stopping at the root(n)th element
    current = head;
    for (int i = 0; i < root && current != NULL; i++) {
        current = current->next;
    }

    // Return the value of the root(n)th element
    return current->val;
}

//Driver code
int main() {
 
    ListNode* head = new ListNode(5);
    head->next = new ListNode(26);
    head->next->next = new ListNode(12);
    head->next->next->next = new ListNode(45);
    head->next->next->next->next = new ListNode(51);

    cout << "Root(n)th element: " << rootNthElement(head) << endl;

    return 0;
}