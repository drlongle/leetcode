class Solution {
    // keep track of four things: info. about leaf nodes, info. about target nodes
    struct record {
        int dist2leaf; // edge count from current to its closest leaf node
        TreeNode* c_leaf;  //closest leaf

        bool reachingTarget; // if from current root , we can go downwards and reach target
        int dist2target;

        record () {
            dist2leaf=INT_MAX;
            c_leaf= NULL;
            reachingTarget=false;
            dist2target=INT_MAX;
        };
    };

    // bottom up traversal: postorder
    // basics: find closest leaf nodes for each current node

    // Then add shortest distance to target from current node
    //    the trick is not to go up then down to form paths, but always look downwards
    //    and combine two downwards paths into one single path!
    record postorder(TreeNode* root)
    {
        // empty node
        if (!root)
        {
            record r;    return r;
        }

        // valid node: check its left and right subtree to find closest leaf node
        record r1= postorder (root->left);
        record r2= postorder (root->right);

        record p;

        if (r1.dist2leaf!=INT_MAX || r2.dist2leaf!=INT_MAX )
            p.dist2leaf= min (r1.dist2leaf, r2.dist2leaf)+1;
        else
            p.dist2leaf = 0; // this is a leaf

        if (r1.dist2leaf < r2.dist2leaf)
            p.c_leaf= r1.c_leaf;
        else
            p.c_leaf= r2.c_leaf;
        if (p.c_leaf==NULL)  p.c_leaf= root;

        // now logic to find target node K
        // two tasks:  shortest distance from root to K + root to closest leaf
        //             obtain path from K to closest leaf
        if (root->val==_k)
        {
            p.reachingTarget=true;
            p.dist2target=0; // the path 1: downwards from self

            // consider the downwards half path:  K to closest leaf
            // using target-> left  to update global optimal solution.
            if (p.dist2leaf< min_len)
            {
                min_len = p.dist2leaf;
                leaf_id= p.c_leaf->val;
            }
        }

        // now compose the path crossing root, reaching target in one or two half paths
        // we don't explicitly store this bend path at all.
        if (r1.reachingTarget || r2.reachingTarget)
        {
            // update its own reaching target info
            p.reachingTarget =true;
            p.dist2target = min( r1.dist2target,  r2.dist2target) +1;
            // now compose the path crossing root
            if (p.dist2target + p.dist2leaf < min_len)
            {
                min_len=p.dist2target + p.dist2leaf;
                leaf_id = p.c_leaf->val;
            }
        }
        return p;
    }
    int _k ;
    int min_len;
    int leaf_id; // the global closest leaf to k
public:
    int findClosestLeaf(TreeNode* root, int k) {
        _k=k; min_len=INT_MAX;

        record r = postorder (root);

        if (min_len==INT_MAX)
            return -1;
        return leaf_id;
    }
};
