#include "RKSearch.h"

int main() {
    std::string txt = "GEEKS FOR GEEKS";
    std::string pat = "GEEK";

    // A prime number
    int q = 101;

    // Function Call
    RabinKarp::search(pat, txt, q);
    return 0;
}
