class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(X==Y) return 0; // no operation required as X and Y are already same

        if(X>Y) return X-Y; // only way to change X to Y is by subtraction

        if(Y % 2){ // Y is odd
            // do (opposite operation to X-1) or Y+1
            return 1 + brokenCalc(X, Y+1);
        }
        else{ // Y is even
            // do (opposite operation of X*2) or Y/2
            return 1 + brokenCalc(X, Y>>1); // Y/2 same as Y>>1
        }
    }
};
