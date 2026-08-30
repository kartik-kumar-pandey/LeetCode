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
class Solution {
public:
    bool isMirror(TreeNode* sleft, TreeNode* sright) {
    if (sleft == NULL && sright == NULL) {
        return true;
    }
    if (sleft == NULL || sright == NULL) {
        return false;
    }
    bool flag=(sleft->val == sright->val);

    bool leftree=isMirror(sleft->left, sright->right);
    bool rightree=isMirror(sleft->right, sright->left);
    
    return  flag && leftree && rightree;
}

bool isSymmetric(TreeNode* root) {
    return isMirror(root, root);
}

};