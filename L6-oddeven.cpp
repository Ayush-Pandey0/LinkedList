#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void traversal(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* arrtoLL(vector<int> arr) {
    if (arr.size() == 1) return new Node(arr[0]);
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

// ✅ Method 1: Your original method - rearrange nodes in place
Node* oddeven(Node* head) {
    if (!head || !head->next) return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenStart = even;

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenStart;
    return head;
}

// ✅ Method 2: Create two separate lists for odd and even positions
/*
Node* oddeven(Node* head) {
    if (!head || !head->next) return head;

    Node* oddHead = nullptr, *oddTail = nullptr;
    Node* evenHead = nullptr, *evenTail = nullptr;
    Node* temp = head;
    int pos = 1;

    while (temp) {
        if (pos % 2 == 1) {
            if (!oddHead) {
                oddHead = oddTail = temp;
            } else {
                oddTail->next = temp;
                oddTail = temp;
            }
        } else {
            if (!evenHead) {
                evenHead = evenTail = temp;
            } else {
                evenTail->next = temp;
                evenTail = temp;
            }
        }
        temp = temp->next;
        pos++;
    }
    if (oddTail) oddTail->next = evenHead;
    if (evenTail) evenTail->next = nullptr;
    return oddHead;
}
*/

// ✅ Method 3: Collect odd and even values separately, then reassign node values
/*
Node* oddeven(Node* head) {
    if (!head || !head->next) return head;

    vector<int> oddVals, evenVals;
    Node* temp = head;
    int pos = 1;
    while (temp) {
        if (pos % 2 == 1)
            oddVals.push_back(temp->data);
        else
            evenVals.push_back(temp->data);
        temp = temp->next;
        pos++;
    }

    temp = head;
    for (int val : oddVals) {
        temp->data = val;
        temp = temp->next;
    }
    for (int val : evenVals) {
        temp->data = val;
        temp = temp->next;
    }
    return head;
}
*/

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    Node* head = arrtoLL(arr);
    cout << "Original Linked List" << endl;
    traversal(head);
    cout << endl;

    cout << "After changing LL" << endl;
    oddeven(head); // use the version you want by uncommenting above
    traversal(head);
}
