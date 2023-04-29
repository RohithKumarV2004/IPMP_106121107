#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
};
Node* push(Node **head, int val){
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->next=NULL;
    temp->data=val;
    (*head)->next=temp;
    *head=(*head)->next;
    //return *head;
}
void print(Node *head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }cout<<endl;
}
bool sum(Node *head1, Node *head2, Node *head3, int num){
    Node *a=head1, *b=head2, *c=head3;
    cout<<"start"<<endl;
    while(a!=NULL){
        int a1=a->data;
        //cout<<"checking for... "<<a->data<<" "<<b->data<<" "<<c->data<<endl;
        b=head2;
        while(b!=NULL){
            int b1=b->data;
            c=head3;
            while(c!=NULL){
                int c1=c->data;
                cout<<"checking for... "<<a->data<<" "<<b->data<<" "<<c->data<<endl;
                if(a1+b1+c1==num){
                    cout<<a->data<<" "<<b->data<<" "<<c->data<<" "<<endl;
                    return true;
                }c=c->next;
            }b=b->next;
        }a=a->next;
        //cout<<a->data<<endl;
    }
    return false;
}
int main(){
    Node *A=(Node*)malloc(sizeof(Node));
    Node *B=(Node*)malloc(sizeof(Node));
    Node *C=(Node*)malloc(sizeof(Node));
    Node *headA=A, *headB=B, *headC=C;
    push (&headA, 20);
    push (&headA, 4);
    push (&headA, 15);
    push (&headA, 10);

    push (&headB, 10);
    push (&headB, 9);
    push (&headB, 4);
    push (&headB, 2);
 
    push (&headC, 1);
    push (&headC, 2);
    push (&headC, 4);
    push (&headC, 8);
    cout<<"A: ";
    print(A->next);
    cout<<"B: ";
    print(B->next);
    cout<<"C: ";
    print(C->next);
    int num=32;
    bool mark=sum(A->next, B->next, C->next, num);
    cout<<mark<<endl;
}