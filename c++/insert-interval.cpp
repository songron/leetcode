//https://oj.leetcode.com/problems/insert-interval/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        
        const int n = intervals.size();
        if (n == 0) {
            result.push_back(newInterval);
            return result;
        }
        if (newInterval.start > intervals[n-1].end) {
            result = intervals;
            result.push_back(newInterval);
            return result;
        }
        if (newInterval.end < intervals[0].start) {
            result.push_back(newInterval);
            result.insert(result.end(), intervals.begin(), intervals.end());
            return result;
        }
        
        int i = 0;
        while (newInterval.start > intervals[i].end) {
            result.push_back(intervals[i++]);
        }
        
        int j = n - 1;
        while (newInterval.end < intervals[j].start) {
            j--;
        }
        
        if (j < i) {
            result.push_back(newInterval);
        }
        else {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[j].end);
            result.push_back(newInterval);
        }

        result.insert(result.end(), intervals.begin()+j+1, intervals.end());
        
        return result;
    }
};