//Linked List: Instertion From Beggining by Adit Ghosh 2401350016
//Date: 10 September 2025

#include<iostream>
#include<cstdlib>
#include<String>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void insertbeginning(node* &head, int val){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

int main(){
    /* Initialize nodes */
    struct node *head;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    /* Allocate memory */
    one = (struct node*)malloc(sizeof(struct node));
    two = (struct node*)malloc(sizeof(struct node));
    three = (struct node*)malloc(sizeof(struct node));

    /* Assign data values */
    one->data = 1;
    two->data = 2;
    three->data=3;

    /* Connect nodes */
    one->next = two;
    two->next = three;
    three->next = NULL;

    /* Save address of first node in head */
    head = one;

    struct node* temp = head;
    
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    
    
    insertbeginning(head, 23);
    cout<<"Inserting 23 at the beginning"<<endl;
    temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;



    return 0;
}




