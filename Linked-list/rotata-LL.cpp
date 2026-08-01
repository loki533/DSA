#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x) , next(NULL){}

};

/*brute force approach
    break the second last link to the tail
    tail->next= head
    and make tail = head
    repeat this n times*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = NULL;

        if(head->next==NULL){
            return head;
        }
    
        for(int i =0 ;i<k;i++){
            ListNode* temp = dummy->next;
            while(temp->next!=NULL){
                prev=temp;
                temp=temp->next;
            }
            prev->next=NULL;
            temp->next=head;
            head = temp;
        }

        return head;
        
    }
};

/*Optimal approach
    Calculate the effective rotations (k%length)
    convert to CLL
    now the tail is located at Length - k%length*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int length= 0;
        ListNode* temp = head;

        if(head==NULL || head->next==NULL){
            return head;
        }

        while(temp->next!=NULL){
            temp =temp->next;
            length++;
        }
        length++;
        temp->next= head; //convert to circular LL
        
        int eff_rot=(k%length);
    

        if(eff_rot == 0){
            temp->next = NULL;
            return head;
        }
        
        int steps = length-eff_rot-1;

        ListNode* tail= head;

        while(steps--){
            tail=tail->next;
        }

        head = tail->next;
        tail->next=NULL;

        return head;
    }
};