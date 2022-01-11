
class ZeroEvenOdd {
private:
    int const n;
    int                  state;
    std::mutex             mtx;
    std::condition_variable cv;
  
    static constexpr int ODD_ZERO  = 0;
    static constexpr int ODD_NUM   = 1;
    static constexpr int EVEN_ZERO = 2;
    static constexpr int EVEN_NUM  = 3;

public:
    ZeroEvenOdd(int n) : n(n), state(ODD_ZERO) {}
  
    void progressState() {
        ++state %= 4;
        cv.notify_all();
    }
  
    void zero(function<void(int)> printNumber) {
        std::unique_lock<std::mutex> lock(mtx);
        for (int i = 0; i < n; ++i) {
            cv.wait(lock, [this]{ return state % 2 == 0; });
            printNumber(0);
            progressState();
        }
    }

    void even(function<void(int)> printNumber) {
        std::unique_lock<std::mutex> lock(mtx);
        for (int i = 2; i <= n; i += 2) {
            cv.wait(lock, [this]{ return state == EVEN_NUM; });
            printNumber(i);
            progressState();
        }
    }

    void odd(function<void(int)> printNumber) {
        std::unique_lock<std::mutex> lock(mtx);
        for (int i = 1; i <= n; i += 2) {
            cv.wait(lock, [this]{ return state == ODD_NUM; });
            printNumber(i);
            progressState();
        }
    }
};


