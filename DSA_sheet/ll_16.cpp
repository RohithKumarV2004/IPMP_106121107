//{ Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


 
#include<bits/stdc++.h>
/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{   
    Node *a=head1, *b=head2;
    // vector<int> vec;
    // while(a!=NULL){
    //     vec.push_back(a->data);
    //     a=a->next;
    // }
    // while(b!=NULL){
    //     vec.push_back(b->data);
    //     b=b->next;
    // }
    // sort(vec.begin(), vec.end());
    // Node *head=(Node*)malloc(sizeof(Node));
    // head->data=vec[0];
    // head->next=NULL;
    // Node *curr=head;
    // for(int i=1; i<vec.size(); i++){
    //     Node *temp=(Node*)malloc(sizeof(Node));
    //     temp->data=vec[i];
    //     temp->next=NULL;
    //     curr->next=temp;
    //     curr=curr->next;
    // }
    // return head;
    Node *dummy=(Node*)malloc(sizeof(Node));
    Node *temp=dummy;
    while(a!=NULL && b!=NULL){
        if(a->data <= b->data){
            Node *tem=(Node*)malloc(sizeof(Node));
            tem->data=a->data;
            tem->next=NULL;
            temp->next=tem;
            temp=temp->next;
            a=a->next;
        }else{
            Node *tem=(Node*)malloc(sizeof(Node));
            tem->data=b->data;
            tem->next=NULL;
            temp->next=tem;
            temp=temp->next;
            b=b->next;
        }
    }while(a!=NULL){
        Node *tem=(Node*)malloc(sizeof(Node));
            tem->data=a->data;
            tem->next=NULL;
            temp->next=tem;
            temp=temp->next;
            a=a->next;
    }while(b!=NULL){
        Node *tem=(Node*)malloc(sizeof(Node));
            tem->data=b->data;
            tem->next=NULL;
            temp->next=tem;
            temp=temp->next;
            b=b->next;
    }
    return dummy->next;
    // code here
}  