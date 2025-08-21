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

SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* curr = head;
    while (curr != nullptr) {
        SinglyLinkedListNode* nextNode = curr->next; // save next
        curr->next = prev; // reverse pointer
        prev = curr;       // move prev
        curr = nextNode;   // move curr
    }
    return prev; // new head
}

// Helper function to print list
void printList(SinglyLinkedListNode* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        SinglyLinkedListNode* head = nullptr;
        SinglyLinkedListNode* tail = nullptr;

        for (int i = 0; i < n; i++) {
            int val; cin >> val;
            SinglyLinkedListNode* newNode = new SinglyLinkedListNode(val);
            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        head = reverse(head);
        printList(head);
    }
    return 0;
}
