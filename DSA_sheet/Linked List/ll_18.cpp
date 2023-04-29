//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        Node *curr=head, *tail;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        tail=curr;
        Node *end=tail;
        curr=head;
        Node *prev=NULL, *nxt=NULL;
        // int flag=0;
        // int count=0;
        // while(curr!=end){
        //     nxt=curr->next;
        //     flag=0;
        //     if(curr->data % 2 != 0){
        //         if(prev!=NULL){
        //             prev->next=curr->next;
        //         }
        //         tail->next=curr;
        //         curr->next=NULL;
        //         tail=curr;
        //         flag=1;
        //     }else{
        //         count++;
        //         if(count==1){
        //             head=curr;
        //         }
        //     }
        //     if(flag==0){
        //         prev=curr;
        //     }
        //     curr=nxt;
        // }
        // return head;
        // code here
        Node *newend=end;
        while(curr->data%2!=0 && curr!=end){
            newend->next=curr;
            curr=curr->next;
            newend->next->next=NULL;
            newend=newend->next;
        }
        if(curr->data%2==0){
            head=curr;
            while(curr!=end){
                if(curr->data%2==0){
                    prev=curr;
                    curr=curr->next;
                }else{
                    prev->next=curr->next;
                    curr->next=NULL;
                    newend->next=curr;
                    newend=curr;
                    curr=prev->next;
                }
            }
        }else{
            prev=curr;
        }
        if(newend!=end && end->data%2!=0){
            prev->next=end->next;
            end->next=NULL;
            newend->next=end;
        }return head;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends