class Solution {
  public:
    double epsilon =
        pow(10.0, -5); // needed in order to compare floating/dobule numbers, as
                       // the division is real divison
    vector<char> operators = {'+', '-', '*',
                              '/'}; // set of operations supported

    bool judgePoint24(vector<int> &cards) {
        vector<double> vec;
        for (const auto i : cards) {
            vec.push_back(
                i * 1.0); // convert the input cards which is in int to double
        }
        return find24(vec);
    }

    bool find24(vector<double> &vec) {
        if (vec.size() == 1) {
            return (abs(vec[0] - 24.0) <= epsilon);
        }

        for (int i = 0; i < vec.size(); ++i) {
            for (int j = 0; j < vec.size(); ++j) {
                // we will consider 2 input numbers at a time to perform math
                // operation
                if (i == j)
                    continue;
                vector<double> res;

                for (int k = 0; k < vec.size(); ++k) {
                    // this for loop is required to copy the numbers that are
                    // not included in the math operation
                    if (k != i && k != j)
                        res.push_back(vec[k]);
                }

                // perform the math operation now
                for (auto op : operators) {
                    if ((op == '+' || op == '*') &&
                        i > j) //  commutative property avoid recalculating as
                               //  i+j == j+i and i*j == j*i
                        continue;
                    if (op == '/' && vec[j] == 0.0)
                        continue; // avoid divide by zero error
                    switch (op) {
                    case '+':
                        res.push_back(vec[i] + vec[j]);
                        break;
                    case '-':
                        res.push_back(vec[i] - vec[j]);
                        break;
                    case '*':
                        res.push_back(vec[i] * vec[j]);
                        break;
                    case '/':
                        res.push_back(vec[i] / vec[j]);
                        break;
                    }
                    if (find24(res))
                        return true;
                    res.pop_back();
                }
            }
        }
        return false;
    }
};
