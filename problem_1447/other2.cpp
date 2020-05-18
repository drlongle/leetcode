class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        set<double> vals;                         //Track decimal form values of all fractions encountered--eliminates need to factorize
        for (int den = 2; den <= n; den++)        //Iterate through denominators from smallest to greatest to ensure simplified forms of fractions are encountered first
            for (int num = 1; num < den; num++){
                double d = (double) num/(double) den;
                if (vals.count(d) == 0){
                    ans.push_back(to_string(num)+"/"+to_string(den));     //Store fractions if the decimal form value has not been encountered
                    vals.insert(d);
                }
            }
        return ans;
    }
};
