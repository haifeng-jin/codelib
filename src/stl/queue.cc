#include <iostream>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

void demo_queue() {
    queue<int> q;

    // Enqueue elements
    q.push(1);
    q.push(2);
    q.push(3);

    // Print and dequeue elements
    cout << "Queue: ";
    while (!q.empty()) {
        cout << q.front() << " "; // Access the front element
        q.pop(); // Dequeue the front element
    }
    cout << endl;
}

void demo_deque() {
    deque<int> dq;

    // Insert elements at both ends
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(0);
    dq.push_back(3);

    // Print elements
    cout << "Deque: ";
    for (int elem : dq) {
        cout << elem << " ";
    }
    cout << endl;

    // Remove elements from both ends
    dq.pop_front();
    dq.pop_back();

    // Print elements after popping
    cout << "Deque after popping: ";
    for (int elem : dq) {
        cout << elem << " ";
    }
    cout << endl;
}


void demo_priority_queue() {
    priority_queue<int> pq;

    // Insert elements
    pq.push(3);
    pq.push(1);
    pq.push(4);
    pq.push(2);

    // Print and remove elements
    cout << "Priority Queue: ";
    while (!pq.empty()) {
        cout << pq.top() << " "; // Access the top element
        pq.pop(); // Remove the top element
    }
    cout << endl;
}

void demo_stack() {
    stack<int> s;

    // Push elements onto the stack
    s.push(1);
    s.push(2);
    s.push(3);

    // Print and pop elements
    cout << "Stack: ";
    while (!s.empty()) {
        cout << s.top() << " "; // Access the top element
        s.pop(); // Pop the top element
    }
    cout << endl;
}

int main() {
    demo_queue();
    demo_deque();
    demo_priority_queue();
    demo_stack();
    return 0;
}