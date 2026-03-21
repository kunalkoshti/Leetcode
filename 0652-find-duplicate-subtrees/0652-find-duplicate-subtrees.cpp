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
typedef unordered_map<int, vector<TreeNode*>> umiv;

class Solution {
public:
    umiv mp;
    int create_map(TreeNode* root) {
        if (!root)
            return -1;
        int left = create_map(root->left);
        int right = create_map(root->right);
        int ht = 1 + max(left, right);
        if (mp.find(ht) == mp.end())
            mp[ht] = {root};
        else {
            mp[ht].push_back(root);
        }
        return ht;
    }
    bool cmp(TreeNode* n1, TreeNode* n2, unordered_map<TreeNode*, int>& nid) {
        if (n1->val != n2->val)
            return false;
        if ((!n1->left && n2->left) || (n1->left && !n2->left) ||
            (n1->left && n2->left && nid[n1->left] != nid[n2->left]))
            return false;
        if ((!n1->right && n2->right) || (n1->right && !n2->right) ||
            (n1->right && n2->right && nid[n1->right] != nid[n2->right]))
            return false;
        return true;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        int max_ht = create_map(root);
        unordered_map<TreeNode*, int> nid;
        vector<TreeNode*> res;
        int ct = 0;
        for (int i = 0; i <= max_ht; i++) {
            for (int j = 0; j < mp[i].size(); j++) {
                if (nid.find(mp[i][j]) != nid.end())
                    continue;
                TreeNode* node1 = mp[i][j];
                nid[node1] = ct;
                bool fl = false;
                for (int k = j + 1; k < mp[i].size(); k++) {
                    if (nid.find(mp[i][k]) != nid.end())
                        continue;
                    TreeNode* node2 = mp[i][k];
                    if (cmp(node1, node2, nid)) {
                        nid[node2] = ct;
                        fl = true;
                    }
                }
                if (fl)
                    res.push_back(node1);
                ct++;
            }
        }
        return res;
    }
};