//{ Driver Code Starts

#include <iostream>
#include <stdio.h>
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

void append(struct Node** headRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)last = last->next;
	last->next = new_node;
}

void printList(struct Node *node)
{
    while(node!=NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    cout<<endl;
} 

void alternatingSplitList(struct Node*); 

struct Node* a;
struct Node* b;

int main()
{
    int test;
    cin>>test;
    
    while(test--)
    {
        a=b=NULL;
        struct Node* head = NULL;
        
        
        int n, k;
        cin>>n;
        
        while(n--)
        {
            cin>>k;
            append(&head, k);
        }
        
        alternatingSplitList(head);
        printList(a);
        printList(b);
    }
    return 0;
}




// } Driver Code Ends


/*
structure of node is as
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
#include<bits/stdc++.h>

/*
These are global variables to store heads of split lists
struct Node* a; //store head of first list
struct Node* b; //store head of second list

*/

void alternatingSplitList(struct Node* head) 
{   struct Node *a1=(struct Node*)malloc(sizeof(struct Node));
    struct Node *b1=(struct Node*)malloc(sizeof(struct Node));
    struct Node *curr=head;
    struct Node *a2=a1;
    struct Node *b2=b1;
    int flag=0;
    while(curr){
        if(flag==0){
            struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
            temp->next=NULL;
            temp->data=curr->data;
            a2->next=temp;
            a2=a2->next;
            curr=curr->next;
            flag=1;
        }else if(flag==1){
            struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
            temp->next=NULL;
            temp->data=curr->data;
            b2->next=temp;
            b2=b2->next;
            curr=curr->next;
            flag=0;
        }
    }
    a=a1->next;
    b=b1->next;
    
}

