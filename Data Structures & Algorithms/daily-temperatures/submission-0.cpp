class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;                  // stack holds indices
        vector<int> result(n, 0);       // initialize with size n and all 0s

        for (int i = n - 1; i >= 0; i--) {
            // pop all indices with temp <= current temp
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }

            // if stack not empty, find next warmer day
            if (!st.empty()) {
                result[i] = st.top() - i;
            }

            // push current index
            st.push(i);
        }

        return result;
    }
};
