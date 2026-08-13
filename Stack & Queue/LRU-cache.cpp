#include<bits/stdc++.h>
using namespace std;

/*Use a DLL and hashmap
    DLL stores the most recently accessed key,value first i.e closer to head
    hashmap stores the key,nodeadress 
    keep track of capacity , if it capacity exceeds -> delete the last node and insert onto first
    any get operation needs the node to be deleted and added to the first*/

class LRUCache{
    public:
        class Node{
            public:
                int key;
                int value;
                Node* prev;
                Node* next;

                Node(int key1,int value1){
                    key = key1;
                    value = value1;
                }
        };

        int capacity;
        unordered_map<int,Node*> m;

        //initializing dummy dll
        Node* head = new Node(-1,-1);
        Node* tail = new Node(-1,-1);

        LRUCache(int capacity1){
            capacity = capacity1;
            head->next = tail;
            tail->prev = head;
        }

        void addnode(Node* newNode){//add node right after head
            Node* temp = head->next;
            newNode->next = temp;
            newNode->prev = head;
            head->next = newNode;
            temp->prev = newNode;
        }

        void deleteNode(Node* delNode){
            Node* delPrev = delNode->prev;
            Node* delNext = delNode->next;
            delPrev->next = delNext;
            delNext->prev = delPrev;
        }

        int get(int key1){
            if(m.find(key1)!=m.end()){
                int ans = m[key1]->value;
                Node* resNode=  m[key1];
                deleteNode(resNode);
                addnode(resNode);
                return ans;
            }
            return -1;
        }

        void put(int key1,int value1){

            if (m.find(key1)!= m.end()){
                deleteNode(m[key1]);
                m.erase(key1);
            }
            if (m.size()==capacity){
                m.erase(tail->prev->key);
                deleteNode(tail->prev);
            }

            Node* newNode = new Node(key1,value1);
            addnode(newNode);
            m[key1] = newNode;
        }
}