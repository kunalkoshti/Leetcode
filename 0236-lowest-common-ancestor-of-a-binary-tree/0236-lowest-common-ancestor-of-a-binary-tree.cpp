/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef pair<bool, bool> pbb;
class Solution {
public:
    pbb lca(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode** res) {
        if (!root)
            return {false, false};
        pbb lft = lca(root->left, p, q, res);
        pbb rgt = lca(root->right, p, q, res);
        if (*res)
            return {true, true};
        if (((lft.first || rgt.first) && root == q) ||
            ((lft.second || rgt.second) && root == p) ||
            ((lft.first && rgt.second) || (lft.second && rgt.first))) {
            *res = root;
            return {true, true};
        }
        return {(lft.first || rgt.first || (root == p)),
                (lft.second || rgt.second || (root == q))};
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = nullptr;
        lca(root, p, q, &res);
        return res;
    }
};