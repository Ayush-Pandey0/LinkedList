#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data, Node* next = nullptr, Node* prev = nullptr) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

// Function to traverse and print the doubly linked list
void traversal(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Convert array to doubly linked list
Node* arrtoDLL(vector<int> arr) {
    if (arr.size() == 0) return nullptr;
    if (arr.size() == 1) return new Node(arr[0]);

    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

// Function to delete the Kth node of the doubly linked list
Node* deleteKthDLL(Node* head,int d) {
    if (head == nullptr || head->next == nullptr|| d==0) {
        delete head;
        return nullptr;
    }

    int count=1;
    

    return head;
}

// Main function
int main() {
    vector<int> arr = {1, 2, 3, 4};

    Node* head = arrtoDLL(arr);

    cout << "Original List: ";
    traversal(head);

    head = deleteKthDLL(head,3);

    cout << "After Deleting Tail: ";
    traversal(head);

    return 0;
}
