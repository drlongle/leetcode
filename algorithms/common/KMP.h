#pragma once

#include <iostream>
#include <string>
#include <vector>

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(std::string &pat, int M, std::vector<int> &lps) {
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            } else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Prints occurrences of pat in txt
void KMPSearch(std::string &pat, std::string &txt) {
    int M = pat.size();
    int N = txt.size();

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    std::vector<int> lps(M, 0);

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            std::cout << "Found pattern " << pat << " at index " << i - j
                      << " of " << txt << std::endl;
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
