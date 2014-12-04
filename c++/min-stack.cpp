//https://oj.leetcode.com/problems/min-stack/

class MinStack {
private:
    stack<int> _stack;
    stack<int> _min_stack;

public:
    void push(int x) {
        _stack.push(x);
        if (x <= getMin()) {
            _min_stack.push(x);
        }
    }

    void pop() {
        if (!_stack.empty()) {
            if (_stack.top() == _min_stack.top()) {
                _min_stack.pop();
            }
            _stack.pop();
        }
    }

    int top() {
        if (!_stack.empty()) {
            return _stack.top();
        }
        return 0;
    }

    int getMin() {
        if (!_min_stack.empty()) {
            return _min_stack.top();
        }
        return INT_MAX;
    }
};
