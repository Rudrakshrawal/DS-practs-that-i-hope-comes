#include <iostream>
using namespace std;

// Node structure for the stack
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Stack ADT using Linked List
class Stack {
private:
    Node* top; // Points to the top of the stack

public:
    // Constructor
    Stack() : top(nullptr) {}

    // Method to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Method to push a value onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    // Method to pop a value from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop from an empty stack." << endl;
            return -1;
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    // Method to peek at the top of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty! Nothing to peek." << endl;
            return -1;
        }
        return top->data;
    }

    // Method to display the stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to clean up memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack stack;

    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Display stack elements
    stack.display();

    // Peek the top element
    cout << "Top element is: " << stack.peek() << endl;

    // Pop elements from the stack
    cout << "Popped: " << stack.pop() << endl;
    cout << "Popped: " << stack.pop() << endl;

    // Display stack elements after popping
    stack.display();

    // Pop from an empty stack
    stack.pop();

    return 0;
}