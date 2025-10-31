#include <iostream>
using namespace std;

#define SIZE 5

class Stack {
    int arr[SIZE], top;
public:
    Stack() : top(-1) {}
    void push(int val) {
        if (top == SIZE-1) cout << "Stack Overflow\n";
        else arr[++top] = val;
    }
    void pop() {
        if (top == -1) cout << "Stack Underflow\n";
        else cout << "Popped: " << arr[top--] << endl;
    }
    void display() {
        for (int i = top; i >= 0; i--) cout << arr[i] << " ";
        cout << endl;
    }
};

class Queue {
    int arr[SIZE], front, rear;
public:
    Queue() : front(-1), rear(-1) {}
    void enqueue(int val) {
        if (rear == SIZE-1) cout << "Queue Full\n";
        else {
            if (front == -1) front = 0;
            arr[++rear] = val;
        }
    }
    void dequeue() {
        if (front == -1 || front > rear) cout << "Queue Empty\n";
        else cout << "Dequeued: " << arr[front++] << endl;
    }
    void display() {
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;
    Queue q;
    int ch, val;
    do {
        cout << "\n1.Push 2.Pop 3.Display Stack\n4.Enqueue 5.Dequeue 6.Display Queue 7.Exit\nChoice: ";
        cin >> ch;
        if (ch == 1) { cout << "Enter: "; cin >> val; s.push(val); }
        else if (ch == 2) s.pop();
        else if (ch == 3) s.display();
        else if (ch == 4) { cout << "Enter: "; cin >> val; q.enqueue(val); }
        else if (ch == 5) q.dequeue();
        else if (ch == 6) q.display();
    } while (ch != 7);
}
