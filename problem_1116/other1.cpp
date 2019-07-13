
class ZeroEvenOdd {
private:
    int n;
    mutex mtx;
    int length;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->length = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function printNumber) {
        while(length < 2*n){
            mtx.lock();
            if ((length < 2*n) && length%2 == 0){
                printNumber(0);
                length++;
            }
            
            
            mtx.unlock();
            std::this_thread::sleep_for (std::chrono::milliseconds(1));
        }
    }

    void even(function printNumber) {
        while(length < 2*n){
            mtx.lock();
            if ((length < 2*n) && (length+1)%4 == 0){
                printNumber(2*(length/4 + 1));
                length++;
            }
            
            
            mtx.unlock();
            std::this_thread::sleep_for (std::chrono::milliseconds(2));
        }
    }

    void odd(function printNumber) {
        while(length < 2*n){
            mtx.lock();
            if ((length < 2*n) && (length-1)%4 == 0){
                printNumber(1 + 2*(length/4));
                length++;
            }
            
            mtx.unlock();
            
            std::this_thread::sleep_for (std::chrono::milliseconds(3));
        }
    }
};

