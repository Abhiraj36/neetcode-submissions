/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        vector<int> starts, ends;
        for (auto &it : intervals) {
            starts.push_back(it.start);
            ends.push_back(it.end);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int rooms = 0, endPtr = 0;

        for (int i = 0; i < starts.size(); i++) {
            if (starts[i] < ends[endPtr]) {
                // Need a new room
                rooms++;
            } else {
                // Reuse a room
                endPtr++;
            }
        }

        return rooms;
    }
};

