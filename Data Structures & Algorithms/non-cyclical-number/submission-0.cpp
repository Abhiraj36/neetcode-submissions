class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        string str = to_string(n);

        while(true){
            int ans = 0;

            for(char c : str){
                int digit = c -'0';
                ans += digit* digit;
            }

            if(ans == 1) return true;
            if(seen.count(ans)) return false;

            seen.insert(ans);
            str= to_string(ans);
        }
    }
};
