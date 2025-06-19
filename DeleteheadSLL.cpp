#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data , Node* next){
        this->data=data;
        this->next=next;
    }
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
Node* vec2LL(vector <int> arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=mover->next;
    }
    return head;
}
void traversal(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node* deletehead(Node* head){
    if(head==nullptr){
        return head;
    }
    Node* temp=head;
    head=head->next;
    temp->next=nullptr;
    return head;
}
int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=vec2LL(arr);
    traversal(head);
    cout<<endl;
    cout<<"After deleting head"<<endl;
    head=deletehead(head);
    traversal(head);
}