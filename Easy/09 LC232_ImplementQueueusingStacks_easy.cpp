class MyQueue {
private:
    stack<int> inStack;
    stack<int> outStack;

    void moveItems() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    MyQueue() = default;

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        moveItems();
        int value = outStack.top();
        outStack.pop();
        return value;
    }

    int peek() {
        moveItems();
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
