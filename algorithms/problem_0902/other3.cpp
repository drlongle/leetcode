class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& my_digits, int limit) {
        int sum=0;
        vector<int>digits;
        for(string s:my_digits){
            digits.push_back(stoi(s));
        }
        int temp=limit;
        int n=0;
        int rem;
        list<int>limit_num;
        while(temp>0){
            rem=temp%10;
            limit_num.push_front(rem);
            temp/=10;
            n++;
        }
        int d=digits.size();
        for(int i=1;i<n;i++){
            sum=sum+pow(d, i);
        }
        bool flag=true;
        while(!limit_num.empty()){
            int num=limit_num.front();
            limit_num.pop_front();
            int l=0;
            if(!flag)
                continue;
            flag=false;
            for(int i=0;i<digits.size();i++){
                if(digits[i] < num || (limit_num.size()==0 && digits[i]<=num))
                    l++;
                if(digits[i] == num)
                    flag=true;
            }
            sum=sum+l*pow(d,limit_num.size());
        }
        return sum;
    }
};