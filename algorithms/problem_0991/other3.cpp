class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ans=0;
        while(X<Y){
            if(Y % 2){ // Y is odd
                // do (opposite operation to X-1) or Y+1
                ++Y;
                ++ans;
            }
            else{ // Y is even
                // do (opposite operation of X*2) or Y/2
                Y=Y>>1; // Y/2 same as Y>>1
                ++ans;
            }
        }
        return ans+X-Y; // if X>Y then the only way to change X to Y is by subtraction
    }
};
