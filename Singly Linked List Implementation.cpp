#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void insertEnd(int val) {
        Node* n = new Node(val);
        if (!head) { head = n; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }

    void deleteNode(int val) {
        if (!head) return;
        if (head->data == val) {
            Node* t = head;
            head = head->next;
            delete t;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != val)
            temp = temp->next;
        if (temp->next) {
            Node* t = temp->next;
            temp->next = temp->next->next;
            delete t;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int ch, val;
    do {
        cout << "\n1.Insert 2.Delete 3.Display 4.Exit: ";
        cin >> ch;
        if (ch == 1) {
            cout << "Enter value: ";
            cin >> val;
            list.insertEnd(val);
        } else if (ch == 2) {
            cout << "Enter value to delete: ";
            cin >> val;
            list.deleteNode(val);
        } else if (ch == 3)
            list.display();
    } while (ch != 4);
}
