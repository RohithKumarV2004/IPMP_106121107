/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//FROM LEETCODE
#include<bits/stdc++.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node->next->next!=NULL){
            node->val=node->next->val;
            node=node->next;
        }node->val=node->next->val;
        node->next=NULL;
    }
};