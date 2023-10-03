#include<iostream>
using namespace std;
class CircularLinkedList{
class Node{
    public:
Node* next;
bool Visited;
int data;

Node(int d){
    data=d;
  next=NULL;
  Visited=false;
}
Node(){
    next=NULL;
      Visited=false;

}
};
public:
Node head;
CircularLinkedList(){
    head.next=&head;
}
void Insert(int d){
    Node* temp=new Node(d);
    Node* prev, *current;
prev=&head;
current=prev->next;
while(current!=&head && current->data<d){
    prev=current;
    current=current->next;
}
while(current!=&head && current->data==d){
    prev->next=current;
    delete(temp);
    return; 
}
temp->next=current;
prev->next=temp;
}
void Delete(int d){ // delete data
    Node* prev=&head;
Node* temp=prev->next;
    while(temp!=&head && temp->data!=d){
        prev=temp;
            temp=temp->next;}

while(temp!=&head && temp->data==d){
 prev->next=temp->next;
    delete(temp);
    return; 
}
      
        }
        
void NumberOfNodes(){
    Node* temp=&head;
    Node* temp1=temp->next;
int count =0;
    while(temp1!=temp){
        count++;
        temp1=temp1->next;

    }
    cout<<"Total number of nodes are "<<count+1;
}        

void Print(){
    cout<<"->";
     Node* temp=&head;
         temp=temp->next;
    while( temp!=&head ){
    cout<<temp->data<<" -> ";
    temp=temp->next;
    }
    cout<<endl;
}
void FindLoop(){
    Node* temp=&head;
    while(temp!=NULL){
        if(temp->Visited==false){
            temp->Visited=true;
            temp=temp->next;
        }
        else if(temp->Visited == true) {
            cout<<"Loop exists "<<endl;
            return ;
        }
    }
    cout<<"Loop doesnot exists"<<endl;
}
~CircularLinkedList(){
    Node*temp=&head;
    while(temp!=&head){
       Node* temp2=temp;
       temp=temp->next;
       delete(temp2);
    }
}
};
int main(){
CircularLinkedList a;
for(int i =0;i<5;i++)
a.Insert(rand()%10);
a.Print();
cout<<"The deleted linked list is :"<<endl;
a.Delete(1);
a.Print();
a.FindLoop();
a.NumberOfNodes();
}