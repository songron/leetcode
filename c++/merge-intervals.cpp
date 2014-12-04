//https://oj.leetcode.com/problems/merge-intervals/

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
private:
    class Compare {
    public:
        bool operator() (const Interval &i1, const Interval i2) {
            return i1.start < i2.start;
        }
    };

public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        if (intervals.empty()) return result;
        
        Compare comp;
        sort(intervals.begin(), intervals.end(), comp);
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start > result.back().end ){
                result.push_back(intervals[i]);
                continue;
            }
            result.back().end = max(result.back().end, intervals[i].end);
        }
        
        return result;
    }
};