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

class BSTIterator {
public:
    stack<TreeNode*> s;
    bool reverse = true;
    void storeNodes(TreeNode* root){
        while(root != NULL){
            s.push(root);
            if(reverse == true){
                root = root->right;
            } else{
                root = root->left;
            }
        }
    }

    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        storeNodes(root);
    }
    
    int next() {
        TreeNode* ans = s.top();
        s.pop();
        if(!reverse) storeNodes(ans->right);
        else storeNodes(ans->left);
        return ans->val;
    }
    
    bool hasNext() {
        return s.size() > 0;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l = BSTIterator(root, false);
        BSTIterator r = BSTIterator(root, true);

        int i = l.next();
        int j = r.next();

        while(i < j){
            int sum = i + j;
            if(sum == k) return true;
            else if(sum < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};