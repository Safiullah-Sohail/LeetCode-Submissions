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
    vector<int> modes;
    vector<pair<int, int>> freq;
    bool increm(int val)
    {
        for (int n = 0; n < freq.size() && freq.size() > 0; n++)
        {
            if (freq[n].first == val)
            {
                freq[n].second++;
                return true;
            }
        }
        return false;
    }
    void traversal(TreeNode* root)
    {
        pair<int, int> temp;
        int extra;
        if (root)
        {
            if (increm(root->val)) {}
            else
            {
                extra = root->val;
                temp = make_pair(extra, 1);
                freq.push_back(temp);
            }
            if (root->left != NULL)
                traversal(root->left);
            if (root->right != NULL)
                traversal(root->right);
        }
    }
    void checkHighest()
    {
        int highest = 0;
        for (int n = 0; n < freq.size(); n++)
        {
            if (freq[n].second > highest)
            {
                highest = freq[n].second;
                modes.clear();
                modes.push_back(freq[n].first);
            }
            else if (freq[n].second == highest)
            {
                modes.push_back(freq[n].first);
            }
        }
    }
    vector<int> findMode(TreeNode* root)
    {
        if (!root)
        {
            return modes;
        }
        if (root->left == NULL && root->right == NULL)
        {
            modes.push_back(root->val);
            return modes;
        }
        traversal(root);
        checkHighest();
        return modes;
    }
};