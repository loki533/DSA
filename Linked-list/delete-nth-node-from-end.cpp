#include<bits/stdc++.h>
using namespace std;

/*Nth node from end ==> L-N+1 th node from start
Optimal approach
    use 2 variables -> fast nd slow
        intialize fast to the Nth Node
        after reaching the Nth node , start iterating both pointers
            until the fast reaches the end , this guarantees the slow pointer would b at the L-Nth node
            then link L-Nth node to L-N+2th*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0,head); //to handle all cases equally , includin ones with only 1 node
        ListNode* fast =dummy;
        ListNode* slow = dummy;

        for(int i =0;i<=n;i++){
            fast = fast->next;     //n+1th link
        }
        
        while(fast!=NULL){
            fast = fast->next;
            slow = slow->next;  //now slow would b at the node just before the Nth node
        }

        slow->next= slow->next->next;

        return dummy->next;

        
    }
};