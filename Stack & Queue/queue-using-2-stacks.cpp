#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {

        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

    }
    
    int pop() {

        if(s1.empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        int element = s1.top();
        s1.pop();
        return element;
    }
    
    int peek() {
        if(s1.empty()){
            cout<<"Empty stack"<<endl;
            return -1;
        }
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

 /*Optimised for push operations*/

 
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {

        s1.push(x);
    }
    
    int pop() {

        if(s1.empty() && s2.empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }

        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int popped = s2.top();
        s2.pop();
        return popped;
    }
    
    int peek() {
        if(s1.empty() && s2.empty()){
            cout<<"Empty stack"<<endl;
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return (s1.empty() && s2.empty() );
    }
};
