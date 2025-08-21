#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> stack_in, stack_out;

    // Helper function to shift elements when needed
    void transfer() {
        while (!stack_in.empty()) {
            stack_out.push(stack_in.top());
            stack_in.pop();
        }
    }

public:
    // Enqueue operation
    void enqueue(int x) {
        stack_in.push(x);
    }

    // Dequeue operation
    void dequeue() {
        if (stack_out.empty()) {
            transfer();
        }
        if (!stack_out.empty()) {
            stack_out.pop();
        }
    }

    // Peek front element
    int front() {
        if (stack_out.empty()) {
            transfer();
        }
        return stack_out.top();
    }
};

int main() {
    int q;
    cin >> q;

    Queue myQueue;
    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            myQueue.enqueue(x);
        } else if (type == 2) {
            myQueue.dequeue();
        } else if (type == 3) {
            cout << myQueue.front() << endl;
        }
    }
    return 0;
}
