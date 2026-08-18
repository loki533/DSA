#include<bits/stdc++.h>
using namespace std;

/*Use the formula 
    2 * value - prev_min = new_val
        where value is the number received to push
        and new_val is the number to be pushed if min changes*/

class MinStack {
private:
    stack<long long> st;
    long long curr_min;

public:
    MinStack() {
    }
    
    void push(int value) {
        long long value1 = value;
        if(st.empty()){
            st.push(value);
            curr_min = value1;
        }

        else{
            if(value < curr_min){
                long long new_val = (2 * value1) - curr_min;
                st.push(new_val);
                curr_min = value1;
            }
            else{
                st.push(value1);
            }
        }
    }
    
    void pop() {
        long long new_value = st.top();

        if(new_value >= curr_min){//not modified
            st.pop();
        }

        else{//modified
            long long prev_min = (2*curr_min) - new_value;
            curr_min = prev_min;
            st.pop();
        }
    }
    
    int top() {
        long long new_value = st.top();

        if(new_value>=curr_min){
            return st.top();
        }

        else{
            return curr_min;
        }
    }
    
    int getMin() {
        return curr_min;
    }
};
