// Construct an expression tree from the given prefix expression eg. +--a*bc/def and traverse
// it using post order traversal (non recursive) and then delete the entire tree.

#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    char data;
    Node *left, *right;

    Node(char value) {
        data = value;
        left = right = NULL;
    }
};

void postOrderTraversal(Node* root) {
    if (root == nullptr) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
    delete root;
}

Node* createExpressionTree(string expression, int& index) {
    if (expression[index] == '\0')
        return NULL;
    Node* newNode = new Node(expression[index++]);

    if (isdigit(expression[index - 1])) {
        return newNode;
    } else {
        newNode->left = createExpressionTree(expression, index);
        newNode->right = createExpressionTree(expression, index);
        return newNode;
    }
}

// Function to delete the entire expression tree
void deleteExpressionTree(Node* root) {
    if (root == nullptr) return;
    deleteExpressionTree(root->left);
    deleteExpressionTree(root->right);
    delete root;
}
int main() {
    string prefixExpression;
    cout << "Enter the prefix expression" << endl;
    cin >> prefixExpression;
    int index = 0;
    Node* root = createExpressionTree(prefixExpression, index);
    cout << "Post-order traversal: ";
    postOrderTraversal(root);

    cout << endl;
    deleteExpressionTree(root);
    return 0;
}
