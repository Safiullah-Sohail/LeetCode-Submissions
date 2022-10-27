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
    TreeNode *getSucessor(TreeNode *current)
    {
        current = current->right;
        while (current != NULL && current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }
    TreeNode *deleteNode(TreeNode *root, int value)
    {
        if (root == NULL)
        {
            return root;
        }
        if (root->val > value)
        {
            root->left = deleteNode(root->left, value);
        }
        else if (root->val < value)
        {
            root->right = deleteNode(root->right, value);
        }
        else
        {
            if (root->left == NULL)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                TreeNode *scssr = getSucessor(root);
                root->val = scssr->val;
                root->right = deleteNode(root->right, scssr->val);
            }
        }
        return root;
    }
};