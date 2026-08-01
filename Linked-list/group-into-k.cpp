#include<bits/stdc++.h>
using namespace std;

/*Approach 
    Find the first k no of elements
    preserve the kth->next element for future linking
    Now point the kth node to Null , to treat it as a individual LL
    Now reverse the LL
    repeat for the next elements*/

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next= head;
        ListNode* group_prev= dummy;

        while(true){

            ListNode* kth = getKthNode(group_prev,k);

            if(!kth){
                break;
            }

            ListNode* nxt_group = kth->next;
            ListNode* curr = group_prev->next;

            for (int i =0;i<k,i++){
                ListNode* temp = curr->next;
                curr->next = nxt_group;
                temp 
            }
        }


        
    }

    ListNode* getKthNode(ListNode* curr,int k){
        while(curr && k>0){
            curr = curr->next;
            k--;
        }
        return curr;
    }
        
};