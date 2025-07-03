#include <bits/stdc++.h>
using namespace std;

// Node class
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

// Traversal function
void traversal(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Convert array to linked list
Node* arrtoLL(vector<int> arr) {
    if (arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

// Delete nth node from end
Node* deletefromend(Node* head, int n) {
    Node* temp = head;
    int count = 0;

    // Count total nodes
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // If head needs to be deleted
    if (n == count) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    // Move to (count - n - 1)th node
    temp = head;
    for (int i = 1; i < count - n; i++) {
        temp = temp->next;
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;

    return head;
}

// Main function
int main() {
    vector<int> arr = {2, 1, 4, 3, 6, 8, 6};
    Node* head = arrtoLL(arr);

    cout << "Original Linked List" << endl;
    traversal(head);

    cout << "After deleting 2nd node from end" << endl;
    head = deletefromend(head, 2);
    traversal(head);

    return 0;
}
