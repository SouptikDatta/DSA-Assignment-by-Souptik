#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedListToBST(ListNode* head) {
    if (!head) {
        return NULL;
    }

    // find middle node
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // create root node
    TreeNode* root = new TreeNode(slow->val);

    // handle left subtree
    if (prev) {
        prev->next = NULL;
        root->left = sortedListToBST(head);
    }

    // handle right subtree
    if (slow->next) {
        root->right = sortedListToBST(slow->next);
    }

    return root;
}

void preOrder(TreeNode* root){
    if(root == NULL) return;
    cout<< root-> val <<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    // create a sorted linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    // convert linked list to binary search tree
    TreeNode* root = sortedListToBST(head);

    // print preorder traversal of binary search tree
    cout << "Preorder traversal of binary search tree:" << endl;
    preOrder(root);
    cout << endl;

    return 0;
}