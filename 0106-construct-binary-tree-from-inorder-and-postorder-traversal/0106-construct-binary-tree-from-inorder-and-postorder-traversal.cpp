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
    TreeNode* buildTree(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart,
     int inEnd, map<int, int>& mp){
        if(postStart < postEnd || inStart >  inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postStart]);
        int inRoot = mp[root->val];
        int numRight = inEnd - inRoot;

        root->right = buildTree(postorder, postStart-1, postStart-numRight, inorder, inRoot+1, inEnd, mp);
        root->left = buildTree(postorder, postStart-numRight-1, postEnd, inorder, inStart, inRoot-1, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = buildTree(postorder, postorder.size()-1, 0, inorder, 0, inorder.size()-1, mp);
        return root;
    }
};