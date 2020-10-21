class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int>v;                      //output vector
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            if(a[i] >= 0)v.push_back(a[i]);       // if asteroid is positive push in vector 
            else
            {
                if(v.size()==0 or v[v.size()-1] <0)v.push_back(a[i]);  // if vector is empty or top asteroid is negative , push it in vector 
                else if(v[v.size()-1]  < abs(a[i])){v.pop_back();i--;} // if top asteroid in vector is less than current asteroid then pop asteroid and i-- to check for asteroids in vector 
                else if(v[v.size()-1]  == abs(a[i]))v.pop_back(); //if they are same pop the asteroid from vector
            }
        }
        return v;          // finally return our output vector
    }
};
