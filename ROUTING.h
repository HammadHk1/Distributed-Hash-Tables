#pragma once
#include<iostream>
using namespace std;
struct Doubly_Node {
    int p, i;
    Doubly_Node* next;
    Doubly_Node* previous;
    Doubly_Node() {
        p = i = 0;
        next = previous = NULL;
    }
};
class FT {
public:
    Doubly_Node* head;
    FT() {
        head = NULL;
    }
    void Insert_to_FT(int p, int i) {
        Doubly_Node* temp = new Doubly_Node;
        temp->p = p;
        temp->i = i;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            temp->previous = NULL;
        }
        else {
            Doubly_Node* temp1 = NULL;
            temp1 = head;
            while (temp1->next != NULL) {
                temp1 = temp1->next;
            }
            temp1->next = temp;
        }
    }
    void display()
    {
        Doubly_Node* temp;
        temp = head;
        while (temp != NULL) {
            cout << "(" << temp->p << "," << temp->i << ")" << endl;

            temp = temp->next;
        }
    }
    void Delete() {

    }
};
