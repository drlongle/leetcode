class H2O {
public:
  
    struct Semaphore {
        Semaphore (int count_ = 0): count(count_) {}

        inline void unlock() {
            std::unique_lock<std::mutex> lock(mtx);
            ++count;
            cv.notify_one();
        }

        inline void lock() {
            std::unique_lock<std::mutex> lock(mtx);
            while (count == 0) cv.wait(lock);
            --count;
        }
    
    private:
        std::mutex mtx;
        std::condition_variable cv;
        int count;
    } h, o;

    std::mutex mtx;
    std::condition_variable cv;
    int rcnt = 0;
  
    H2O(): h(2), o(1) {}

    void wait_released_all() {
        std::unique_lock<std::mutex> lock(mtx);

        if (++rcnt == 3) {
            rcnt = 0;
            cv.notify_all();
        } else {
            cv.wait(lock);
        }
    }

    void hydrogen(function<void()> releaseHydrogen) {
        std::lock_guard<Semaphore> hg(h);
        releaseHydrogen();
        wait_released_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::lock_guard<Semaphore> og(o);
        releaseOxygen();
        wait_released_all();
    }
};

