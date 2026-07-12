class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char,char> a = {
            {')','('},
            {']', '['},
            {'}','{'}
        };

        for(char c:s) {
            if (a.count(c)) {
                if(!stack.empty() && stack.top() == a[c]) {
                    stack.pop();
                } else return false;
            }
            else {
                stack.push(c);
            }
        } return stack.empty();
    }
};
