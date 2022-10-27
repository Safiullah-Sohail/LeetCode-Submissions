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
    void traversal(TreeNode *root, vector<int> *numbers)
    {
        if (!root)
            return;
        traversal(root->left,numbers);
        numbers->push_back(root->val);
        traversal(root->right,numbers);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> numbers;
        traversal(root,&numbers);
        return numbers[k - 1];
    }
};