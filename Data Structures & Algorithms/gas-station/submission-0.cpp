class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if (totalGas < totalCost)  // not enough total gas
            return -1;

        int currentGas = 0, startIndex = 0;
        for (int i = 0; i < gas.size(); i++) {
            currentGas += gas[i] - cost[i];

            if (currentGas < 0) {  // can't reach next station
                startIndex = i + 1; // start fresh from next one
                currentGas = 0;     // reset tank
            }
        }

        return startIndex;
    }
};

