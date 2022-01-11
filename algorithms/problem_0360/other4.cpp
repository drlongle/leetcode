class Solution {
public:
    int A,B,C;
    int f(int x){
        return A*x*x + B*x + C;
    }
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        A = a,B = b,C = c;
        vector<int> img;
        bool inverseAnswer = false;

        if(a!=0){
            // if its a parabola, append the elements further away from the midPoint y
            //inverse if its concavity is up

            inverseAnswer = a > 0 ? true:false;
            double y = -1.0*b/(2*a);

            //points to the furthest elements
            int i = 0,j = nums.size()-1;
            while(i<=j){
                double d1 = abs(nums[i]-y),d2 = abs(nums[j]-y);
                if(d1  >= d2) img.push_back(f(nums[i++]));
                else img.push_back(f(nums[j--]));

            }
        }
            //its a line , so just append the element from left to right if the angular coefficient
            //is greater than 0 , or inverse at the end if b < 0
        else{
            if(b!=0){
                inverseAnswer = b < 0 ? true:false;
                for(int x:nums) img.push_back(f(x));
            }
            else{
                //f(x) = c for all x
                int n = nums.size();
                while(n--) img.push_back(c);
            }
        }
        if(inverseAnswer) reverse(begin(img),end(img));
        return img;
    }
};

