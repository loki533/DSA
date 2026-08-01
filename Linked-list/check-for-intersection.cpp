#include<bits/stdc++.h>
using namespace std;

/*Brute force approach
    Since intersection means that the entire node remains the same
    For the first LL check if any of the Node is same as the 2nd LL
        if not return NULL*/


        

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headB!=NULL){
            ListNode* temp = headA; //so that after check of every Node in ListA, it resets
            while(temp!=NULL){
                if (temp == headB){
                    return headB;
                }
                temp = temp->next;
            }
        headB = headB->next;
        }
        
        return NULL;
        
    }
};

/*Better approach
    since we are "effectivley searching " use HASHING
    since hashing takes O(1)
    hash the node addresses of the first LL , then search for the specific hashes from 2nd LL*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> hash;
        ListNode* temp = headA;
        while(temp!=NULL){
            hash.insert(temp);
            temp = temp->next;
        }

        ListNode* temp1=headB;
        while(temp1!=NULL){
            if(hash.find(temp1)!=hash.end()){
                return temp1;
            }
            temp1=temp1->next;
        }

        return NULL;
        
    }
};

/*Optimal approach is to 
    reduce the search length
    take two dummy nodes pointing at the head of the different LLs
    now iterate over them , if either of them becomes NULL , point to the head of the opposite LL
    check if both nodes become equal*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* d1 = new ListNode(0);
        d1->next = headA;

        ListNode* d2 = new ListNode(0);
        d2->next = headB;

        // Traverse both lists, when one reaches the end, redirect it to the head of the other list
        while (d1 != d2) {
            d1 = d1 == NULL ? headB : d1->next;
            d2 = d2 == NULL ? headA : d2->next;
        }
        
        return d1;  // If they meet, return the intersection node, otherwise NULL
    }
        

        
};