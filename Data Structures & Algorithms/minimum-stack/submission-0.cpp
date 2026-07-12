#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> st;       // main stack
    stack<int> minStack; // stack to track minimums

    MinStack() {
        // no need to "new" stacks in C++, they’re already objects
    }
    
    void push(int val) {
        st.push(val);
        // if minStack is empty or val is <= current min, push to minStack too
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        // if top of both stacks are equal, pop both
        if (st.top() == minStack.top()) {
            minStack.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

