#include <functional>
#include <string>

std::string &ltrim(std::string &s) {
    using namespace std;

    s.erase(s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

std::string &rtrim(std::string &s) {
    using namespace std;

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

std::string &trim(std::string &s) { return rtrim(ltrim(s)); }
