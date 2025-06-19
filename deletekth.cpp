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
    cout << endl;
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

Node* deletekth(Node* head, int d) {
    if (head == NULL) return NULL;

    if (d == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    int cnt = 1;

    while (temp != NULL && cnt < d - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL || temp->next == NULL) return head;

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;

    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    Node* head = arrtoLL(arr);

    cout << "Original List: ";
    traversal(head);

    head = deletekth(head, 3);  // Delete 3rd node (value 3)

    cout << "After deleting 3rd node: ";
    traversal(head);

    return 0;
}
