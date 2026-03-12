#include <iostream>
using namespace std;

class Stack {
 private:
     int arr[10]; // Array to store stack elements
     int top; // Index of the top element
     int capacity; // Maximum size of the stack

 public:
     // Constructor to initialize the stack
     Stack() {
         top = -1; // Stack is empty
         capacity = 10; // Maximum size of the stack
     }

     // Push Operation
     void push(int value) {
         if (top == capacity - 1) {
             cout << "Stack Overflow! Cannot Push" << value << "\n";
         } else {
             arr[++top] = value; // The increment top and insert value
         }
     }

     // Pop Operation
     int pop() {
         if (top == -1) {
             cout << "Stack Underflow!\n";
             return -1; // Return the sentinel value to indicate error
         } else {
             return arr[top--]; // Return the top element and decrement top
         }
     }

     // Peek Operation
     int peek() {
         if (top == -1) {
             cout << "Stack is empty!\n";
             return -1; // Return a sentinel value to indicate error
         } else {
             return arr[top]; // Return the top element
         }
     }

     // Print the stack
     void printStack() {
         if (top == -1) {
             cout << "Stack is empty!\n";
         } else {
             cout << "Items in the stack: ";
             for (int i = top; i >= 0; i--) {
                 cout << arr[i];
                 if (i > 0) cout << ", ";
             }
             cout << "\n";
         }
     }
 };

int main() {
    Stack stack;

    // Push the elements into the stack
    stack.push(20);
    stack.push(40);
    stack.push(60);

    // Print the stack
    stack.printStack();

    // Pop an element and print it
    int poppedItem = stack.pop();
    cout << "Popped item is: " << poppedItem << "\n";

    // Peek the stack and print the top-most element
    int peekedItem = stack.peek();
    cout << "Peeked item is: " << peekedItem << "\n";

    // Print the stack again
    stack.printStack();

    return 0;
}
