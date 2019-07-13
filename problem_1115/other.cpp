class FooBar {
private:
    int n;
    bool               fooTime;
    std::mutex             mtx;
    std::condition_variable cv;

public:
    FooBar(int n) : n(n), fooTime(true) {}
  
    void setFooTime(bool ft) {
        fooTime = ft;
        cv.notify_one();
    }

    void foo(function<void()> printFoo) {
        std::unique_lock<std::mutex> lock(mtx);
        for (int i = 0; i < n; i++) {
            cv.wait(lock, [this](){ return fooTime; });
            printFoo();
            setFooTime(false);
        }
    }

    void bar(function<void()> printBar) {
        std::unique_lock<std::mutex> lock(mtx);
        for (int i = 0; i < n; i++) {
            cv.wait(lock, [this](){ return !fooTime; });
            printBar();
            setFooTime(true);
        }
    }
};

