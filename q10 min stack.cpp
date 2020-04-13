// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.

#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack <long int> s;
    long int min;
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if(s.size()==0)
        {
            min = x;
            s.push(x);
        }
        else
        {
            if(x<min)
            {
                long int temp2 = x;
                long long int temp = 2*temp2-min;
                s.push(temp);
                min = x;
            }
            else
            {
                s.push(x);
            }
        }
    }
    
    void pop() {
        if(s.size()!=0)
        {
            if(s.top()<min)
            {
                min = 2*min-s.top();
                s.pop();
            }
            else
            {
                s.pop();
            }
        }
        
    }
    
    int top() {
        if(s.top()<min)
        {
            return min;
        }
        return s.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */