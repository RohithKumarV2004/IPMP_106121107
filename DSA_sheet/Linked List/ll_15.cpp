//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    
    struct node *reverse (struct node *head, int k)
    { 
        struct node *curr=head;
        struct node *prev=NULL;
        struct node *nxt=NULL;
        int count=0;
        while(curr!=NULL && count<k){
                nxt=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nxt;
                count++;
        }
        count=0;
        if(head!=NULL){
            head->next=curr;
        }
        while(curr!=NULL && count<k-1){
            curr=curr->next;
            count++;
        }
        if(curr!=NULL){
            curr->next=reverse(curr->next, k);
        }
        return prev;
        // Complete this method
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cout<<"enter t: ";
    cin>>t;
    cout<<endl;
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cout<<"enter n: ";
        cin >> n;
        cout<<endl;
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cout<<"enter a value: ";
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cout<<"enter a value for k: ";
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends