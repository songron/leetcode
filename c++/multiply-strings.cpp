//https://oj.leetcode.com/problems/multiply-strings/

class Solution {
private:
    string addBig(string num1, string num2) {
        int m=num1.size(), n=num2.size();
        if (m < n) {
            swap(num1, num2);
            swap(m, n);
        }
        
        if (n == 0) return num1;
        if (n == 1 && num2[0] == '0') return num1;

        int a = 0, i=m-1, j=n-1;
        while (i >= 0) {
            int x = a;
            if (i >= 0)
                x += num1[i--] - '0';
            if (j >= 0)
                x += num2[j--] - '0';
                
            num1[i+1] = x % 10 + '0';
            a = x / 10;
        }
        
        if (a > 0) 
            num1.insert(num1.begin(), '1');
        return num1;
    }
    
    // '0' <= num2 <= '9'
    string multiplySingleNumber(string num, char c) {
        if (c == '0') return "0";
        const int n = num.size();
        int a = 0;
        for (int i=n-1; i>=0; i--) {
            int x = a + (num[i] - '0') * (c - '0');
            num[i] = x % 10 + '0';
            a = x / 10;
        }
        
        if (a > 0)
            num.insert(num.begin(), a + '0');
        return num;
    }

public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        if (m < n) {
            swap(num1, num2);
            swap(m, n);
        }
        
        string r("0"), zeroes;
        for (int i=n-1; i>=0; i--) {
            if (num2[i] != '0') {
                string s = multiplySingleNumber(num1, num2[i]);
                s += zeroes;
                r = addBig(s, r);
            }
            zeroes.append(1, '0');
        }
        
        // delete first 0s
        while ((int)r.size() > 1 && r[0] == '0')
            r.erase(r.begin());
        
        return r;
    }
};