//Linked List: Linear Search by Adit Ghosh 2401350016
//Date: 24 September 2025

#include <iostream>
#include <cstdlib>
#include <String>
using namespace std;

struct node {
    int data;
    struct node *next;
};

void displayList(struct node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    struct node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void linearSearch(struct node* head, int key) {
    struct node* current = head;
    int position = 0;
    bool found = false;

    while (current != NULL) {
        if (current->data == key) {
            cout << "Element " << key << " found at position " << position + 1 << "." << endl;
            found = true;
            break;
        }
        current = current->next;
        position++;
    }

    if (!found) {
        cout << "Element " << key << " not found in the list." << endl;
    }
}

int main() {
    struct node *head = NULL;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    one = (struct node*)malloc(sizeof(struct node));
    two = (struct node*)malloc(sizeof(struct node));
    three = (struct node*)malloc(sizeof(struct node));

    one->data = 10;
    two->data = 20;
    three->data = 30;

    one->next = two;
    two->next = three;
    three->next = NULL;

    head = one;
    
    displayList(head);
    
    int searchKey;
    cout << "Enter the element to search for: ";
    cin >> searchKey;
    
    linearSearch(head, searchKey);

    return 0;
}


