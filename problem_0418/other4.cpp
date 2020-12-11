/*
Basic idea of the solution is to first construct an information array storing the situation of each word
happening at the start of a line, i.e., where in a sentence does this line ends (next_i) and how many
ends of sentence (periods) this line would contain.

Then, we would simulate a placing of words for all the rows we have. It's not really word-by-word
placement, but only counting next line's starting word and the line's periods based on our information
array.

Complexity:
Time Complexity: O(sentence.size() + cols)
To construct the information array - O(sentence.size())
For the first word's situation, we only loop through all words <2 times by skip counting of same cycles.
For other words, since in each loop we delete the last word at beginning and try to add more words to the end, each word would appear exactly once when we finish this cycle of deleting the first word in line and extending forward and end up at having the first word in sentence as the first word in line again.
To simulate word placing on each rows - O(cols)
Space Complexity (extra): O(sentence.size())
 */

/**
  * Tuple to store some information.
  * Intention is to store, for each word of the sentence placed at the beginning of the
  * line, which word would be placed at the start of next line (next_i), and how many
  * end of sentences (periods) would be placed in on this line.
  */
struct Tuple {
    int next_i;
    int periods;

    Tuple(int _next_i, int _periods) : next_i(_next_i), periods(_periods) {}
};

/**
  * This overload is only a helper for print debugging.
  * It does not serve any purpose in the actual solution.
  */
ostream& operator<<(ostream& os, Tuple const& tuple) {
    os << "(" << tuple.next_i << "," << tuple.periods << ")";
    return os;
}

/**
  * This overload is only a helper for print debugging.
  * It does not serve any purpose in actual solution, but would be a helpful tool
  * reusable for all LeetCode studies.
  */
template <class T>
ostream& operator<<(ostream& os, vector<T> const& v) {
    for (int i = 0; i < v.size()-1; i++) {
        os << v[i] << ", ";
    }
    os << v[v.size()-1] << ";";
    return os;
}

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        vector<Tuple> tuples;

        int remaining_space = cols, next_i = 0, periods = 0;
        // Some redundant comparison to prevent int(-1) > size_t(5) error from casting.
        while (remaining_space > 0 && remaining_space >= sentence[next_i].size()) {
            remaining_space  -= sentence[next_i++].size() + 1;
            if (next_i == sentence.size()) {
                next_i = 0;
                periods++;
            }
            // Save some counting if line is long enough to cycle sentence twice.
            if (next_i == 0 && periods > 0) {
                periods += remaining_space / (cols - remaining_space);
                remaining_space = remaining_space % (cols - remaining_space);
            }
        }
        // If starting word is longer than the line - screen is blown up.
        if (next_i == 0 && periods == 0) {
            return 0;
        }
        tuples.emplace_back(next_i, periods);

        for (int i = 1; i < sentence.size(); i++) {
            // for each subsequent word to be placed at start of line, simply free up
            // space taken by previous word, and try to extend to end of line from the
            // previous last word position.
            remaining_space += sentence[i-1].size() + 1;
            while (remaining_space > 0 && remaining_space >= sentence[next_i].size()) {
                remaining_space  -= sentence[next_i++].size() + 1;
                if (next_i == sentence.size()) {
                    next_i = 0;
                    periods++;
                }
            }
            // If starting word is longer than the line - screen is blown up.
            if (next_i == i && periods == 0) {
                return 0;
            }
            tuples.emplace_back(next_i, periods);
        }

        int cursor = 0;
        int reps = 0;
        for (int i = 0; i < rows; i++) {
            reps += tuples[cursor].periods;
            cursor = tuples[cursor].next_i;
        }

        return reps;
    }
};
