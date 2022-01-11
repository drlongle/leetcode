class H2O {
public:
    void hydrogen(function<void()> releaseHydrogen) {
        wait_until_I_can_join('H');
        wait_until_we_are_ready();
        releaseHydrogen();
        I_am_water_now('H');
    }

    void oxygen(function<void()> releaseOxygen) {
        wait_until_I_can_join('O');
        wait_until_we_are_ready();
        releaseOxygen();
        I_am_water_now('O');
    }

private:
    // constants to define what constitutes a water molecule
    static constexpr int H_PER_WATER = 2;
    static constexpr int O_PER_WATER = 1;
  
    // a mutex to allow atomic read/write operations
    std::mutex critical_section;
  
    // counters to keep track of how many of each type of atom is being processed
    int H_count = 0;
    int O_count = 0;
  
    /////
    ///// Phase 1: Blocking atoms if we already have enough of that type for the current batch.
    /////
  
    std::mutex              join_mtx;
    std::condition_variable join_cv;

    bool can_I_join(char atom) {
        std::lock_guard<std::mutex> guard(critical_section);
        if (atom == 'H' && H_count < H_PER_WATER) { ++H_count; return true; }
        if (atom == 'O' && O_count < O_PER_WATER) { ++O_count; return true; }
        return false;
    }
  
    void wait_until_I_can_join(char atom) {
        std::unique_lock<std::mutex> lock(join_mtx);
        join_cv.wait(lock, [&]{ return can_I_join(atom); });
    }
  
    /////
    ///// Phase 2: Waiting to release atoms until all of them are ready.
    /////
  
    std::mutex              ready_mtx;
    std::condition_variable ready_cv;
  
    bool are_we_ready() {
        std::lock_guard<std::mutex> guard(critical_section);
        return H_count == H_PER_WATER && O_count == O_PER_WATER;
    }
  
    void wait_until_we_are_ready() {
        std::unique_lock<std::mutex> lock(ready_mtx);
        if (are_we_ready()) ready_cv.notify_all();
        else                ready_cv.wait(lock);
    }
  
    /////
    ///// Phase 3: Waiting until all atoms in the group are released until we let new ones in.
    /////
  
    void I_am_water_now(char atom) {
        std::lock_guard<std::mutex> guard(critical_section);
        H_count -= (atom == 'H');
        O_count -= (atom == 'O');
        if (H_count == 0 && O_count == 0)
            join_cv.notify_all();
    }
};
