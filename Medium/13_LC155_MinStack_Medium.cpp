class MinStack {
private:
    stack<int> values;
    stack<int> minimums;

public:
    MinStack() {}

    void push(int value) {
        values.push(value);

        if (minimums.empty() || value <= minimums.top()) {
            minimums.push(value);
        }
    }

    void pop() {
        if (values.top() == minimums.top()) {
            minimums.pop();
        }
        values.pop();
    }

    int top() {
        return values.top();
    }

    int getMin() {
        return minimums.top();
    }
};
