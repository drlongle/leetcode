// Apparently it is all about locking in the same order to avoid deadlock
class DiningPhilosophers {
public:
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int first  = philosopher;
        int second = (philosopher+N-1)%N;
        // to avoit deadlock: lock the mutex with smallest number first
        if (first > second) {
            swap(first, second);
        }

        forkMutexes_[first ].lock();
        forkMutexes_[second].lock();
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        forkMutexes_[second].unlock();
        forkMutexes_[first ].unlock();        
    }
private:
    static constexpr int N = 5;
    mutex forkMutexes_[N];
};
