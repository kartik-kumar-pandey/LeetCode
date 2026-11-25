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

    int cntOfNodes = 0;

    pair<int, int> solve(TreeNode* root) { //sum, cnt

        if(root == nullptr) {
            return {0, 0};
        }

        pair<int, int> leftRes = solve(root->left);
        pair<int, int> rightRes = solve(root->right);

        int totalSum = root->val + leftRes.first + rightRes.first;
        int totalNodes = 1 + leftRes.second + rightRes.second;

        int avg = (totalSum/totalNodes);

        if(avg == root->val) {
            cntOfNodes++;
        }

        return {totalSum, totalNodes};
    }
public:
    int averageOfSubtree(TreeNode* root) {

        solve(root);
        return cntOfNodes;
    }
};