#include<bits/stdc++.h>
using namespace std;

class ArrayQueue{
    private:
        int* arr;
        int end;
        int start;
        int currsize,maxsize;

    public:
        ArrayQueue(){
            arr = new int[10];
            end = -1;
            start = -1;
            currsize = 0;
            maxsize = 10;
        }

        void push(int x){
            if(currsize == maxsize-1){
                cout<<"Queue is full "<<endl;
                return;
            }

            if (end ==-1){
                start = 0;
                end = 0;
            }
            else{
                end = (end+1)%maxsize;
            }

            arr[end] = x;
            currsize++;
        }

        int pop(){
            if(currsize == 0){
                cout<<"Queue is empty"<<endl;
            }

            int popped = arr[currsize];

            if (currsize == 1){
                start--;
                end--;
            }
            
            else{
                end = (end+1)%maxsize;
            }

            currsize--;
            return popped;
        }

        int peak(){
            if (currsize == 0){
                cout<<"Empty queue"<<endl;
            }

            return arr[start];
        }


        
}