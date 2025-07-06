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
void palindrome(Node* head){
    Node* temp=head;
    int n=0;
    while(temp!=NULL){
        n=n*10+temp->data;
        temp=temp->next;
    }
    int m=n;
    int rev=0;
    while(m){
        int d=m%10;
        rev=rev*10+d;
        m/=10;
    }
    if(rev==n){
        cout<<"Palindrome"<<endl;
        
    }
    else{
        cout<<"Not Palindrome"<<endl;

    }
    
}
int main(){
    vector <int> arr={1,2,1};
    Node* head=arrtoLL(arr);
    palindrome(head);
}