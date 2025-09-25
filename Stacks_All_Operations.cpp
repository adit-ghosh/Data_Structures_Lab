//Stacks: All Operations (Arrays + Linked List) by Adit Ghosh 2401350016
//Date: 24 September 2025

#include <iostream>
#include <String>
using namespace std;

struct Node {
    int data;
    Node* next;
};

const int MAX_SIZE = 100;
int arrStack[MAX_SIZE];
int topArr = -1;

void initializeArrayStack() {
    int elements[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; ++i) {
        if (topArr < MAX_SIZE - 1) {
            arrStack[++topArr] = elements[i];
        }
    }
}

void arrayStack() {
    initializeArrayStack();
    int choice, data;

    do {
        cout << "\n--- Array Stack Menu ---" << endl;
        if (topArr >= 0) {
            cout << "Stack: ";
            for (int i = topArr; i >= 0; i--) {
                cout << arrStack[i] << " ";
            }
            cout << "(top)" << endl;
        } else {
            cout << "Stack: empty" << endl;
        }

        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (topArr >= MAX_SIZE - 1) {
                    cout << "Stack Overflow! Cannot push more elements." << endl;
                } else {
                    cout << "Enter value to push: ";
                    cin >> data;
                    arrStack[++topArr] = data;
                    cout << data << " pushed to stack." << endl;
                }
                break;
            case 2:
                if (topArr < 0) {
                    cout << "Stack Underflow! Cannot pop from empty stack." << endl;
                } else {
                    data = arrStack[topArr--];
                    cout << data << " popped from stack." << endl;
                }
                break;
            case 3:
                if (topArr < 0) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Top element is: " << arrStack[topArr] << endl;
                }
                break;
            case 4:
                if (topArr < 0) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack elements: ";
                    for (int i = topArr; i >= 0; i--) {
                        cout << arrStack[i] << " ";
                    }
                    cout << endl;
                }
                break;
            case 5:
                cout << "Exiting Array Stack menu." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
}

Node* head = nullptr;

void initializeLinkedListStack() {
    int elements[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; ++i) {
        Node* newNode = new Node{elements[i], head};
        head = newNode;
    }
}

void linkedListStack() {
    initializeLinkedListStack();
    int choice, data;

    do {
        cout << "\n--- Linked List Stack Menu ---" << endl;
        if (head != nullptr) {
            cout << "Stack: ";
            Node* current = head;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << "(top)" << endl;
        } else {
            cout << "Stack: empty" << endl;
        }
        
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { 
                cout << "Enter value to push: ";
                cin >> data;
                Node* newNode = new Node{data, head};
                head = newNode;
                cout << data << " pushed to stack." << endl;
                break;
            }
            case 2: { 
                if (head == nullptr) {
                    cout << "Stack Underflow! Cannot pop from empty stack." << endl;
                } else {
                    Node* temp = head;
                    data = temp->data;
                    head = head->next;
                    delete temp;
                    cout << data << " popped from stack." << endl;
                }
                break;
            }
            case 3:
                if (head == nullptr) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Top element is: " << head->data << endl;
                }
                break;
            case 4:
                if (head == nullptr) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack elements: ";
                    Node* current = head;
                    while (current != nullptr) {
                        cout << current->data << " ";
                        current = current->next;
                    }
                    cout << endl;
                }
                break;
            case 5:
                cout << "Exiting Linked List Stack menu." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
}

int main() {
    int methodChoice;
    cout << "Choose a stack implementation method:" << endl;
    cout << "1. Array Method" << endl;
    cout << "2. Linked List Method" << endl;
    cout << "Enter your choice: ";
    cin >> methodChoice;

    if (methodChoice == 1) {
        arrayStack();
    } else if (methodChoice == 2) {
        linkedListStack();
    } else {
        cout << "Invalid choice. Exiting." << endl;
    }

    return 0;
}