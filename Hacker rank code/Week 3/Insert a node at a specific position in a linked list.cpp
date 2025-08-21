#include <iostream>
#include <vector>
using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;
    SinglyLinkedListNode(int node_data) {
        data = node_data;
        next = nullptr;
    }
};

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);

    // Case 1: insert at head
    if (position == 0) {
        newNode->next = head;
        return newNode;
    }

    // Case 2: insert at given position
    SinglyLinkedListNode* curr = head;
    for (int i = 0; i < position - 1 && curr != nullptr; i++) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

// Helper to print the list
void printList(SinglyLinkedListNode* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n; cin >> n;
    SinglyLinkedListNode* head = nullptr;
    SinglyLinkedListNode* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        SinglyLinkedListNode* node = new SinglyLinkedListNode(val);
        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    int data, pos;
    cin >> data >> pos;

    head = insertNodeAtPosition(head, data, pos);
    printList(head);

    return 0;
}
