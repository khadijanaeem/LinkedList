#include<iostream>
#include<cstdlib>
using namespace std;

class SingleLinkedList{

class Node{
public:
Node* next;
int data;

Node(int d){
    data=d;
    next=NULL;
}
};
public:
Node* head;
Node* tail;

SingleLinkedList(){
    head=tail=NULL;
}
void insert(int d){
       Node* temp=new Node(d);
    Node* current=head;
    Node* prev;
    while(current!=NULL && current->data<d){
    prev=current;
    current=current->next;
    }
temp->next=current;
if(current==head){
    head=temp;
}else{
    prev->next=temp;
}
}
int divisor(Node* temp,Node* prev){
 for(int i=prev->data;i>1;i--){
    if(prev->data%i==0){
        if(temp->data%i==0){
return i;
        }
    }
 }   
 return 1;
}
void HighestCommonDivisor(){
Node* temp=head;
Node* prev;
while(temp->next!=NULL){
prev=temp;
temp=temp->next;
//find divisor
int h=divisor(temp,prev);
//insert between nodes
Node* newnode=new Node(h);
newnode->next=temp;
prev->next=newnode;
}
}
void print(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

~SingleLinkedList(){
    Node* temp=head;
    while(temp!=NULL){
temp=temp->next;
delete temp;
    }
    head=tail=NULL;
}


};
int main(){
SingleLinkedList l;

for(int i=0;i<7;i++){
l.insert(rand()%15);
}
l.print();
cout<<endl;
cout<<"After adding highest common divisor "<<endl;
l.HighestCommonDivisor();
l.print();
}
