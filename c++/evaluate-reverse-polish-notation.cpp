//https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> ops;
        for (int i = 0; i < tokens.size(); i++) {
            string op = tokens[i];
            // determine if op is a operator
            if (op == "+" || op == "-" || op == "*" || op == "/") {
                int num1, num2;
                num2 = ops.top(); ops.pop();
                num1 = ops.top(); ops.pop();
                
                if (op == "+") {
                    ops.push(num1 + num2);
                }
                else if (op == "-") {
                    ops.push(num1 - num2);
                }
                else if (op == "*") {
                    ops.push(num1 * num2);
                }
                else {
                    ops.push(num1 / num2);
                }
            }
            else {  // op is an interger
                ops.push(strToInt(op));
            }
        }
        
        int result = ops.top();
        ops.pop();
        return result;
    }
    
    int strToInt(string &op) {
        int num = 0, flag = 1;
        int i = 0;
        if (op[0] == '-') {
            flag = -1;
            i++;
        }
        else if (op[0] == '+') {
            i++;
        }
        
        for (; i < op.size(); i++) {
            num = num * 10 + (op[i] - '0');
        }
        
        return flag * num;
    }
};