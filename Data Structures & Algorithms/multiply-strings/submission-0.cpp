class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int m = num1.size(), n = num2.size();
        vector<int> result(m + n, 0);
        
        // Multiply each digit from the end
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                
                result[i + j + 1] = sum % 10;      // store current digit
                result[i + j] += sum / 10;         // carry to the left
            }
        }
        
        // Convert result array to string (skip leading zeros)
        string ans = "";
        int i = 0;
        while (i < result.size() && result[i] == 0) i++;
        for (; i < result.size(); i++) ans.push_back(result[i] + '0');
        
        return ans.empty() ? "0" : ans;
    }
};
