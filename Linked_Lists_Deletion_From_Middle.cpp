//Linked List: Deletion from middle by Adit Ghosh 2401350016
//Date: 24 September 2025

#include <iostream>
#include <String>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void createList(Node*& head, int n) {
    if (n <= 0) {
        head = nullptr;
        cout << "No nodes to create." << endl;
        return;
    }

    head = new Node();
    cout << "Enter data for node 0: ";
    cin >> head->data;
    head->next = nullptr;
    Node* last = head;

    for (int i = 1; i < n; ++i) {
        Node* newNode = new Node();
        cout << "Enter data for node " << i << ": ";
        cin >> newNode->data;
        newNode->next = nullptr;
        last->next = newNode;
        last = newNode;
    }
}

int display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return 0;
    }
    cout << "Linked List: ";
    Node* temp = head;
    int count = 0;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
        count++;
    }
    cout << "NULL" << endl;
    return count;
}

void deleteMiddle(Node*& head) {
    int totalNodes = 0;
    Node* temp = head;
    while (temp != nullptr) {
        totalNodes++;
        temp = temp->next;
    }

    if (totalNodes == 0) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }
    if (totalNodes <= 2) {
        cout << "List has 2 or fewer nodes. Deletion from the middle is not applicable." << endl;
        return;
    }
    
    int middlePosition = (totalNodes - 1) / 2;

    Node* current = head;
    Node* previous = nullptr;
    int currentIndex = 0;

    while (current != nullptr && currentIndex < middlePosition) {
        previous = current;
        current = current->next;
        currentIndex++;
    }

    if (current == nullptr) {
        cout << "Error: Middle node not found." << endl;
    } else {
        if (previous == nullptr) { 
            head = head->next;
        } else {
            previous->next = current->next;
        }
        cout << "Node at index " << middlePosition << " with data " << current->data << " deleted." << endl;
        delete current;
    }
}

int main() {
    Node* head = nullptr;
    int numNodes;

    cout << "Enter the number of nodes to create: ";
    cin >> numNodes;

    createList(head, numNodes);
    
    int totalNodes = display(head);
    cout << "Total nodes: " << totalNodes << endl;
    
    deleteMiddle(head);
    display(head);
    
    Node* current = head;
    while(current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}



