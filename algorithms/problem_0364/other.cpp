class Solution {
public:
    int help(vector<NestedInteger>& nestedList, int depth){
        int sum = 0;
        for (auto & v : nestedList){
            if (v.isInteger()){
                maxDepth = max (maxDepth, depth);
                numsum += v.getInteger();
                sum += v.getInteger() * (1 - depth);
            } else {
                sum += help (v.getList(), depth + 1);
            }
        }
        return sum;
    }

    int depthSumInverse(vector<NestedInteger>& nestedList) {
        return help (nestedList, 1) + maxDepth * numsum;
    }
    int maxDepth = 1;
    int numsum = 0;
};
