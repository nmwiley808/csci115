#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class Node {
public:
    explicit Node(int data) {
        this->data = data;
        this->LeftChild = nullptr;
        this->RightChild = nullptr;
    }
    int data;
    Node* LeftChild;
    Node* RightChild;
};

class BST {
private:
    Node* root;

    static Node* InsertNode(Node* node, int data);

    static bool FindNode(const Node* node, int data);

    static int Largest(const Node* node);

    static void printTree(const Node* node);

public:
    BST();                              // Constructor
    Node* getRoot() const;              // Getter for root
    void Insert(int data);              // Public insert
    void PrintPostOrder() const;              // Public post-order printer
    void Find(int data) const;                // Public search/lookup
    void PrintLargest() const;                // Public largest value printer
};

// Constructor
inline BST::BST() {
    root = nullptr;
}

// Getter
inline Node* BST::getRoot() const {
    return this->root;
}

// Public insert (uses private InsertNode and updates root)
inline void BST::Insert(int data) {
    root = InsertNode(root, data);
}

// Private recursive insert
inline Node *BST::InsertNode(Node *node, int data) {
    if (node == nullptr) {
        return new Node(data);
    }
    if (data < node->data) {
        node->LeftChild = InsertNode(node->LeftChild, data);
    } else if (data > node->data) {
        node->RightChild = InsertNode(node->RightChild, data);
    }
    // Duplicate values are ignored
    return node;
}

// Public post-order printer
inline void BST::PrintPostOrder() const {
    printTree(root);
}

// Private post-order traversal
inline auto BST::printTree(const Node *node) -> void {
    if (node == nullptr) return;
    printTree(node->LeftChild);
    printTree(node->RightChild);
    cout << node->data << " ";
}

// Public search with output
inline void BST::Find(int data) const {
    if (FindNode(root, data)) {
        cout << data << endl;
    } else {
        cout << data << " is not a member of the list/ " << data << " not found" << endl;
    }
}

// Private recursive search
inline bool BST::FindNode(const Node* node, int data) {
    if (node == nullptr) return false;
    if (node->data == data) return true;
    if (data < node->data) return FindNode(node->LeftChild, data);
    return FindNode(node->RightChild, data);
}

// Public method to print the largest value
inline void BST::PrintLargest() const {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
    } else {
        cout << "Largest element in the list is: " << Largest(root) << endl;
    }
}

// Private recursive method to find the largest value
inline int BST::Largest(const Node* node) {
    while (node->RightChild != nullptr) {
        node = node->RightChild;
    }
    return node->data;
}

#endif //LIST_H
