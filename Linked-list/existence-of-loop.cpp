#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x) , next(NULL){}

};

/*optimal approach
    Use two pointer fast and slow
    if they both meet each other at some point , it means thers a loop*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!=NULL && fast->next!=NULL){ //to avoid dereferencing a null , at fast->next->next
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
        
    }
};