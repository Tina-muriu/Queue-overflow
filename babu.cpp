#include <iostream>
#define size 50
using namespace std;

class Queue {
    int front, rear;
    int array[size];
public:
    Queue() {
        front = rear = -1;
    }

    void enqueue(int item) {
        if (rear == size - 1) {
            cout << "Queue overflow" << endl;
            return;
        } else {
            if (rear == -1) {
                // Inserting for the first time
                rear++;
                front++;
                array[rear] = item;
            } else {
                // Inserting afterwards
                rear++;
                array[rear] = item;
            }
        }
    }

    int dequeue() {
        if (front == -1 && rear == -1) {
            cout << "Queue underflow" << endl;
            return 0;
        } else if (front == rear) {
            int data = array[front];
            front = -1;
            rear = -1;
            return data;
        } else {
            int data = array[front];
            front = front + 1;
            return data;
        }
    }

    void display() {
        while (front != -1 && front <= rear) {
            cout << dequeue() << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int i, n, item;
    cout << "How many items? ";
    cin >> n;
    cout << "Enter values: ";
    for (i = 0; i < n; i++) {
        cin >> item;
        q.enqueue(item);
    }
    cout << "Queue contents: ";
    q.display();
    return 0;
}

