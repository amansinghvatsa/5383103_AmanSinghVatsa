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

// Merge two sorted linked lists
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* headA, SinglyLinkedListNode* headB) {
    if (!headA) return headB;
    if (!headB) return headA;

    SinglyLinkedListNode dummy(0);  // dummy node
    SinglyLinkedListNode* tail = &dummy;

    while (headA && headB) {
        if (headA->data <= headB->data) {
            tail->next = headA;
            headA = headA->next;
        } else {
            tail->next = headB;
            headB = headB->next;
        }
        tail = tail->next;
    }

    // Append remaining nodes
    if (headA) tail->next = headA;
    else tail->next = headB;

    return dummy.next;
}

// Helper: print linked list
void printList(SinglyLinkedListNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n1, n2, val;

        cin >> n1;
        SinglyLinkedListNode* headA = nullptr;
        SinglyLinkedListNode* tailA = nullptr;
        for (int i = 0; i < n1; i++) {
            cin >> val;
            SinglyLinkedListNode* newNode = new SinglyLinkedListNode(val);
            if (!headA) {
                headA = newNode;
                tailA = newNode;
            } else {
                tailA->next = newNode;
                tailA = newNode;
            }
        }

        cin >> n2;
        SinglyLinkedListNode* headB = nullptr;
        SinglyLinkedListNode* tailB = nullptr;
        for (int i = 0; i < n2; i++) {
            cin >> val;
            SinglyLinkedListNode* newNode = new SinglyLinkedListNode(val);
            if (!headB) {
                headB = newNode;
                tailB = newNode;
            } else {
                tailB->next = newNode;
                tailB = newNode;
            }
        }

        SinglyLinkedListNode* mergedHead = mergeLists(headA, headB);
        printList(mergedHead);
    }
    return 0;
}
