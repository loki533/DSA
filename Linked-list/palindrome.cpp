#include<bits/stdc++.h>
using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };


class Solution {
public:
    ListNode* reverse(ListNode* head){
        if (head == NULL || head->next == NULL){
            return head;
        }

        ListNode* newHead = reverse(head->next);

        ListNode* front= head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }
    bool isPalindrome(ListNode* head) {

        if (!head || !head->next)
            return true;


        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next !=NULL && fast->next->next !=NULL){
            fast= fast->next->next;
            slow = slow->next;
        }

        ListNode* newHead = reverse(slow->next);
        ListNode* first = head; //pointer to the 1st half
        ListNode* second = newHead; //reverssed 1st half

        while(second!=NULL){
            if (first->val != second->val ){
                reverse(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        
        }

        reverse(newHead);
        return true;
    }
};