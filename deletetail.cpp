#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data,Node* next){
        this->data=data;
        this->next=next;
    }
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
void traversal(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node* arrtoLL(vector <int> arr){
    if(arr.size()==1) return new Node(arr[0]);
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=mover->next;
    }
    return head;
}
Node* deletetail(Node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;

}
int main(){
    vector <int> arr={1,2,3,4};
    Node* head=arrtoLL(arr);
    traversal(head);
    cout<<endl;
    deletetail(head);
    traversal(head);

}