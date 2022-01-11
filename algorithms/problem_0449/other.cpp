class Codec {

    private:
    void preOrder(TreeNode* root, string &o) {
        if(!root) {
            o.push_back('#');
            o.push_back(',');
            return;
        }
        
        // o.push_back(root->val);
        o+=to_string(root->val);
        o.push_back(',');
        preOrder(root->left,o);
        preOrder(root->right,o);
    }
    
    vector<string> split(string &a) {
        istringstream x(a);
        string token;
        
        
        vector<string> ans;
        while(getline(x,token,',')){
            ans.push_back(token);
        }
        
        return ans;
        
    }
    
    TreeNode* buildTree(int &i, vector<string> &ss) {
        if(i==ss.size())
            return NULL;
        
        if(ss[i]=="#")
            return NULL;
        
        TreeNode*root=new TreeNode(stoi(ss[i]));
        i+=1;
        root->left = buildTree(i,ss);
        i+=1;
        root->right = buildTree(i,ss);
        
        return root;
        
        
    }
    public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string o="";
        preOrder(root,o);
        // cout<<o<<endl;
        return o;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> ss = split(data);
        int i=0;
        TreeNode* root = buildTree(i,ss);
        
        return root;
    }
};

