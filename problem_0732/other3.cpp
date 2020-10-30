class Node {
public:
    int start, end, mid, total, lazy;
    Node *left, *right;
    Node(int start, int end, int lazy): start(start), end(end), total(lazy), lazy(lazy), left(NULL), right(NULL) {
        mid = start + ((end - start) >> 1);
    }

    Node* getLeft() {
        if (left) left->lazy += lazy,left->total += lazy;
        return left ? left : left = new Node(start, mid, lazy);
    }

    Node* getRight() {
        if (right) right->lazy += lazy,right->total += lazy;
        return right ? right : right = new Node(mid, end, lazy);
    }

    void update(int start, int end) {
        if (start >= end) return;
        if (start == this->start && this->end == end) {
            lazy++;total++;
        } else {
            getLeft()->update(start, min(mid, end));
            getRight()->update(max(start, mid), end);
            lazy = 0,total = max(left->total, right->total);
        }
    }
};
class MyCalendarThree {
private:
    Node *root;
public:
    MyCalendarThree() {
        root = new Node(0, 1000000000, 0);
    }

    int book(int start, int end) {
        root->update(start, end);
        return root->total;
    }
};
