#include "KMP.h"

void test1() {
    std::string txt("ABABDABACDABABCABAB");
    std::string pat("ABABCABAB");
    KMPSearch(pat, txt);
}

void test2() {
    std::string txt("abcabcabcabca");
    std::string pat("cabca");
    KMPSearch(pat, txt);
}

int main() {
    test1();
    test2();
    return 0;
}