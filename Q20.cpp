#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Definition for a doubly linked list node.
struct ListNode {
    int val;
    ListNode* prev;
    ListNode* next;
    ListNode(int x) : val(x), prev(NULL), next(NULL) {}
};

TreeNode* sortedListToBST(ListNode* head) {
    if (!head) {
        return NULL;
    }

    // Step 1: Find the middle node
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Create a new node with the value of the middle node
    TreeNode* root = new TreeNode(slow->val);

    // Set the previous node's next pointer to null to split the linked list into two halves
    if (prev) {
        prev->next = NULL;
    }

    // Step 3: Recursively repeat steps 1 and 2 for the left and right halves of the linked list
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);

    // Step 4: Return the root node of the binary search tree
    return root;
}

// A utility function to print the inorder traversal of a binary tree
void printInorder(TreeNode* node) {
    if (node==NULL) return; 
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

// Driver code to test the algorithm
int main() {
    // Create a linked list with four nodes (1 -> 2 -> 3 -> 4)
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->prev = head;
    head->next->next = new ListNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = new ListNode(4);
    head->next->next->next->prev = head->next->next;

    // Convert the linked list into a binary search tree
    TreeNode* root = sortedListToBST(head);

    // Print the inorder traversal of the resulting tree
    cout << "Inorder traversal of the constructed BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}