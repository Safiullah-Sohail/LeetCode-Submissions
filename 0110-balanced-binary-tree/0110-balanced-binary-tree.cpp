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
    bool flag = true;
    int height(TreeNode *root)
    {
        if(!root)
        {
            return 0;
        }
        int lftHeight = height(root->left);
        int rghHeight = height(root->right);
        if(lftHeight - rghHeight > 1 || lftHeight - rghHeight < -1)
        {
            flag = false;
        }
        int hght = max(lftHeight, rghHeight) + 1;
        return hght;
    }
    bool isBalanced(TreeNode *root)
    {
        height(root);
        return flag;
    }
};