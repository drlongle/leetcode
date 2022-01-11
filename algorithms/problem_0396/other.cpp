/*
Calculate the rotateSum for the initial array. Also calculate the sum of all values in the array.
Now each time for j= 1 to A.size():

Add sum to rotateSum
Sumbract (A.size()) * A[A.size() - j ] from rotateSum
Keep the max value.
*/

class Solution {
public:
    int maxRotateFunction(vector<int> &A) {
        int rotateSum = 0;
        int sum = 0 ;
        for (int i = 0; i < A.size(); i++) {
            rotateSum += i * A[i];
            sum+= A[i];
        }
        //Each time we add sum and subtract (A.size()) * A[A.size() - j ]
        int max = rotateSum;        
        for (int j = 1; j < A.size(); j++) {
            rotateSum += sum - (A.size()) * A[A.size() - j ];
            max = std::max(max, rotateSum);
        }

        return max;
    }
};
