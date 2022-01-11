class Solution {
    // Generate candidates, time complexity ??? masters theorem needed
    void generateWeirdNumbers(vector<int> &set, unsigned int candidate, const int n) {
        static const int N = 5;
        static const int table[N] = {0, 1, 6, 8, 9};

        // Our base case
        if (candidate > n) {
            return;
        }

        // Add to set, if its a wierd number
        if (getTransform(candidate) != candidate) {
            set.push_back(candidate);
        }

        // Watch for edge case to be a bit faster...
        if (candidate <= 100000000 && candidate * 10 <= n) {
            // Increase the order of the variable
            candidate *= 10;

            // Avoid the infinite recursion for 0 + 10 * 0 + 100 * 0...
            for (int i = (candidate != 0) ? 0 : 1; i < N; i++) {
                generateWeirdNumbers(set, candidate + table[i], n);
            }
        }
    }

    //!< Gets transformation of int, -1 if it cant be done!
    int getTransform(int number) {
        static const int table[] = {0, 1, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 9, INT_MIN, 8, 6};
        int transform = 0;

        while (transform >= 0 && number > 0) {
            transform *= 10;
            transform += table[number % 10];
            number /= 10;
        }
        return (number == 0 && transform >= 0) ? transform : -1;
    }

public:
    int confusingNumberII(int n) {
        vector<int> weirdNumbers;
        int ret = 0;

        //!< Each candidate that doesn't equal its transformed value is a weird number,
        // assuming the candidates won't result in an invalid transformation
        generateWeirdNumbers(weirdNumbers, 0, n);
        return weirdNumbers.size();
    }
};
