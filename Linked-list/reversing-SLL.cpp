#include<bits/stdc++.h>
using namespace std;

/*Brute force approach
    Use a stack to push data , then once completely traversd pop em*/

struct Node{
    int data;
    Node* next;
    Node(int x):data(x) ,next(NULL) {}
};

class Solution{
    public:
        Node* reverselist(Node* head){
            stack<int> st;
            Node* temp = head;

            while (temp != NULL){
                st.push(temp->data);
                temp = temp->next;
            }

            temp = head;

            while(temp!=NULL){
                temp->data = st.top();
                st.pop();
                temp = temp->next;
            }

            return head;
        }


};

/*Better approach
    just reverse the links , to avoid usin extra space*/

class Solution{
    public:
        Node* reverselist(Node* head){
            Node* temp = head;
            Node* prev= NULL;

            while(temp != NULL){
                Node* Forward = temp->next;
                temp->next = prev;
                prev = temp;
                temp = Forward;
            }
        }

        return prev;

};

/*Recursive approach*/

class Solution{
    public:
        Node* reverse_list(Node* head){
            if(head == NULL || head->next == NULL)
                return head;

        //recursivley call it
        Node* new_head = reverse_list(head->next);

        Node* front = head->next; 
        front->next = head; //reverse the link
        head->next = NULL; //break the current link

        return new_head;
    }
};