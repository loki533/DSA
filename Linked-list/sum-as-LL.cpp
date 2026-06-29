#include<bits/stdc++.h>
using namespace std;

/* 2->4->3 + 5->6->4
    342 + 465 = 807 (7->0->8)
    
use 2 pointers to iterate through both the LLs
    until u reach the end of both
        do the addition where
        carry = sum/10
        data = sum%10*/

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
    
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* temp = result;
        int carry =0;

        while(l1 != NULL || l2!=NULL || carry !=0){
            int sum = carry; //add the previous carry as well
            
            if(l1!=NULL){
                sum += l1->val;
                l1=l1->next;
            }
            
            if(l2!=NULL){
                sum += l2->val;
                l2=l2->next;
            }

            carry = sum/10;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            


        }
        return result->next;
    }
};
