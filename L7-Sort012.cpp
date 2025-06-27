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

Node* Sort012(Node* head) {
    if (!head || !head->next) return head;
   Node* temp=head;
   int c0 = 0, c1 = 0, c2 = 0;

   while(temp!=NULL){
        if(temp->data==0){
            c0++;
        }
        if(temp->data==1){
            c1++;
        }
        if(temp->data==2){
            c2++;
        }
        temp=temp->next;
   }
   temp=head;
   while(temp!=NULL){
        if(c0>0){
            temp->data=0;
            temp=temp->next;
            c0--;
            continue;
        }
        else if(c1>0){
            temp->data=1;
            temp=temp->next;
            c1--;
            continue;
        }
        else{
            temp->data=2;
            temp=temp->next;
            c2--;
            continue;
        }
   }

   
    return head;
}

int main() {
    vector<int> arr = {1,2,1,2,0,0,1,2};
    Node* head = arrtoLL(arr);
    cout << "Original Linked List" << endl;
    traversal(head);
    cout << endl;

    cout << "After changing LL" << endl;
    Sort012(head); 
    traversal(head);
}
