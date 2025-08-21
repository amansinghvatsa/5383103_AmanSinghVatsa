#include <iostream>
#include <vector>
using namespace std;

class DoublyLinkedListNode {
public:
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;
    DoublyLinkedListNode(int node_data) {
        data = node_data;
        next = nullptr;
        prev = nullptr;
    }
};

DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    if (!head) return nullptr;

    DoublyLinkedListNode* curr = head;
    DoublyLinkedListNode* temp = nullptr;

    while (curr != nullptr) {
        // Swap next and prev
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        // Move to next node (which is curr->prev after swap)
        curr = curr->prev;
    }

    // After the loop, temp points to the node before NULL
    if (temp != nullptr) {
        head = temp->prev;
    }
    return head;
}

// Helper: print doubly linked list
void printList(DoublyLinkedListNode* head) {
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
        DoublyLinkedListNode* head = nullptr;
        DoublyLinkedListNode* tail = nullptr;

        for (int i = 0; i < n; i++) {
            int val; cin >> val;
            DoublyLinkedListNode* newNode = new DoublyLinkedListNode(val);
            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        head = reverse(head);
        printList(head);
    }
    return 0;
}
