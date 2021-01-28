class MyCircularQueue {
public:
    int front=0,rear=0,count=0;
    vector<int>arr;
    int k;
    MyCircularQueue(int k) {
        this->k=k;
        arr.resize(k,-1);
    }

    bool enQueue(int value) {
        if(count==k)return false;
        arr[rear] = value;
        rear = (rear+1)%k;
        count++;
        return true;
    }

    bool deQueue() {
        if(count==0)
            return false;
        arr[front]=-1;
        front = (front+1)%k;
        count--;
        return true;
    }

    int Front() {
        return arr[front];
    }

    int Rear() {
        return arr[(rear-1+k)%k];
    }

    bool isEmpty() {
        return count==0;
    }

    bool isFull() {
        return count==k;
    }
};
