#include<bits/stdc++.h>
using namespace std;

class ArrayStack{
    private:
        int* stackarray;
        int capacity;
        int top;
    public:

        ArrayStack(int size = 1000){
            capacity = size;
            stackarray = new int[capacity];
            top = -1;
        }

        ~ArrayStack(){
            delete[] stackarray;
        }

        void push(int x){
            if (top == capacity - 1){
                cout << "Stack Overflow" << endl;
                return ;
            }
            stackarray[top++] =x;
        }

        int pop(){
            if (top == -1){
                cout<<"Stack Underflow"<<endl;
                return;
            }
            return stackarray[top--];
        }

        int top(){
            if (top == -1){
                cout<<"Stack Underflow"<<endl;
                return;
            }
            return stackarray[top];
        }

        bool isempty(){
            return (top == -1);
        }
}