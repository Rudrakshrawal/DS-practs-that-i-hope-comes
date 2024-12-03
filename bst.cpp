#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary Search Tree ADT
class BST {
private:
    Node* root;

    // Helper function for insertion
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Helper function for searching
    bool search(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == value) {
            return true;
        }
        if (value < node->data) {
            return search(node->left, value);
        }
        return search(node->right, value);
    }

    // Helper function for inorder traversal
    void inorder(Node* node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() : root(nullptr) {}

    // Public method to insert a value
    void insert(int value) {
        root = insert(root, value);
    }

    // Public method to search for a value
    bool search(int value) {
        return search(root, value);
    }

    // Public method to perform inorder traversal
    void inorderTraversal() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    // Insert values
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Search for a value
    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 90: " << (tree.search(90) ? "Found" : "Not Found") << endl;

    // Inorder traversal
    cout << "Inorder Traversal: ";
    tree.inorderTraversal();

    return 0;
}