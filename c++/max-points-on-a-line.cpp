/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        /* https://oj.leetcode.com/problems/max-points-on-a-line/
        For each point, check every other point and see how many points 
        line on the same line. (by slope)
            * there may be same points
            * two points may line on the vertical line (the slope is infinite)
        */
        
        if (points.empty()) return 0;
        const int n = points.size();
        const long long fac = 1000000000;
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            unordered_map<long long, int> counter;
            int same = 1;
            int ver = 1;
            int maxCount = 0;
            
            for (int j = i + 1; j < n; j++) {
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    same++;
                    ver++;
                }
                else if (points[j].x == points[i].x) {
                    ver++;
                }
                else {
                    long long slope = fac * (long long)(points[j].y - points[i].y) / (long long)(points[j].x - points[i].x);
                    ++counter[slope];
                    if (counter[slope] > maxCount) maxCount = counter[slope];
                }
            }
            
            maxCount += same;
            if (ver > maxCount) maxCount = ver;
            if (maxCount > result) result = maxCount;
        }
        
        return result;
    }
};