#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key , value ,cnt;
    Node* next;
    Node* prev;
    Node(int key1,int value1){
        key = key1;
        value = value1;
        cnt = 1;
    }
};

struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addNode(Node* newNode){
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next=newNode;
        temp->prev = newNode;
        size++;
    }

    void deleteNode(Node* delNode){
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
};

class LFUCache {
    private:
        unordered_map<int,Node*> keyNode;
        unordered_map<int,List*> freqmap;

        int maxSizeCache;
        int minfreq;
        int currsize;


    public:
        LFUCache(int capacity) {
            maxSizeCache = capacity;
            minfreq = 0;
            currsize= 0;
        }

        void Updatefreqlist(Node* node){
            freqmap[node->cnt]->deleteNode(node); //remove the node from the frequency map

            //to update the minfreq
            if(node->cnt == minfreq && freqmap[node->cnt]->size == 0){
                minfreq++;
            }

            List* next_highest_freq = new List();

            //if the next higher freq list is already exisiting
            if(freqmap.find(node->cnt+1) != freqmap.end()){
                next_highest_freq = freqmap[node->cnt+1];
            }

            node->cnt++;
            next_highest_freq->addNode(node);

            freqmap[node->cnt] = next_highest_freq;
            keyNode[node->key] = node;
        }
        
        int get(int key) {
            if(keyNode.find(key) != keyNode.end()){
                int ans = keyNode[key]->value;
                Updatefreqlist(keyNode[key]);

                return ans;
            }
            return -1;
        }
        
        void put(int key, int value) {
            if (maxSizeCache==0){
                return;
            }

            if (keyNode.find(key)!=keyNode.end()){
                keyNode[key]->value=value;
                Updatefreqlist(keyNode[key]);
            }

            else{
                
                if(currsize == maxSizeCache){
                    List* list = freqmap[minfreq];
                    keyNode.erase(list->tail->prev->key);

                    freqmap[minfreq]->deleteNode(list->tail->prev);
                    currsize--;
                }

                currsize++;
                minfreq = 1;
                List* list = new List();

                if(freqmap.find(minfreq)!=freqmap.end()){
                    list = freqmap[minfreq];
                }

                Node* node = new Node(key,value);
                list->addNode(node);

                keyNode[key] =node;
            }
        }
    };




