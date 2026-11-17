class MyCircularQueue {
private:
    vector<int> data;
    int frontIndex;
    int count;
    int capacity;

public:
    MyCircularQueue(int k) {
        data.resize(k);
        frontIndex = 0;
        count = 0;
        capacity = k;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        int insertIndex = (frontIndex + count) % capacity;
        data[insertIndex] = value;
        ++count;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        frontIndex = (frontIndex + 1) % capacity;
        --count;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[frontIndex];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }

        int rearIndex = (frontIndex + count - 1) % capacity;
        return data[rearIndex];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};
