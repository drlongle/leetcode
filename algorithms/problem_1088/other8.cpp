class Solution {
    int max;
    int count = 0;
    array<int, 5> digits = {{0, 1, 6, 8, 9}};
    unordered_map<int, int> rotations = {
            {0, 0},
            {1, 1},
            {6, 9},
            {8, 8},
            {9, 6}
    };

    void dfs(int candidate, int candidate_rotated, int power = 1) {
        if (candidate != candidate_rotated) {
            // cout << "Counting " candidate << ", " << candidate_rotated << endl;
            count++;
            // Do not short circuit here. Still need to iterate neighbors.
            // Example: the pair 11,11 is not counted, but its neighbor 118,811 is counted.
        }

        for (const auto& next_digit : digits) {
            // Add digit to the right of the current candidate
            // Example:
            // candidate = 19
            // candidate * 10: 190
            // next_digit = 6
            // 190 + 6 = 196
            long long next_value = static_cast<long long>(candidate) * 10 + next_digit;

            // Better to break here than check at the beginning of the recursive loop
            // since all values hereafter will be greater (since we have sorted our
            // list of digits).
            // Example:
            // max = 100
            // candidate = 10
            // next_value = 100 (ok)
            // next_value = 101 (greater than max)
            // value after next_value = 106 (also greater than max)
            // 108 and 109 also are greater than max
            if (next_value > max) {
                break;
            }

            // Add rotated digit to the left of the current rotated candidate
            // Example:
            // next_digit: 6
            // candidate_rotated: 61
            // rotations[next_digit]: 9
            // pow(10, power): 100
            // 9 * 100: 900
            // 900 + 61 -> 961
            int next_rotated = rotations[next_digit] * pow(10, power) + candidate_rotated;

            // Recurse
            dfs(next_value, next_rotated, power + 1);
        }
    }

public:
    int confusingNumberII(int N) {
        max = N;

        // Exclude 0,0
        for (int i = 1; i < digits.size(); ++i) {
            const int& digit = digits[i],
                    rotated_digit = rotations[digit];
            dfs(digit, rotated_digit);
        }

        return count;
    }
};
