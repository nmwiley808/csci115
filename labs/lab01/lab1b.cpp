#include <iostream>
using namespace std;

//Define the Node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node*& head, int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << ", ";
        }
        temp = temp->next;
    }
    cout << endl;
}

// Function to delete the first element of the linked list
void deleteFirst(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Function to delete the last element of the linked list
void deleteLast(Node*& head){
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

int main() {
    Node* head = nullptr; // Initialize the linked list

    // Insert elements at the beginning
    insertAtBeginning(head, 60);
    insertAtBeginning(head, 40);
    insertAtBeginning(head, 20);

    // Print the linked list
    cout << "Items in the linked list: ";
    printLinkedList(head);

    // Delete the first element and print the linked list
    deleteFirst(head);
    cout << "Items in the linked list after deleting the first element: ";
    printLinkedList(head);

    // Delete the last element and print the linked list
    deleteLast(head);
    cout << "Items in the linked list after deleting the last element: ";
    printLinkedList(head);

    return 0;
}

