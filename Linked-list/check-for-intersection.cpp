#include<bits/stdc++.h>
using namespace std;

/*Brute force approach
    Since intersection means that the entire node remains the same
    For the first LL check if any of the Node is same as the 2nd LL
        if not return NULL*/

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x) , next(NULL){}

};

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