class Solution 
{
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
         sort(products.begin(),products.end());
         vector<vector<string>> vec(searchWord.size());
         for(int i=0;i<products.size();i++)
         {
             for(int k=0;k<searchWord.size();k++)
             {
                 if(searchWord[k]==products[i][k])
                 {
                    if(vec[k].size()<3)
                       vec[k].push_back(products[i]);
                 }    
                 else
                    break; 
             }
         }
         return vec;
    }
};
