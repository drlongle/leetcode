class Solution {
public:
    int minFlips(string target) {
        int n = target.size();                          // Total bulbs.
        int flips = 0;                                  // Final answer.
        char status = '0';                              // This stores the status of bulbs that are
                                                        // ahead of current index `i`.
        for (int i=0; i<n; i++) {                       // For each bulb =
            if (status != target[i]) {                  // If what we want is different from what
                                                        // it is at this moment, make a flip.
                flips++;                                // We made a flip.
                status = status == '0' ?  '1' : '0';    // Now status of remaining
                                                        // bulbs have changed.
            }
        }
        return flips; // Awesome, return the answer now.
    }
};
