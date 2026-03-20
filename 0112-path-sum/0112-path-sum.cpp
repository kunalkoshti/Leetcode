/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

typedef pair<int, bool> pib;
class Solution {
public:
    bool check(TreeNode* root, int targetSum, int curr) {
        if (!root) {
            return false;
        }
        if (!root->left && !root->right) {
            if (targetSum == (curr+root->val))
                return true;
            else
                return false;
        }
        return (check(root->left, targetSum, curr + root->val) ||
                check(root->right, targetSum, curr + root->val));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return check(root, targetSum, 0);
    }
};