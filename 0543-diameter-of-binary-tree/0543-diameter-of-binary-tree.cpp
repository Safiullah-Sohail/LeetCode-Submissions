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
    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        int leftHt = height(root->left);
        int rightHt = height(root->right);
        return 1 + max(leftHt, rightHt);
    }
    int diameterOfBinaryTree(TreeNode* root)
    {
        queue<TreeNode *> que;
        int maxDist = 0;
        if (!root)
            return 0;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            int leftDist = 0;
            int rightDist = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = que.front();
                que.pop();
                if (temp->left != NULL)
                {
                    leftDist = height(temp->left);
                }
                if (temp->right != NULL)
                {
                    rightDist = height(temp->right);
                }
                if (leftDist + rightDist > maxDist)
                {
                    maxDist = leftDist + rightDist;
                }
                if (temp->left != NULL)
                {   
                    que.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    que.push(temp->right);
                }
            }
        }
        return maxDist;
    }
};