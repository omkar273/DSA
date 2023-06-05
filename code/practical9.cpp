// A Dictionary stores keywords and its meanings. Provide facility for adding new keywords, deleting keywords, updating values of any entry. Provide facility to display whole data sorted in ascending/ Descending order. Also find how many maximum comparisons may require for finding any keyword. Use AVL tree and find the complexity for finding a keyword

#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

struct Node {
    string keyword;
    string meaning;
    int height;
    Node* left;
    Node* right;
};

// Function to get the height of a node
int getHeight(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// Function to get the maximum of two integers
int getMax(int a, int b) {
    return max(a, b);
}

// Function to create a new node
Node* createNode(string keyword, string meaning) {
    Node* newNode = new Node();
    newNode->keyword = keyword;
    newNode->meaning = meaning;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}

// Function to right rotate subtree rooted with y
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + getMax(getHeight(y->left), getHeight(y->right));
    x->height = 1 + getMax(getHeight(x->left), getHeight(x->right));

    // Return new root
    return x;
}

// Function to left rotate subtree rooted with x
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + getMax(getHeight(x->left), getHeight(x->right));
    y->height = 1 + getMax(getHeight(y->left), getHeight(y->right));

    // Return new root
    return y;
}

// Function to get the balance factor of a node
int getBalanceFactor(Node* node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Function to insert a node into the AVL tree
Node* insertNode(Node* root, string keyword, string meaning) {
    // Perform the normal BST insertion
    if (root == nullptr)
        return createNode(keyword, meaning);

    if (keyword < root->keyword)
        root->left = insertNode(root->left, keyword, meaning);
    else if (keyword > root->keyword)
        root->right = insertNode(root->right, keyword, meaning);
    else  // Keywords are the same, update the meaning
        root->meaning = meaning;

    // Update the height of the ancestor node
    root->height = 1 + getMax(getHeight(root->left), getHeight(root->right));

    // Check the balance factor and balance the tree if needed
    int balanceFactor = getBalanceFactor(root);

    // Left Left Case
    if (balanceFactor > 1 && keyword < root->left->keyword)
        return rightRotate(root);

    // Right Right Case
    if (balanceFactor < -1 && keyword > root->right->keyword)
        return leftRotate(root);

    // Left Right Case
    if (balanceFactor > 1 && keyword > root->left->keyword) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balanceFactor < -1 && keyword < root->right->keyword) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Return the balanced root
    return root;
}

// Function to find the node with minimum key value
Node* findMinNode(Node* node) {
    Node* current = node;

    while (current->left != nullptr)
        current = current->left;

    return current;
}

// Function to delete a node from the AVL tree
Node* deleteNode(Node* root, string keyword) {
    // Perform the normal BST deletion
    if (root == nullptr)
        return root;

    if (keyword < root->keyword)
        root->left = deleteNode(root->left, keyword);
    else if (keyword > root->keyword)
        root->right = deleteNode(root->right, keyword);
    else {
        // Node with the keyword found

        // Node with only one child or no child
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else  // One child case
                *root = *temp;

            delete temp;
        } else {
            // Node with two children, get the in-order successor
            Node* temp = findMinNode(root->right);

            // Copy the in-order successor's data to this node
            root->keyword = temp->keyword;
            root->meaning = temp->meaning;

            // Delete the in-order successor
            root->right = deleteNode(root->right, temp->keyword);
        }
    }

    // If the tree had only one node, return
    if (root == nullptr)
        return root;

    // Update the height of the current node
    root->height = 1 + getMax(getHeight(root->left), getHeight(root->right));

    // Check the balance factor and balance the tree if needed
    int balanceFactor = getBalanceFactor(root);

    // Left Left Case
    if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balanceFactor > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balanceFactor < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Return the balanced root
    return root;
}

// Function to display the AVL tree in ascending order
void displayAscending(Node* root) {
    if (root == nullptr)
        return;

    displayAscending(root->left);
    cout << root->keyword << ": " << root->meaning << endl;
    displayAscending(root->right);
}

// Function to display the AVL tree in descending order
void displayDescending(Node* root) {
    if (root == nullptr)
        return;

    displayDescending(root->right);
    cout << root->keyword << ": " << root->meaning << endl;
    displayDescending(root->left);
}

// Function to find the maximum number of comparisons required to find a keyword
int findMaxComparisons(Node* root, string keyword, int comparisons) {
    if (root == nullptr)
        return comparisons;

    if (root->keyword == keyword)
        return comparisons + 1;

    if (keyword < root->keyword)
        return findMaxComparisons(root->left, keyword, comparisons + 1);

    return findMaxComparisons(root->right, keyword, comparisons + 1);
}

int main() {
    Node* root = nullptr;

    int choice;
    string keyword, meaning;
    int comparisons = 0;  // Move the declaration outside the switch statement

    do {
        cout << "1. Add a keyword\n";
        cout << "2. Delete a keyword\n";
        cout << "3. Update the meaning of a keyword\n";
        cout << "4. Display the dictionary in ascending order\n";
        cout << "5. Display the dictionary in descending order\n";
        cout << "6. Find the maximum number of comparisons\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the keyword: ";
                cin >> keyword;
                cout << "Enter the meaning: ";
                cin.ignore();
                getline(cin, meaning);
                root = insertNode(root, keyword, meaning);
                cout << "Keyword added successfully.\n";
                break;
            case 2:
                cout << "Enter the keyword to delete: ";
                cin >> keyword;
                root = deleteNode(root, keyword);
                cout << "Keyword deleted successfully.\n";
                break;
            case 3:
                cout << "Enter the keyword to update: ";
                cin >> keyword;
                cout << "Enter the new meaning: ";
                cin.ignore();
                getline(cin, meaning);
                root = insertNode(root, keyword, meaning);
                cout << "Meaning updated successfully.\n";
                break;
            case 4:
                cout << "Dictionary in ascending order:\n";
                displayAscending(root);
                break;
            case 5:
                cout << "Dictionary in descending order:\n";
                displayDescending(root);
                break;
            case 6:
                cout << "Enter the keyword to search: ";
                cin >> keyword;
                comparisons = findMaxComparisons(root, keyword, 0);
                cout << "Maximum comparisons required: " << comparisons << endl;
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

        cout << endl;
    } while (choice != 7);

    return 0;
}
