#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x) , next(NULL){}

};

/*We are given access to the node to b deleted
    So the approach would be to Copy the nextnodes data to the Current node
        and change the next of the current node*/

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
        
    }
};