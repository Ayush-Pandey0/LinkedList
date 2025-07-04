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
Node* reverseLL(Node* head){
    Node* temp=head;
    stack <int> st;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}
int main(){
    vector <int> arr={1,2,3,4};
    Node* head=arrtoLL(arr);
    cout<<"Original Linked List"<<endl;
    traversal(head);
    cout<<endl;
    cout<<"After reversing LL"<<endl;
    reverseLL(head);
    traversal(head);
}