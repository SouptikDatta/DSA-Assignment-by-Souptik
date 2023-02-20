#include <iostream>

using namespace std;

struct AVLNode {
    int value;
    AVLNode* left;
    AVLNode* right;
    int height;
};

int countNodesInRange(AVLNode* root, int a, int b) {
    int count = 0;

    if (root == NULL) {
        return 0;
    }

    if (root->value < a) {
        count += countNodesInRange(root->right, a, b);
    }
    else if (root->value > b) {
        count += countNodesInRange(root->left, a, b);
    }
    else {
        count += 1;
        count += countNodesInRange(root->left, a, b);
        count += countNodesInRange(root->right, a, b);
    }

    return count;
}

int main() {
    AVLNode* root = new AVLNode{ 10, NULL, NULL, 1 };
    root->left = new AVLNode{ 5, NULL, NULL, 1 };
    root->right = new AVLNode{ 15, NULL, NULL, 1 };
    root->left->left = new AVLNode{ 3, NULL, NULL, 1 };
    root->left->right = new AVLNode{ 7, NULL, NULL, 1 };
    root->right->left = new AVLNode{ 12, NULL, NULL, 1 };
    root->right->right = new AVLNode{ 18, NULL, NULL, 1 };

    int a = 5, b = 15;

    int count = countNodesInRange(root, a, b);

    cout << "Number of nodes in the range [" << a << ", " << b << "]: " << count << endl;

    return 0;
}