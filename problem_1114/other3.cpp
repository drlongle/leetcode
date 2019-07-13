
// Use atomic
Foo() : i(0) {

}

atomic_int i;

void first(function<void()> printFirst) {
    printFirst();
    i=1;
}

void second(function<void()> printSecond) {
    while(i!=1){}
    printSecond();
    i=2;
}

void third(function<void()> printThird) {
    while(i!=2){}
    printThird();
}

// Use two atomic
class Foo {
    atomic<bool> f1;
    atomic<bool> f2;
public:
    Foo():f1(false), f2(false) {
        
    }

    void first(function<void()> printFirst) {
        printFirst();
        f1=true;
    }

    void second(function<void()> printSecond) {
        while(!f1)
        {

        }
        printSecond();
        f2 = true;
    }

    void third(function<void()> printThird) {
        while(!f2)
        {

        }
        printThird();
    }
};

