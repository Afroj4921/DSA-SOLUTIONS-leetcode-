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
    pair<int, int> f(TreeNode* root, int & result){
        if(root == NULL){
            return {0, 0};
        }
        
        auto l = f(root->left, result);
        auto r = f(root->right, result);

        int total = l.first + r.first + root->val;
        int cnt = l.second + r.second + 1;
        int avg = total/cnt;
        if(avg == root->val){
            result += 1;
        }

        return {total, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        int result = 0;

        f(root, result);

        return result;
    }
};