//Linked List: All Operations by Adit Ghosh 2401350016
//Date: 17 September 2025

#include<iostream>
#include<string>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void displayList(Node* head) {
    Node* temp = head;
    cout << "Linked List: Start-> ";
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) { 
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}


Node* createLinkedList(int n) {
    if(n<=0) return nullptr;

    Node* head = new Node();
    Node* temp = head;
    
    for(int i=0; i<n; i++) {
        cout << "Enter data for node " << i+1 << ": ";
        cin >> temp->data;
        if(i != n-1) {
            temp->next = new Node();
            temp = temp->next;
        } else {
            temp->next = nullptr;
        }
    }
    
    return head;

    

}

void insertAtBeginning(Node* &head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node* &head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(Node* &head, int newData, int pos) {
    Node* newNode = new Node();
    newNode->data = newData;

    if (pos <= 1 || head == nullptr) { 
        cout << "Inserting at the beginning.\n";
        insertAtBeginning(head, newData);
        return;  // Important: return here after inserting
    }

    Node* temp = head;
    for (int i = 1; temp != nullptr && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) { 
        cout << "Position out of range, inserting at end.\n";
        insertAtEnd(head, newData);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteFromBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted: " << temp->data << endl;
    delete temp;
}

void deleteFromEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }
    if (head->next == nullptr) { // Only one node
        cout << "Deleted: " << head->data << endl;
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    cout << "Deleted: " << temp->next->data << endl;
    delete temp->next;
    temp->next = nullptr;
}

void deleteFromPosition(Node*& head, int pos) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }
    if (pos <= 1) { // Delete first node
        deleteFromBeginning(head);
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != nullptr && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position out of range.\n";
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    cout << "Deleted: " << nodeToDelete->data << endl;
    delete nodeToDelete;
}


void mainmenu(){
    int nodeNumber;
    int val, pos, choice;
    string any, reuse;

    Node* head = nullptr;

    do {
        if (head == nullptr) {
            cout << "Enter the number of nodes: ";
            cin >> nodeNumber;
            head = createLinkedList(nodeNumber);
            displayList(head);
        }

        cout << "\nMenu:" << endl;
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert at position" << endl;
        cout << "4. Delete from beginning" << endl;
        cout << "5. Delete from end" << endl;
        cout << "6. Delete from position" << endl;
        cout << "7. Display list" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to enter: ";
            cin >> val;
            insertAtBeginning(head, val);
            displayList(head);
            break;
        case 2:
            cout << "Enter the value to enter: ";
            cin >> val;
            insertAtEnd(head, val);
            displayList(head);
            break;
        case 3:
            cout << "Enter the value to enter: ";
            cin >> val;
            cout << "Enter the position for the node: ";
            cin >> pos;
            insertAtPosition(head, val, pos);
            displayList(head);
            break;
        case 4:
            deleteFromBeginning(head);
            displayList(head);
            break;
        case 5:
            deleteFromEnd(head);
            displayList(head);
            break;
        case 6:
            cout << "Enter the position for the node: ";
            cin >> pos;
            deleteFromPosition(head, pos);
            displayList(head);
            break;
        case 7:
            displayList(head);
            break;
        case 8:
            return; // Exit the function
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }

        cout << "Do you want to reuse the current list? (Y/N): ";
        cin >> reuse;
        if (reuse != "Y" && reuse != "y") {
            // Free the current list
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            head = nullptr;
        }

        cout << "Press 'Y' to continue, any other key to exit: ";
        cin >> any;
    } while (any == "Y" || any == "y");
}

int main(){
  
    mainmenu();

    return 0;
}