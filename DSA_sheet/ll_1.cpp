//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{   int count=0;
    Node *curr=head;
    while(curr!=NULL){
        count++;
        curr=curr->next;
    }
    if(n>count){
        return -1;
    }
    curr=head;
    int num=count-n+1;
    for(int i=0; i<num-2; i++){
        curr=curr->next;
    }
    if(num==1||num==2){
        if(num==1){
            Node *hi=head;
            head=head->next;
            return hi->data;
        }else if(num==2){
            Node *hi=head;
            hi=hi->next;
            head->next=hi->next;
            return hi->data;
        }
    }
    Node *temp=curr->next;
    curr->next=temp->next;
    return temp->data;
    
}

