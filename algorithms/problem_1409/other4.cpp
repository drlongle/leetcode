/*
Fenwick Tree

Naive approach :
Find the position of the element,
Pick every element in quire[I] and insert it in the beginning of the array
Update the position of all the elements after the 0

We can implement, it using a vector
The time complexity = O(n^2) and space complexity = O(n)

Better Approach :
We can observe that we have 3 operations that needed to be performed
1.Push_front :
2.Find the index of a number
3.Update the index’s of the rest of the elements from index 1

We can keep the elements in a sorted manner using a treeset/set.
However finding the position of element by looking at the number of elements < or > element[I] would take O(n) which brings the time complexity to O(n^2)

An efficient Data structure that can find the number of elements < or > an element[I] is Fenwick tree.

I use fenwick tree to solve the problem.
The idea is instead of pushing the element to the front i.e assigning an index 0 for every query.
I assign -1 for the first query, -2 for the second query, -3 for the third …
By doing so we can observe that range of index’s = [-m,m]
However we know that array index cannot be negative, Hence i encode it such that
-m = 0
-m+1 = 1
-m+2 = 2
.
.
.
m=2m.
Basically right shifting the range to start from 0.
By doing so our new range is [0,2m]

Operations we perform:
We initialize our Fenwick tree of size 2m
Set all the values from [1…m] i.e [m..2m] to 1
For every query
we find its postion by finding the number of set elements < the given query.
we set it's postion to 0 in fenwick tree
set its new to -1,-2,-3 i.e (m,m-1,m-2)

Time complextiy : O(nlogn), space(2m)
*/

class Solution {
public:
    void update(vector<int>& tree,int i,int val) {
        while(i<tree.size()) {
            tree[i]+=val;
            i+=(i&(-i));
        }
    }
    
    int getSum(vector<int>& tree,int i) {
        int s = 0;
        while(i>0) {
            s+=tree[i];
            i-=(i&(-i));
        }
        return s;
    }
    
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> res,tree((2*m)+1,0);
        unordered_map<int,int> hmap;
        for(int i=1;i<=m;++i) {
            hmap[i] = i+m;
            update(tree,i+m,1);
        }

        for(int querie : queries) {
            res.push_back(getSum(tree,hmap[querie])-1);
            update(tree,hmap[querie],-1);
            update(tree,m,1);
            hmap[querie] = m;
            m--;
        }  
        return res;     
    }
};
