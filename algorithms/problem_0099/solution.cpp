/*
99. Recover Binary Search Tree

Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

Solution sketch:

First, walk the BST to see to found pairs of nodes that violate the BST
property. The walk is done in the same way for checking whether a BST is valid.

To fix the BST; we first attempt to swap each pair of conflicting nodes and
check whether we have a valid BST.

If we still do not have a valid BST, we now attempt to swap conflicting nodes.
Eventually, one of our awap attempts will fix the problem.
*/

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <string.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Candidate
{
    enum Violate_type
    {
        LEFT = 0,
        RIGHT = 1
    };

    Candidate(TreeNode* a, TreeNode* d, Violate_type type):
        m_ancestor(a), m_descendent(d), m_type(type)
    {

    }

    TreeNode* m_ancestor;
    TreeNode* m_descendent;
    Violate_type m_type;
};

struct Bad_node
{
    Bad_node(TreeNode* node, int c): m_node(node), m_count(c)
    { }

    TreeNode* m_node;
    int m_count;
};

class Solution {
public:
    string serialize(TreeNode* root)
    {
        ostringstream oss;
        queue<TreeNode*> nodes;

        nodes.emplace(root);
        while(nodes.size())
        {
            TreeNode* node = nodes.front();
            if (node != root)
                oss << ",";
            if (node != NULL)
            {
                oss << node->val;
                nodes.emplace(node->left);
                nodes.emplace(node->right);
            }
            else
                oss << "null";
            nodes.pop();
        }

        return oss.str();
    }

    TreeNode* deserialize(const string& input)
    {
        istringstream iss(input);
        queue<TreeNode*> nodes;
        TreeNode* root = NULL;
        string s;

        if (!getline(iss, s, ','))
            return NULL;
        if (s == "null")
            return NULL;
        root = new TreeNode(atoi(s.c_str()));
        nodes.emplace(root);

        while(nodes.size())
        {
            TreeNode* parent = nodes.front();
            nodes.pop();
            if (parent == NULL)
                continue;
            if (!getline(iss, s, ','))
                break;
            TreeNode* left = NULL;
            if (s != "null")
                left = new TreeNode(atoi(s.c_str()));
            nodes.emplace(left);
            parent->left = left;

            if (!getline(iss, s, ','))
                break;
            TreeNode* right = NULL;
            if (s != "null")
                right = new TreeNode(atoi(s.c_str()));
            nodes.emplace(right);
            parent->right = right;
        }

        return root;
    }

    void recoverTree(TreeNode* root) {
        vector<Candidate> candidates;
        map<TreeNode*, int> bad_nodes;
        vector<Bad_node> bad;
        TreeNode* min_node;
        TreeNode* max_node;

        find_bad_nodes(root, min_node, max_node, candidates);

        switch (candidates.size())
        {
        case 1:
            swap(candidates.front().m_ancestor->val,
                candidates.front().m_descendent->val);
            break;

        case 2:
        case 3:
        default:
            for (const auto& c : candidates)
            {
                vector<Candidate> temp;
                swap(c.m_ancestor->val, c.m_descendent->val);
                find_bad_nodes(root, min_node, max_node, temp);
                if (temp.empty())
                    return; 
                else swap(c.m_ancestor->val, c.m_descendent->val);
            }

            for (const auto& c : candidates)
            {
                ++bad_nodes[c.m_ancestor];
                ++bad_nodes[c.m_descendent];
            }

            for (const auto& b : bad_nodes)
                bad.emplace_back(b.first, b.second);

            sort(bad.begin(), bad.end(),
                [](const Bad_node& a, const Bad_node& b)
                { return a.m_count > b.m_count;});
            for (size_t i = 0; i < bad.size(); ++i)
                for (size_t j = i+1; j < bad.size(); ++j)
                {
                    vector<Candidate> temp;
                    swap(bad[i].m_node->val, bad[j].m_node->val);
                    find_bad_nodes(root, min_node, max_node, temp);
                    if (temp.empty())
                        return; 
                    swap(bad[i].m_node->val, bad[j].m_node->val);
                }
            break;
        case 0:
            cout << "Error. Found " << candidates.size() << " candidates!\n";
        }
    }

    void find_bad_nodes(TreeNode* root, TreeNode*& min_node,
        TreeNode*& max_node, vector<Candidate>& candidates)
    {
        if (!root)
        {
            min_node = max_node = 0;
            return;
        }
        else
            min_node = max_node = root;

        if (root->left)
        {
            TreeNode* min_left;
            TreeNode* max_left;
            find_bad_nodes(root->left, min_left, max_left, candidates);
            if (min_left->val > root->val)
                candidates.emplace_back(root, min_left, Candidate::LEFT);
            if (max_left != min_left && max_left->val > root->val)
                candidates.emplace_back(root, max_left, Candidate::LEFT);
            if (min_node->val > min_left->val)
                min_node = min_left;
            if (min_node->val > max_left->val)
                min_node = max_left;
            if (max_node->val < min_left->val)
                max_node = min_left;
            if (max_node->val < max_left->val)
                max_node = max_left;
        }

        if (root->right)
        {
            TreeNode* min_right;
            TreeNode* max_right;
            find_bad_nodes(root->right, min_right, max_right, candidates);
            if (min_right->val < root->val)
                candidates.emplace_back(root, min_right, Candidate::RIGHT);
            if (max_right != min_right && max_right->val < root->val)
                candidates.emplace_back(root, max_right, Candidate::RIGHT);
            if (min_node->val > min_right->val)
                min_node = min_right;
            if (min_node->val > max_right->val)
                min_node = max_right;
            if (max_node->val < min_right->val)
                max_node = min_right;
            if (max_node->val < max_right->val)
                max_node = max_right;
        }
    }
};

int main()
{
    Solution sol;
    string input;
    input = "3,1,4,null,null,2";

    TreeNode* root = sol.deserialize(input);
    sol.recoverTree(root);
    cout << sol.serialize(root) << endl;

    return 0;
}
