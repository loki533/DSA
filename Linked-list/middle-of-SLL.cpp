#include<bits/stdc++.h>
using namespace std;

/*slow pointer -> moves one node at a time
fast pointer -> moves 2 nodes at a atime*/

class Node{
    public:
        int data;
        Node* next;

        Node(int data1,Node* next1){
            data = data1;
            next = next1;
        }

        Node(int data1){
            data =data1;
            next = nullptr;
        }

        Node* middleNode(Node* head){
            Node* slow = head;
            Node* fast = head;

            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow;

        }

};

