/*
Binary Lifting

ok so there is concept of binary lifting,
what is binary lifting ??

So any number can be expressed power of 2,
and we can greedily find that ,
by taking highest powers and taking the modulo,
or just utilising the inbuilt binary format that
how numbers are stored in computer,
so we know how to represent k in binary format,
so now using the same concept we will jump on k height using binary powers,
and remove the highest power ,
but here we must know the 2^i th height parent from every node,
so we will preprocess the tree as shown in the code,
so u could see as 2^i = 2^(i-1) + 2^(i-1),
so if we calculated 2^(i-1) th parent of every node beforehand
we could calculate 2^i th parent from that,
like 2^(i-1) th parent of 2^(i-1) th parent of the node,
right like 4th parent is 2nd parent of 2nd parent of node,
this is called binary lifting.

so now utilise the binary version of k and jump accordingly.
I have also made parent of 0 to -1,
so that I could stop if I went above the node.
*/

class TreeAncestor
{
public:
    vector<vector<int>> v;
    TreeAncestor(int n, vector<int> &parent)
    {
        vector<vector<int>> par(n, vector<int>(20));
        for (int i = 0; i < n; i++)
            par[i][0] = parent[i];
        for (int j = 1; j < 20; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (par[i][j - 1] == -1)
                    par[i][j] = -1;
                else
                    par[i][j] = par[par[i][j - 1]][j - 1]; // par[i][j] means 2^j-th ancestor of i
            }
        }
        swap(v, par);
    }
    int getKthAncestor(int node, int k)
    {
        for (int i = 0; i < 20; i++)
        {
            if ((k >> i) & 1)
            {
                node = v[node][i];
                if (node == -1)
                    return -1;
            }
        }
        return node;
    }
};
