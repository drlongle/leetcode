class Solution 
{
public:
    bool circularArrayLoop(vector<int>& nums) 
    {
         //set array element to 0 if cycle is not possible using this element 
         for(int i=0;i<nums.size();i++)  //removing self loops(cycles of length 1)
         {
             if(abs(nums[i])%nums.size()==0)
                nums[i]=0; 
             else
             {
                 if(nums[i]<0)
                    nums[i]=-1*(abs(nums[i])%nums.size());
                 else
                    nums[i]=nums[i]%nums.size(); 
             }
         }   
         //now if there is a cycle it will always be of length >1
         int i,j,len,order;  
         //if order=-1 it means backward
         //if order=+1 it means forward
         for(int k=0;k<nums.size();k++)
         {
             if(nums[k]!=0)
             {
                i=j=k;
                len=0;
                if(nums[i]<0)          order=-1;
                else /*if(nums[i]>0)*/ order=+1;
                while(1)
                {
                    if(order==+1)
                    {
                        if(nums[j]>0)
                        {
                            j=(j+nums[j])%nums.size();
                            len++;
                        }
                        else //if(nums[j]<0||nums[j]==0)
                        {
                            while(i!=j)
                            {
                                int t=nums[i];
                                nums[i]=0;
                                i=(i+t)%nums.size();
                            }
                            break;
                        }
                    }
                    else //if(order==-1)
                    {
                        if(nums[j]<0)
                        {
                            j=(j+nums[j]>=0?(j+nums[j]):(nums.size()+j+nums[j]));
                            len++;
                        }
                        else //if(nums[j]>0||nums[j]==0)
                        {
                            while(i!=j)
                            {
                                int t=nums[i];
                                nums[i]=0;
                                i=(i+t>=0?(i+t):(nums.size()+i+t));
                            }
                            break;
                        }
                    }
                    if(j==i||len>nums.size())
                       return true; 
                }
             }
         }
         return false;    
    }
};
