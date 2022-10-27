/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool exists(vector<int> vec,int val)
    {
        if(vec.size() == 0)
            return false;
        for(int n=0 ; n<vec.size() ; n++)
        {
            if(vec.at(n) == val)
            {
                return true;
            }
        }
        return false;
    }
    bool solve(TreeNode *root, vector<int> &vec, int val)
    {
        if (!root)
        {
            return false;
        }
        if (exists(vec,val - root->val))
        {
            return true;
        }   
        vec.push_back(root->val);
        return solve(root->left, vec, val) || solve(root->right, vec, val);
    }
    bool findTarget(TreeNode *root, int val)
    {
        vector<int> vec;
        return solve(root, vec, val);
    }
};