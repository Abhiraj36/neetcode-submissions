class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool a = false, b = false, c = false; // track if we can match each part

        for (auto& t : triplets) {
            // skip if any number is larger than target
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2])
                continue;

            // check which parts we can match
            if (t[0] == target[0]) a = true;
            if (t[1] == target[1]) b = true;
            if (t[2] == target[2]) c = true;

            // if all parts are covered → we can form target
            if (a && b && c) return true;
        }

        return a && b && c;
    }
};