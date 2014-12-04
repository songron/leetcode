//https://oj.leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int getWeight(char c) {
        switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }
    
    int romanToInt(string s) {
        string roms[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        const int n=s.length();
        int num = 0, k = 0;
        
        for (int i=0; k < n && i < 13; i++) {
            while ((n-k) >= (int)roms[i].size() && s.substr(k, (int)roms[i].size()) == roms[i]) {
                num += nums[i];
                k += (int)roms[i].size();
            }
        }
        
        return num;
    }
};