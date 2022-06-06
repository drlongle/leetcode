#pragma once

#include <iostream>
#include <string>

namespace RabinKarp {
static constexpr long long d = 256;

/* pat -> pattern
txt -> text
q -> A prime number
 */
void search(std::string &pat, std::string &txt, int q) {
    int M = pat.size();
    int N = txt.size();
    int i, j;
    long long p = 0; // hash value for pattern
    long long t = 0; // hash value for txt
    long long h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters one by one
        if (p == t) {
            bool flag = true;
            /* Check for characters one by one */
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    flag = false;
                    break;
                }
            }

            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]

            if (j == M)
                std::cout << "Pattern found at index " << i << std::endl;
        }

        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            // We might get negative value of t, converting it
            // to positive
            if (t < 0)
                t = (t + q);
        }
    }
}
} // namespace RabinKarp