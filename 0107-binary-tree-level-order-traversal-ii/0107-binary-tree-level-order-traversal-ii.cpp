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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<vector<int>> v;

        if (root != nullptr) {
            q.push(root);
        }

        while (!q.empty()) {
            int lsize = q.size();
            vector<int> temp;

            for (int i = 0; i < lsize; i++) {
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);

                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }

            v.push_back(temp);
        }
        reverse(v.begin(),v.end());

        return v;
    }
};