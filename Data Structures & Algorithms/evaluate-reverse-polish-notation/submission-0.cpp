#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long operate(long long a, long long b, const string& token) {
        if (token == "+") return a + b;
        if (token == "-") return a - b;
        if (token == "*") return a * b;
        if (token == "/") return a / b;
        return 0; // default (won’t reach here)
    }

    int evalRPN(vector<string>& tokens) {
        stack<long long> st;  // use long long to prevent overflow

        for (string &token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();

                long long result = operate(a, b, token);
                st.push(result);
            } else {
                st.push(stoll(token)); // stoll handles large numbers safely
            }
        }

        return (int)st.top();
    }
};

