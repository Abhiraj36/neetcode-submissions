#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> leftMaxHeap; // max-heap (lower half)
    priority_queue<int, vector<int>, greater<int>> rightMinHeap; // min-heap (upper half)

public:
    MedianFinder() {}

    void addNum(int num) {
        // Step 1: Add to max-heap first
        leftMaxHeap.push(num);

        // Step 2: Balance, move largest from left to right
        rightMinHeap.push(leftMaxHeap.top());
        leftMaxHeap.pop();

        // Step 3: Ensure left side is >= right side in size
        if (leftMaxHeap.size() < rightMinHeap.size()) {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }
    
    double findMedian() {
        if (leftMaxHeap.size() > rightMinHeap.size()) {
            return leftMaxHeap.top(); // odd case
        }
        return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0; // even case
    }
};

