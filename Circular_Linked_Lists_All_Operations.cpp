//Circular Linked List: All Operations by Adit Ghosh 2401350016
//Date: 24 September 2025

#include <iostream>
#include<String>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

Node* createCircularList(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void initializeList(int elements[], int n, Node*& head) {
    if (n <= 0) {
        head = nullptr;
        return;
    }
    head = createCircularList(elements[0]);
    Node* current = head;
    for (int i = 1; i < n; i++) {
        current->next = createCircularList(elements[i]);
        current = current->next;
    }
    current->next = head;
}

void displayCircularList(Node* head) {
    if (head == nullptr) {
        cout << "Circular Linked List is empty." << endl;
        return;
    }
    Node* current = head;
    cout << "Circular Linked List: ";
    do {
        cout << current->data;
        current = current->next;
        if (current != head) {
            cout << " -> ";
        }
    } while (current != head);
    cout << " -> (head)" << endl;
}

void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = createCircularList(newData);
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        cout << newData << " inserted at the beginning." << endl;
        return;
    }
    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    newNode->next = head;
    last->next = newNode;
    head = newNode;
    cout << newData << " inserted at the beginning." << endl;
}

void insertAtEnd(Node*& head, int newData) {
    Node* newNode = createCircularList(newData);
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        cout << newData << " inserted at the end." << endl;
        return;
    }
    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    last->next = newNode;
    newNode->next = head;
    cout << newData << " inserted at the end." << endl;
}

void insertAtPosition(Node*& head, int newData, int pos) {
    if (pos <= 1) {
        insertAtBeginning(head, newData);
        return;
    }
    Node* newNode = createCircularList(newData);
    Node* current = head;
    for (int i = 1; i < pos - 1; i++) {
        if (current->next == head) {
            cout << "Position out of bounds. Inserting at the end." << endl;
            insertAtEnd(head, newData);
            return;
        }
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    cout << newData << " inserted at position " << pos << "." << endl;
}

void deleteFromBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }
    Node* temp = head;
    if (head->next == head) {
        head = nullptr;
    } else {
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
    }
    cout << temp->data << " deleted from the beginning." << endl;
    delete temp;
}

void deleteFromEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }
    if (head->next == head) {
        cout << head->data << " deleted from the end." << endl;
        delete head;
        head = nullptr;
        return;
    }
    Node* current = head;
    while (current->next->next != head) {
        current = current->next;
    }
    Node* temp = current->next;
    current->next = head;
    cout << temp->data << " deleted from the end." << endl;
    delete temp;
}

void deleteFromPosition(Node*& head, int pos) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }
    if (pos <= 1) {
        deleteFromBeginning(head);
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    for (int i = 1; i < pos; i++) {
        if (temp->next == head) {
            cout << "Position out of bounds. Deletion failed." << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    cout << temp->data << " deleted at position " << pos << "." << endl;
    delete temp;
}

void mainMenu() {
    int elements[] = {10, 20, 30, 40, 50};
    int n = sizeof(elements) / sizeof(elements[0]);
    Node* head = nullptr;

    initializeList(elements, n, head);
    
    int data, position, choice;
    string any_key;

    do {
        cout << "\n--- Circular Linked List Menu ---" << endl;
        displayCircularList(head);
        cout << "\n1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert at Specific Position" << endl;
        cout << "4. Delete at Beginning" << endl;
        cout << "5. Delete at End" << endl;
        cout << "6. Delete at Specific Position" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                insertAtBeginning(head, data);
                break;
            case 2:
                cout << "Enter data to insert: ";
                cin >> data;
                insertAtEnd(head, data);
                break;
            case 3:
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position: ";
                cin >> position;
                insertAtPosition(head, data, position);
                break;
            case 4:
                deleteFromBeginning(head);
                break;
            case 5:
                deleteFromEnd(head);
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                deleteFromPosition(head, position);
                break;
            case 7:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 7);

    Node* current = head;
    if (current != nullptr) {
        Node* next_node;
        do {
            next_node = current->next;
            delete current;
            current = next_node;
        } while (current != head);
    }
}

int main() {
    mainMenu();
    return 0;
}