#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node
class Node {
public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = nullptr;
    }
};

// Function to add two linked lists
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* current = dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr ) {
        int sum = carry;

        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        current->next = new Node(sum % 10);
        current = current->next;
    }

    return dummy->next;
}

// Utility function to print linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to create linked list from vector
Node* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;

    Node* head = new Node(nums[0]);
    Node* current = head;
    for (int i = 1; i < nums.size(); ++i) {
        current->next = new Node(nums[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Example: 342 + 465 = 807
    vector<int> num1 = {2, 4, 3}; // Represents 342
    vector<int> num2 = {5, 6, 4}; // Represents 465

    Node* l1 = createList(num1);
    Node* l2 = createList(num2);

    Node* result = addTwoNumbers(l1, l2);

    cout << "Sum: ";
    printList(result);  // Output: 7 0 8

    return 0;
}
